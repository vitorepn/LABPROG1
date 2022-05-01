#include<iostream>

using namespace std;

class Numero{
    public:
    int chave;
    Numero* prox;
    Numero(int chave):chave(chave){
        prox = nullptr;
    }

};

class Conjunto{
    int valorMax;
    int qtd;
    Numero* inicio;
    public:
    int getMax(){
        return valorMax;
    }
    Numero* getInicio(){
        return inicio;
    }
    Conjunto(int valorMax):valorMax(valorMax){
        inicio = nullptr;
        qtd = 0;
    }
    Conjunto(){
        inicio = nullptr;
        qtd = 0;
    }
    bool buscar(int n){
        
        Numero* aux = inicio;
        while(aux!=nullptr){
            if(aux->chave==n){
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
    void imprimir(){
        Numero* aux = inicio;
        while(aux!=nullptr){
            cout<<"Chave: "<<aux->chave<<endl;
            aux = aux->prox;
        }
    }
    bool inserir(int n){
        if(n > valorMax){
            cout<<"Valor invalido"<<endl;
            return 0;
        }
        if(buscar(n)){
            cout<<"Valor ja existente"<<endl;
            return 0;
        }
        Numero* aux = inicio;

        if(qtd == 0){
            inicio = new Numero(n);
            cout<<"Adicao feita com sucesso"<<endl;
            qtd++;
            return 1;
        }

        while(aux->prox!=nullptr){
            aux = aux->prox; 
        }
        
        aux->prox = new Numero(n);
        cout<<"Adicao feita com sucesso"<<endl;
        qtd++;
        return 1;
    }
    Conjunto uniao(Conjunto &c1){
        int max;
        if(valorMax>c1.getMax()){
            max = valorMax;
        }else{
            max = c1.getMax();
        }
        Conjunto cRes(max);
        Numero* aux = inicio;
        while(aux!=nullptr){
            cRes.inserir(aux->chave);
            aux = aux->prox;
        }
        aux = c1.getInicio();
        while(aux!=nullptr){
            if(!cRes.buscar(aux->chave)){
                cRes.inserir(aux->chave);
            };
            aux = aux->prox;
        }
        return cRes;
    }

    Conjunto intersecao(Conjunto &c1){
        int max;
        Numero* aux = inicio;
        if(valorMax>c1.getMax()){
            max = valorMax;
        }else{
            max = c1.getMax();
        }
        Conjunto cRes(max);

        while(aux!=nullptr){
            if(c1.buscar(aux->chave)){
                cRes.inserir(aux->chave);
            };
            aux = aux->prox;
        }
        return cRes;
    }

    Conjunto diferenca(Conjunto &c1){
        int max;
        Numero* aux = inicio;
        if(valorMax>c1.getMax()){
            max = valorMax;
        }else{
            max = c1.getMax();
        }
        Conjunto cRes(max);

        while(aux!=nullptr){
            if(!c1.buscar(aux->chave)){
                cRes.inserir(aux->chave);
            };
            aux = aux->prox;
        }

        return cRes;
    }
};