#include <locale.h>
#include "tad_list1.c"

tipo_lista lista_bus;

void monta_tela(){
    printf(" --- MENU PROGRAMA ---\n");
    printf("\n| 1 - Carregar");
   	printf("\n| 2 - Incluir");
   	printf("\n| 3 - Média");
   	printf("\n| 4 - Valor");
   	printf("\n| 7 - sair\n|");
   	printf("\n|Escolha uma opção: ");
}

char escolh(){
    return getchar();
}

void limpa_tela(){
    system("cls");
}

void opc(char opcao){
    switch(opcao){
        case '1':
            break;
        case '2':
            inclur();
            break;
        case '3':
            break;
        case '4':
            break;
        case '7':
            printf("Saindo...");
            break;
        default:
            printf("Escolha uma opção valida!");
            break;
    }
}

int main (){
    char opcao;
    do{
        monta_tela();
        opcao = escolh();
        limpa_tela();
        opc(opcao);
        fflush(stdin);
        getchar();
        limpa_tela();
    }while(opcao != '7');
    return 1;
}
