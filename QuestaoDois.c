/*
    Codigo desenvolvido para a cadeira de Algoritmo e Estrutura de Dados
    Professor responsavel é o prof. Gentil
    Alunos que trabalharam no programa: Lucas Felipe, Wesley Versart, Franscico Remo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct pessoa{
    char nome[50];
    char sexo;
    int idade;
};

FILE *entrada, *saida, *genero, *idade;

void registrar(FILE *entrada,FILE *genero,FILE *idade);
void menu(int opcao);
void copia(FILE *genero,FILE *idade,FILE *saida);
void olhar(FILE *entrada, FILE *saida);

int main(){
    setlocale(LC_ALL,"portuguese");
    int opcao;
    do{
        printf("-----MENU-----\n 1 - registrar\n 2 - visualizar\n 3 - sair\n\nEscolha uma opção: ");
        scanf("%d",&opcao);
        system("pause");
        system("cls");

        menu(opcao);
    }while(opcao !=3);
    return 1;
}

void menu(int opcao){
    switch(opcao){
        case 1:
            //chamada da função CADASTRAR
            registrar(entrada, genero, idade);
            break;
        case 2:
            //chamada de função VISUALIZAR
            copia(genero,idade,saida);
            olhar(entrada,saida);
            break;
        case 3:
            printf("Saindo...\n\n");
            break;
        default:
            printf("Escolha uma opção valída!");
            break;
    }
    system("pause");
    system("cls");
}

void registrar(FILE *entrada,FILE *genero,FILE *idade){
    struct pessoa dado;

    entrada = fopen("entrada.txt","a+t");
    genero = fopen("genero.txt","a+t");
    idade = fopen("idade.txt","a+t");
        printf("Nome: ");
        scanf("%s",&dado.nome);

        printf("Sexo (M/F): ");
        scanf("%s",&dado.sexo);

        printf("Idade: ");
        scanf("%d",&dado.idade);

        fputc(dado.sexo,entrada);
        fprintf(entrada," %s ",dado.nome);
        fprintf(entrada," %d\n",dado.idade);

        fputc(dado.sexo,genero);
        fprintf(idade,"%d \n", dado.idade);
    fclose(entrada);
    fclose(idade);
    fclose(genero);
}

void copia(FILE *genero,FILE *idade,FILE *saida){
    int m = 0, f = 0, maior = 0, id;
    char ler1, ler2[100];

    saida = fopen("saida.txt","w+t");
    genero = fopen("genero.txt","r+t");
    idade = fopen("idade.txt","r+t");

        while(!feof(genero)){
            ler1 = fgetc(genero);
            if(ler1 == 'M' || ler1 == 'm'){
                m++;
            }else if(ler1 == 'F' || ler1 ==  'f'){
                f++;
            }
        }
        while(!feof(idade)){
            ler2[100] = fgetc(idade);
            id = atoi(ler2);
            if(id > maior){
                maior <- id;
            }
        }

        fprintf(saida,"O numero de homens: %d\n",m);
        fprintf(saida,"O numero de mulheres: %d\n",f);
        fprintf(saida,"A idade da pessoa mais velha: %d\n\n",maior);

    fclose(saida);
    fclose(idade);
    fclose(genero);
}

void olhar(FILE *entrada, FILE *saida){
    char ler[1000], *aparecer;
    entrada = fopen("entrada.txt","r+t");
        while(!feof(entrada)){
            aparecer = fgets(ler,1000,entrada);
            if(aparecer == NULL){
                break;
            }else{
                printf("%s",aparecer);
            }
        }
        printf("\n\n");
    fclose(entrada);

    saida = fopen("saida.txt","r+t");
        while(!feof(saida)){
            aparecer = fgets(ler,1000,saida);
            if(aparecer == NULL){
                break;
            }else{
                printf("%s",aparecer);
            }
        }
    fclose(saida);
}
