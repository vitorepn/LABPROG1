#include <iostream>
#include "classes.h"

using namespace std;

int main(){
    Banco b(10);
    stats st;
    ClienteComum cc1("Joao",1,3,5);
    ClienteComum cc2("Jose",2,4,6);
    ClienteComum cc3("Luiz",3,5,2);
    ClientePreferencial cp1("Maria",1,3);
    ClientePreferencial cp2("Ana",2,4);
    ClientePreferencial cp3("Jorge",3,5);

    b.adicionar(cc2);
    b.adicionar(cc3);
    b.adicionar(cc1);
    b.adicionar(cp2);
    b.adicionar(cp3);
    b.adicionar(cp1);
    
    st = b.simular();
    cout<<st.tempoMedio<<" "<<st.desistentes<<endl;
}