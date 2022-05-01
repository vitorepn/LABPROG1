#include <iostream>

using namespace std;

class Empregado{
    protected:
    string nome;
    int cracha;
    float salarioBase;
    float salarioLiquido;
    public:
    Empregado(string nome, int cracha, float salarioBase)
        :nome(nome),cracha(cracha),salarioBase(salarioBase){};
    string getNome(){return nome;}
    int getCracha(){return cracha;}
    float getSalarioBase(){return salarioBase;}
    float getSalarioLiquido(){return salarioLiquido;}
};

class Mensalista:public Empregado{
    public:
    Mensalista(string nome, int cracha, float salarioBase, float percentual)
        :Empregado(nome,cracha,salarioBase){
            salarioLiquido = salarioBase - percentual*salarioBase;
        }
};

class Horista:public Empregado{
    public:
    Horista(string nome, int cracha, float salarioBase, int horas)
        :Empregado(nome,cracha,salarioBase){
            salarioLiquido = salarioBase*horas;
        }
};

class Comissionado:public Empregado{
    public:
    Comissionado(string nome, int cracha, float salarioBase, int vendas)
        :Empregado(nome,cracha,salarioBase){
            salarioLiquido = salarioBase*vendas;
        }
};