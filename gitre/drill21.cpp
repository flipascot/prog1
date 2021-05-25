#include "../lib_files/std_lib_facilities.h"
#include <vector>
class wrong_form_exception{
};
//1.
template<typename T> struct S 
{ 
	
	//2.
	S(): val(T()){}
	S(T t): val(t) {}
	
	//5.
	T& get();
	//9.
	T& set(T t);
	
	//10.
	T& operator=(const T& s);
	//11.
	const T& get() const;
	//12.
	T& read_val(T& v);
	

private:
	//7.
	T val; 
};

//6.
template<typename T>  
T& S<T>::get()
{
	return val;
}

//9.
template<typename T>
T& S<T>::set(T t){
	val=t;
	return val;
}
//10.
template<typename T>
T& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}
//11.
template<typename T>
const T& S<T>::get() const{
	return val;
}
//12.
template<typename T>
T& S<T>::read_val(T& v){
	std::cin >> v;
	return v;
	
}
//14.
template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch;
	
	is >> ch; //{
	if (ch!='{') throw wrong_form_exception();
	else{
	for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') {
        	break;
        	}
    	}
    	}
    	
    	return is;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{";
	for (int i=0; i<v.size(); ++i){
		os << v[i] << ",";
	}
	os << "}";
	
	return os;
}

int main() {

try{
	//3.
	S<int> si {0};
	
	S<char> sc {'o'};
	
	S<double> sd {1.50};
	
	S<string> ss {"macska"};
	
	S<vector<int>> sv {vector<int>{1,2,3}};
	
	//4.
	/*
	cout <<"int: " << si.val << '\n';
	cout <<"char: " << sc.val << '\n';
	cout <<"double: " << sd.val << '\n';
	cout <<"string: " << ss.val << '\n';
	for (int i = 0; i<sv.val.size(); ++i)
	cout << "vektor ["<<i<<"]= " << sv.val[i]<< "\n";*/
	
	//8.
	cout <<"re int: " << si.get() << '\n';
	cout <<"re char: " << sc.get() << '\n';
	cout <<"re double: " << sd.get() << '\n';
	cout <<"re string: " << ss.get() << '\n';
	for (int i = 0; i<sv.get().size(); ++i)
        cout << "vektor [" << i << "]: " << sv.get()[i] << "\n";
        
       cout << "setted int: " << si.set(12) << '\n';
       
       //13.
       cout<<"írjon be rendre egy chart, egy integert, egy sztringet, majd egy double-t KÜLÖN SORBA" << '\n';
       char c;
       sc.read_val(c);
       
       int i;
       si.read_val(i);
       
       string s;
       ss.read_val(s);
       
       double d;
       sd.read_val(d);
       
       //14.
       cout << "int vektor: formátuma legyen {val,val,val}" << '\n';
       vector<int> vii;
       sv.read_val(vii);
       
       //egy kis ellenőrzés:
       	for (int i = 0; i<vii.size(); ++i)
        cout << "vektor [" << i << "]: " << vii[i] << "\n";
        }
catch(exception& e){
cerr << e.what() << '\n';
return 1;
}
       
}
