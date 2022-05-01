#include <iostream>
#include "vetor.h"

using namespace std;

int main(){
    Vetor v1(1,1);
    Vetor v2(5,1);
    cout<<v1.prodEscalar(v2);
}