#include<iostream>
#include<unordered_map>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode *next;
    ListNode* random;
    ListNode (int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

/*void insertAt(ListNode* &head,ListNode* &tail,int val){
	ListNode* newNode = new ListNode(val);
	if(head == NULL){
		head = newNode;
		tail = newNode;}
	else{
		tail -> next = newNode;
		tail = newNode;
	}
	return;
}
ListNode* cloneTheLinkedList (ListNode* head) {
    //Create a clone LL using next ptr
	ListNode* cloneHead = NULL;
	ListNode* cloneTail = NULL;
	ListNode* temp = head;
	while(temp != NULL){
		insertAt(cloneHead,cloneTail,temp->data);
		temp = temp -> next;
	}
	//Create mapping
	unordered_map<ListNode*,ListNode*> mapping;
	ListNode* temp1 = head;
	ListNode* temp2 = cloneHead;
	while(temp1 != NULL && temp2 != NULL){
		mapping[temp1] = temp2;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	//setting the random pointer
	temp1 = head;
	temp2 = cloneHead;
	while(temp1 != NULL){
		temp2->random = mapping[temp1->random];
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return cloneHead;
}*/
/* This is the ListNode class definition

class ListNode {
    public:
    int data;
    ListNode *next;
    ListNode* random;
    ListNode (int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
*/

void insertAt(ListNode* &head,ListNode* &tail,int val){
	ListNode* newNode = new ListNode(val);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
	return;
}
ListNode* cloneTheLinkedList (ListNode* head) {
    ListNode* cloneTail = NULL;
	ListNode* cloneHead = NULL;
	ListNode* temp = head;
	while(temp != NULL){
		insertAt(cloneHead,cloneTail,temp->data);
		temp = temp->next;
	}
	ListNode* oldNode = head;
	ListNode* cloneNode = cloneHead;
	while(oldNode != NULL && cloneNode != NULL){
		ListNode* next = oldNode->next;
		oldNode->next = cloneNode;
		oldNode = next;
		
		next = cloneNode->next;
		cloneNode->next = oldNode;
		cloneNode = next;
	}
	oldNode = head;
	cloneNode = cloneHead;
	while(oldNode != NULL){
		oldNode->next->random = (oldNode->random)? oldNode->random->next : oldNode->random;
		oldNode = oldNode->next->next;	}
	oldNode = head;
	cloneNode = cloneHead;
	while(oldNode != NULL && cloneNode != NULL){
		oldNode->next = cloneNode->next;
		oldNode = oldNode->next;
		if(oldNode != NULL)
			cloneNode->next = oldNode->next;
		cloneNode = cloneNode->next;
	}
	return cloneHead;
}