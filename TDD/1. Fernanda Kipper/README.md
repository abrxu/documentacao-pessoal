# TDD - Fernanda Kipper

[Vídeo de base da Kipper](https://www.youtube.com/watch?v=T6ChO8LQxRE)

## Bibliotecas utilizadas:
- [JUnit](https://junit.org/junit5/)
- [Mockito](https://site.mockito.org/)

### Shortcut para criar testes unitários no IntelliJ:
```markdown
Ctrl + Shift + T
```

### Podemos assim criar o teste para:

```src > main > java > com.picpaysimplificado > repositories > UserRepository```

Cria-se então o pacote ```repositories``` em _**test**_ juntamente com o ```UserRepositoryTest```
```java
@DataJpaTest // pois estamos testando JPA
@ActiveProfiles("test") // "profile de testes" que irá ser criado num .properties jajá
class UserRepositoryTest {

    @Test
    void findUserByDocument() {

    }
}
```

### De onde pegar os dados de teste?

-> Há duas opções:
1. **Database para testes unitários**
- **Pró:** Mais próximos à situação real por conta de gerenciamento de banco de dados igual de prod;
- **Contra:** Mais custoso e lento pois há a necessidade de conexão com db, criação de tabelas, alteração de tabelas conforme escala de aplicação na prod etc.
2. **Banco de dados em memória (H2, por exemplo)**
- **Pró:** Mais rápido para escrita de testes e flexível por ser armazenado em memória;
- **Contra:** Mais "afastado" da realidade da aplicação, porém se bem feito consegue cumprir o papel.

### Testando aplicação com banco de dados em memória:

- Dependência do H2 Database no Spring
```xml
<dependency>
    <groupId>com.h2database</groupId>
    <artifactId>h2</artifactId>
    <scope>runtime</scope>
</dependency>
```
- Configurando application.properties para **testes unitários**

1. Entrando em ```src > test``` cria-se a pasta ```resources```
2. Dentro do resources, cria-se o ```application-test.properties```
3. Relacionar banco de dados em memória ou específico para testes nesse _.properties_

- Para especificar em um arquivo qual arquivo de teste utilizar, denota-se:
```java
@ActiveProfiles("test")
```

## Colocando a mão na massa e começando os testes:

## Repository

1. Precisamos primeiramente inserir dados no Banco de Dados por meio do teste **antes de fazer as validações do teste**. Podemos fazer isso utilizando o EntityManager:

```java
@Autowired
EntityManager entityManager
```
e logo após cria-se um novo método **privado** como método auxiliar:
```java
// seguindo lógica da aplicação, por isso usa-se UserDTO assim como na aplicação.
private User createUser(UserDTO data) {
    User newUser = new User(data); // entidade já possui construtor com UserDTO
    this.entityManager.persist(newUser); // persistindo entidade no banco de dados
    return newUser;
}
```
pronto! criadinho o método auxiliar para nos ajudar nos testes unitários. E agora?

iremos usar esse método ```createUser``` dentro dos nossos casos de teste unitário para criar um usuário e fazer uma consulta no banco de dados.

2. Nomenclatura de métodos de teste:

Conforme exemplos dados no vídeo, majoritariamente se usa:

1.1. 
```java
@Test
    // ou Error
    void findUserByDocumentSuccess() {

    }
```
1.2.
```java
@Test
    void findUserByDocumentCase1() {

    }
```

3. Descrevendo teste unitário com anotação ```@DisplayName("Descrição do teste")``` falando **o que o método deveria fazer**

4. Escrevendo "finalmente" o teste:

```java
@DataJpaTest // pois estamos testando JPA
@ActiveProfiles("test") // "profile de testes" que irá ser criado num .properties jajá
class UserRepositoryTest {

    @Test
    @DisplayName("Should get user successfully from DB")
    void findUserByDocumentCase1() {
        String document = "99999999901"; // criando separado para usar em consulta dps
        UserDTO data = new UserDTO("Abreu", "Teste", document, new BigDecimal(10), "teste@gmail.com", "teste@2025", UserType.COMMON);
        this.createUser(data);
    }

    private User createUser(UserDTO data) {
        User newUser = new User(data);
        this.entityManager.persist(newUser);
        return newUser;
    }
}
```

5. Nesse caso em específico, já que precisamos testar a funcionalidade de buscar um _User_ por meio de um _Documento_ iremos injetar no repository o próprio repository

```java
@Autowired
UserRepository userRepository;

@Test
@DisplayName("Should get user successfully from DB")
void findUserByDocumentCase1() {
    String document = "99999999901";
    UserDTO data = new UserDTO("Abreu", "Teste", document, new BigDecimal(10), "teste@gmail.com", "teste@2025", UserType.COMMON);
    this.createUser(data);
    
    Optional<User> result = this.userRepository.findUserByDocument(document); // usando o repository
    assertThat(result.isPresent()).isTrue(); // verificar que o usuário foi encontrado e está presente no resultado
}
```

prontinho! agora criaremos um teste para garantir que: quando um usuário não exista garantir que não será retornado nada do banco de dados.

```java
@Autowired
UserRepository userRepository;

@Test
@DisplayName("Should not get User from DB when user does not exist")
void findUserByDocumentCase2() {
String document = "99999999901";

    Optional<User> result = this.userRepository.findUserByDocument(document);
    
    assertThat(result.isEmpty()).isTrue();
}
```

## Service

1. Pensar nos casos que podem ocorrer ao decorrer do método, analisando o código bem antes de definir os casos;
2. Setar o ```@DisplayName("Should[...]")``` para descrever o comportamento esperado daquele teste;
3. Mockar os dados para buildar o ambiente propício para o teste daquele caso:

3.1. Injetando as mesmas dependências que existem no ```Service``` original com annotation ```@Mock```:
```java
@Mock
private UserService userService;

@Mock
private TransactionRepository repository;

@Mock
private AuthorizationService authService;

@Mock
private NotificationService notificationService;
```

3.2. Precisaremos também de uma instância do ```Service``` originário deste teste usando também uma annotation que detalhe que a classe deve usar os ```Mocks``` e não as classes reais:

```java
@Autowired
@InjectMocks
private TransactionService transactionService;
```

3.3. Adiciona-se também um novo método com a annotation ```@BeforeEach``` (indicando que este método deve ser executando sempre antes do teste unitário). O método será void e é comumente nomeado de ```setup```;
```java
@BeforeEach
void setup() {
    MockitoAnnotations.initMocks(this); // this = essa classe de testes
}
```



