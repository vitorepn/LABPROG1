
#include <iostream>
using namespace std;


template <class T>
class Conjunto{
    T* vetor;
    int tamanho, qtd;
    public:
    Conjunto(int tamanho):tamanho(tamanho),qtd(0){
        vetor = new T[tamanho];
    };

    Conjunto& operator += (T novoElemento){
        if(qtd==tamanho){
            return *this;
        }
        for(int i = 0;i<qtd;i++){
            if(vetor[i] == novoElemento){
                return *this;
            }
        }
        vetor[qtd++] = novoElemento;
    }
    T operator [](int n){
        if(n>=qtd){
            throw "Acesso inválido";
        }
        return vetor[n];
    }

    Conjunto& operator += (Conjunto& conjunto){
        for(int i = 0;i<conjunto.tamanho;i++){
            *this += conjunto[i];
        }
    }
};


int main(){
    Conjunto<int> c1(5);
    Conjunto<int> c2(5);
    c1 +=1;
    c2 +=2;
    c1 += c2;
    cout<<c1[0];
}