//
// Created by Joseph Garcia on 2/27/24.
//

#ifndef CS8_VECTOR_SCRATCH_MYVECTOR_CPP
#define CS8_VECTOR_SCRATCH_MYVECTOR_CPP

#include "myVector.h"

template <typename T>
myVector<T>::myVector()
{
    array = new T[0];
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
myVector<T>::myVector(unsigned int size, T& data)
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
T* myVector<T>::end() const
{
    return sizeOfArray > 0 ? &array[sizeOfArray-1] : nullptr;
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
T& myVector<T>::at(unsigned int index) const
{
    if (index > sizeOfArray)
        return array[sizeOfArray-1]; // return last element
    return array[index];
}

template<typename T>
void myVector<T>::resize()
{
    if (sizeOfArray == 0 || capacity == 0)
    {
        sizeOfArray =1;
        capacity = 1;
    }
    else
    {
        capacity *= 2;
        sizeOfArray += 1;
        T *arrayCopy = new T[sizeOfArray];
        for( int i = 0; i < sizeOfArray; i++)
        {
            arrayCopy[i] = array[i]; // New array contains old array
        }
        delete array;
        array = arrayCopy;

    }
    //sizeOfArray +=1;

}

template<typename T>
void myVector<T>::resizeDown()
{

    capacity /= 2;
    T *arrayCopy = new T[sizeOfArray];
    for( int i = 0; i < sizeOfArray; i++)
    {
        arrayCopy[i] = array[i]; // New array contains old array
    }
    delete array;
    array = arrayCopy;
}

template <typename T>
bool myVector<T>::empty() const
{
    if (sizeOfArray== 0)
        return true;
    else
        return false;
}

template <typename T>
void myVector<T>::push_back(const T& data)
{
    if (sizeOfArray < capacity)
    {
        array[sizeOfArray-1] = data;
        sizeOfArray += 1;
    }
    else
    {
        resize();
        array[sizeOfArray-1] = data;
    }
}


template <typename T>
void myVector<T>::pop_back()
{
    sizeOfArray -= 1;
    if (sizeOfArray < capacity / 2)
        resizeDown(); // RESIZE DOWN DOEEE
}




template <typename T>
unsigned int myVector<T>:: size() const
{

    return sizeOfArray;
}

template <typename T>
myVector<T>::~myVector()
{
    delete array;
}

template <typename T>
myVector<T>& myVector<T>:: operator+(const T& data)
{
    push_back(data);
    return *this;
}

template <typename T>
myVector<T>& myVector<T>:: operator+(const myVector<T> & data)
{
    for (int i = 0; i < data.sizeOfArray ; i ++)
    {
        push_back(data.at(i));
    }
    return *this;
}

template <typename T>
myVector<T>& myVector<T>::operator-(const T &data)
{
    for(int i = 0; i < sizeOfArray ; i++)
    {
        if (data == array[i])
            pop_back(i);
    }
    return *this;

}

template <typename T>
void myVector<T>::sort(unsigned int start, unsigned int end)
{
    if (start < (end))
    {
        int d = divide(start);
        divide(start,d -1);
        divide(d + 1, end);
    }
}

template <typename T>
unsigned int myVector<T>::divide(unsigned int start, unsigned int end)
{
    unsigned int index = start;
    T pivot = array[end];
    for (unsigned int i = start; i < end; i++)
    {
        if(array[i] < pivot )
        {
            T temp = array[i];
            array[i] = array[index];
            array[index] = temp;
            index++;
        }
    }
    T temp = array[end];
    array[end] = array[index];
    array[index] = temp;
    return index;
}

template <typename T>
myVector<T>& myVector<T>::operator-(const myVector<T> & data)
{
    unsigned length;
    if (data.sizeOfArray > sizeOfArray)
        length = sizeOfArray;
    else
        length = data.sizeOfArray;
    sort(0);
    data.sort(0);
    for(int i = 0; i < length ; i++)
    {
        if (data.at(i) == array[i])
            pop_back(i);
    }
    return *this;
}

template <typename T>
myVector<T>& myVector<T>::operator=(const myVector<T> & data)
{
    if (data.sizeOfArray > sizeOfArray)
    {
        for(int i = 0; i < sizeOfArray ; i++)
        {
            array[i] = data.at[i];
        }
        for (int i = data.sizeOfArray - sizeOfArray; i < data.sizeOfArray; i++)
        {
            push_back(data.i);
        }
    }
    else
    {
        for(int i = 0; i < data.sizeOfArray ; i++)
        {
            array[i] = data.at[i];
        }
        for(int i = sizeOfArray - data.sizeOfArray; i < sizeOfArray ; i++)
        {
           pop_back(i);
        }
    }

    ~myVector<T>();
    return *this;
}

template <typename T>
std::ostream&  operator<<(std::ostream& out, const myVector<T>& vector)
{
    for(int i =0; i < vector.sizeOfArray ; i++)
    {
        std::cout<< vector.at(i);
    }

}


#endif