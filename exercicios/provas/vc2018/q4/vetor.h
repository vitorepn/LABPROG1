#include <iostream>
#include<cmath>
using namespace std;

class Vetor{
    float x,y;
    public:
    Vetor(float x, float y):x(x),y(y){}
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    void imprimir(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    Vetor soma(Vetor &v1){
        return Vetor(x+v1.x,y+v1.y);
    }
    float norma(){
        return sqrt(pow(x,2)+pow(y,2));
    }
    float angulo(Vetor &v1){
        float ang1 = atan(y/x);
        if(v1.x==0){
            return ang1*57.2958;
        }
        float ang2 = atan(v1.y/v1.x);
        float dif = abs(ang2-ang1);
        return dif*57.2958;
    }
    float prodEscalar(Vetor &v1){
        return norma()*v1.norma()*cos(angulo(v1)/57.2958);
    }
};