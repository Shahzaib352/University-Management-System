#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include"Node.h"
using namespace std;

template <typename T>
class SinglyLinkedList{
    private:
    // Attributes
    Node<T>* Head;
    Node<T>* Tail;

    public:
    // Constructor
    SinglyLinkedList() : Head(nullptr) {}

    // Method
    Node<T>* getHead() const {return Head;}

    T get(const T& target) {
        Node<T>* temp = Head; 
        while (temp != nullptr) {
            if (temp->data == target) { 
                return temp->data; // Return the found data
            }
            temp = temp->next;
        }
        throw runtime_error("Target not found!"); // Throw an exception if not found
    }


    void insert(T data){
        Node<T>* new_node = new Node(data);
        // If list is empty
        if(Head == nullptr){
            Head = new_node;
            Tail = new_node;
        }
        else{
            Tail->next = new_node;
            Tail = new_node;
        }
    }

    void display() const {
        // If List is empty
        if(Head == nullptr){
            cout << "Nothing Found!" << endl;
        }
        else{
            Node<T>* temp = Head;
            while(temp != nullptr){
                cout << temp->data << endl ;
                temp = temp->next;
            }
        }  
    }

    void remove(const T& TargetData) {
        // If list is empty
        if (Head == nullptr) {
            cout << "Empty!" << endl;
            return;
        }

        // If deletion at head
        if (Head->data == TargetData) {
            Node<T>* temp = Head;
            Head = Head->next;
            if (Head == nullptr) { // If the list is now empty
                Tail = nullptr;
            }
            delete temp;
            cout << "Removed successfully." << endl;
            return;
        }

        // If deletion at any other place
        Node<T>* temp = Head;
        Node<T>* prev = nullptr;
        while (temp != nullptr) {
            if (temp->data == TargetData) {
                prev->next = temp->next; // Skip the node to delete
                if (temp == Tail) { // Update Tail if needed
                    Tail = prev;
                }
                delete temp;
                cout << "Removed successfully." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        // If no match found
        cout << "No match found." << endl;
    }


    void search(const T& TargetedData){
        Node<T>* temp = Head;
        // if list is empty
        if(Head == nullptr){
            cout << "Empty!" << endl;
            return;
        }

        // If not empty
        while(temp != nullptr){
            if(temp->data == TargetedData){
                cout << temp->data << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No match found." << endl;
    }

     update(const T& OldData, const T& NewData){
        Node<T>* temp = Head;
        // if list is empty
        if(Head == nullptr){
            cout << "Empty!" << endl;
            return;
        }

        // If not empty
        while(temp != nullptr){
            if(temp->data == OldData){
                temp->data = NewData; // Update the data
                cout << "Updated successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No match found." << endl;
    }
    
    bool find(const T& TargetedData){
        Node<T>* temp = Head;
        while(temp != nullptr){
            if(temp->data == TargetedData){
                return true;
            }
            temp = temp->next;
        }
        return false
    } 
};

#endif