#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char banda[30];
    int ano, qntd, generoID;
    float preco;
} CD;

int numCDs = 0;
CD cd[50];

void cadastrarCDs();
void vendaCDs();
void buscarCDs();
void finalizaFuncao();

int main (){
    
    int opcao;
    
    do{
        printf("--- Loja SOM E ARTE ---\n");
        printf("1 - Cadastrar CD's\n");
        printf("2 - Vender CD's\n");
        printf("3 - Buscar CD por Genero\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                cadastrarCDs();
                break;
                
            case 2:
                vendaCDs();
                break;
            
            case 3:
                buscarCDs();
                break;
            
            case 0:
                printf("Saindo...");
                break;
                
            default:
            printf("Opcao Inválida =( tente novamente!");
        }
        
    } while(opcao != 0);
    
}

void finalizaFuncao(){
    printf("\nPressione Enter para continuar.\n");
    getchar();
    getchar();
    system("clear");
}

void cadastrarCDs() {
    system("clear");
    if(numCDs >= 50){
        printf("Estoque lotado, não é possível cadastrar mais CD's =(");
    }
    
    printf("--- Cadastrar CD's ---\n");
    printf("Nome da banda: ");
    scanf(" %[^\n]", cd[numCDs].banda);
    printf("Ano de lancamento: ");
    scanf("%d", &cd[numCDs].ano);
    printf("Genero (por ID): ");
    scanf("%d", &cd[numCDs].generoID);
    printf("Quantidade no estoque: ");
    scanf("%d", &cd[numCDs].qntd);
    printf("Preço do produto: ");
    scanf("%f", &cd[numCDs].preco);
    
    printf("Produto Cadastrado com sucesso! =)");
    
    numCDs++;
    
    finalizaFuncao();
}

void vendaCDs() {
    system("clear");
    
    int qntdCompras;
    float total;
    
    if (numCDs == 0){
        printf("Ainda não existem produtos cadastrados.\n");
    }
    
    printf("--- Realizar Compra ---\n");
    printf("Quantiade de CD's: ");
    scanf("%d", &qntdCompras);
    
    if (qntdCompras <= 0) {
        printf("Quantidade inválida, tente novamente! =)\n");
    } else if (qntdCompras > cd[0].qntd) {
        printf("Estoque insuficiente =( Estoque atual: %d\n", cd[0].qntd);
    } else {
        
        cd[0].qntd -= qntdCompras; 
        total = qntdCompras * cd[0].preco;
        
        printf("Compra realizada com sucesso! =) Total:%.2f reais\n", total);
        printf("Estoque restante: %d\n", cd[0].qntd);
    }
    
    finalizaFuncao();
}

void buscarCDs() {
    system("clear");
    
    int id;
    
    printf("Informe o ID do genero: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numCDs; i++) {
        if (cd[i].generoID == id) {
            printf("Nome da Banda: %s\n", cd[i].banda);  
            printf("Ano: %d\n", cd[i].ano);  
            printf("ID do genero: %d\n", cd[i].generoID);  
            printf("Quantidade no estoque: %d\n", cd[i].qntd);
            printf("Preço do produto: %.2f reais\n", cd[i].preco);
            printf("-------------------------\n");
        }
    }
    
    finalizaFuncao();
}