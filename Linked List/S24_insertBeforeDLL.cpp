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

// Convert array to DLL
Node* arrayToDLL(vector<int> &vec){
    Node* head = new Node(vec[0]);
    Node* temp = head ;
    for(int i = 1 ; i < vec.size() ; i++){
        Node* newNode = new Node(vec[i]);
        temp->next = newNode;
        newNode->prev = temp ;
        temp = temp->next;
    }
    return head ;
}

// Traversing DLL
void traverseDLL(Node* head){
    Node* temp = head ;
    while(temp != nullptr){
        cout << temp->data << " " ;
        temp = temp->next;
    }
}

// Function to insert At tail
Node* insertBeforeValue(Node* head, int key, int val) {
    Node* newNode = new Node(val);

    // Case 1: empty list
    if(head == NULL) return head;

    Node* curr = head;

    // find the node with given key
    while(curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    // Case 2: key not found
    if(curr == NULL) return head;

    // Case 3: insert before head
    if(curr == head) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    // Case 4: insert in middle
    Node* prevNode = curr->prev;

    prevNode->next = newNode;
    newNode->prev = prevNode;

    newNode->next = curr;
    curr->prev = newNode;

    return head;
}

int main(){
    vector<int> vec ;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);

    Node* head = arrayToDLL(vec);

    // Printing DLL
    cout << "Printing original DLL : ";
    traverseDLL(head);
    cout << endl ;

    // Tail Deletion
    head = insertBeforeValue(head,4,45);
    cout << "Printing DLL after node insertion at head : ";
    traverseDLL(head);
    cout << endl ;
}