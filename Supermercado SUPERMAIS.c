#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
}Produtos;

Produtos produto;

void cadastrarProduto();
void mostraProduto();
void realizarCompra();
void finalizaFuncao();

int main(){
    int opcao;
    produto.quantidade = 0;
    
    do{
        printf("--- Supermercado SUPERMAIS ---\n");
        printf("1- Cadastrar Produto\n");
        printf("2- Mostrar Produtos em Estoque\n");
        printf("3- Realizar Compra\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                cadastrarProduto();
                break;
            
            case 2:
                mostraProduto();
                break;
            
            case 3:
                realizarCompra();
                break;
            
            case 0:
                printf("Saindo...");
                break;
            
            default:
            printf("Opcao inválida =( tente novamente!");
        }
        
    } while(opcao != 0);
    
    return 0;
  
}

void finalizaFuncao(){
    printf("\nPressione Enter para continuar.\n");
    getchar();
    getchar();
    system("clear");
}

void cadastrarProduto() {
    system("clear");
    printf("--- Cadastrar Produto ---\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome);  
    printf("Quantidade no estoque: ");
    scanf("%d", &produto.quantidade);
    printf("Preço do produto:  ");
    scanf("%f", &produto.preco);
    printf("\nProduto cadastrado com sucesso!\n");
    finalizaFuncao();
}

void mostraProduto() {
    system("clear");
    if (produto.quantidade < 0) {
        printf("Ainda não existem produtos cadastrados.\n");
    }
    printf("--- Dados do Produto ---\n");
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade no estoque: %d\n", produto.quantidade);
    printf("Preço do produto: %.2f reais\n", produto.preco);
    
    finalizaFuncao();
}

void realizarCompra() {
    system("clear");
    
    float total;
    
    if (produto.quantidade < 0) {
        printf("Ainda não existem produtos cadastrados.\n");
    }
    
    int quantidadeCompras;
    printf("--- Realizar Compra ---\n");
    printf("Quantidade de produtos: ");
    scanf("%d", &quantidadeCompras);

    if (quantidadeCompras <= 0) {
        printf("Quantidade inválida, tente novamente! =).\n");
    } else if (quantidadeCompras > produto.quantidade) {
        printf("Estoque insuficiente =( Estoque atual: %d\n", produto.quantidade);
    } else {
        
        produto.quantidade = produto.quantidade - quantidadeCompras;
        
        total = quantidadeCompras * produto.preco;
        
        printf("Compra realizada com sucesso! =) Total:%.2f reais\n", total);
        printf("Estoque restante: %d\n", produto.quantidade);
        
        finalizaFuncao();
    }
}
