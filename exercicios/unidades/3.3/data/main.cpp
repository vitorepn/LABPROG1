#include <iostream>
#include "Data.h"

using namespace std;

int main(){
    Data* data1 = new Data(0,13,13);
    data1->adiantar(3,-2,0);
    data1->visualizar();
}