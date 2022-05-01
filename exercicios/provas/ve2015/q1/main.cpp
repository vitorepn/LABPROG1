//O funcionamento da busca binária tá meio estranho

#include <iostream>
#include "metodosBusca.h"
#include<ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 100,k,m=50;
    int v[100];
    //BuscaAleatoria mb1(n);
    BuscaLinear mb2(n);
    BuscaBinaria mb3(n);

    for(int i = 0;i<n;i++){
        k = rand()%m;
        v[i] = k;
    }
    k = rand()%m;

    cout<<"BuscaLinear:"<<(buscar(mb2,v,n,k)?"Sim":"Nao")<<endl;
    cout<<"BuscaBinaria:"<<(buscar(mb3,v,n,k)?"Sim":"Nao")<<endl;

}