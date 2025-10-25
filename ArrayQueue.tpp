template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
if (i <= 0) i = 100;            // default size if invalid
    maxSize = i;
    buffer = new T[maxSize];        // allocate array memory
    this->length = 0;               // start empty
    frontIndex = 0;
    backIndex = maxSize - 1;        // set back one step before front

}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
if (isEmpty())
        throw std::string("Queue is empty. No back element.");
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
delete[] buffer;                // free memory
    buffer = nullptr;
    maxSize = 0;
    frontIndex = 0;
    backIndex = 0;
    this->length = 0;

}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
maxSize = copyObj.maxSize;
    buffer = new T[maxSize];        // new array of same size
    this->length = copyObj.length;

    for (int i = 0; i < this->length; ++i) {
        int src = (copyObj.frontIndex + i) % copyObj.maxSize;
        buffer[i] = copyObj.buffer[src];
 } // <-- closes the for-loop

   
    frontIndex = 0;
    backIndex  = (this->length == 0) ? (maxSize - 1) : (this->length - 1);
} // <-- closes the copy(...) function


template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
 if (isEmpty())
        throw std::string("Queue is empty. Cannot dequeue.");

    frontIndex = (frontIndex + 1) % maxSize;
    --this->length;

    if (this->length == 0) {
        frontIndex = 0;
        backIndex = maxSize - 1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
if (isFull())
        throw std::string("Queue is full. Cannot enqueue.");

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    ++this->length;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
if (isEmpty())
        throw std::string("Queue is empty. No front element.");
    return buffer[frontIndex];

}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
