#include <cstddef>
#include <iostream>
#include "BNode.h"
#include"TraversalAlgo.h"
#include "TraversalApplication.h"
#include "NonRecursiveTraversal.h"
#include "MorrisTraversal.h"
#include "ConstructTreeGivenInorderAndPreorder.h"
using namespace std;
int main() {
    
    int in[] = {1,2,3,4,5};
    int pre[]= {4,2,1,3,5};
    BNode<int>* node = createTree(in, pre, 5);
    inorder(node); cout<<endl;
    preorder(node); cout<<endl;
    postorder(node); cout<<endl;
    
    /*
    BNode<int>* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
     */
    
    //Morris Inorder traversal
    //morrisInorder(root);
    
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

