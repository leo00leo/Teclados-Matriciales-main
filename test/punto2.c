#include "punto2.h"
int est[10][7]={
    {1,1,1,1,1,1,0},//0
    {1,1,1,1,1,0,0},//1
    {0,1,1,0,0,0,0},//2
    {1,1,0,1,1,0,1},//3
    {0,1,1,0,0,1,1},//4
    {1,0,1,1,0,1,1},//5
    {1,0,1,1,1,1,1},//6
    {1,1,1,0,0,0,0},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,1,0,1,1}//9
};
char tec[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
void punto2_init(int a, int b, int c, int d, int e, int f, int g, int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3){
int pines[7]={a,b,c,d,e,f,g};
int ent[4]={f0,f1,f2,f3};
int sal[4]={c0,c1,c2,c3};
RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
    for(int i=0;i<7;i++){
        if(pines[i]<8){
            GPIOA-> CRL |=(0xF<<(pines[i]*4));
            GPIOA-> CRL |=(0x1<<(pines[i]*4));
        

        }else{
            GPIOA -> CRH &=~ (0xF<<((pines[i]%8)*4));
            GPIOA -> CRH |= (0x1<<((pines[i]%8)*4));
        }
    }
    for(int i=0;i<4;i++){
        if(ent[i]<8){
            GPIOA->CRL|=~(0xF<<ent[i]*4);
            GPIOA->CRL|=~(0x8<<ent[i]*4);
        }

        else{
            GPIOA->CRH|=(0xF<<(ent[i]%8)*4);
            GPIOA->CRH|=(0x8<<(ent[i]%8)*4);
        }
    }
    for(int i=0;i<4;i++){
        if(sal[i]<8){
            GPIOB->CRL|=(0xF<<sal[i]*4);
            GPIOB->CRL|=(0x1<<sal[i]*4);
        }
        else{
            GPIOB->CRH|=(0xF<<(sal[i]%8)*4);
            GPIOB->CRH|=(0x1<<(sal[i]%8)*4);
        }
    }
}
int punto2(int a, int b, int c, int d, int e, int f, int g,char num, int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3){
int pines[7]={a,b,c,d,e,f,g};
int sal[4]={c0,c1,c2,c3};
int ent[4]={f0,f1,f2,f3};
    switch(num){
        case'0':
        for(int i=0;i<7;i++){
            if(est[0][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'1':
        for(int i=0;i<7;i++){
            if(est[1][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'2':
        for(int i=0;i<7;i++){
            if(est[2][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'3':
        for(int i=0;i<7;i++){
            if(est[3][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'4':
        for(int i=0;i<7;i++){
            if(est[4][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'5':
        for(int i=0;i<7;i++){
            if(est[5][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'6':
        for(int i=0;i<7;i++){
            if(est[6][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'7':
        for(int i=0;i<7;i++){
            if(est[7][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'8':
        for(int i=0;i<7;i++){
            if(est[8][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
        break;
        case'9':
        for(int i=0;i<7;i++){
            if(est[9][i]){
                GPIOA->BSRR|=(1<<pines[i]);
            }
            else{
                GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
    }
}