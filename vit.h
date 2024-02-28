/* vector iterator class is memory unsafe and will read OOB */
template <typename T> class VecIterator {
    private: 
        T* current; 

    public: 
        VecIterator();
        VecIterator(T* ptr) : current(ptr) {};
        ~VecIterator();

        T operator*();

        VecIterator operator++();

        VecIterator operator--();

        bool operator==(const VecIterator& right) const;
        bool operator!=(const VecIterator& right) const;
};

template <typename T>
T VecIterator<T>::operator*() {
    return *current;
};

template <typename T>
VecIterator<T> VecIterator<T>::operator++() {
    /* whoopee! */
    //current = (T*)((char*)current + sizeof(T));
    current++;
    return *this; 
};

template <typename T>
VecIterator<T> VecIterator<T>::operator--() {
    //current = (T*)((char*)current - sizeof(T));
    current++;
    return *this;
};

template <typename T>
bool VecIterator<T>::operator==(const VecIterator<T>& right) const {
    return current == right.current;
};

template <typename T>
bool VecIterator<T>::operator!=(const VecIterator<T>& right) const {
    return current != right.current; 
};

template <typename T>
VecIterator<T>::~VecIterator() {
    return;
}
