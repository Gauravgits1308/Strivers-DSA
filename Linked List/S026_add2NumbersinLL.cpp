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

Node* add2Numbers(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;

    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode ;

    while(temp1 != nullptr || temp2 != nullptr || carry){
        int sum = carry ;

        if(temp1) {
            sum = sum + temp1->data ;
            temp1 = temp1->next ;
        }
        if(temp2) {
            sum = sum + temp2->data ;
            temp2 = temp2->next ;
        }

        Node* newNode = new Node(sum%10);
        curr->next = newNode ;
        carry = (sum/10);

        curr = curr->next ;
    }
    return (dummyNode->next) ;
}
int main(){
    vector<int> num1 ;
    vector<int> num2 ;
    num1.push_back(2);
    num1.push_back(4);
    num2.push_back(6);
    num2.push_back(8);
    num2.push_back(1);

    Node* head1 = convertArrayToLL(num1);
    Node* head2 = convertArrayToLL(num2);
    Node* ansNode = nullptr ;

    // Traversing Number1
    cout << "Number1 : " ;
    traverseLL(head1);
    cout << endl ;

    // Traversing Number2
    cout << "Number2 : " ;
    traverseLL(head2);
    cout << endl ;

    // Final Sum of two Numbers
    cout << "Sum is : " ;
    ansNode = add2Numbers(head1,head2);
    traverseLL(ansNode);
    cout << endl;

}

/*
👉 Add two numbers stored in linked lists (digit by digit)

Example:
2 → 4   (represents 42)
6 → 8 → 1   (represents 186)

Result: 8 → 2 → 2   (represents 228)

⚙️ Core Idea (Very Important)
👉 Just like normal addition on paper

  42
+186
----
 228

We:
Add digits
Keep carry
Move forward

🔁 Algorithm (Step-by-Step)
1. Initialize pointers
temp1 = head1
temp2 = head2
carry = 0

2. Create dummy node
dummy → helps avoid edge cases
curr → used to build answer

3. Loop until everything is processed
while(temp1 OR temp2 OR carry)

👉 Why carry?
Because last addition may create extra digit (like 9+1=10)

4. Calculate sum
sum = carry

if(temp1 exists) → add temp1->data
if(temp2 exists) → add temp2->data

5. Create new node
digit = sum % 10
carry = sum / 10

👉 Example:

sum = 12 → digit = 2, carry = 1

6. Attach node to result
curr->next = new Node(digit)
curr = curr->next

7. Move pointers
if(temp1) temp1 = temp1->next
if(temp2) temp2 = temp2->next

8. Return result
return dummy->next

🔄 Dry Run (Quick Revision)
temp1: 2 → 4
temp2: 6 → 8 → 1
Step	Sum	Digit	Carry
2+6	8	8	0
4+8	12	2	1
0+1+carry	2	2	0

Result:
8 → 2 → 2

📌 Why we use dummyNode
🔹 1. Avoid handling first node separately
Without dummy → need special if(head == NULL)
With dummy → same logic for all nodes

🔹 2. Simplifies code
No extra conditions
Clean and uniform loop

🔹 3. Prevents bugs
No risk of:
uninitialized head
null pointer errors in first insertion

🔹 4. Easy insertion
curr->next = new Node(value);
curr = curr->next;

👉 Works for every node (including first)

🔹 5. Always have a starting pointer
dummyNode acts as a fixed starting point
We never lose reference to head

🔹 6. Final result is easy
return dummyNode->next;

👉 Skip dummy, return actual list

🔹 7. Improves readability (Interview important)
Code looks clean and professional
Easy to understand and debug
🧾 One-Line Revision

👉 Dummy node removes special handling of head and makes insertion uniform.
*/