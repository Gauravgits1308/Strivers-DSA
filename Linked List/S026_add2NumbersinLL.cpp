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