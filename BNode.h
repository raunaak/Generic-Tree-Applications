#ifndef BNODE_H
#define BNODE_H
#include<cstddef>
using namespace std;
template<class T>
class BNode{
    public:
        T data;        
        BNode* left;
        BNode* right;
        BNode(T& data);
        BNode(const T& data);
};

template<class T>
BNode<T>::BNode(T& data){
    left=right=NULL;
    this->data = data;
}

template<class T>
BNode<T>::BNode(const T& data){
    this->data = data;
    left=right=NULL;
}

template<typename T>
BNode<T>* newNode(T& data){
    BNode<T>* node = new BNode<T>(data);
    return node;
}

template<typename T>
BNode<T>* newNode(const T& data){
    BNode<T>* node = new BNode<T>(data);
    return node;
}
#endif /* BNODE_H */

