#include "tecmat.h"
char tec[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
void tecmat_init(int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3){
int ent[4]={f0,f1,f2,f3};
int sal[4]={c0,c1,c2,c3};

RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
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
char tecmat(int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3){
int sal[4]={c0,c1,c2,c3};
int ent[4]={f0,f1,f2,f3};
for(int i=0;i<4;i++){
    GPIOB->BSRR|=(1<<sal[i]);
    for(i=0;i<4;i++){
        GPIOB->BSRR|=(1<<(sal[i]+16));
    }
    for(int j=0;j<4;j++){
        if(GPIOA->IDR&(1<<ent[j])==0){
            return tec[i][j];
        }
    }
    GPIOB->BSRR|=(1<<sal[i]);
}
return 'x';
}