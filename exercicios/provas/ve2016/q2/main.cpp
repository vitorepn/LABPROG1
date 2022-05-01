// Fiquei com preguiça de implementar a partida

#include<iostream>
#include "classes.h"

using namespace std;

int main(){
    Goleiro go1("Ron Weasley",5,3,4,10,20);
    Apanhador ap1("Harry",3,2,6,10);
    Batedor ba1("Jimmy",3,6,4,8),
            ba2("Ritchie",3,6,3,7);
    Artilheiro ar1("Demelza",5,7,3,8),
            ar2("Ginny",10,7,3,2),
            ar3("Katie",2,7,4,4);
    
    QuadribolTime q1("Grifinoria"), q2("Sonserina");

    q1.adicionarJogador(go1);
    q1.adicionarJogador(ap1);
    q1.adicionarJogador(ba1);
    q1.adicionarJogador(ba2);
    q1.adicionarJogador(ar1);
    q1.adicionarJogador(ar2);
    q1.adicionarJogador(ar3);

    cout<<q1.pegarHabilidadeTotal();
}