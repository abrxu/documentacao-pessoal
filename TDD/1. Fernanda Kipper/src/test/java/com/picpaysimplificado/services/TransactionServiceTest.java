package com.picpaysimplificado.services;

import com.picpaysimplificado.domain.user.User;
import com.picpaysimplificado.domain.user.UserType;
import com.picpaysimplificado.dtos.TransactionDTO;
import com.picpaysimplificado.repositories.TransactionRepository;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.springframework.beans.factory.annotation.Autowired;

import java.math.BigDecimal;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.*;

class TransactionServiceTest {

    @Mock
    private UserService userService;

    @Mock
    private TransactionRepository repository;

    @Mock
    private AuthorizationService authService;

    @Mock
    private NotificationService notificationService;

    @Autowired
    @InjectMocks
    private TransactionService transactionService;

    @BeforeEach
    void setup() {
        MockitoAnnotations.initMocks(this);
    }

    @Test
    @DisplayName("Should create transaction successfully when everything runs ok")
    void createTransactionCase1() throws Exception {
        User sender = new User(1L, "abreu", "baumhardt", "99999999901", "sla@yahoo.com", "senha@teste", new BigDecimal(1000), UserType.COMMON);
        User receiver = new User(2L, "joao", "gabriel", "99999999902", "sla2@yahoo.com", "senha@teste", new BigDecimal(1000), UserType.COMMON);
        when(userService.findUserById(1L)).thenReturn(sender);
        when(userService.findUserById(2L)).thenReturn(receiver);

        // não precisa do userService.validateTransaction(sender, transaction.value()); pois ele não retorna nada para precisar de alguma validação

        when(authService.authorizeTransaction(any(), any())).thenReturn(true); // não há validação com esses valores, então não importa o que é recebido

        TransactionDTO request = new TransactionDTO(new BigDecimal(10), 1L, 2L);
        transactionService.createTransaction(request);

        // com todo "cenário" construido certinho, agora podemos validar

        verify(repository, times(1)).save(any()); // verificando que o método save tenha sido chamado apenas uma vez

        sender.setBalance(new BigDecimal(0));
        verify(userService, times(1)).saveUser(sender); // verificando se foi atualizado saldo

        receiver.setBalance(new BigDecimal(20));
        verify(userService, times(1)).saveUser(receiver); // verificando se foi atualizado saldo

        verify(notificationService, times(1)).sendNotification(sender, "Transação realizada com sucesso");
        verify(notificationService, times(1)).sendNotification(receiver, "Transação recebida com sucesso");
    }

    @Test
    @DisplayName("Should throw an Exception when the transaction is not allowed")
    void createTransactionCase2() throws Exception {
        User sender = new User(1L, "abreu", "baumhardt", "99999999901", "sla@yahoo.com", "senha@teste", new BigDecimal(1000), UserType.COMMON);
        User receiver = new User(2L, "joao", "gabriel", "99999999902", "sla2@yahoo.com", "senha@teste", new BigDecimal(1000), UserType.COMMON);
        when(userService.findUserById(1L)).thenReturn(sender);
        when(userService.findUserById(2L)).thenReturn(receiver);

        when(authService.authorizeTransaction(any(), any())).thenReturn(false);

        Exception thrown = Assertions.assertThrows(Exception.class, () -> { // usando função anônima tenta pegar uma Exception
            TransactionDTO request = new TransactionDTO(new BigDecimal(10), 1L, 2L);
            transactionService.createTransaction(request);
        });

        Assertions.assertEquals("Transação não autorizada", thrown.getMessage()); // verificando mensagem da exceção
    }
}