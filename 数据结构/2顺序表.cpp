/**
SqList 顺序表
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
#include <iostream>//仅仅为了 void List<T>.show() 存在

template <typename T>
class List {
private:
    T* _head;
    int _length;
public:
    List () {
        _head = NULL;
        _length = 0;
    }

    List (int n) {
        _head = new T[n];
        _length = n;
    }

    ~List () { clear(); }

    bool clear () {
        delete[] _head;
        _head = NULL;
        _length = 0;
    }

    bool empty () { return _length; }

    int size () { return _length; }

    T& get (int i) { return _head[i]; }

    T& operator[] (int i) { return get(i); }

    List& insert(int pos, T e) {
        //TODO: 根据 POS 位置，选择从尾部追加或者从头部追加
        if (pos < 0 || pos > _length) { return *this; }
        T* newhead = new T[++_length];
        if (!newhead) { return *this; }
        int i = 0;
        for (; i < pos; newhead[i] = _head[i], ++i) {}
        newhead[i++] = e;
        for (; i < _length; newhead[i] = _head[i - 1], ++i) {}
        delete[] _head;
        _head = newhead;
        return *this;
    }

    List& del(int pos) {
        //TODO: 根据 POS 位置，选择从尾部删除或者从头部删除
        if (pos < 0 || pos > _length) {
            return *this;
        }
        T* newhead = new T[--_length];
        if (!newhead) { return *this; }
        int i = 0;
        for (; i < pos; newhead[i] = _head[i], ++i) {}
        for (; i < _length; newhead[i] = _head[i + 1], ++i) {}
        delete[] _head;
        _head = newhead;
        return *this;
    }

    List<T>& show () {
        std::cout << "Length: " << size() << std::endl;
        for (int i = 0; i < _length; ++i) {
            std::cout << _head[i] << " ";
        }
        std::cout << std::endl;
        return *this;
    }
};
int main() {
    List<int> l(5);
    for (int i = 0; i < 5; ++i) {
        l[i] = i;
    }
    l.show();
    l.insert(5,8888).insert(0,666);
    l.show();
    l.del(0).del(5);
    l.show();
    l.clear();
    l.show();
}
