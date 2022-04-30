#include <iostream>
#include "recursos.h"


using namespace std;

int main(){
    // Deque* deque1 = new Deque(5);
    // deque1->inserir(frente,5);
    // deque1->inserir(frente,6);
    // deque1->inserir(retaguarda,4);
    // deque1->inserir(frente,10);
    // deque1->inserir(retaguarda,9);
    // deque1->inserir(frente,0);
    // deque1->inserir(frente,4);
    // deque1->imprimir();
    // deque1->remover(frente);
    // deque1->remover(retaguarda);
    // deque1->imprimir();

    Fila* fila1 = new Fila(3);
    fila1->inserir(3);
    fila1->inserir(4);
    fila1->imprimir();
    fila1->remover();
    fila1->remover();
    fila1->imprimir();
}