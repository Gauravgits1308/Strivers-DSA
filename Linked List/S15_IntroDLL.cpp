#include<iostream>
using namespace std ;
class Node{
    public:
    int data ;
    Node* next ;
    Node* prev ;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr ;
    }
};

int main(){
    Node* newNode = new Node(12);
    cout << newNode->data << endl ;
    cout << newNode->next << endl ;
    cout << newNode->prev << endl ;
}