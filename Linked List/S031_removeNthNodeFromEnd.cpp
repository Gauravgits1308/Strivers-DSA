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
    int length = 0 ;
    Node* temp = head ;
    while(temp){
        length++;
        temp = temp->next ;
    }

    if(n < 0 || n > length){
        cout << "Out Of Bound Input" << endl ;
        return head ;
    }

    int position = length-n+1 ;
    if(position == 1){
        Node* temp1 = head ;
        head = head->next ;
        delete temp1 ;
        return head ;
    }

    Node* prev = head ;
    int itr = 0 ;
    while(itr < position-2){
        prev = prev->next ;
        itr++;
    }
    Node* curr = prev->next ;
    prev->next = prev->next->next ;
    delete curr ;
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

    // Traversing after deleting nth node from the end
    head = removeNthNodefromEnd(head,8);
    cout << "LL after node deletion : " ;
    traverseLL(head) ;
    cout << endl ;
}

/*
🧠 Thought Process (Simple)
🔹 1. Find length
while(temp){
    length++;
}
👉 Now you know total nodes

🔹 2. Validate input
if(n < 0 || n > length)
👉 Prevents invalid deletion
⚠️ Small fix:
👉 Should be:
if(n <= 0 || n > length)

🔹 3. Convert position
position = length - n + 1
👉 Now problem becomes:
Delete kth node from start

🔹 4. Handle head deletion
if(position == 1)
👉 Special case

🔹 5. Reach previous node
while(itr < position - 2)
👉 Stop at node before target

🔹 6. Delete node
prev->next = curr->next;
delete curr;

⚠️ Special Remarks
🔸 1. Two-pass solution
Pass 1 → find length
Pass 2 → delete node
👉 Time = O(n)

🔸 2. Space efficient
👉 No extra memory
👉 Space = O(1)

🔸 3. Handles edge cases
✔ Deleting head
✔ Out of bound input

🔸 4. Your test case
removeNthNodefromEnd(head, 8);
👉 Length = 6
👉 n = 8 → invalid

✔ Output:
Out Of Bound Input

🔸 5. Small improvement
Instead of:
prev->next = prev->next->next;

Better:
prev->next = curr->next;
(more readable)

🚀 Is it optimized?
Aspect	Status
Time	O(n) ✅
Space	O(1) ✅
Passes	2 ❗
Interview optimal	❌
*/