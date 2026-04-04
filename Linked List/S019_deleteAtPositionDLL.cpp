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
Node* deleteAt(Node* head, int position){
    // Case 1: Empty list
    if(head == nullptr) return nullptr;

    // Case 2: Delete head
    if(position == 1){
        Node* temp = head;
        head = head->next;

        if(head != nullptr)
            head->prev = nullptr;

        delete temp;
        return head;
    }

    Node* temp = head;
    int itr = 1;

    // Traverse to the given position
    while(temp != nullptr && itr < position){
        temp = temp->next;
        itr++;
    }

    // Case 3: Position out of bounds
    if(temp == nullptr){
        cout << "Position out of range" << endl;
        return head;
    }

    // Case 4: Tail node
    if(temp->next == nullptr){
        temp->prev->next = nullptr;
        delete temp;
        return head;
    }

    // Case 5: Middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

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

    Node* head = arrayToDLL(vec);

    // Printing DLL
    cout << "Printing original DLL : ";
    traverseDLL(head);
    cout << endl ;

    // Tail Deletion
    head = deleteAt(head,5);
    cout << "Printing DLL after given position deletion : ";
    traverseDLL(head);
    cout << endl ;


}