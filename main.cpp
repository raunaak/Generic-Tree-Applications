#include <cstddef>
#include <iostream>
#include "BNode.h"
#include"TraversalAlgo.h"
#include "TraversalApplication.h"
#include "NonRecursiveTraversal.h"
using namespace std;
int main() {
    BNode<int>* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    
    inorderWithoutRecursion(root);
    
    /* Simple traversal applications
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    cout<<totalNodes(root)<<endl;
    cout<<maxElement(root)<<endl;
    cout<<minElement(root)<<endl;
    printLeftViewRecursion(root);
    printLeftViewNonRecursion(root);*/
    
    /* Traversal
     * inorder(root); cout<<endl;
     * preorder(root); cout<<endl;
     * postorder(root); cout<<endl;
    */
    return 0;
}

