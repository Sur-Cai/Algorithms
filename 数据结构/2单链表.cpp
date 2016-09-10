/**
LkList 单链表
Author: Hou Baron
Date:   2016-09-08
Page:   P19
class ListBase<T> {
public:
    virtual bool         clear()            = 0;
    virtual bool         empty()            = 0;
    virtual int          size()             = 0;
    virtual T&           get(int)           = 0;
    virtual T&           operator[](int)    = 0;
    virtual ListBase<T>& insert(int i, T e) = 0;// 在第 i 个位置之前插入
    virtual ListBase<T>& del(int)           = 0;
};
*/
#include <iostream> //仅仅为了 void List<T>.show() 存在
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T> (T d, Node<T>* n): data(d), next(n) {}
    Node<T> (T d): data(d), next(NULL) {}
    Node<T> ():next(NULL) {}
    friend std::ostream& operator<< (std::ostream& output, Node<T> e) {
        output << "Self: " << &e << "| Data: " << e.data << "| Next: " << e.next << std::endl;
    }
};
template <typename T>
class List{
private:
    Node<T>* _head;
    int _length;
public:
    List () :_length(0),_head(NULL) {}

    List (int l) :_length(l) {
        if (l == 0) {
            _head = NULL;
        }
        _head = new Node<T>[_length];
        for (int i = 0; i < _length - 1; ++i) {
            (_head + i)->next = (_head + i + 1);
        }
        (_head + _length - 1)->next = NULL; //nullptr
    }

    ~List () { clear(); }

    List<T>& clear () {
        delete[] _head;
        _length = 0;
        return *this;
    }

    bool empty () { return _length; }

    int  size  () { return _length; }

    Node<T>& get (int pos) { //有问题
        //if (pos < 0 || pos > _length) { return NULL; }
        Node<T>* cur = _head;
        for (int i = 0; i != pos && cur; ++i, cur = cur->next) {}
        return *cur;
    }

    Node<T>& operator[] (int pos) { return get(pos); }

    List<T>& insert (int pos, T data) {
        if (pos < 0 || pos > _length) { return *this; }
        Node<T>* elem = new Node<T>();

        if (!elem) { return *this; }
        elem->data = data;

        ++_length;
        if (pos == 0) { //TODO: 可能有更优雅的解决方案
            elem->next = _head;
            _head = elem;
            return *this;
        }

        Node<T> *cur = _head;
        for (int i = 0; i < pos - 1 && cur; ++i, cur = cur->next) {}
        elem->next = cur->next;
        cur->next = elem;
        return *this;
    }

    List<T>& del (int pos) {
        if (pos < 0 || pos > _length) { return *this; }
        else if (pos == 0) {
            --_length;
            Node<T> *cur = _head;
            _head = _head->next;
            delete cur;
            return *this;
        }

        --_length;
        Node<T> *cur = _head, *cur_pre;
        for (int i = 0; i < pos && cur; ++i, cur_pre = cur, cur = cur->next) {}
        cur_pre->next = cur->next;
        delete cur, cur_pre;
        return *this;
    }

    List<T>& show () {
        if (!_head || !_length) {
            std::cout << "Length: " << size() << std::endl;
            std::cout << "----------\n";
            return *this;
        }
        std::cout << "Length: " << size() << std::endl;
        for (Node<T>* cur = _head; cur; cur = cur->next) {
            std::cout << "Self: " << cur << "| Data: " << cur->data << "| Next: " << cur->next << std::endl;
        }
        std::cout << "----------\n";
        return *this;
    }
};
int main() {
    List<int> l;
    l.show().insert(0,666).show().insert(0,777).insert(2,888).show().del(0).show().clear().show();
}
