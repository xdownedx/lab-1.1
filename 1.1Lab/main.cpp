#include <list>
#include <iostream>
#include <cmath>

using namespace std;


template<class T>
bool predicat(T elem, int value) {
    return elem%value==0;
}

template<class T>
list<T> filter(list<T>lst, int value) {

    list<T> nLst;
    auto p = lst.begin();

    while (p != lst.end()) {
        if (predicat<T>((*p),value)) {
            nLst.push_back(*p);
        }
        p++;
    }
    return nLst;
}
template<class T>
void pop(list<T>& lst, T element) {

    auto p = lst.begin();

    while (p != lst.end()) {
        if (*p == element) {
            lst.remove(element);
            break;
        }
        p++;
    }
}

template<class T>
void push(list<T>& lst, T elem) {

    if (lst.empty()) {
        lst.push_back(elem);
    }

    else {
        auto p = lst.begin();

        while (p != lst.end()) {
            if (*p > elem) {
                break;
            }
            p++;
        }
        lst.insert(p, elem);
    }
}

int main()
{
    list<int> lst;
    int i = 0;
    for (i = 0; i < 10; i += 1)
        lst.push_back((i+0.1));

    push(lst, 1);
    pop(lst, 20);

    lst = filter(lst, 3);

    list<int>::iterator p = lst.begin();
    while (p != lst.end())
    {
        //перемещение по контейнеру с помощью указателя, нет операции [i]
        cout << *p << " ";
        p++;
    }
    return 0;
}
