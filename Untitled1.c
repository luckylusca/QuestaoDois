#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct pessoa{
    char nome[50];
    char sexo;
    int idade;
};

void cadastrar(FILE *file1, FILE *file2);

void main(){
    setlocale(LC_ALL, "portuguese");
    int opcao;
    FILE *file1, *file2;
    do{
        printf("-----MENU-----");
        scanf("%d",&opcao);
        system("pause");
        system("cls");
        switch(opcao){
            case 1:
                cadastrar(file1,file2);
                break;
            case 2:
                break;
            case 3:
                printf("Saindo...");
                break;
            default:
                printf("Escolha uma opção valída!");
                break;
        }
    }while(opcao != 3);
}

void cadastrar(FILE *file1,FILE *file2){
    struct pessoa dado;
    file1 = fopen("entrada.txt","a+t");
        printf("Nome: ");
        scanf("%s",&dado.nome);

        printf("Sexo: ");
        scanf("%s",&dado.sexo);

        printf("Idade: ");
        scanf("%d",&dado.idade);

        fputc(dado.sexo,file1);
        fprintf(file1,dado.nome);
        fprintf(file1,"%d",dado.idade);
    fclose(file1);
}
