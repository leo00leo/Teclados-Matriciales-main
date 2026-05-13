#include "stm32f103xb.h"
#include "string.h"

#define ledrojo      7
#define ledverde     8
#define ledamarillo  9
#define ledcambio    10

int correcto0;
int correcto1;
int correcto2;

char cambiocontra;

char contra[3]={'1', '1', '1'};
char caracter[3]={'x', 'x', 'x'};
char nc[3];

int main(void)
{
    tecinit(0, 1, 2, 3, 4, 5, 6, 7);

    GPIOA->CRH &= ~(0xF<<((ledrojo % 8) * 4));
    GPIOA->CRH |=(0x1<<((ledrojo % 8) * 4));

    GPIOA->CRH &= ~(0xF<<((ledverde % 8) * 4));
    GPIOA->CRH |=(0x1<<((ledverde % 8) * 4));

    GPIOA->CRH &=~(0xF<<((ledamarillo % 8) * 4));
    GPIOA->CRH |=(0x1<<((ledamarillo % 8) * 4));

    GPIOA->CRH &=~(0xF<<((ledcambio % 8) * 4));
    GPIOA->CRH |=(0x1<<((ledcambio % 8) * 4));

    delay_init();

        while (1)
         {
        for (int i = 0; i < 3; i++)
        {
            while (caracter[i] == 'x')
            {
                caracter[i] = tecar(0,1,2,3,4,5,6,7);
                delay_ms(20);
            }
        }
        if (caracter[0] == contra[0])
        {
            correcto0 = 0;
        }
        if (caracter[1] == contra[1])
        {
            correcto1 = 0;
        }
        if (caracter[2] == contra[2])
        {
            correcto2 = 0;
        }
        correcto0 = strcmp(caracter[0], contra[0]);
        correcto1 = strcmp(caracter[1], contra[1]);
        correcto2 = strcmp(caracter[2], contra[2]);

        if (correcto0 !=0||correcto1!= 0||correcto2!= 0)
        {
            GPIOA-> BSRR |= (1 << ledrojo);
            GPIOA-> BSRR |= (1 << (ledverde + 16));
        }else{
            GPIOA-> BSRR |=(1<<(ledrojo + 16));
            GPIOA-> BSRR |=(1<<ledverde);
            GPIOA-> BSRR |=(1<<ledamarillo);

            while (cambiocontra=='x')
            {
                cambiocontra = tecar(0, 1, 2, 3, 4, 5, 6, 7);
            }
            GPIOA->BSRR |= (1 << ledcambio);
            delay_ms(2000);
            if (cambiocontra == '#')
            {
            GPIOA->BSRR |= (1 << (cambiocontra + 16));
            for (int i = 0; i < 3; i++)
            {
            while (nc[i] == 'x')
            {
                nc[i] = tecar(0, 1, 2, 3, 4, 5, 6, 7);
            }
        }

        strcpy(contra, nc);
            
        }else{
            GPIOA->BSRR |= (1 << (ledcambio + 16));
            GPIOA->BSRR |= (1 << (ledamarillo + 16));
            }
        }
    }
}