#include<iostream>

using namespace std;

class Empregado{
    string nome;
    int salario;
    int ramal;
    static int contador;
    public:
    Empregado(string nome,int salario,int ramal)
        :nome(nome),
        salario(salario),
        ramal(ramal)
        {
            contador++;
            verificar();
    }
    string getNome(){return nome;}
    int getSalario(){return salario;}
    void setSalario(int s){salario = s;}
    int getRamal(){return ramal;}
    void setRamal(int r){ramal = r;}
    static int getContador(){return contador;}
    void verificar(){
        if(Empregado::getContador()>50){
            cout<<"Acima do maximo por "<<50-Empregado::getContador()<<endl;
        }else if(Empregado::getContador()<10){
            cout<<"Abaixo do minimo por "<<10-Empregado::getContador()<<endl;
        }
    }
};

int Empregado::contador = 0;

int main(){
    Empregado e1("b",1,1);
    Empregado e2("a",2,2);
}