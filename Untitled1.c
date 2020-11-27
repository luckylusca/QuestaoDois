#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct pessoa{
    char nome[50];
    char sexo;
    int idade;
};

void copia(FILE *file1,FILE *file2);
void cadastrar(FILE *file1, FILE *file2);
void visualizar( FILE *file2);

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
    char ler[1000];
    file1 = fopen("entrada.txt","a+t");
        printf("Nome: ");
        scanf("%s",&dado.nome);

        printf("Sexo (m/f): ");
        scanf("%s",&dado.sexo);

        printf("Idade: ");
        scanf("%d",&dado.idade);

        fputc(dado.sexo,file1);
        fprintf(file1," %s ",dado.nome);
        fprintf(file1," %d\n",dado.idade);
    fclose(file1);

    file1 = fopen("entrada.txt","rt");
    file2 = fopen("saida.txt", "wt");
        copia(file1,file2);
    fclose(file1);
    fclose(file2);
}

void copia(FILE *file1,FILE *file2){
    int f = 0, m = 0, id = 0;
    char ler[1000], *result;
    while(!feof(file1)){
            result = fgets(ler, 1000, file1);
            if(result == "m"){
                m++;
            }else if(result == "f"){
                f++;
            }
        }
    fprintf(file2,"O numero de homens: %d \n",m);
    fprintf(file2,"O numero de mulheres: %d",f);
}

void visualizar(FILE *file2){
    file2 = fopen("saida.txt", "rt");
        while(!feof(file2)){

        }
    fclose(file2);
}
