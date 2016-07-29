#include <iostream>
#include <vector>
#define Datatype int
using namespace std;
class List {
    private:
        int _length;
        Datatype* _head;
    public:
         List (int length, Datatype default_num);
        ~List ();

        void      Show () const;
        bool      Empty () const;
        Datatype& operator[] (const unsigned int index) const;
        bool      Clear ();
        bool      Insert (Datatype d, int pos);
};

List::List (int length, Datatype default_num = 0): _length(length) {
    _head = new Datatype[length];
    for (int i = 0; i < length; ++i) {
        *(_head + i) = default_num;
    }
}
List::~List () {
    Clear();
}
void List::Show() const{
    for(int i = 0; i < _length; ++i) {
        std::cout << *(_head + i) <<  " ";
    }
    std::cout << std::endl;
}
bool List::Empty () const {
    return _length && _head != NULL;
}
Datatype& List::operator[] (const unsigned int index) const {
    return *(_head + index);
}
bool List::Clear () {
    _length = 0;
    delete [] _head;
    _head = NULL;
}
bool List::Insert (Datatype d, int pos) {
    //| | |  可以在这些这些地方插
    // 0 1 2
    if (pos < 0 || pos > _length) {
        return false;
    }
    int _new_length = _length + 1;
    Datatype* _new_head = new Datatype[_new_length];
    int i;
    for (i = 0; i < pos-1; ++i) {
        *(_new_head + i) = *(_head + i);
        cout << i<<*(_new_head + i) << " ";
    }
    *(_new_head + i) = d;
    cout <<"/"<< i<<*(_new_head + i) << "/ ";
    //++i;
    for (; i < _length; ++i) {
        *(_new_head + i + 1) = *(_head + i);
        cout << i<<*(_new_head + i) << " ";
    }
    Clear();
    _head = _new_head;
    _length = _new_length;
    cout << endl;
    return true;
}
int main () {
    List l(2);
    l.Show();
    l.Insert(100,2);
    l.Show();
    l.Insert(99, 0);
    l.Show();
}
