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

    Node* temp = head ;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    while(temp){
        if(temp->data == 0) count0++ ;
        if(temp->data == 1) count1++ ;
        if(temp->data == 2) count2++ ;
        temp = temp->next ;
    }
    Node* mover = head ;
    while(count0 > 0){
        mover->data = 0 ;
        mover = mover->next ;
        count0-- ;
    }

    while(count1 > 0){
        mover->data = 1 ;
        mover = mover->next ;
        count1-- ;
    }

    while(count2 > 0){
        mover->data = 2 ;
        mover = mover->next ;
        count2-- ;
    }

    return head ;
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
🧠 Thought Process (How we think)
🔹 1. Understand the problem
👉 Linked list contains only:
0, 1, 2
👉 We need:
All 0 → then 1 → then 2

🔹 2. Idea comes (simplest approach)
👉 Instead of sorting like arrays or changing links:
➡️ Just count how many 0s, 1s, 2s are there

🔹 3. First traversal (counting)
count0, count1, count2
👉 Traverse list:
If 0 → count0++
If 1 → count1++
If 2 → count2++

🔹 4. Second traversal (overwrite data)
👉 Now we know:
how many 0s, 1s, 2s needed
So:
Fill first count0 nodes with 0
Then count1 nodes with 1
Then count2 nodes with 2

🔹 5. No need to change links
👉 Just change values:
mover->data = 0 / 1 / 2
🔁 Flow Example
Original: 0 → 2 → 1 → 2 → 0 → 0
Count:
0 → 3 times  
1 → 1 time  
2 → 2 times  
Rewrite:
0 → 0 → 0 → 1 → 2 → 2

⚠️ Special Remarks (Important)
🔸 1. Two-pass solution
First pass → count
Second pass → overwrite
👉 Time = O(n)

🔸 2. Space efficient
👉 No extra data structure
👉 Space = O(1) ✅

🔸 3. Does NOT change structure
👉 Only data changes
👉 Links remain same

🔸 4. Very simple and safe
👉 No pointer manipulation
👉 No risk of breaking list

🔸 5. Works only for 0,1,2
👉 This approach is special case
👉 Not general sorting

🔸 6. Best for beginners
👉 Easy to implement
👉 Easy to debug

🔸 7. Interview insight
👉 This is good solution, but:

Better solution:
➡️ Dutch National Flag (link-based, 1-pass)
🧾 One-Line Revision
👉 Count 0s, 1s, 2s and overwrite the list.
*/