#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct pessoa{
    char nome[50];
    char sexo[1];
    int idade;
};

void registrar();

int main(){
    int opcao;
    do{
        printf("1 - registrar\n2 - visualizar\n3 - sair\n\nEscolha: ");
        scanf("%d",&opcao);

        switch(opcao){
        case 1:
            registrar();
            break;
        case 2:
            break;
        case 3:
            printf("Saindo...");
            break;
        default:
            printf("Escolha uma opção válida");
            break;
    }
    system("pause");
    system("cls");

    }while(opcao != 3);
    return 1;
}


void registrar(){
    struct pessoa entrar;
    FILE *file1, *file2;
    file1 = fopen("entrada.txt","a");
        printf("Insira o sexo: ");
        fflush(stdin);
        scanf("%s",&entrar.sexo);

        printf("Insira o nome: ");
        fflush(stdin);
        scanf("%s",&entrar.nome);

        printf("Insira a idade: ");
        fflush(stdin);
        scanf("%d",&entrar.idade);

        fwrite(&entrar, sizeof(struct pessoa),1, file1);

    fclose(file1);
}
