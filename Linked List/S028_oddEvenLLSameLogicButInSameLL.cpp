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
    vector<int> ans ;
    while(odd != nullptr){
        ans.push_back(odd->data);
        if(odd->next)
            odd = odd->next->next;
        else
            odd = nullptr; 
    }
    while(even != nullptr){
       ans.push_back(even->data);
        if(even->next)
            even = even->next->next;
        else
            even = nullptr;
    }

    Node* temp = head ;
    int i = 0 ;
    while(i < ans.size()){
        temp->data = ans[i];
        temp = temp->next ;
        i++ ;
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
    // vec.push_back(12);

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
📌 Approach (Step-by-Step)
🔹 1. Handle edge case
If head == nullptr → return nullptr

🔹 2. Initialize pointers
odd = head
even = head->next
odd → visits 1st, 3rd, 5th nodes
even → visits 2nd, 4th, 6th nodes

🔹 3. Store values in array
vector<int> ans;

🔹 4. Traverse odd positions
Add values of odd index nodes
ans.push_back(odd->data);
Move safely:
if(odd->next)
    odd = odd->next->next;
else
    odd = nullptr;

🔹 5. Traverse even positions
Add values of even index nodes
ans.push_back(even->data);

🔹 6. Update original linked list
Traverse list again
Replace values using array
temp->data = ans[i];

🔹 7. Return head
return head;
🧠 Flow Summary
Original: 2 → 4 → 6 → 8 → 10

Step 1 (odd): 2, 6, 10  
Step 2 (even): 4, 8  
Array: [2, 6, 10, 4, 8]
Final LL: 2 → 6 → 10 → 4 → 8

⚠️ Special Remarks (IMPORTANT)
🔸 1. Uses extra space
Vector stores all values → O(n) space

🔸 2. Does NOT change structure
Only modifies data
Links (next) remain same

🔸 3. Safer than pointer manipulation
No risk of breaking links
Good for beginners

🔸 4. Two traversals
1st → fill vector
2nd → update list
👉 Time = O(n)

🔸 5. Must handle next->next carefully
You correctly used:
if(ptr->next)
✔ prevents crash

🔸 6. Works for all cases
Odd length ✔
Even length ✔
Single node ✔

🔸 7. Not optimal for interviews
Interview expects:
👉 O(1) space (in-place solution)

🔸 8. Advantage over your previous method
Method	Space	Modifies list
New LL (previous)	O(n)	No
Vector (this one)	O(n)	Yes
In-place (best)	O(1)	Yes
🧾 One-Line Revision
👉 Store odd and even node values in array, then overwrite the linked list.
*/