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

// Function to delete node from a given position
Node* deleteAt(Node* head,int position){
    if(head == nullptr) return nullptr;

    // delete head case
    if(position == 1){
        Node* temp = head ;
        head = head -> next;
        delete temp ;
        return head ;
    }

    Node* prev = head ;
    int itr = 0;
    while(itr < (position-2)){
        if(prev->next == nullptr) return head; // out of bounds
        prev = prev->next;
        itr++;
    }

    if(prev->next == nullptr) return head; // nothing to delete
    Node* forward = prev->next->next ;
    Node* target = prev->next ; // target node
    prev->next = forward;

    delete target ;
    return head ;
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
    head = deleteAt(head,3);
    cout << "The linked list after deletion at position3 : " ;
    traverseLL(head);
    cout << endl ;
    
}