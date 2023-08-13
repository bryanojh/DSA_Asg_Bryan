#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    void push(T element);
    T pop();
    bool is_empty();
    int size();

private:
    struct Node {

        T data;
        Node *next;

        Node() : next(nullptr) {}  // Default constructor
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node *mHead;
    Node *mTail;
};

#endif // QUEUE_H