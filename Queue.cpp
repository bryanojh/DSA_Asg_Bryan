#include "Queue.h"

template <typename T>
Queue<T>::Queue() {
    mHead = nullptr;
    mTail = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
    while (mHead != nullptr) {
        Node *node = mHead;
        mHead = mHead->next;
        delete node;
    }
}

template <typename T>
void Queue<T>::push(T element) {
    Node *node = new Node(element);
    node->data = element;
    node->next = nullptr;

    if (mHead == nullptr) {
        mHead = node;
        mTail = node;
    } else {
        mTail->next = node;
        mTail = node;
    }
}

template <typename T>
T Queue<T>::pop() {


    T element = mHead->data;
    Node *node = mHead;
    mHead = mHead->next;
    delete node;

    if (mHead == nullptr) {
        mTail = nullptr;
    }

    return element;
}

template <typename T>
bool Queue<T>::is_empty() {
    return mHead == nullptr;
}

template <typename T>
int Queue<T>::size() {
    int size = 0;
    for (Node *node = mHead; node != nullptr; node = node->next) {
        size++;
    }

    return size;
}


