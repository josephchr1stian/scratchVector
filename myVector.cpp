//
// Created by Joseph Garcia on 2/27/24.
//

#include "myVector.h"

template <typename T>
myVector<T>::myVector()
{

}

template <typename T>
T* myVector<T>:: begin()
{
    T *ptr = &array[0];
    return ptr;
}