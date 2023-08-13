#include "BinarySearchTree.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr),_count(0) {}

template <typename T>
typename BinarySearchTree<T>::TreeNode* BinarySearchTree<T>::insertRecursive(TreeNode* node, const T& value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value< node->data) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    root = insertRecursive(root, value);
}

template <typename T>
void BinarySearchTree<T>::inOrderTraversal(TreeNode* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->data << "\n";
        inOrderTraversal(node->right);
    }
}



template <typename T>
void BinarySearchTree<T>::displayInOrder() {
    inOrderTraversal(root);
    std::cout << std::endl;
}

template <typename T>
int BinarySearchTree<T>::getCount() {
    return _count;
}

template <typename T>
void BinarySearchTree<T>::setCount(int count) {
    this->_count = count;
}

template <typename T>
T* BinarySearchTree<T>::searchRecursive(TreeNode* node, const T& value) const {
    if (node == nullptr || node->data == value) {
        return (node != nullptr) ? &(node->data) : nullptr;
    }

    if (value < node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

template <typename T>
T* BinarySearchTree<T>::fullTreeSearchRecursive(TreeNode* node, const T &value) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data == value) {
        return &(node->data);
    }

    T * leftResult = fullTreeSearchRecursive(node->left, value);
    if (leftResult) {
        return leftResult;
    }

    return fullTreeSearchRecursive(node->right, value);
}

template <typename T>
T* BinarySearchTree<T>::search(const T& value) const {
    return searchRecursive(root, value);
}

template <typename  T>
T *BinarySearchTree<T>::fullTreeSearch(const T &value) const {
    return this->fullTreeSearchRecursive(root,value);
}