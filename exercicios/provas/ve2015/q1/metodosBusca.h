#include<iostream>

using namespace std;
class MetodoBusca{
    protected:
    int* lista;
    int tamanho;
    int qtd;
    public:
    MetodoBusca(int max):tamanho(max),qtd(0){
        lista = new int[max];
    };
    MetodoBusca();
    bool inserir(int e){
        lista[qtd++] = e;
    };
    bool remover(int i){
        for(int j = 0; j<qtd;j++){
            if(lista[j]==i){
                for(j;j<qtd-1;j++){
                    lista[j] = lista[j+1];
                }
                qtd--;
            }
        }
    };
    virtual bool busca(int e){
    };
};

class BuscaLinear:public MetodoBusca{
    public:
    BuscaLinear(int n):MetodoBusca(n){
    };
    bool busca(int e){
        for(int i = 0; i<qtd; i++){
            if(lista[i] == e){
                return 1;                
            }
        }
        return 0;
    };
};

class BuscaBinaria:public MetodoBusca{
    public:
    BuscaBinaria(int n):MetodoBusca(n){};
    bool busca(int e){
        if(e==lista[qtd/2]){
            return 1;
        }
        if(qtd==1){
        return 0;
        }
        if(e<lista[qtd/2]){
            BuscaBinaria mb(qtd/2);
            for(int i = 0;i<qtd/2;i++){
                mb.inserir(lista[i]);
            }
            return mb.busca(e);
        }
        if(e>lista[qtd/2]){
            BuscaBinaria mb(qtd/2);
            for(int i = qtd/2;i<qtd;i++){
                mb.inserir(lista[i]);
            }
            return mb.busca(e);
        }

    };    
};

bool buscar(MetodoBusca &mb, int*vet, int n, int k){
    for(int i = 0;i<n;i++){
        mb.inserir(vet[i]);
    }
    return mb.busca(k);
};