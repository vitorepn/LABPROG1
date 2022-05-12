#include <iostream>
#include <string>

using namespace std;

enum tipoJogador {
    artilheiro,
    batedor,
    apanhador,
    goleiro,
    outro
};

class Jogador {
    private:
        string nome;
        int forca;
        int velocidade;
        int estilo;
        int bonus;
        int pontos;
        tipoJogador tipo;
        
    public:
        Jogador(string nome, int forca, int velocidade, int estilo, tipoJogador tipo=outro):
            nome(nome), forca(forca), velocidade(velocidade), estilo(estilo), tipo(tipo) {};
        Jogador() : nome(" "), forca(0), velocidade(0), estilo(0), tipo(outro) {
            bonus=0;
            pontos=0;
        };
    string getNome(){ return nome;};
    int setBonus(int valor) {
        bonus=valor;
        return bonus;
    }
    void setPontos(int valor){
        pontos=valor;
    }
    int getBonus(){ return bonus;};
    int getPontos() { return pontos;};
    tipoJogador getTipo(){ return tipo;};

};

class Artilheiro: public Jogador {
    private:
        int jogosBons;
    public: 
        Artilheiro(string nome, int forca, int velocidade, int estilo, int jogosBons, tipoJogador tipo=outro) :
            Jogador(nome, forca, velocidade, estilo, artilheiro), jogosBons(jogosBons){
                int bonus = setBonus(20*jogosBons);
                setPontos(1*forca + 3*velocidade + 2*estilo + bonus);
            };
};

class Batedor: public Jogador {
    private:
        int balacos;
    public:
        Batedor(string nome, int forca, int velocidade, int estilo, int balacos, tipoJogador tipo=outro) :
            Jogador(nome, forca, velocidade, estilo, batedor), balacos(balacos){
                int bonus = setBonus((balacos%100)*2);
                setPontos(3*forca + 1*velocidade + 1*estilo + bonus);
            };
};

class Apanhador: public Jogador {
    private:
        int pomoOuro;
    public:
        Apanhador(string nome, int forca, int velocidade, int estilo, int pomoOuro, tipoJogador tipo=outro) :
            Jogador(nome, forca, velocidade, estilo, apanhador), pomoOuro(pomoOuro){
                int bonus = setBonus(10*pomoOuro);
                setPontos(1*forca + 2*velocidade + 3*estilo + bonus);
            };
};

class Goleiro: public Jogador {
    private:
        int camisaLimpa;
        int qtdJogos;
    public:
        Goleiro(string nome, int forca, int velocidade, int estilo, int camisaLimpa, int qtdJogos, tipoJogador tipo=outro) :
            Jogador(nome, forca, velocidade, estilo, goleiro), camisaLimpa(camisaLimpa), qtdJogos(qtdJogos) {
                int bonus = setBonus((-1)*(qtdJogos-camisaLimpa));
                setPontos(2*forca + 3*estilo + bonus);
            };
};

class QuadribolTime {
    private: 
        string nomeTime;
        int tamanho;
        Jogador *jogadores;
    public:
        QuadribolTime(string nomeTime, int tamanho=0):
            nomeTime(nomeTime), tamanho(0), jogadores(new Jogador[7]){};
        ~QuadribolTime(){
            delete [] jogadores;
        }
        string getNomeTime(){ return nomeTime;};
        void adicionarJogador(Jogador player){
            if(tamanho==7){
                cout <<"Time ja esta completo!" << endl;
            }
            else{
                jogadores[tamanho]=player;
                cout<< "DA ARRAY: " << jogadores[tamanho].getTipo() << endl;
                tamanho++;
                cout << "Jogador: " << player.getNome() << " adicionado no Time:  "<< nomeTime << endl;
              
            }
        }
        // tipoJogador getTipo(int i){ return jogadores[i].getTipo();};
        void alterarJogador(int indice, Jogador player){
            if(indice>=7){
                cout <<"Nao existe jogador com esse indice!" << endl;
            }
            else{
                tipoJogador tipo = player.getTipo();
                int contArt=0;
                int contBat=0;
                int contAp=0;
                int contGol=0;
                for(int i=0; i<tamanho; i++){
                    cout<< "indice: " << i << endl;
                    // cout<< "array funciona???" << jogadores[i].getNome() <<  endl;
                    cout<<"estou vendo: " <<  jogadores[i].getTipo() << endl;
                    if(jogadores[i].getTipo()==artilheiro){ contArt++; };
                    if(jogadores[i].getTipo()==batedor){ contBat++; };
                    if(jogadores[i].getTipo()==apanhador){ contAp++; };
                    if(jogadores[i].getTipo()==goleiro){ contGol++; };
                }
                if(contArt<3 && tipo==artilheiro){
                    jogadores[indice]=player;
                    cout << "Jogador: " << player.getNome() << " adicionado no Time:  "<< nomeTime << " por alteracao" << endl;
                }
                else if(contBat<2 && tipo==batedor){
                    jogadores[indice]=player;
                    cout << "Jogador: " << player.getNome() << " adicionado no Time:  "<< nomeTime << " por alteracao" << endl;
                }
                else if(contAp<1 && tipo == apanhador){
                    jogadores[indice]=player;
                    cout << "Jogador: " << player.getNome() << " adicionado no Time:  "<< nomeTime << " por alteracao" << endl;
                }  
                else if(contGol<1 && tipo == goleiro){
                    jogadores[indice]=player;
                    cout << "Jogador: " << player.getNome() << " adicionado no Time:  "<< nomeTime << " por alteracao" << endl;
                }
                else{
                    cout<< "Nao eh possivel realizar a troca!" << endl;
                }
            }
        }
        int pegarHabilidadeTotal(){
            int contArt=0;
            int contBat=0;
            int contAp=0;
            int contGol=0;
            for(int i=0; i<tamanho; i++){
                cout<<"ta certo vagabundo ?? " << jogadores[i].getTipo() << endl;
                if(jogadores[i].getTipo()==artilheiro){ contArt++; };
                if(jogadores[i].getTipo()==batedor){ contBat++; };
                if(jogadores[i].getTipo()==apanhador){ contAp++; };
                if(jogadores[i].getTipo()==goleiro){ contGol++; };
            }
            if(contArt==3 && contBat==2 && contAp==1 && contGol==1){
                int habilidadeTotal=0;
                for(int i=0; i<tamanho; i++){
                    habilidadeTotal+= jogadores[i].getPontos();
                }
                return habilidadeTotal;
            }
            else{
                cout << "Time invalido!!" << endl;
                return -1;
            }
            
        }
};

