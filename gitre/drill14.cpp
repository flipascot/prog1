#include <iostream>
#include <vector>

using namespace std;

class B1{
public:
    void f(){
        cout<<"B1:f()\n";
    }
    
    virtual void vf(){
        cout<<"B1:vf()\n";
    }

    virtual void pvf()=0;
};

class D1: public B1{
public:
    void f(){
        cout<<"D1:f()\n";
    }
    virtual void vf() override {
        cout<<"D1:vf()\n";
    }
    
};


class D2: public D1{
    virtual void pvf() override {
        cout<<"D2:pvf()\n";
    }
};



class B2{
    public:
    virtual void pvf()=0;
};

class D21: public B2{
    public:
    string szoveg = "Krisz";
    void pvf() override {
        cout<<szoveg<<'\n';
    }
};

class D22: public B2{
    public:
    int szam = 11;
    void pvf() override {
        cout<<szam<<'\n';
    }

};

void f(B2& kap){
    kap.pvf();
}

int main(){
    B1 b1obj;
    b1obj.vf();
    b1obj.f();

    D1 d1obj;
    d1obj.vf();
    d1obj.f();

    B1& ref = d1obj;
    ref.vf();
    ref.f();

    D2 d2obj;
    d2obj.vf();
    d2obj.f();
    d2obj.pvf();

    D21 d21obj;
    D22 d22obj;
    f(d21obj);
    f(d22obj);



    return 0;
}
