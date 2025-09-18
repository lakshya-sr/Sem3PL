#include <iostream>

using namespace std;

Node *deletion_begin(Node *head){
	Node *prev = head, *first = head;
	if(head == NULL){
		cout << "Empty\n";
		return NULL;
	}
	
	if(prev->next == prev){
		head = NULL;
		return prev;
	}
	
	while(prev->next != head){
		prev = prev->next;
		prev->next = first->next;
		head = prev->next;
		free(first);
		return head;
	}
}
