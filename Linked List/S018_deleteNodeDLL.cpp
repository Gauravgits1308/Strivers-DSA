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

// Function to delete a given node
Node* deleteNode(Node* head, int element){
    // Case 1: Empty list
    if(head == nullptr) return nullptr;

    // Case 2: Element is at head
    if(head->data == element){
        Node* temp = head;          // store current head
        head = head->next;          // move head forward

        // update prev pointer of new head
        if(head != nullptr) 
            head->prev = nullptr;

        delete temp;                // delete old head
        return head;
    }

    Node* temp = head;

    // Traverse to find the element
    while(temp != nullptr && temp->data != element){
        temp = temp->next;
    }

    // Case 3: Element not found
    if(temp == nullptr){
        cout << "Element " << element << " Not Found" << endl;
        return head;
    }

    // Case 4: Element is at tail
    if(temp->next == nullptr){
        temp->prev->next = nullptr; // unlink last node
        delete temp;                // delete tail
        return head;
    }

    // Case 5: Element is in middle
    temp->prev->next = temp->next;  // link previous to next
    temp->next->prev = temp->prev;  // link next to previous

    delete temp;                    // delete node

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
    head = deleteNode(head,10);
    cout << "Printing DLL after given node deletion : ";
    traverseDLL(head);
    cout << endl ;


}