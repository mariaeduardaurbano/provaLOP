#include <stdio.h>

struct Pessoa{
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p;
    
    printf("Informe o nome: ");
    scanf("%s", p.nome);
    
    printf("Informe a idade: ");
    scanf("%d", &p.idade);
    
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d", p.idade);
    
    return 0;
}