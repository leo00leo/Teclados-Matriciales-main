#include "d7s.h"
#include "tecmat.h"

int main(void){
    tecmat_init(0,1,2,3,4,5,6,7);
    d7s_init(0,1,2,3,4,5,6);
    while(1){
        char tecla = tecmat(0,1,2,3,4,5,6,7);
        if(tecla!='x'){
            d7s(0,1,2,3,4,5,6,tecla);
        }
    }
    return 0;
}