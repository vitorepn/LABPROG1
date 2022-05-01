#include <iostream>

using namespace std;

class Jogador{
    protected:
    int forca,velocidade,estilo,habilidade;
    string nome;
    public:
    Jogador(string nome, int forca, int velocidade, int estilo)
        :forca(forca),
        velocidade(velocidade),
        estilo(estilo){};
    Jogador(){};
    int getHabilidade(){
        return habilidade;
    }
    int getForca(){
        return forca;
    }
    Jogador(Jogador* jogador){
        forca = jogador->forca;
        velocidade = jogador->velocidade;
        estilo = jogador->estilo;
        habilidade = jogador->habilidade;
    }
};

class Artilheiro:public Jogador{
    int truque;
    public:
    Artilheiro(string nome, int forca, int velocidade, int estilo, int truque)
        :Jogador(nome,forca,velocidade,estilo),truque(truque){
        habilidade = 1*forca + 3*velocidade + 2*estilo + 20*truque;
        };
};

class Batedor:public Jogador{
    int balaco;
    public:
    Batedor(string nome, int forca, int velocidade, int estilo, int balaco)
        :Jogador(nome,forca,velocidade,estilo),balaco(balaco){
        habilidade = 3*forca + 1*velocidade + 1*estilo;
        if(balaco>100){
            cout<<"entrei aqui";
            int n = (int)balaco/100;
            habilidade = habilidade*(2^n);
        }
        };

};

class Apanhador:public Jogador{
    int pomo;
    public:
    Apanhador(string nome, int forca, int velocidade, int estilo, int pomo)
        :Jogador(nome,forca,velocidade,estilo),pomo(pomo){
        habilidade = 1*forca + 2*velocidade + 3*estilo + 10*pomo;
        };
};

class Goleiro:public Jogador{
    int camisaLimpa, jogos;
    public:
    Goleiro(string nome, int forca, int velocidade, int estilo, int camisaLimpa, int jogos)
        :Jogador(nome,forca,velocidade,estilo),camisaLimpa(camisaLimpa),jogos(jogos){
        habilidade = 1*forca + 2*velocidade + 3*estilo -(jogos-camisaLimpa);
        };
};

class QuadribolTime{
    int qtd;
    string nome;
    Jogador* jogadores;
    public:
    QuadribolTime(string nome):qtd(0),nome(nome){
        jogadores = new Jogador[7];
    }
    void adicionarJogador(Jogador jogador){
        jogadores[qtd] = jogador;
        cout<<jogadores[qtd].getHabilidade()<<endl;
        qtd++;
    }
    void alterarJogador(int n, Jogador jogador){
        if(n > 6){
            cout<<"Entrada invalida";
            return;
        }
        jogadores[n] = jogador;
    }
    int pegarHabilidadeTotal(){
        int total = 0;
        if(qtd<7){
            return -1;
        }
        for(int i = 0; i<7;i++){
            total += (jogadores[i]).getHabilidade();
        }
        return total;
    }
};