#pragma once
#include <iostream>
#include "../BprojectTwo/clsMyQueue.h"

template <class T>

class clsMyStack : public clsMyQueue<T>
{

public:
    void push(T Item)
    {
        clsMyQueue<T>::_MyList.InsertAtBeginning(Item);
    }

    T Top()
    {
        return clsMyQueue<T>::front();
    }

    T Bottom()
    {
        return clsMyQueue<T>::back();
    }
};
