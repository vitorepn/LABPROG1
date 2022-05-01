#include <iostream>

using namespace std;

class Fibonacci{
    int tamanhoMax;
    int* sequencia;
    public:
    Fibonacci(int n):tamanhoMax(n){
        sequencia = new int[n];
        sequencia[0]=1;
        sequencia[1]=1;
        for(int i=2;i<n;i++){
            sequencia[i] = sequencia[i-1]+sequencia[i-2];
        }
    }
    void imprimir(){
        for(int i=0;i<tamanhoMax;i++){
            cout<<sequencia[i]<<" ";
        }
    }
    int getNumero(int posicao){
        return sequencia[posicao];
    }
    int getPosicao(int numero){
        for(int i=0;i<tamanhoMax;i++){
            if(sequencia[i] == numero){
                return i;
            }
        }
    }
};