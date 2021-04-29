/* g++ drill15masodik.cpp ./std_lib_facilities.h -o drill15masodik */


#include "std_lib_facilities.h"
#include <iostream>

struct Person{
Person(): first_n(""), last_n(""), age(0) {}
Person(string first,string last, int a);

string first_name() const {return first_n;}
string last_name()  const {return last_n;} 
string full_name()  const {return first_n+" "+last_n;}
int get_age() const {return age;}

private:
string first_n;
string last_n;
int age;
};

Person::Person(string first,string last, int a):first_n(first), last_n(last), age(a){

if (a<0 || a>150) error("Helytelen életkor, 0 és 150 közötti egész számot adjon meg");
for (int i=0; i<full_name().size(); i++){
	if (full_name()[i]== ':' || full_name()[i]== ';' || full_name()[i]== '"' || full_name()[i]== '\''
	|| full_name()[i]== '[' || full_name()[i]== ']' || full_name()[i]== '*' || full_name()[i]== '^' || full_name()[i]== '%' 
	|| full_name()[i]==  '$' || full_name()[i]== '#' || full_name()[i]== '@' || full_name()[i]== '!')
	error("Helytelen karakterhasználat! Csak ABC betűit és számokat használjon!");
}
for (int i=0; i<full_name().length();i++){
if (first_name().length()<1 || last_name().length()<1 || isdigit(full_name()[i])) error ("Teljes nevet adjon meg, számok használata nélkül!");
}
}

istream& operator>>(istream& is, Person& p){
string f,l;
int a;
is >> f >> l >> a;
Person p1 (f,l,a);
p= p1;
return is;
}

ostream& operator<<(ostream& os, Person& p){
os <<"name: " <<p.full_name() << " age: " << p.get_age();
return os;
}

int main() {
try{
Person p("Istavn"," ",69);
cout << "age: " << p.get_age() <<" name: " << p.full_name() << '\n';

Person p2;
cin >> p2;
cout << p2 <<'\n';

cout << "A ciklusos kiíratás: " << '\n';
vector<Person> v;
Person p3;
for (int i=0; i<10; i++){
	cin >> p3;
	v.push_back(p3);
	cout << v[i] << '\n';	
}
}
catch(exception &e){
cerr<< e.what() << endl;
}
catch(...){
cerr << "error" << endl;
}
return 0;
}
