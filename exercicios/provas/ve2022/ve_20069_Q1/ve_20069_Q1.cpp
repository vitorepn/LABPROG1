#include <iostream>
#include "ve_20069_Q1.h"

using namespace std;

int main(){
    RemoveFim rf;
    rf.imprimir();
    rf.inserir(3);
    rf.imprimir();
    rf.inserir(4);
    rf.inserir(5);
    rf.imprimir();
    rf.remover();
    rf.imprimir();

    RemoveInicio ri;
    ri.imprimir();
    ri.inserir(3);
    ri.imprimir();
    ri.inserir(4);
    ri.inserir(5);
    ri.imprimir();
    ri.remover();
    ri.imprimir();
    ri.remover();
    ri.remover();
    ri.remover();
    
}