#include<iostream>
#include<vector>
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

Node* oddEven(Node* head){
    if(head == nullptr) return nullptr;

    Node* odd = head ;
    Node* even = head->next ;
    Node* evenHead = even ; // Used to link odd and even created LL
    while(even != nullptr && even->next != nullptr){
        odd->next = odd->next->next ;
        odd = odd->next ;

        even->next = even->next->next ;
        even = even->next ;
    }
    odd->next = evenHead ;
    return head ;

}
int main(){
    vector<int> vec ;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);
    vec.push_back(12);

    Node* head = convertArrayToLL(vec);

    cout << "Original LL : " ;
    traverseLL(head);
    cout << endl ;

    cout << "Odd Even LL : " ;
    head = oddEven(head) ;
    traverseLL(head) ;
    cout << endl ;
}
/*
🧠 Thought Process (Simple Thinking)
🔹 1. Understand the goal
👉 We want:
All odd position nodes → first  
Then even position nodes
Example:
2 → 4 → 6 → 8 → 10 → 12
Odd: 2, 6, 10  
Even: 4, 8, 12  
Result: 2 → 6 → 10 → 4 → 8 → 12

🔹 2. Idea comes
👉 Instead of creating new list,
➡️ Why not rearrange links?

🔹 3. Use two pointers
odd = head
even = head->next
👉 Now we can track:
odd nodes
even nodes separately

🔹 4. Store even starting point
evenHead = even
👉 So we can attach it later

🔹 5. Skip nodes (main trick 🔥)
odd->next = odd->next->next;
👉 Connect odd to next odd (skip even)
even->next = even->next->next;
👉 Connect even to next even (skip odd)

🔹 6. Move pointers
odd = odd->next;
even = even->next;
👉 Continue process

🔹 7. Join both lists
odd->next = evenHead;
👉 Attach even list after odd list

⚠️ Special Remarks (Important)

🔸 1. Loop condition is VERY important
while(even != nullptr && even->next != nullptr)
👉 Prevents crash (safe access)

🔸 2. No extra space used
👉 Everything done in same list
👉 Space = O(1) ✅

🔸 3. Time complexity
👉 One traversal → O(n)

🔸 4. Original nodes reused
👉 No new nodes created
👉 Just links changed

🔸 5. Core trick
👉 Skip one node to group same positions

🔸 6. Most important line
odd->next = odd->next->next;
👉 This is the heart of solution

🧾 One-Line Revision
👉 Skip alternate nodes to form odd and even chains, then connect them.

🚀 Ultra Short Memory Trick
Odd skips even  
Even skips odd  
Join both
*/