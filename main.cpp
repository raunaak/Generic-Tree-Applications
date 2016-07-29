#include <cstddef>
#include <iostream>
#include "BNode.h"
#include"TraversalAlgo.h"
#include "TraversalApplication1.h"
#include "NonRecursiveTraversal.h"
#include "MorrisTraversal.h"
#include "ConstructTreeGivenInorderAndPreorder.h"
#include "TraversalApplication2.h"
#include "Subtree.h"
#include "LowestCommonAncestor.h"
#include "InorderSuccessor.h"
using namespace std;
int main() {
    /*
     *                  4
     *                /   \
     *              2       5
     *            /   \
     *           1     3
     */
    
    BNode<int>* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    BNode<int>* n = inorderSuccessor(root, 3);
    if(n) cout<<n->data<<endl;
    
    //Lowest common ancestor
    //cout<<lowestCommonAncestor(root,3,5)<<endl;
    
    /*
    BNode<int>* subroot = newNode(2);
    subroot->left = newNode(1);
    subroot->right = newNode(3);
    cout<<subtree(root, subroot)<<endl;
    */
    
    /*
    cout<<maxWidth(root)<<endl;
    printNodesAtDistance(root, 3);
    printAncestor(root,1);*/
    
    /*Create a tree given inorder and preorder traversal
    int in[] = {1,2,3,4,5};
    int pre[]= {4,2,1,3,5};
    BNode<int>* node = createTree(in, pre, 5);
    inorder(node); cout<<endl;
    preorder(node); cout<<endl;
    postorder(node); cout<<endl;
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

