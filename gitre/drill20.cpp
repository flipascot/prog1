#include "std_lib_facilities.h"

template<typename T, int N>
struct array {
    typedef T* iterator;
    typedef unsigned int size_type;

    T elems[N];

    iterator begin() { return elems; }
    iterator end() { return elems+N; }
    size_type size() const { return N; }
    T& operator[](int n) { return elems[n]; }
    T* data() { return elems; }
};

template<typename Iter>
void print(Iter first, Iter end, const string& s)
{
    cout << s << ": { ";
    while (first!=end) {
        cout << *first << ' ';
        ++first;
    }
    cout << "}\n";
}


template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while (f1!=e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int position = 0;

int main()
try
{
    
    const int arr_sz = 10;

    array<int,arr_sz> array_int;
    for (int i = 0; i<array_int.size(); ++i) array_int[i] = i;
    print(array_int.begin(),array_int.end(),"array_int");

   
    vector<int> vector_int;
    for (int i = 0; i<arr_sz; ++i) vector_int.push_back(i);
    print(vector_int.begin(),vector_int.end(),"vector_int");

    
    list<int> list_int;
    for (int i = 0; i<arr_sz; ++i) list_int.push_back(i);
    print(list_int.begin(),list_int.end(),"list_int");

    cout << endl;

    
    array<int,arr_sz> array_copy = array_int;
    print(array_copy.begin(),array_copy.end(),"array_copy");

    vector<int> vector_copy = vector_int;
    print(vector_copy.begin(),vector_copy.end(),"vector_copy");

    list<int> list_copy = list_int;
    print(list_copy.begin(),list_copy.end(),"list_copy");

    cout << endl;

    
    //  (array<int>::Iterator p)
    for (auto p = array_int.begin(); p!=array_int.end(); ++p)
        *p += 2;
    print(array_int.begin(),array_int.end(),"array_int+=2");

    for (auto p = vector_int.begin(); p!=vector_int.end(); ++p)
        *p += 3;
    print(vector_int.begin(),vector_int.end(),"vector_int+=3");

    for (auto p = list_int.begin(); p!=list_int.end(); ++p)
        *p += 5;
    print(list_int.begin(),list_int.end(),"list_int+=5");

    cout << endl;

 
    vector<int>::iterator v_it = my_copy(array_int.begin(),array_int.end(),vector_int.begin());
    array<int,arr_sz>::iterator a_it = my_copy(list_int.begin(),list_int.end(),array_int.begin());

    if (v_it!=vector_int.begin() && a_it!=array_int.begin())
    {
        print(array_int.begin(),array_int.end(),"array_int copied from list_int");
        print(vector_int.begin(),vector_int.end(),"vector_int copied from array_int");
        print(list_int.begin(),list_int.end(),"list_int");
    }

    cout << endl;

   
    v_it = find(vector_int.begin(),vector_int.end(),3);
    if (v_it != vector_int.end())
    {
        for(vector<int>::iterator v_iter = vector_int.begin(); v_iter != v_it; ++v_iter)
            ++position;
        cout << "In vector_int, position of 3 is at " << position+1 << ".\n";
    }    



    list<int>::iterator l_it = find(list_int.begin(),list_int.end(),27);
    if (l_it!=list_int.end())
    {
        for (list<int>::iterator iter = list_int.begin(); iter!=l_it; ++iter)
            ++position;
        cout << "In list_int, position of 27 is at  " << position+1 << ".\n";
    }
    else
        cout << "27 is not in list_int.\n";
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...) 
{
    cerr << "exception\n";
}
