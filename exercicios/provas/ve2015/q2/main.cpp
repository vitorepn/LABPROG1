#include <iostream>
#include "conjunto.h"

using namespace std;
int main(){
    Conjunto c1(5);
    Conjunto c2(8);

    c1.inserir(3);
    c1.inserir(2);
    c1.inserir(5);

    c2.inserir(5);
    c2.inserir(7);


    c1.diferenca(c2).imprimir();

}