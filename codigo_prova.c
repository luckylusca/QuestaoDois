#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE *file;
typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    int cod_terminal;
    data dat;
    int hora;
    char placa[8];
    int cod_empresa;
}onibus;
typedef onibus elemento;

const elemento VL_NULO = {0, 0, 0, 0, 0, "", 0};

#include "tad_list1.c"
#include "tad_list2.c"

tipo_lista lista;

void montar_tela(){
    printf("\n --- Programa Terminais ---\n");
    printf("\n 1 - Carrega lista");
    printf("\n 2 - Lista dados");
    printf("\n 3 - Média de tempo");
    printf("\n 4 - Valor da empresa");
    printf("\n 5 - Inverte lista");
    printf("\n 6 - Tamanho lista");
    printf("\n 7 - Sair");
    printf("\nEscolha uma opção: ");
}

char escolhe_opcao(){
	return getchar();
}

void limpa_tela(){
	system("cls");
}

void reg_cod_term(int *cod_terminal){
    printf("Insira o código do terminal: ");
    fflush(stdin);
    scanf("%d",&cod_terminal);
    limpa_tela();
}

void reg_data(int *dia, int *mes, int *ano){
    printf("\nInsira o dia: ");
    fflush(stdin);
    scanf("&d", &dia);

    printf("\nInsira o mes: ");
    fflush(stdin);
    scanf("&d", &mes);

    printf("\nInsira o ano: ");
    fflush(stdin);
    scanf("%d", &ano);
    limpa_tela();
}

void reg_hora(int *hora){
    printf("Formato base [0000]\nInsira a hora: ");
    fflush(stdin);
    scanf("%d",&hora);
    limpa_tela();
}

void reg_placa(char *placa){
    printf("Insira a placa: ");
    fflush(stdin);
    scanf("%s",&placa);
    limpa_tela();
}

void reg_cod_empr(int *cod_empresa){
    printf("Insira o código da empresa: ");
    fflush(stdin);
    scanf("&d",&cod_empresa);
    limpa_tela();
}

void registrar(){
    int pos; elemento elem = VL_NULO;
    reg_cod_term(elem.cod_terminal);
    reg_data(elem.dat.dia, elem.dat.mes, elem.dat.ano);
    reg_hora(elem.hora);
    reg_placa(elem.placa);
    reg_cod_empr(elem.cod_empresa);

    arquivo(file);
    printf("\n Registro realizado com sucesso! \n");

}

void arquivo(FILE file){
    file = fopen("2019-09-06.txt","a");
        fprintf(file,"%i ",elem.cod_terminal);
        fprintf(file,"%i",elem.dat.dia);
        fprintf(file,"%i",elem.dat.mes);
        fprintf(file,"%i ",elem.dat.ano);
        fprintf(file,"%s ",elem.placa);
        fprintf(file,"%i\n",elem.cod_empresa);
    fclose(file);
}

void listar() {
    int i, tam; elemento elem;
	limpa_tela();
    tam = tamanho(lista);
    if (tam > 0) {
        for (i=1;i<=tam;i++) {
            if (obter_elemento(lista,i,&elem))
                printf("\n%d %d%d%d %d %d", i, elem.cod_terminal, elem.dat.dia, elem.dat.mes, elem.dat.ano, elem.hora, elem.placa, elem.cod_empresa);
        }
    }else
      printf(" Lista vazia!");
   printf("\n<tecle ENTER para continuar>");
   getchar();
}

int main(){
    char opcao;
    setlocale(LC_ALL, "Portuguese");

    do{
        montar_tela();
        opcao = escolhe_opcao();

        limpa_tela();
        switch(opcao){
            case '1':
                break;

            case '2':
                registrar();
                break;

            case '3':
                break;

            case '4':
                break;

            case '5':
                break;

            case '6':
                break;

            case '7':
                printf("\nSaindo...");
                break;

            default:
                break;
        }
        getchar();
        limpa_tela();
    }while(opcao != '7');
    return 1;
}
