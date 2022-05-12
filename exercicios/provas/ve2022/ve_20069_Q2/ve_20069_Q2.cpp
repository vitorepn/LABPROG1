#include <iostream>
#include "ve_20069_Q2.h"

using namespace std;

int main(){
    Buffer b1(5);
    b1.inserir(1);
    b1.inserir(2);
    b1.inserir(3);
    b1.inserir(4);
    b1.inserir(5);
    b1.inserir(6);
    b1.remover();
    b1.inserir(7);
    b1.remover();
    b1.inserir(8);
    int c = 0;
    for(int i = 0;i<8;i++){
        c = b1.ler();
    }


}