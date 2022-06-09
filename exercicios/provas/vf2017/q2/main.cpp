#include <iostream>
#include <math.h>

using namespace std;

class Polinomio{
    float x, a, b;
    public:
    Polinomio(float x):x(x),a(0),b(0){};
    friend Polinomio& operator+(float a ,Polinomio& pol);
    Polinomio& operator+(float b){
        this->b = b;
        return *this;
    };
    float operator^(int n){
        return a*pow(x,n)+b;
    }
};

Polinomio& operator+(float a,Polinomio &pol){
    pol.a = a;
    return pol;
}


int main(){
    Polinomio pol(3);
    float a = 1;
    float b = 1;
    int n = 2;
    cout<<(a+pol+b^n);
}