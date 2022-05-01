//não sei se funciona, estou com preguiça de testar

#include <iostream>
#include <cmath>

using namespace std;

class Retangulo{
    protected:
    float a,b,c,d;
    Retangulo(float a,float b,float c,float d):a(a),b(b),c(c),d(d){}
    public:
    Retangulo(float altura, float largura):a(altura),c(altura),b(largura),d(largura){}
    virtual float perimetro(){
        return a+b+c+d;
    }
    virtual float area(){
        return a*c;
    }
};

class Quadrado:public Retangulo{
    protected:
    Quadrado(float baseMaior,float baseMenor, float altura):
    Retangulo(
    baseMaior,
    baseMenor,
    sqrt(altura*altura+pow((baseMaior-baseMenor)/2,2)),
    sqrt(altura*altura+pow((baseMaior-baseMenor)/2,2))){

    }
    public:
    Quadrado(float n):Retangulo(n,n){}

};

class TrapezioIsosceles:public Quadrado{
    float altura;
    public:
    TrapezioIsosceles(float baseMaior, float baseMenor, float altura):Quadrado(baseMaior,baseMenor,altura){}
    float area(){
        return (a+b)*c/2;
    }
};