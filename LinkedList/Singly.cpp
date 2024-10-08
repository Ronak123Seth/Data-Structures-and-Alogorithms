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
        void length(Node* &head){
            Node* temp = head;
            int c=0;
            while(temp != NULL){
                ++c;
                temp=temp->next;
            }
            cout<<"Length of linked list is "<<c<<endl;
        }
        void insertAtHead(Node* &head,int value){
            Node* temp = new Node(value);
            temp->next=head;
            head=temp;
        }
        void insertAtTail(Node* &tail,int value){
            Node* temp = new Node(value);
            tail->next = temp;
            tail = temp;
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
        
        void deleteNode(Node* &head,int position){
            Node* temp=head;
            int count=1;
            while(count<position-1){
                count++;
                temp=temp->next;
            }
            temp->next = temp->next->next;
        }
        void change(Node* &head){
            Node* temp = head;
            Node* prev = NULL;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            head = temp;
            prev->next = NULL;
        }
        void display(Node* &head){
            Node* temp=head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }

};
int main(){
    Node* n1 = new Node(5);
    Node* head = n1;
    Node* tail = n1;
    n1->insertAtTail(tail,10);
    n1->insertAtTail(tail,19);
    n1->insertAt(head,2,100);
    n1->deleteNode(head,2);
    n1->display(head);
    n1->length(head);
    n1->change(head);
    n1->display(head);
}