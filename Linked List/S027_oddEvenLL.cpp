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
    Node* ans = new Node(-1) ; // dummy Node to store ans LL
    Node* temp = ans; 
    while(odd != nullptr){
        Node* newNode = new Node(odd->data);
        temp->next = newNode ;
        temp = temp->next ;

        if(odd->next)
            odd = odd->next->next;
        else
            odd = nullptr;
    }
    while(even != nullptr){
        Node* newNode = new Node(even->data);
        temp->next = newNode ;
        temp = temp->next ;

        if(even->next)
            even = even->next->next;
        else
            even = nullptr;
    }

    return ans->next ;
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
📌 Approach (Step-by-Step)
🔹 1. Handle edge case
If head == nullptr → return nullptr

🔹 2. Initialize pointers
odd = head
even = head->next
odd → points to 1st node
even → points to 2nd node

🔹 3. Create dummy node
ans = new Node(-1)
temp = ans
Used to build result list easily

🔹 4. Traverse odd indexed nodes
Loop through: 1 → 3 → 5 → ...
Add each node’s data into new list
temp->next = new Node(odd->data)
temp = temp->next
Move pointer safely:
if(odd->next)
    odd = odd->next->next;
else
    odd = nullptr;

🔹 5. Traverse even indexed nodes
Loop through: 2 → 4 → 6 → ...
Append after odd nodes

🔹 6. Return result
return ans->next;
Skip dummy node
🧠 Flow Summary
Original: 2 → 4 → 6 → 8 → 10 → 12

Odd: 2 → 6 → 10  
Even: 4 → 8 → 12  
Result: 2 → 6 → 10 → 4 → 8 → 12

⚠️ Special Remarks (VERY IMPORTANT)
🔸 1. Always check before next->next
Prevents segmentation fault
if(ptr->next)

🔸 2. Dummy node simplifies insertion
No need to handle first node separately
Cleaner logic

🔸 3. Extra space used
New nodes are created → O(n) space
Not optimal for interviews

🔸 4. Original list remains unchanged
You are not modifying input list
You are creating a new list

🔸 5. Time Complexity
Traversing twice → O(n)

🔸 6. Works for all cases
Even length ✔
Odd length ✔
Single node ✔
Empty list ✔

🔸 7. Interview expectation
This is valid but not optimal

Better approach:
👉 Rearrange pointers (O(1) space)
🧾 One-Line Revision
👉 Traverse odd and even positions separately and append them into a new list.
*/