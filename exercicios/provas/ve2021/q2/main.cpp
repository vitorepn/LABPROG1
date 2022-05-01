// Provávelmente um dos piores códigos que eu já fiz,
// mas nesse caso eu me dei ao luxo de desistir
// faz parte.
// Paz na terra

#include <iostream>
#include "jogo.h"

using namespace std;
int main(){
    int n;
    int estado;
    int x,y;
    cout<<"Digite o tamanho do jogo: ";
    cin>>n;
    Jogo* jogo1 = new Jogo(n);
    jogo1->imprimir();

    while(1){
        cout<<"Turno do jogador "<<jogo1->getTurno()<<endl;
        cout<<"Escolha a posicao da sua jogada: ";
        cin>>x>>y;
        estado = jogo1->jogar(x,y);
        if(estado == 0){
            cout<<"Jogada Invalida"<<endl;
            continue;
        }
        if(estado == 1){
            cout<<"Jogada Valida"<<endl;
        }
        jogo1->imprimir();
        if(jogo1->verificarVitoria()){
            cout<<"Vitoria do jogador "<<jogo1->getVencedor();
            return 1;
        }
        if(jogo1->verificarVelha()){
            cout<<"Empate";
            return 0;
        }
    }
}