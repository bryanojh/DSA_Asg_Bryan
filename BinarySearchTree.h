#ifndef RESTAURANT_BINARY_SEARCH_TREE_H
#define RESTAURANT_BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;
    int _count;
    TreeNode* insertRecursive(TreeNode* node, const T& value);
    void inOrderTraversal(TreeNode* node);
    T* searchRecursive(TreeNode* node, const T& value) const;
    T* fullTreeSearchRecursive(TreeNode* node, const T& value) const;

public:
    BinarySearchTree();
    void insert(const T& value);
    T* search(const T& value) const;

    T* fullTreeSearch(const T& value) const;
    void displayInOrder();
    int getCount();
    void setCount(int count);
};


#endif //RESTAURANT_BINARY_SEARCH_TREE_H
