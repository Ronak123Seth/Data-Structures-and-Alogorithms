#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int value){
            this->data=value;
            this->next=NULL;
        }
        void insertAt(Node* &head,int position,int value){
            Node* temp = head;
            int count=1;
            while(count<position-1){
                temp = temp->next;
                count++;
            }
            Node* insertNode = new Node(value);
            insertNode->next = temp->next;
            temp->next=insertNode;
        }
        Node* reverse(Node* &head,int k){
            Node* prev = NULL;
            Node* next = NULL;
            Node* curr = head;
            int count = 0;
            while(curr != NULL && count<k){
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if(curr != NULL){
                head -> next = reverse(next,k);
            }
            head = prev;
            return head;
        }
        void display(Node* &head){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main(){
    Node *n1=new Node(4);
    Node* head=n1;
    n1->insertAt(head,2,10);
    n1->insertAt(head,3,11);
    n1->insertAt(head,4,100);
    n1->insertAt(head,5,199);
    n1->insertAt(head,6,101);
    n1->display(head);
    n1->reverse(head,3);
    n1->display(head);
}