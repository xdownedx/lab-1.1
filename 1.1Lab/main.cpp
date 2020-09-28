#include <list>
#include <iostream>
#include <cmath>

using namespace std;

template<class T>
list<T> filter(list<T>lst) {

    list<T> nLst;
    if (lst.size() == NULL) {
        return nLst;
    }
    list<int>::iterator p = lst.begin();
    while (p != lst.end()) {
        if (*p%3==0) {
            nLst.push_back(*p);
        }
        p++;
    }
    return nLst;
}
template<class T>
void pop(list<T>& lst, T element) {

    if (lst.size() == NULL) {
        exit(0);
    }

    list<int>::iterator p = lst.begin();
    while (p != lst.end()) {
        if (*p == element) {
            lst.remove(element);
            break;
        }
        p++;
    }
}

template<class T>
void push(list<T>& lst, T element) {
    list<int>::iterator p = lst.begin();
    while (p != lst.end())
    {
        if (*p > element && element > 0)
            break;
        else
            p++;
    }
    lst.insert(p, element);
}

int main()
{
    list<int> lst;
    int i = 0;
    for (i = 0; i < 10; i += 1)
        lst.push_back((i+0.1));

    push(lst, 1);
    pop(lst, 20);

    lst = filter(lst);

    list<int>::iterator p = lst.begin();
    while (p != lst.end())
    {
        //перемещение по контейнеру с помощью указателя, нет операции [i]
        cout << *p << " ";
        p++;
    }
    return 0;
}
