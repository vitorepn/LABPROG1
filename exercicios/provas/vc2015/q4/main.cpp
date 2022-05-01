#include <iostream>
#include "classes.h"

using namespace std;

int main(){
    Ponto p1(0,0);
    Ponto p2(0,3);
    Quadrado q1(p1,p2);
    cout<<q1.perimetro();
}