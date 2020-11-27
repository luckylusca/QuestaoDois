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
void copia(FILE *file1, FILE *file2);
void visualizar(FILE *file2);

void main(){
    setlocale(LC_ALL, "portuguese");
    int opcao;
    FILE *file1, *file2;
    do{
        printf("-----MENU-----\n 1 - registrar\n 2 - visualizar\n 3 - sair\n\nEscolha uma opção: ");
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
        system("cls");
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
        fprintf(file1," %s ",dado.nome);
        fprintf(file1," %d",dado.idade);
    fclose(file1);

    file1 = fopen("entrada.txt","r");
    file2 = fopen("saida.txt", "a");
        copia(file1,file2);
    fclose(file1);
    fclose(file2);
}

void copia(FILE *file1, FILE *file2){
    char ler[1000];
    while(fgets(ler, 1000,file1) != NULL){
        fputs(ler,file2);
    }
}

void visualizar(FILE *file2){
    char *result, linha[1000];
    file2 = fopen("saida.txt", "rt");
        while(!feof(file2)){
            result = fgets(linha, 1000, file2);
            if(result){
                printf("");
            }
        }
    fclose(file2);
}
