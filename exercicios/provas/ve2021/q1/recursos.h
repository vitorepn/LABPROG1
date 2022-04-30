#include<iostream>

using namespace std;

enum modoDeque{
    frente = 0,
    retaguarda
};

class No{
    public:
    int chave;
    No* prox;
    No(){
        prox = nullptr;
    };
    No(int n){
        chave = n;
        prox = nullptr;
    }
    ~No(){
        cout<<"destrutor "<<chave<<endl;
    }
};

class Deque{
    protected:
    int qtd;
    int max;
    No* inicio;
    public:
    Deque(int n){
        max = n;
        qtd = 0;
        inicio = nullptr;
    };
    void imprimir(){
        if(qtd==0){
            cout<<"Lista vazia";
            return;
        }
        No* aux = inicio;
        while(aux!=nullptr){
            cout<<"chave:"<<aux->chave<<endl;
            aux = aux->prox;
        }
    }
    int getQtd(){
        return qtd;
    }
    void inserir(modoDeque modo,int n){
        if(qtd==max){
            cout<<"Limite atingido"<<endl;
            return;
        }
        if(modo == frente){
            No* no = new No(n);
            no->prox = inicio;
            inicio = no;
            qtd++;
        }
        if(modo == retaguarda){
            No* no = new No(n);
            No* aux = inicio;
            while(aux->prox!=NULL){
                aux = aux->prox;
            }
            aux->prox = no;
            qtd++;
        }
    }
    void remover(modoDeque modo){
        if(modo == frente){
            No *aux = inicio;
            inicio = inicio->prox;
            delete aux;
            qtd--;
        }
        if(modo==retaguarda){
            if(qtd==0){
                cout<<"Lista vazia";
                return;
            }
            if(qtd==1){
                No *aux = inicio;
                inicio = nullptr;
                delete aux;
                return;
            }
            No *aux = inicio;
            No *aux2 = inicio->prox;
            while(aux2->prox!=NULL){
                aux = aux->prox;
                aux2 = aux2->prox;
            }
            delete aux2;
            aux->prox = NULL;
            qtd--;
        }
    }
};

class Fila:public Deque{
    void inserir(modoDeque modo,int n){}
    void remover(modoDeque modo){}
    public:
    Fila(int n):Deque(n){};
    void inserir(int n){
        if(qtd==max){
            cout<<"Limite atingido";
            return;
        }
        No* no = new No(n);
            no->prox = inicio;
            inicio = no;
            qtd++;
    }
    void remover(){
        if(qtd==0){
                cout<<"Lista vazia";
                return;
            }
        if(qtd==1){
            No *aux = inicio;
            inicio = nullptr;
            delete aux;
            qtd--;
            return;
        }
        No *aux = inicio;
            No *aux2 = inicio->prox;
            while(aux2->prox!=NULL){
                aux = aux->prox;
                aux2 = aux2->prox;
            }
            delete aux2;
            aux->prox = NULL;
            qtd--;
    }
};

