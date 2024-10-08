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
        void reverse(Node* &head, Node* curr, Node* prev) {
            if (curr == NULL) {
                head = prev;
                return;
            }

            Node* forward = curr->next;
            curr->next = prev;

            reverse(head, forward, curr); 
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
    n1->display(head);
    n1->reverse(head,head,NULL);
    n1->display(head);
}