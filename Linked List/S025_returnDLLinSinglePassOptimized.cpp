#include<iostream>
#include<stack>
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

Node* reverseDLL(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* last = nullptr;
    Node* curr = head;
    while(curr != nullptr){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }
    return last->prev;
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

    head = reverseDLL(head);
    cout << "Printing DLL after reversing : ";
    traverseDLL(head);
    cout << endl ;
}