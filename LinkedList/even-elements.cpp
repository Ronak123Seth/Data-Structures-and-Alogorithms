#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        void insertAtHead(Node* &head,int value){
            Node* temp = new Node(value);
            temp->next=head;
            head=temp;
        }
        void even_elements(Node* &head){
            Node* temp=head;
            while(temp != NULL){
                if(temp->data % 2 == 0){
                    cout<<temp->data<<" ";
                }
                temp=temp->next;
            }
        }
        void print(Node* &head){
            Node* temp=head;
            while(temp != NULL){
                 cout<<temp->data<<" ";
                temp = temp->next;  
            }
            cout<<endl;
        }
};
int main(){
    Node* n1 = new Node(5);
    Node* head=n1;
    n1->insertAtHead(head,10);
    n1->insertAtHead(head,17);
    n1->insertAtHead(head,18);
    n1->insertAtHead(head,20);
    n1->insertAtHead(head,11);
    n1->print(head);
    n1->even_elements(head);
}