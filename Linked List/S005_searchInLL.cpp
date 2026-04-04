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

// Function to find an element in Linked List
bool isFound(Node* head,int val){
    Node* temp = head ;
    while(temp != nullptr){
        if(temp->data == val) return true ;
        temp = temp->next ;
    }
    return false ;
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

    // Searching an element in Linked List
    cout << "The Linked List contains 7 : " << isFound(head,7) << endl;
    cout << "The Linked List contains 4 : " << isFound(head,4) << endl;

    
}