#include <iostream>

using namespace std;

int mdc(int a, int b){
    int aux;
    if (a > b){
        aux = a;
        a = b;
        b = aux;
    }
    while (b % a){
        b -= a;
        if (a > b){
            aux = a;
            a = b;
            b = aux;
        }
    }
    return a;
}

class numeroRacional
{
public:
    int numerador, denominador;
    numeroRacional(int num, int den){
        if (den == 0){
            throw "Inválido";
        }
        numerador = num;
        denominador = den;
        simplificar();    
    }

    void simplificar(){
        int a = mdc(numerador,denominador);
        numerador = numerador / a;
        denominador = denominador / a;
    }
    void Imprimir(){
        cout << numerador << "/" << denominador << endl;
    }

    numeroRacional operator+(numeroRacional ldo){
        return numeroRacional(numerador*ldo.denominador+ldo.numerador*denominador,
                            denominador*ldo.denominador);
    }

    numeroRacional operator/(numeroRacional ldo){
        return numeroRacional(numerador*ldo.denominador,denominador*ldo.numerador);
    }

    numeroRacional operator++(int a){
        numeroRacional temp =(*this);
        ++(*this);
        //simplificar();
        return temp;
    }
    numeroRacional operator++(){
        numerador += denominador;
        //simplificar();
        return(*this);
    }
};

std::ostream& operator<<(ostream& out, const numeroRacional& num){
    out << num.numerador;
    return out;
}
int main(){
    numeroRacional f1 = numeroRacional(10,3);
    numeroRacional f2 = numeroRacional(5,3);
    int a = 5;
    cout<<(++f1);
}