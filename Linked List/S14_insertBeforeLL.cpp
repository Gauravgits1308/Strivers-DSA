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

// Function to convert an array to LL
Node* convertArrayToLL(vector<int> &vec){
    Node* head = new Node(vec[0]);
    Node* mover = head;
    for(int i = 1 ; i < vec.size() ; i++){
        Node* temp = new Node(vec[i]);
        mover->next = temp ;
        mover = mover->next ;
    }
    return head ;
}

// Function to traverse a linked list
void traverseLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " " ;
        temp = temp->next ;
    }
}

// Function to insert a node before given value
Node* insertBefore(Node* head, int before, int value){
    if(head == nullptr) return nullptr; // empty list

    // insert before head
    if(head->data == before){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* temp = head->next;
    Node* prev = head;

    while(temp != nullptr && temp->data != before){
        temp = temp->next;
        prev = prev->next;
    }

    // case when element not found
    if(temp == nullptr){
        cout << "Element " << before << " Not Found" << endl;
        return head;
    }

    Node* newNode = new Node(value);
    newNode->next = temp;
    prev->next = newNode;

    return head;
}

int main(){
    vector<int> vec ;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);

    Node* head = convertArrayToLL(vec);
    cout << "Printing head of Linked List : " << head->data << endl ;

    // Traversing a Linked List
    cout << "The Linked List is : " ;
    traverseLL(head);
    cout << endl;

    // Deleting node at position 3
    head = insertBefore(head,10,0);
    cout << "The linked list after insertion of an element at given position : " ;
    traverseLL(head);
    cout << endl ;
    
}