class Partida{
    private:
        bool valido;
    public:
        Partida(bool valido, string vencedor):valido(valido){};
        Partida(){};
        bool realizar(QuadribolTime &t1, QuadribolTime &t2, string &res){
            int pontosT1=t1.pegarHabilidadeTotal();
            int pontosT2=t2.pegarHabilidadeTotal();
            if(pontosT1 < 0 || pontosT2<0){
                return false;
            }
            if(pontosT1 > pontosT2){
                res = t1.getNomeTime();
                return true;
            }
            else if(pontosT1 < pontosT2){
                res = t2.getNomeTime();
                 return true;
            }
            else if(pontosT1==pontosT2){
                res = "Empate";
                 return true;
            }
            return false;
        }
        bool getValido(){return valido;};        
};


int main(){
    Goleiro go1("Ron Weasley", 5, 3, 4, 10, 20);
    Apanhador ap1("Harry Potter", 3, 2, 6, 10);
    Batedor ba1("Jimmy Peakes", 3, 6, 4, 8), ba2("Ritchi Coote", 3, 6, 3, 7);
    Artilheiro ar1("Demelza Robins", 5, 7, 3, 8), ar2("Ginny Weasley", 10, 7, 3, 2), 
    ar3("Katie Bell", 2, 7,4,4);

    Goleiro go2("Miles Bletchley", 5,3,4,10,50);
    Apanhador ap2("Draco Malfoy", 5, 1, 5, 20);
    Batedor ba4("Vincent Crabbe", 3, 6, 4, 8), ba5("Gregory Goyle", 3, 6, 3, 7);
    Artilheiro ar4("Graham Montague", 5, 7, 3,8), ar5("Adrian Pucey", 10, 7, 3, 2), ar6("Cassius Warrington", 2, 7, 4, 0);

    QuadribolTime q1("Grifinoria"), q2("Sonserina");

    q1.adicionarJogador(go1);
    q1.adicionarJogador(ap1);
    q1.adicionarJogador(ba1);
    q1.adicionarJogador(ap2);
    q1.adicionarJogador(ar1);
    q1.adicionarJogador(ar2);
    q1.adicionarJogador(ar3);

    q2.adicionarJogador(go2);
    q2.adicionarJogador(ap2);
    q2.adicionarJogador(ba4);
    q2.adicionarJogador(ba5);
    q2.adicionarJogador(ar4);
    q2.adicionarJogador(ar5);
    q2.adicionarJogador(ar6);

    Partida p;
    string res;
    bool b;

    b=p.realizar(q1,q2, res);
  
    if(b){
        cout<< q1.getNomeTime() << " X " << q2.getNomeTime() << " -> " << res << endl;
    }
    else{
        cout << "Jogo invalido" << endl;
    }

    q1.alterarJogador(3,ba2);
   

    b=p.realizar(q1,q2, res);
  
    if(b){
        cout<< q1.getNomeTime() << " X " << q2.getNomeTime() << " -> " << res << endl;
    }
    else{
        cout << "Jogo invalido" << endl;
    }

    return 0;
}