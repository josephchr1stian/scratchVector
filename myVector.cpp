//
// Created by Joseph Garcia on 2/27/24.
//

#include "myVector.h"

template <typename T>
myVector<T>::myVector()
{
    capacity = 0;
    sizeOfArray = 0;
}
template <typename T>
myVector<T>::myVector(unsigned int size)
{

     array = new T[size];
     capacity = size;
     sizeOfArray = size;

}
template <typename T>
myVector<T>::myVector(unsigned int size, T data)
{
    array = new T[size];
    sizeOfArray = size;
    capacity = size;

    for (int i = 0; i < size; i++)
    {
        array[i] = data;
    }


}
template <typename T>
T* myVector<T>::begin() const
{
    T *ptr = &array[0];
    return ptr;
}

template <typename T>
T& myVector<T>::front() const
{
    if (sizeOfArray == 0)
        std::cout << "empty array";
    return array[0];
}

template <typename T>
T& myVector<T>::back() const
{
    if (sizeOfArray == 0)
        std::cout << "empty array";
    return array[sizeOfArray-1];
}

template<typename T>
void myVector<T>::resize()
{
    if (sizeOfArray == 0)
    {
        sizeOfArray =1;
        capacity = 1;
    }
    capacity *= 2;
    T *arrayCopy = new T[sizeOfArray];
    for( int i = 0; i < sizeOfArray; i++)
    {
        arrayCopy[i] = array[i]; // New array contains old array
    }
    delete array;
    array = arrayCopy;
}


template <typename T>
unsigned int myVector<T>:: size() const
{

    return sizeOfArray;
}