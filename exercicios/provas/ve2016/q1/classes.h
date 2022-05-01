#include <iostream>

using namespace std;

class Cliente{
    public:
    string nome;
    int chegada;
    int duracao;
    Cliente(string nome, int chegada, int duracao):nome(nome),chegada(chegada),duracao(duracao){}
};

class ClienteComum:public Cliente{
    public:
    int tempoMaximo;
    ClienteComum(string nome, int chegada, int duracao, int tempoMaximo)
    :Cliente(nome,chegada,duracao),tempoMaximo(tempoMaximo){}
    ClienteComum():Cliente("null",0,0){}
};

class ClientePreferencial:public Cliente{
    public:
    ClientePreferencial(string nome, int chegada, int duracao)
    :Cliente(nome,chegada,duracao){}
    ClientePreferencial():Cliente("null",0,0){}
        
};

class stats{
    public:
    float tempoMedio;
    int desistentes;
    stats(){};
    stats(float tempoMedio,int desistentes):tempoMedio(tempoMedio),desistentes(desistentes){}
};

class Banco{
    public:
    int tamanho;
    int qtdComum;
    int qtdPreferencial;
    ClienteComum* filaComum;
    ClientePreferencial* filaPreferencial;
    Banco(int tamanho):tamanho(tamanho){
        qtdComum = 0;
        qtdPreferencial = 0;
        filaComum = new ClienteComum[10];
        filaPreferencial = new ClientePreferencial[10];
    };
    void adicionar(ClienteComum cliente){
        if(qtdComum + qtdPreferencial >= tamanho){return;}
        filaComum[qtdComum++] = cliente;
    }
    void adicionar(ClientePreferencial cliente){
        if(qtdComum + qtdPreferencial >= tamanho){return;}
        filaPreferencial[qtdPreferencial++] = cliente;
    }
    stats simular(){
        int tempo = 1;
        int desistentes = 0;
        int contador = 0;
        float tMedio=0;
        for(int i = 0;i<qtdComum;i++){
            while(i<qtdComum){
                if(tempo > (this->filaComum[i].chegada+this->filaComum[i].tempoMaximo)){
                cout<<"O cliente "<<this->filaComum[i].nome<< " desistiu"<<endl;
                i++;
                desistentes++;
                }else{break;}
            }
            if(i>=qtdComum){break;}
            cout<<"No tempo "<<tempo<<" "<<this->filaComum[i].nome<<" foi atendido"<<endl;
            for(int j = 0;j<this->filaComum[i].duracao;j++){
                tempo++;
            }
            tMedio += this->filaComum[i].duracao;
            cout<<"No tempo: "<<tempo<<" "<<this->filaComum[i].nome<<" terminou o atendimento"<<endl;
        }

        for(int i = 0; i<qtdPreferencial;i++){
            tMedio += this->filaPreferencial[i].duracao;
        }
        return stats((tMedio)/(qtdComum+qtdPreferencial-desistentes),desistentes);
    }
};