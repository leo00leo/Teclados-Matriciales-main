#include "d7s.h"
int est[10][7]={
    {1,1,1,1,1,1,0},
    {1,1,1,1,1,0,0},//1
    {0,1,1,0,0,0,0},//2
    {1,1,0,1,1,0,1},//3
    {0,1,1,0,0,1,1},//4
    {1,0,1,1,0,1,1},//5
    {1,0,1,1,1,1,1},//6
    {1,1,1,0,0,0,0},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,1,0,1,1},//9
    {1,1,1,0,1,1,1},//A
    {0,0,1,1,1,1,1},//B
    {1,0,0,1,1,1,0},//C
    {0,1,1,1,1,0,1},//D
};
void d7s_init(int a, int b,int c, int d,int e, int f,int g){ //funciones
    int pines[7]={a,b,c,d,e,f,g};
    RCC->APB2ENR|= RCC_APB2ENR_IOPAEN;
    for(int i=0;i<7;i++){
        if(pines[i]<8){
            GPIOA-> CRL |=(0xF<<(pines[i]*4));
            GPIOA-> CRL |=(0x1<<(pines[i]*4));
        

        }else{
            GPIOA -> CRH &=~ (0xF<<((pines[i]%8)*4));
            GPIOA -> CRH |= (0x1<<((pines[i]%8)*4));
        }
    }
}
void d7s(int a,int b,int c,int d,int e,int f,int g, char num){
int pines[7]={a,b,c,d,e,f,g};
int numInt;
if(num=='0') numInt=0;
else if(num=='1') numInt=1;
else if(num=='2') numInt=2;
else if(num=='3') numInt=3;
else if(num=='4') numInt=4;
else if(num=='5') numInt=5;
else if(num=='6') numInt=6;
else if(num=='7') numInt=7;
else if(num=='8') numInt=8;
else if(num=='9') numInt=9;
if((numInt>=0) && (numInt <=9)){
    for(int i=0;i<7;i++){
        if(est[numInt][i]) GPIOA -> BSRR |= (1<<pines[i]);
        else GPIOA -> BSRR |= (1<<(pines[i]+16));
    }
}else{
    switch (num)
    {
    case 'a':
        for(int i=0;i<7;i++){
        if(est[11][i]) GPIOA -> BSRR |= (1<<pines[i]);
        else GPIOA -> BSRR |= (1<<(pines[i]+16));
    }
        break;
    case 'b':
        for(int i=0;i<7;i++){
        if(est[12][i]) GPIOA -> BSRR |= (1<<pines[i]);
        else GPIOA -> BSRR |= (1<<(pines[i]+16));
    }
        break;
    case 'c':
        for(int i=0;i<7;i++){
        if(est[13][i]) GPIOA -> BSRR |= (1<<pines[i]);
        else GPIOA -> BSRR |= (1<<(pines[i]+16));
    }
        break;
    case 'd':
        for(int i=0;i<7;i++){
        if(est[14][i]) GPIOA -> BSRR |= (1<<pines[i]);
        else GPIOA -> BSRR |= (1<<(pines[i]+16));
    }
        break;
    
    default:
        break;
    }
}
}