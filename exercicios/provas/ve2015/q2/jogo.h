#include<iostream>

using namespace std;

enum situacao{
    Invalida,
    Valida,
    Empate,
    VitoriaO,
    VitoriaX,
};

class Jogo{
    char** tabuleiro;
    int tamanho;
    int turno;
    int jogoEncerrado;
    public:
    Jogo(){
        tamanho = 8;
        turno = 0;
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
                tabuleiro[i][j] = '_';
            }
        }
        for(int i = 0;i<4;i++){
            tabuleiro[0][2*i+1]='b';
            tabuleiro[1][2*i]='b';
            tabuleiro[2][2*i+1]='b';
            tabuleiro[5][2*i]='p';
            tabuleiro[6][2*i+1]='p';
            tabuleiro[7][2*i]='p';
        }
    }
    char getTurno(){
        if (turno%2 == 0){
            return 'B';
        }
        if (turno%2 == 1){
            return 'P';
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
    situacao jogar(int x,int y,char diagonal){
        if(tabuleiro[x-1][y-1]!=' '){return Invalida;}
        if(x<1||x>tamanho+1||y<1||y>tamanho+1){return Invalida;}
        if(turno%2==0){
            tabuleiro[x-1][y-1]='b';
            turno++;
            return Valida;
        }
        if(turno%2==1){
            tabuleiro[x-1][y-1]='p';
            turno++;
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