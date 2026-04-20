#include<iostream>
#include <vector>
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

// Function to traverse a linked list
void traverseLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " " ;
        temp = temp->next ;
    }
}

Node* removeNthNodefromEnd(Node* head, int n){
    if(head == nullptr) return nullptr;

    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead safely
    for(int i = 0; i < n; i++){
        if(fast == nullptr){
            cout << "Out Of Bound Input" << endl;
            return head;
        }
        fast = fast->next;
    }

    // If fast becomes NULL → delete head
    if(fast == nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Move both pointers
    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    Node* dltNode = slow->next;
    slow->next = dltNode->next;
    delete dltNode;

    return head;
}

int main(){
    vector<int> vec ;
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(0);

    Node* head = convertArrayToLL(vec);

    // Traversing a Linked List
    cout << "Original LL : " ;
    traverseLL(head);
    cout << endl ;

    // Traversing after deleting nth node from the end
    head = removeNthNodefromEnd(head,8);
    cout << "LL after node deletion : " ;
    traverseLL(head) ;
    cout << endl ;
}

/*
🧠 Thought Process (Very Simple)
🔹 1. Understand the problem
👉 Remove nth node from end

🔹 2. Idea comes
👉 Instead of counting length:
➡️ Use two pointers (fast & slow)

🔹 3. Create a gap of n
fast moves n steps ahead
👉 Now:
distance between fast and slow = n

🔹 4. Move both together
while(fast reaches end)
👉 When fast reaches last node:
slow is just before the node to delete

🔹 5. Handle edge case
👉 If fast becomes NULL after moving n steps:
Delete head node

🔹 6. Delete node
slow->next = slow->next->next;
🔁 Flow Example
1 → 2 → 3 → 4 → 5
n = 2
fast after n steps → 3  
move both:
fast: 3 → 4 → 5  
slow: 1 → 2 → 3  
Delete → 4

⚠️ Special Remarks (Important)
🔸 1. One-pass solution
👉 No need to calculate length
👉 Time = O(n) ✅

🔸 2. Space efficient
👉 No extra memory
👉 Space = O(1)

🔸 3. Key trick
👉 Maintain gap of n nodes

🔸 4. Important edge cases
n == length → delete head
n > length → invalid input
single node list

🔸 5. Pointer safety
👉 Always check before moving:
if(fast == nullptr)

🔸 6. No restarting traversal
👉 Both pointers move forward only once
👉 Still one traversal

🧾 One-Line Revision
👉 Keep fast n steps ahead, then move both to find node to delete.
🚀 Ultra Short Memory Trick
Gap n → move together → delete
*/