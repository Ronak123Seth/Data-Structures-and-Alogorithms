#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0)
            countZero+=1;
        else if(temp->data == 1)
            countOne+=1;
        else
            countTwo+=1;
        temp = temp->next;
    }
    temp = head;
    while(countZero>0){
        countZero--;
        temp->data = 0;
        temp=temp->next;
    }
    while(countOne>0){
        countOne--;
        temp->data = 1;
        temp=temp->next;
    }
    while(countTwo>0){
        countTwo--;
        temp->data = 2;
        temp=temp->next;
    }
    return head;
}
void insertAt(Node* &tail,Node* temp){
    tail->next = temp;
    tail = temp;
}
Node* sortList(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0)
            insertAt(zeroTail,temp);
        else if(temp-> data == 1)
            insertAt(oneTail,temp);
        else
            insertAt(twoTail,temp);
        temp = temp->next;
    }
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    twoTail->next = NULL;
    return zeroHead->next;
}