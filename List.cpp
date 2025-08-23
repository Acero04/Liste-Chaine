#include "Node.hpp"
#include "List.hpp"
#include <iostream>


////////////////////////////////////////////////////////////
//
//PUBLIC METHODS
//
////////////////////////////////////////////////////////////
template<typename T>
List<T>::List() : m_root(nullptr) {}

template<typename T>
List<T>::List(const T value) {
    m_root = new Node<T>();
    m_root->value = value;
    m_root->Next = nullptr;
}


template<typename T>
void List<T>::displayRoot() const 
{
    if (m_root != nullptr) {
        std::cout << m_root->value;
    } else {
        std::cout << "The list is empty.\n";
    }
}


template<typename T>
void List<T>::insert(const T value) 
{
    Node<T> *nextNode = search(m_root);

    nextNode->value = value;
    nextNode->next = nullptr;
}

//////////////////////////////////////////////////////////
//                                                      //
//                  PRIVATE METHODS                     //
//                                                      //
//////////////////////////////////////////////////////////

template<typename T>

Node<T>* List<T>::search(Node<T>* currentNode) const {
    while (currentNode != nullptr) {
        currentNode = currentNode->Next;
    }
    return currentNode;
    
}
