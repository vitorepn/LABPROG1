#include <iostream>

using namespace std;

template <unsigned T>
struct Fatorial{
    static const unsigned result = T*Fatorial<T-1>::result;
};

template <unsigned T>
struct superFatorial{
    static const unsigned result = Fatorial<T>::result*superFatorial<T-1>::result;
};

template<>
struct superFatorial<1>{
    static const unsigned result = 1;
};

template <>
struct Fatorial<1>{
    static const unsigned result = 1;
};


int main(){
    cout<<Fatorial<3>::result<<endl;
    cout<<superFatorial<4>::result<<endl;
}