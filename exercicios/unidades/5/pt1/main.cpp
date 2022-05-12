#include <iostream>

using namespace std;

class Classe{
    static int contador;
    public:
    Classe(){
        contador++;
    }
    static int getContador(){
        return contador;
    }
    ~Classe(){
        contador--;
    }
};

int Classe::contador = 0;

int main(){
    Classe c1;
    Classe c2;
    cout<<Classe::getContador();
}