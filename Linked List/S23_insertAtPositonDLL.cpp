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
Node* insertAtPosition(Node* head, int position,int value){
    Node *newNode = new Node(value);

    // When insertion is done at head
    if(position == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        return head;
    }

    // Other Cases
    int itr = 0 ;
    Node* temp = head->next;
    Node* before = head;
    while(itr < (position-2)){
        before = before->next ;
        temp = temp->next ;
        itr++;
    }
    
    before->next = newNode ;
    newNode->prev = before ;
    newNode->next = temp ;

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
    head = insertAtPosition(head,1,45);
    cout << "Printing DLL after node insertion at head : ";
    traverseDLL(head);
    cout << endl ;
}