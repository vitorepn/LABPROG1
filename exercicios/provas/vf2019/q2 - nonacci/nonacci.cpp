#include<stdio.h>
#include<iostream>
#define N 5

using namespace std;


template <int T>
class Nonacci{
    int tipo;
    int posicao;
    public:
    Nonacci():posicao(0),tipo(T){}
    int getPosicao(){
        return posicao;
    }
    int setPosicao(int n){
        posicao = n;
    }
    int getTipo(){
        return tipo;
    }

    template <int U>
    friend ostream& operator<< (ostream& out, const Nonacci<U> nonacci);

    template <int U>
    friend Nonacci<U> operator<< (const Nonacci<U>& nonacci, int n);
    //friend istream& operator>> (int n,const Nonacci<T> nonacci);

};

template <int T>
ostream& operator<< (ostream& out, const Nonacci<T> nonacci){
    if(nonacci.posicao<=nonacci.tipo){
        out<<1;
        return out;
    }

    int numeros[T];
    for(int i = 0;i<T;i++){
        numeros[i] = 1;
    }

    for (int i = T; i<nonacci.posicao;i++){
        int aux = 0;
        for(int j = 0; j<T;j++){
            aux+=numeros[j];
        }
        for(int j = 0; j<T-1;j++){
            numeros[j] = numeros[j+1];    
        }
        numeros[T-1] = aux;
    }
    out<<numeros[T-1];
    return out;
}

template <int T>
Nonacci<T> operator<< (Nonacci<T>& nonacci, int n){
    nonacci.setPosicao(n);
    return nonacci;
}



int main(){
    Nonacci<N> X;
    X<<4;
    cout<<(X<<8);

}