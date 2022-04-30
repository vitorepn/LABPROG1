#include<iostream>

using namespace std;

class Matriz{
    float M11,M12,M21,M22;
    public:
    Matriz(float M11,float M12, float M21, float M22):M11(M11),M12(M12),M21(M21),M22(M22){ }
    float getItem(string Item){
        if(Item == "M11") return M11;
        if(Item == "M12") return M12;
        if(Item == "M21") return M21;
        if(Item == "M22") return M22;
        cout<<"Entrada inválida";
        return 0;
    }
    void visualizar(){
        cout<<"|"<<M11<<" "<<M12<<"|"<<"\n"<<"|"<<M21<<" "<<M22<<"|";
    }
    float det(){
        return(M11*M22-M21*M12);
    }
    Matriz* inversa(){
        float denominador = -det();
        if (denominador == 0) {
            cout<<"Matriz nao inversivel";
            return nullptr;}

        float m11 = -(M22/denominador);
        float m12 = (M12/denominador);
        float m21 = (M21/denominador);
        float m22 = -(M11/denominador);
        return new Matriz(m11,m12,m21,m22);
    }
};