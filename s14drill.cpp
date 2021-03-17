#include <iostream>
#include"std_lib_facilities.h"
#include <vector>

using namespace std;

class B1{
public:
    virtual void vf(){
        cout<<"B1:vf()\n";
    }
    void f(){
        cout<<"B1:f()\n";
    }
    
    virtual void pvf()=0;
};

class D1: public B1{
public:
    virtual void vf() override {
        cout<<"D1:vf()\n";
    }
    void f(){
        cout<<"D1:f()\n";
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
	string valami1 = "Banfalvi";
	void pvf() override {
		cout<<valami1<<"\n";
	}
};

class D22: public B2{
public:
	int valami2 = 11;
	void pvf() override {
		cout<<valami2<<"\n";
	}
};

void f(B2& bazis){
	bazis.pvf;
}; 

int main(){

    B1 b1obj;
    b1obj.vf();
    b1obj.f();

    D1 d1obj;
    d1obj.vf();
    d1obj.f();

    b1&ref = d1obj;
    //B1& x{D1};
    ref.vf();
    ref.f();

    D2 d2obj;
    d2obj.vf;
    d2obj.f;
    d2obj.pvf;
   
   D21 d21obj;
   d22 d22obj;
   
   f(d21obj);
   f(d22obj);   
       
    

    return 0;
}
