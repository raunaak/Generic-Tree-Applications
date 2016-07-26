#include <cstddef>
#include <iostream>
#include "BNode.h"
#include"TraversalAlgo.h"
using namespace std;
int main() {
    BNode<int>* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    inorder(root); cout<<endl;
    preorder(root); cout<<endl;
    postorder(root); cout<<endl;
    
    return 0;
}

