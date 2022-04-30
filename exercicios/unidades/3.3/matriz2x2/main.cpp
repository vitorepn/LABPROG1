#include <iostream>
#include "matriz.h"

using namespace std;

int main(){
    Matriz* matriz1 = new Matriz(1,2,3,4);
    cout<<matriz1->det();
    cout<<matriz1->inversa()->det();
}