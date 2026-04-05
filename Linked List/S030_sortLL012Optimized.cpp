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
 
Node* sort012(Node* head){
    if(head == nullptr) return nullptr ;

    Node* list0 = new Node(-1); // dummyNodes
    Node* list1 = new Node(-1); // dummyNodes
    Node* list2 = new Node(-1); // dummyNodes
    Node* mover0 = list0;
    Node* mover1 = list1;
    Node* mover2 = list2;

    Node* temp = head ;
    while(temp){
        // Creates list0
        if(temp->data == 0){
            mover0->next = temp;
            mover0 = mover0->next ;
        }

        // Creates list1
        else if(temp->data == 1){
            mover1->next = temp;
            mover1 = mover1->next ;
        }
        
        // Creates list2
        else {
            mover2->next = temp;
            mover2 = mover2->next ;
        }
        temp = temp->next ;
    }
    // connect lists
    mover0->next = list1->next ? list1->next : list2->next;
    mover1->next = list2->next;
    mover2->next = nullptr;

    return list0->next;
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

    // Traversing sorted LL
    cout << "Sorted LL : " ;
    head = sort012(head) ;
    traverseLL(head) ;
    cout << endl ;
}

/*
🧠 Thought Process (Very Simple)
🔹 1. Understand problem
👉 List has only:
0, 1, 2
👉 Need:
All 0 → then 1 → then 2

🔹 2. Idea comes
👉 Instead of sorting:
➡️ Group similar values together

🔹 3. How to group?
👉 Create 3 separate lists:
list0 → for 0s  
list1 → for 1s  
list2 → for 2s  

🔹 4. Traverse once
while(temp)
👉 For each node:
If 0 → attach to list0
If 1 → attach to list1
If 2 → attach to list2

🔹 5. Important thinking
👉 We are not creating new nodes
👉 We are just rearranging links

🔹 6. Connect lists
0-list → 1-list → 2-list

🔹 7. Return final head
return list0->next;
🔁 Flow Example
Original: 0 → 2 → 1 → 2 → 0 → 0
After grouping:
list0: 0 → 0 → 0  
list1: 1  
list2: 2 → 2  
Final:
0 → 0 → 0 → 1 → 2 → 2

⚠️ Special Remarks (Important)
🔸 1. One-pass solution
👉 Only one traversal
👉 Time = O(n) ✅

🔸 2. Constant space
👉 Only few pointers used
👉 Space = O(1) ✅

🔸 3. No data modification
👉 You didn’t change values
👉 Only links changed (better approach)

🔸 4. Dummy nodes simplify logic
👉 Avoid edge cases
👉 Clean connections

🔸 5. Important edge handling
mover0->next = list1->next ? list1->next : list2->next;
👉 Handles case when no 1s exist

🔸 6. Proper termination
mover2->next = nullptr;
👉 Prevents unwanted links

🔸 7. Stable ordering
👉 Relative order of 0s, 1s, 2s is preserved

🧾 One-Line Revision
👉 Split into 3 lists (0,1,2) and connect them in one pass.
*/