#include<iostream>

using namespace std;

enum modo{
    frente = 0,
    atras
};

class No{
    int chave;
    No* prox;
    public:
    No(){prox = nullptr;};
    No(int n){
        chave = n;
        prox = nullptr;
    }
    No(No* no){
        chave = no->getChave();
        prox = no->getProx();
    }
    No* getProx(){return prox;}
    void setProx(No* no){prox = no;}
    int getChave(){return chave;}
    ~No(){cout<<"No: "<<chave<<" destruido"<<endl;}
};

class EstruturaBase{
    protected:
    int qtd;
    No* inicio;
    EstruturaBase():qtd(0),inicio(nullptr){};
    void remover(modo modo){
        if(qtd==0){
            cout<<"Lista vazia"<<endl;
            return;
        }
        if(modo == frente){
            No *aux = inicio;
            inicio = inicio->getProx();
            delete aux;
            qtd--;
        }
        if(modo==atras){
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
            No *aux2 = inicio->getProx();
            while(aux2->getProx()!=nullptr){
                aux = aux->getProx();
                aux2 = aux2->getProx();
            }
            delete aux2;
            aux->setProx(nullptr);
            qtd--;
        }
    }
    public:
    
    void imprimir(){
        if(qtd==0){
            cout<<"Lista vazia"<<endl;
            return;
        }
        cout<<"Iniciando impressao"<<endl;
        No* aux = inicio;
        while(aux!=nullptr){
            cout<<"chave:"<<aux->getChave()<<endl;
            aux = aux->getProx();
        }
    }

    void inserir(int n){
        if(qtd==0){
            inicio = new No(n);
            qtd++;
            return;
        }
        No* no = new No(n);
            No* aux = inicio;
            while(aux->getProx()!=nullptr){
                aux = aux->getProx();
            }
            aux->setProx(no);
            qtd++;
    }
    
};

class RemoveInicio:public EstruturaBase{
    public:
    RemoveInicio():EstruturaBase(){};
    void remover(){
        EstruturaBase::remover(frente);        
    }
};

class RemoveFim:public EstruturaBase{
    public:
    RemoveFim():EstruturaBase(){};
    void remover(){
        EstruturaBase::remover(atras);
    }
};



