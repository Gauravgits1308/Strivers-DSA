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

// Function to delete a given node
Node* deleteNode(Node* head,int element){
    if(head == nullptr) return nullptr; // No element in linked list

    // When head is the element 
    if(head->data == element){
        Node* temp = head;
        head = head -> next ;
        delete temp ;
        return head ;
    }

    Node* temp = head->next ;
    Node* prev = head ;
    while(temp != nullptr && temp->data != element){
        temp = temp->next;
        prev = prev->next;
    }

    // Case when element is not present in linked list
    if(temp == nullptr) {
        cout << "Element " << element << " Not Found" << endl;
        return head;
    }

    prev->next = prev->next->next ;
    delete temp;
    return head;
}

int main(){
    vector<int> vec ;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);
    vec.push_back(21);
    vec.push_back(43);
    vec.push_back(64);
    vec.push_back(85);
    vec.push_back(106);

    Node* head = convertArrayToLL(vec);
    cout << "Printing head of Linked List : " << head->data << endl ;

    // Traversing a Linked List
    cout << "The Linked List is : " ;
    traverseLL(head);
    cout << endl;

    // Deleting tailof linked list
    head = deleteNode(head,106);
    cout << "The linked list after element deletion : " ;
    traverseLL(head);
    cout << endl ;

}