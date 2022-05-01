#include <iostream>
#include "classes.h"

using namespace std;
int main(){
    TrapezioIsosceles tr1(3,2,1);
    Retangulo rt1(1,2);
    cout<<rt1.perimetro()<<endl;
    cout<<tr1.perimetro()<<endl;
}