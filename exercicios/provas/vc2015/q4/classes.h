#include <iostream>
#include <cmath>
using namespace std;

class Ponto{
    int x,y;
    public:
    Ponto(int x, int y):x(x),y(y){};
    int getX(){return x;}
    int getY(){return y;}
    int setX(int arg){x = arg;}
    int setY(int arg){y = arg;}
    float distancia(Ponto &ponto){
        int dX = x - ponto.getX();
        int dY = y - ponto.getY();
        return sqrt(pow(dX,2)+pow(dY,2));
    }
};

class Retangulo{
    Ponto a,b,c;
    public:
    Retangulo(const Ponto &a, const Ponto&b,const Ponto&c):a(a),b(b),c(c){};
    float perimetro(){
        return 2*(a.distancia(b)+b.distancia(c));
    }
    float area(){
        return a.distancia(b)*b.distancia(c);
    }

};

class Quadrado{
    Ponto a,b;
    public:
    Quadrado(Ponto &a, Ponto &b):a(a),b(b){};
    float perimetro(){
        return 4*a.distancia(b);
    }
    float area(){
        return pow(a.distancia(b),2);
    }

};

class Circulo{
    Ponto centro;
    int raio;
    public:
    Circulo(Ponto &centro, int raio):centro(centro),raio(raio){};
    float perimetro(){
        return 2*3.145*raio;
    }
    float area(){
        return 3.145*pow(raio,2);
    }

};