
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Compra
{
    float valor;
    float multas;
};

struct Venda
{
    float valor;
};

struct agenda {
    int cod;
    char marca[20];
    char modelo[20];
    char cor[20];
    struct Compra compra;
} registros[100];

void cadastrar(int cod, int pos);
void consultar();
int verifica_pos();
void zerar();
int verifica_cod(int cod);
void excluir();

int main(void)
{

    int op = 0;
    int retorno;
    int codaux;
    int posicao;

    zerar();

    while ( op != 4 )
    {
        printf("\n\n\t\t\t\t** AGENCIA DE CARROS **\n\n\nMENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Sair\n\nOpcao: ");
        scanf("%d",&op);

        system("cls");

        switch (op)
        {
            case 1:
            {
                posicao = verifica_pos();

                if ( posicao != -1 )
                {
                    printf("\nEntre com o codigo desejado\n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod(codaux);

                    if ( retorno == 1 )
                        cadastrar(codaux,posicao);
                    else
                        printf("\nCodigo ja existente\n");
                }
                else
                    printf("\nA agenda esta cheia\n");

                break;
            }
            case 2:
            {
                consultar();
                break;
            }
            case 3:
            {
                excluir();
                break;
            }
            case 4:
            {
                printf("\n\nTchau");
                break;
            } // ERRO: Faltou o fecha chaves
            default :
            { // ERRO: Faltou o abre chaves
                printf("Opcao Invalida");
                break;
            }
        }
    }

    getch();

    return 0;
}

void cadastrar(int cod, int pos)
{
    pos = verifica_pos();

    registros[pos].cod = cod;

    printf("\n Marca:\n");
    gets(registros[pos].marca);

    printf("\n Modelo:\n");
    scanf("%s", registros[pos].modelo); // Toda string (vetor de char) é um ponteiro para estrutura

    printf("\n Cor:\n");
    scanf("%s", registros[pos].cor); // Toda string (vetor de char) é um ponteiro para estrutura

    printf("\n Valor: \n");
    scanf("%f", &registros[pos].compra.valor);

    //registros[pos].venda.valor = 0;

    printf("\nCadastro Realizado com Sucesso!\n\n");
}

void consultar()
{
    int cont = 0;
    int cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);

    for ( cont = 0; cont < 100; cont++ )
    {
        if ( registros[cont].cod == cod )
        {
            if ( registros[cont].compra.valor != 0 ) // Caso o veiculo ainda esteja no cadastro
            {
                printf("\n Marca: %s", registros[cont].marca);
                printf("\n Modelo: %s", registros[cont].modelo);
                printf("\n Cor: %s", registros[cont].cor);
                printf("\n Valor: %f", registros[cont].compra.valor);
            }
            return; // retorna se encontrou o veiculo
        }
    }

    printf("\nCodigo nao encontrado\n"); // Sera mostrado apenas se nao encontrar

}

int verifica_pos()
{
    int cont = 0;

    for ( cont = 0; cont < 100; cont++ )
        if ( registros[cont].compra.valor == 0 )
            return cont;

    return -1;
}

void zerar()
{
    int cont = 0;

    for ( cont = 0; cont < 100; cont++ ) // 'for' de 0 até <= 100, resulta em 101 valores
    {
        registros[cont].cod = 0;
        strcpy(registros[cont].marca, "");
        strcpy(registros[cont].modelo, "");
        strcpy(registros[cont].cor, "");
        registros[cont].compra.valor = 0;
    }
}

int verifica_cod(int cod)
{
    int cont = 0;

    for ( cont = 0; cont < 100; cont++ )
    {
        if ( registros[cont].cod == cod )
            return 0;
    }

    return 1;
}

void excluir()
{
    int cod = 0;
    int cont = 0;

    printf("\nEntre com o codigo do registro que deseja excluir\n");
    scanf("%d",&cod);

    for ( cont = 0; cont < 100; cont++ )
    {
        if ( registros[cont].cod == cod )
        {
            if ( registros[cont].compra.valor != 0 ) // Controle pelo valor de compra
            {
                registros[cont].cod = 0;
                strcpy(registros[cont].marca, "");
                strcpy(registros[cont].modelo, "");
                strcpy(registros[cont].cor, "");
                registros[cont].compra.valor = 0;

                printf("\nExclusao feita com sucesso\n");
            }

            return; // Retorna se encontrou o codigo
        }
    }

    printf("\nCodigo nao encontrado\n"); // Sera mostrado apenas se nao encontrar
}
