#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//estrutura de dados
struct pessoa{
    char nome[50];
    char sexo;
    int idade;
};

//criação de funções
void copia(FILE *file1,FILE *file2);
void cadastrar(FILE *file1, FILE *file2);
void visualizar( FILE *file2);

//declaração de arquivos
FILE *file1, *file2;

void main(){
    setlocale(LC_ALL, "portuguese");
    int opcao;
    do{
            //sistema menu
        printf("-----MENU-----\n 1 - registrar\n 2 - visualizar\n 3 - sair\n\nEscolha uma opção: ");
        scanf("%d",&opcao);
        system("pause");
        system("cls");
        switch(opcao){
            case 1:
                //chamada da função CADASTRAR
                cadastrar(file1,file2);
                break;
            case 2:
                //chamada de gunção VISUALIZAR
                visualizar(file2);
                break;
            case 3:
                printf("Saindo...");
                break;
            default:
                printf("Escolha uma opção valída!");
                break;
        }
        system("pause");
        system("cls");
    }while(opcao != 3);
}

void cadastrar(FILE *file1,FILE *file2){
    struct pessoa dado;
    //aberttura do arquivo file1
    file1 = fopen("entrada.txt","a+t");
        //recebendo dados
        printf("Nome: ");
        scanf("%s",&dado.nome);

        printf("Sexo (M/F): ");
        scanf("%s",&dado.sexo);

        printf("Idade: ");
        scanf("%d",&dado.idade);

        //escrevendo dados no arquivo
        fputc(dado.sexo,file1);
        fprintf(file1," %s ",dado.nome);
        fprintf(file1," %d\n",dado.idade);
    fclose(file1);

    file1 = fopen("entrada.txt","rt");
    file2 = fopen("saida.txt", "wt");
        //colocar dados pro segundo arquivo
        copia(file1,file2);
    fclose(file1);
    fclose(file2);
}

void copia(FILE *file1,FILE *file2){
    int f = 0, m = 0;
    char ler[100], masc[] = "Mm", fem[] = "Ff", result[100];

    //comparando caracter
    ler[100] = fgets(result,100,file1);
    for(int i = 0; i < strlen(ler); i+50){
        for(int j=0; j < strlen(masc);j++){
            if(ler[i] == masc[j]){
                m++;
            }
        }
        for(int x; x < strlen(fem); x++){
            if(ler[i] == fem[x]){
                f++;
            }
        }
    }
    //salvando no arquivo file2 formatada
    fprintf(file2,"O numero de homens: %d\n",m);
    fprintf(file2,"O numero de mulheres: %d",f);
}

void visualizar(FILE *file2){
    char ler[1000], *result;
    file2 = fopen("saida.txt", "rt");
    //ciclo para ler o segundo arquivo
        while(!feof(file2)){
                // mostrando tudo dentro do arquivo
            result = fgets(ler,1000,file2);
            printf("%s", result);
        }
    printf("\n\n");
    fclose(file2);
}
