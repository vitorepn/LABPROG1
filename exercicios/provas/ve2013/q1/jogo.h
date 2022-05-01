//Copiei bastante coisa da VE-2021-Q2

#include<iostream>

using namespace std;

enum situacao{
    Invalida,
    Valida,
    Empate,
    Vitoria,
};

enum jogador{
    O = 0,
    X = 1,
};

class Jogo{
    char** tabuleiro;
    int tamanho;
    int turno;
    int jogoEncerrado;
    public:
    Jogo(char inicial){
        tamanho = 3;
        turno = 0;
        if(inicial == X){turno = 1;}
        jogoEncerrado = 0;
        tabuleiro = new char*[tamanho];
        for(int i=0;i<tamanho;i++){
            tabuleiro[i] = new char[tamanho];
        }
        resetar();
    }
    void resetar(){
        for(int i = 0;i<tamanho;i++){
            for(int j = 0;j<tamanho;j++){
                tabuleiro[i][j] = ' ';
            }
        }
    }
    char getTurno(){
        if (turno%2 == 0){
            return 'O';
        }
        if (turno%2 == 1){
            return 'X';
        }
    }
    void imprimir(){
        for(int i = 0;i<tamanho;i++){
            for(int j = 0;j<tamanho;j++){
                cout<<tabuleiro[i][j];
                if(j!=tamanho-1) cout<<'|';
            }
            cout<<endl;
            for(int k = 0;k<2*tamanho-1;k++){
                cout<<"-";
            }
            cout<<endl;
        }
    }
    situacao jogar(int x,int y){
        if(tabuleiro[x-1][y-1]!=' '){return Invalida;}
        if(x<1||x>tamanho+1||y<1||y>tamanho+1){return Invalida;}
        if(turno%2==0){
            tabuleiro[x-1][y-1]='O';
            turno++;
            if(verificarVitoria()){return Vitoria;}
            return Valida;
        }
        if(turno%2==1){
            tabuleiro[x-1][y-1]='X';
            turno++;
            if(verificarVitoria()){return Vitoria;}
            return Valida;
        }

    }
    bool verificarVitoria(){
        int flag = 0;
        if(turno == 0){
            return 0;
        }
        for(int i = 0;i<tamanho-1;i++){
            if(tabuleiro[i][i]==tabuleiro[i+1][i+1]&&tabuleiro[i][i]!=' '){flag++;}
        }
        if(flag == tamanho-1){return 1;}
        flag = 0;

        for (int i = 0;i<tamanho-1;i++){
            if(tabuleiro[i][tamanho-i]==tabuleiro[i+1][tamanho-i-1]&&tabuleiro[i][tamanho-i]!=' '){flag++;}
        }
        if(flag == tamanho-1){return 1;}
        flag = 0;
        for(int i = 0;i<tamanho;i++){
            for(int j = 0; j<tamanho-1;j++){
                if(tabuleiro[i][j]==tabuleiro[i][j+1]&&tabuleiro[i][j]!=' '){flag++;}
            }
            if(flag == tamanho-1){return 1;}
            flag = 0;
        }
        for(int i = 0;i<tamanho;i++){
            for(int j = 0; j<tamanho-1;j++){
                if(tabuleiro[j][i]==tabuleiro[j][i+1]&&tabuleiro[j][i]!=' '){flag++;}
            }
            if(flag == tamanho-1){return 1;}
            flag = 0;
        }
        return 0;
    }
    char getVencedor(){
        int t = turno-1;
        if(t%2 == 0){return 'X';
        }
        if(t%2 == 1){return 'O';}
    }
    bool verificarVelha(){
        for(int i = 0; i<tamanho; i++){
            for(int j = 0; j<tamanho; j++){
                if(tabuleiro[i][j]==' ') return 0;
            }
        }
        return 1;
    }
};