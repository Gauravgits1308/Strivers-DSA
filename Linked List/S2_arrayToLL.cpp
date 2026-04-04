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
int main(){
    vector<int> vec ;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);

    Node* ans = convertArrayToLL(vec);
    cout << ans->data << endl ;
}

/*
Important Notes (Array → Linked List)
Converts a vector<int> into a singly linked list.
Head pointer stores address of first node and should never be moved.
Mover pointer is used to traverse and build the linked list.

Initialize mover as:

Node* mover = head;

Do NOT create a separate node for mover:

// Wrong
Node* mover = new Node(vec[0]);

Each element is converted into a node:

Node* temp = new Node(vec[i]);

Link nodes using:

mover->next = temp;

Move the mover pointer forward:

mover = temp;

Loop starts from index 1 because first element is already used for head:

for(int i = 1; i < vec.size(); i++)
Handle empty vector case:
if(vec.size() == 0) return nullptr;
Time Complexity: O(n)
Space Complexity: O(n)
Nodes are created in heap memory using new.
Memory is not freed (no delete) → possible memory leak.
Traversal for printing:
while(ans != nullptr){
    cout << ans->data << " ";
    ans = ans->next;
}
🎯 Key Takeaways
Head remains fixed
Mover keeps moving
Use next to connect nodes
Always handle edge cases
Avoid creating duplicate head nodes
*/