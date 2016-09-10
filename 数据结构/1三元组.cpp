/**
Triplet 三元组
Author: Hou Baron
Date:   2016-09-05
Page:   P9
*/
template <typename T>
class Triplet {
private:
    T _elem[3];
public:
    Triplet () {
       // _elem[0] = _elem[1] = _elem[2] = NULL; // T 的初值
    }
    Triplet (T e1, T e2, T e3) {
        _elem[0] = e1;
        _elem[1] = e2;
        _elem[2] = e3;
    }
    ~Triplet() {
        //_elem[0] = _elem[1] = _elem[2] = NULL;// T 的初值
        delete[] _elem;
    }
    T&   get (int i) {
        --i;
        return _elem[i];
    }
    bool set (int i, T e) {
        --i;
        return (_elem[i] = e);
    }
        bool isAscending () {
        return (_elem[0] <= _elem[1] && _elem[1] <= _elem[2]);
    }
    bool isDescending () {
        return (_elem[0] >= _elem[1] && _elem[1] >= _elem[2]);
    }
    bool sort () {
        for (int i = 2; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (_elem[j] > _elem[j + 1]) {
                    T temp;
                    temp = _elem[j];
                    _elem[j] = _elem[j + 1];
                    _elem[j + 1] = temp;
                }
            }
        }
        return isAscending();
    }
    T&   max () {
        int imax = 0;
        for (int i = 0; i < 3; ++i) {
            if (_elem[i] > _elem[imax]) {
                imax = i;
            }
        }
        return _elem[imax];
    }
    T&   min () {
        int imin = 0;
        for (int i = 0; i < 3; ++i) {
            if (_elem[i] < _elem[imin]) {
                imin = i;
            }
        }
        return _elem[imin];
    }
};
int main() {}
