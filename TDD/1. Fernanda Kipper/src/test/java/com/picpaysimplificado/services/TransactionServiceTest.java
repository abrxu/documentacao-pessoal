package com.picpaysimplificado.services;

import com.picpaysimplificado.domain.user.User;
import com.picpaysimplificado.domain.user.UserType;
import com.picpaysimplificado.repositories.TransactionRepository;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.springframework.beans.factory.annotation.Autowired;

import java.math.BigDecimal;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.when;

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
        when(userService.findUserById(1L)).thenReturn(receiver);

        // não precisa do userService.validateTransaction(sender, transaction.value()); pois ele não retorna nada para precisar de alguma validação

        when(authService.authorizeTransaction(any(), any())).thenReturn(true); // não há validação com esses valores, então não importa o que é recebido
    }

    @Test
    @DisplayName("Should throw an Exception when the transaction is not allowed")
    void createTransactionCase2() {

    }
}