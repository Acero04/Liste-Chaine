#ifndef __MY_LIST_H__
#define __MY_LIST_H__

#include "Node.hpp"
#include <cstdint>
#include <iostream>
#include <stdexcept>

template<typename T>
class List {
    private:
        Node<T>* m_root;
        size_t m_size;

        //methods
        void displayNode(Node<T> *currentNode) const;
        bool searchNode(Node<T>* someNode) const;
        void deleteNode(const Node<T> *target);
        bool is_empty() const;
        Node<T>* find_previous_and_next_node(const int position) const;
        size_t find_position(Node<T>* myNode);

    public:
        //constructor && destructor.
        List<T>();
        List<T>(const T value);
        ~List<T>();

        //methods
        void insert(const T value);
        void insert(const T value, const unsigned int position);
        void delete_value(const T value);
        void delete_value(const unsigned int position);
        void displayList() const ;
        unsigned int getSize() const;
        bool find_value(const T value) const;
};

//////////////////////////////////////////////////////
//                                                  //
//              public methods.                     //
//                                                  //
//////////////////////////////////////////////////////

// constructors
template<typename T>
List<T>::List() : m_root(nullptr),m_size(0) {

    std::cout << "m_root = " << m_root << "\n";
    std::cout << "---------OBJET CREER--------\n";
}
//
template<typename T>
List<T>::List(const T value) : m_size(1) {

    m_root = new Node<T>();
    m_root->value = value;
    m_root->Next = nullptr;

    std::cout << "m_root = " << m_root << "\n";
    std::cout << "---------OBJET CREER--------\n";
}
//destructor.
template<typename T>
List<T>::~List<T>() {

//    Node<T>* currentNode = m_root;
    Node<T>* tmp = nullptr;

    while (m_root != nullptr) {
        tmp = m_root->Next;
        delete m_root;
        m_root = tmp;
    }
    std::cout << "---------OBJET DETRUIT--------\n";
}

//METHODS-----------------------------
//
template<typename T>
void List<T>::insert(const T value) {

    Node<T>* newNode = new Node<T>();
    newNode->value = value;
    newNode->Next = nullptr;

    if (is_empty()) {
        m_root = newNode;
    } else {
        Node<T> *tmp = m_root;
        while (tmp->Next != nullptr) {
            tmp = tmp->Next;
        }
        tmp->Next  = newNode;
    }
    m_size++;
}
//
template<typename T>
void List<T>::insert(const T value, const unsigned int position) {

    if (position <= 0 || position > m_size + 1) {
        std::cout << "Position valide [" << 1 << "..." << m_size + 1 << "]\n.";

        throw std::length_error("La position entrer n'est pas valide");
    }

    Node<T> *newNode = new Node<T>();
    newNode->value = value;

    if (position == 1) {

        newNode->Next = m_root;
        m_root = newNode;
        m_size++;

    }  else {

        Node<T> *previousNode = find_previous_and_next_node(position - 1);

        if (static_cast<size_t>(position) < m_size) {
            newNode->Next = previousNode->Next;
            previousNode->Next = newNode;
        }
    }
    m_size += 1;
}
//

template<typename T>
void List<T>::delete_value(const T value) {

    if (is_empty()) {
        std::cout << "la liste est vide.\n";
    } else if (!find_value(value)) {
        std::cout << "l'element n'est pas dans la liste.\n";
    } else {
        Node<T>* newNode = new Node<T>();
        newNode->value = value;

        size_t position = find_position(newNode);
        Node<T>* previousNode = find_previous_and_next_node(position - 1);

        previousNode->Next = newNode->Next;
        delete newNode;
    }
}

//
template<typename T>
void List<T>::delete_value(const unsigned int position) {

    Node<T>* previousNode = find_previous_and_next_node(position - 1);
    Node<T>* currentNode = find_previous_and_next_node(position);

    previousNode->Next = currentNode->Next;
    delete currentNode;
    m_size -= 1;
}
//
template<typename T>
void List<T>::displayList() const {
    displayNode(m_root);
}
//
template<typename T>
bool List<T>::find_value(const T value) const {

    Node<T>* someNode = new Node<T>();

    someNode->value = value;
    someNode->Next = nullptr;

    return searchNode(someNode);
}

////////////////////////////////////////////////////
//                                                //
//              private methods.                  //
//                                                //
////////////////////////////////////////////////////

template<typename T>
bool List<T>::is_empty() const {
    return m_root == nullptr;
}
//
template<typename T>
void List<T>::displayNode(Node<T>* currentNode) const {

    if (currentNode == nullptr) {
        std::cout << "0x000\n";
    } else {
        std::cout << "[" << currentNode->value << "]->";
        displayNode(currentNode->Next);
    }
}
//

//b
template<typename T>
unsigned int List<T>::getSize() const {
    return m_size;
}
//
template<typename T>
bool List<T>::searchNode(Node<T>* someNode) const {

    if (is_empty()) {
        return false;
    } else {
        Node<T> *tmp = m_root;

        while (tmp != nullptr) {
            if (tmp->value == someNode->value) {
                return true;
            }
            tmp = tmp->Next;
        }
        return false;
    }
}
//

//
template<typename T>
Node<T>* List<T>::find_previous_and_next_node(const int position) const {

    Node<T>* tmp = m_root;
    int i = 1;
    while(i < position) {
        tmp = tmp->Next;
        i++;
    }
    return tmp;
}

//
template<typename T>
size_t List<T>::find_position(Node<T>* myNode) {

    Node<T>* tmp = m_root;
    size_t npos = 1;

    while (tmp != nullptr) {
        if (tmp->value == myNode->value) {
            return npos;
        }
        npos++;
        tmp = tmp->Next;
    }
    return SIZE_MAX;
}

#endif
