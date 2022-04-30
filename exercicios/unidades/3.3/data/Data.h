#include<iostream>

using namespace std;

class Data{
    int dia,mes,ano;
    public:
    Data(int d,int m, int a){
        reiniciar(d,m,a);
    }
    Data(){
        reiniciar(1,1,1);
    }
    void reiniciar(int d, int m, int a){
        dia = d;
        mes = m;
        ano = a;
        normalizar();
    }
    int getDia(){
        return dia;
    }
    int getMes(){
        return mes;
    }
    int getAno(){
        return ano;
    }
    bool bissexto(){
        if(ano%400==0){return true;}
        if(ano%4==0&&ano%100!=0){return true;}
        return false;
    }
    int Dias(){
        if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
            return 31;
        }
        if(mes==2){
            return (28+bissexto());
        }
        return 30;

    }
    void adiantar(int d, int m, int a){
        dia+=d;
        mes+=m;
        ano+=a;
        normalizar();
    }
    void normalizar(){
        if(!diaValido()){cout<<"ERRO: Dia invalido\n";}
        if(!mesValido()){cout<<"ERRO: Mes invalido\n";}
        if(!anoValido()){cout<<"ERRO: Ano invalido\n";}
    }
    bool diaValido(){
        if(dia<1){return 0;}
        if(dia>Dias()){return 0;}
        return 1;
    }
    bool mesValido(){
        if(mes<1||mes>12) return 0;
        return 1;
    }
    bool anoValido(){
        if(ano<1) return 0;
        return 1;
    }
    void visualizar(){
        cout<<dia<<"/"<<mes<<"/"<<ano;
    }
};