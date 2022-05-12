#include <iostream>

using namespace std;


class No{
    int chave;
    bool estado;
    public:
    No():estado(0){};
    int getChave(){return chave;}
    int setChave(int n){chave = n;}
    int getEstado(){return estado;}
    int setEstado(int n){estado = n;}
};

class Buffer{
    int tamanho;
    int leitura;
    int sentinelaInserir;
    int sentinelaRemover;
    No *Lista;
    public:
    Buffer (int tamanho):tamanho(tamanho),leitura(0),sentinelaRemover(0),sentinelaInserir(0){
        Lista = new No[tamanho];
    }
    void inserir(int n){
        if(cheio()){
            cout<<"Buffer cheio"<<endl;
            return;
        }
        Lista[sentinelaInserir].setChave(n);
        Lista[sentinelaInserir].setEstado(1);
        sentinelaInserir++;
        if(sentinelaInserir == tamanho){
            sentinelaInserir = 0;
        }
    }

    void remover(){
        Lista[sentinelaRemover].setEstado(0);
        sentinelaRemover++;
        if(sentinelaRemover == tamanho){
            sentinelaRemover = 0;
        }
    }

    bool cheio(){
        for(int i = 0;i<tamanho;i++){
            if(!Lista[i].getEstado()){
                return 0;
            }
        }
        return 1;
    }
    int ler(){
        while(!Lista[leitura].getEstado()){
            leitura++;
            if(leitura==tamanho){
                leitura = 0;
            }
        }
        int chave = Lista[leitura].getChave();
        cout<<"Posicao: "<<leitura<<"- Chave: "<<chave<<endl;
        leitura++;
        if(leitura==tamanho){leitura = 0;}
        return chave;
    }


};