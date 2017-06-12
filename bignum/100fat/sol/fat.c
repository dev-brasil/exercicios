#include <stdio.h>

// Tamanho maximo do vetor
#define MAX           300
// BLOCO define o numero de digitos de cada int
#define BLOCO         10000
#define BLOCO_PRINT   "%04d"

// O numero de grande porte (aqui notado big_num)
// e' representado por um vetor de inteiros, cada
// um armazenando 4 digitos. Esquematicamente, temos
// big_num[MAX] | ... | big_num[0]

// Multiplica o big num por um inteiro normal
void big_product(int big_num[], int normal_int)
{
    int i;
    int excesso = 0;

    for(i = 0; i < MAX; ++i)
    {
        big_num[i] *= normal_int;
        big_num[i] += excesso;
        excesso     = (big_num[i] >= BLOCO) ? big_num[i]/BLOCO : 0;
        big_num[i]  = big_num[i] % BLOCO;
    }
}

// Escreve o big_num no terminal
void big_print(int big_num[])
{
    int i = MAX - 1;

    while(i >= 0)
    {
        if(big_num[i] == 0) i--;
        else break;
    }

    if(i < 0) printf("0");

    else
    {
        printf("%d", big_num[i]);

        i--;

        while(i >= 0)
        {
            printf(BLOCO_PRINT, big_num[i]);
            i--;
        }
    }

    printf("\n");
}

int main()
{
    int big_num[MAX];

    int i;

    // Inicializando os blocos
    big_num[0] = 1;

    for(i = 1; i < MAX; ++i)
    {
        big_num[i] = 0;
    }

    // Calculo de 100!
    for(i = 2; i <= 100; ++i)
    {
        big_product(big_num, i);
    }

    big_print(big_num);

    return 0;
}
