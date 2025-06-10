#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int id;
} Pizzas;

Pizzas pizza[50];
int numPizza = 0; 

typedef struct {
    char nome[50];
    int id;
} Clientes;

Clientes cliente[50];
int numCliente = 0;

void cadastroPizza();
void cadastroCliente();
void listarPizzas();
void listarCliente();
void vendasPizza();
void finalizaFuncao();

int main() {
    int opcao;
    do {
        printf("--- Pizzaria NOSTRA PIZZA ---\n");
        printf("1 - Cadastrar Pizzas\n");
        printf("2 - Cadastrar Clientes\n");
        printf("3 - Listar Pizzas\n");
        printf("4 - Listar Clientes\n");
        printf("5 - Vender Pizzas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: 
                cadastroPizza(); 
                break;
            
            case 2: 
                cadastroCliente(); 
                break;
            
            case 3: 
                listarPizzas(); 
                break;
            
            case 4: 
                listarCliente(); 
                break;
            
            case 5: 
                vendasPizza(); 
                break;
            
            case 0: 
                printf("Saindo..."); 
                break;
            
            default: 
                printf("Opcao Inválida =( tente novamente!\n");
        }
    } while (opcao != 0);

    return 0;
}

void finalizaFuncao(){
    printf("\nPressione Enter para continuar.\n");
    getchar();
    getchar();
    system("clear");
}

void cadastroPizza() {
    system("clear");
    printf("-- Cadastro de Pizzas --\n");
    printf("Nome da Pizza: ");
    scanf(" %[^\n]", pizza[numPizza].nome);  
    printf("Preço da Pizza : ");
    scanf("%f", &pizza[numPizza].preco);
    printf("ID da Pizza : ");
    scanf("%d", &pizza[numPizza].id);
    
    printf("\nPizza cadastrada com sucesso!\n");
 
    numPizza++; 
    
    finalizaFuncao();
}

void cadastroCliente() {
    system("clear");
    printf("-- Cadastro do Cliente --\n");
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", cliente[numCliente].nome);  
    printf("ID do Cliente: ");
    scanf("%d", &cliente[numCliente].id);

    printf("Cliente cadastrado com sucesso!\n");

    numCliente++; 
    
    finalizaFuncao();
}
    
void listarPizzas() {
    system("clear");
    printf("--- Pizzas Cadastradas ---\n");
    for(int i = 0; i < numPizza; i++) {
        printf("Nome da pizza : %s\n", pizza[i].nome);
        printf("Preço : %.2f\n", pizza[i].preco);
        printf("ID da Pizza : %d", pizza[i].id);
        printf("\n-------------------------\n");
    }
    
    finalizaFuncao();
}
    
void listarCliente() {
    system("clear");
    
    printf("--- Clientes Cadastrados ---\n");
    for(int i = 0; i < numCliente; i++) {
        printf("Nome do Cliente : %s\n", cliente[i].nome);
        printf("ID : %d\n", cliente[i].id);
        printf("\n-----------------------------\n");
    }
    
    finalizaFuncao();
}

void vendasPizza() {
    system("clear");
    
    int clienteID;
    int clienteEncontrado = 0;
    int pizzaID;
    int pizzaEncontrada = 0;
    float total;
    int quantidade;
    int indiceCliente;
    int indicePizza;

    if (numCliente == 0) {
        printf("Nenhum cliente cadastrado =( tente novamente.\n");
    }
    if (numPizza == 0) {
        printf("Nenhuma pizza cadastrada =( tente novamente.\n");
    }

    printf("Digite o ID do cliente: ");
    scanf("%d", &clienteID);
    for (int i = 0; i < numCliente; i++) {
        if (cliente[i].id == clienteID) {
            clienteEncontrado = 1;
            indiceCliente = i;
            printf("Cliente encontrado =) \n");
        }
    }
    if (!clienteEncontrado) {
        printf("Cliente não cadastrado =(\n");
    }

    printf("Digite o ID da pizza que você deseja: ");
    scanf("%d", &pizzaID);
    for (int i = 0; i < numPizza; i++) {
        if (pizza[i].id == pizzaID) {
            pizzaEncontrada = 1;
            indicePizza = i;
            printf("Pizza cadastrada =) \n");
            break;
        }
    }
    if (!pizzaEncontrada) {
        printf("Está pizza não está na lista de cadastros =(\n");
        finalizaFuncao();
        return;
    }

    printf("Digite a quantidade desejada da pizza: ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Quantidade inválida =( Tente novamente.\n");
    }

    total = pizza[indicePizza].preco * quantidade;
    
    printf("Total a pagar: %.2f reais\n", total);
    
    finalizaFuncao();
}
