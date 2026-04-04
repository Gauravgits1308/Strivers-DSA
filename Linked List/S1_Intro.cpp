#include<iostream>
using namespace std;

// Created Node Data Type
class Node{
    public:
    int data ;
    Node* next ;

    // Constructor
    Node(int num){
        this->data = num ;
        this->next = nullptr ;
    }
};

int main(){
    Node* n1 = new Node(10);
    cout << n1->data << endl ;
    cout << n1->next << endl ;
}