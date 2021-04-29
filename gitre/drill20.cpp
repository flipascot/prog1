#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

using namespace std;



template<typename C>
void print(const C& c)
 {
	for(auto& a:c)
		cout<< a << ' ';
	cout << endl;
	cout << endl;
 }



template<typename T>
 void incr(T& t, int n=1)
 {

 	for(auto& a:t)
 		a+=n;
 }

template<typename Iter1, typename Iter2>
 // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	 for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;

    return f2;
}


int main()
{


	const int size=10;
	int arr[size];

	for(int i =0; i<size; i++)
	{
		arr[i]=i;
	}


	array<int, size> a;
	copy(arr, arr+ size, a.begin());
	cout<<"Az array kiiratva:"<<endl;
	print(a);

	

	vector<int> v(size);
	copy(arr, arr+ size, v.begin());
	cout<<"A vector kiiratva:"<<endl;
	print(v);

	

	list<int> l(size);
	copy(arr, arr+ size, l.begin());
	cout<<"A list kiiratva:"<<endl;
	print(l);

	

	array<int, size> a2=a;
	cout<<"Az array_copy kiiratva:"<<endl;
	print(a2);

	vector<int> v2=v;
	cout<<"A vector_copy kiiratva:"<<endl;
	print(v2);

	list<int> l2=l;
	cout<<"A list_copy kiiratva:"<<endl;
	print(l2);

	
	

	incr(a2, 2);
	cout<<"Az array megnovelve kiiratva:"<<endl;
	print(a2);

	incr(v2, 3);
	cout<<"A vector megnovelve kiiratva:"<<endl;
	print(v2);

	incr(l2, 5);
	cout<<"A list megnovelve kiiratva:"<<endl;
	print(l2);

	
	my_copy(a2.begin(), a2.end(), v2.begin());
	my_copy(l2.begin(), l2.end(), a2.begin());

	cout<<"A vector miutan bele copyztuk az arrayt :"<<endl;
	print(v2);
	cout<<"At array miutan bele copyztuk a listet :"<<endl;
	print(a2);

	vector<int>:: iterator serc;
	serc=find(v2.begin(), v2.end(), 3);
	if(serc!= v2.end())
		cout<< "A" <<' '<<distance(v2.begin(), serc) << ". helyen van" << endl;
	else
		 cout<< "Nincs ilyen eleme";

	list<int>:: iterator serc2;
	serc2=find(l2.begin(), l2.end(), 27);
	if(serc2!= l2.end())
		cout<< "A" <<' '<<distance(l2.begin(), serc2) << ". helyen van" << endl;
	else
		 cout<< "Nincs ilyen eleme" << endl;

}
