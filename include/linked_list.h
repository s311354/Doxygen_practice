#ifndef INCLUDE_LINKED_LIST_H_
#define INCLUDE_LINKED_LIST_H_

/** Dummy Linked list
    */
typedef struct Node_T {
	int data;
	struct Node * next;
}Node, *P_Node;

/** Dummy Doubly Linked list
    */
typedef struct Du_Node_T {
	int data;
	struct Node* prev;
	struct Node* next;
}Du_Node, *P_Du_Node;

void linked_list_dynamic_init(P_Node* p_node);

void linked_list_push_node(P_Node* head_ref, int data);

void linked_list_reverse(P_Node* head_ref);

void printList(P_Node head);

void printList_middle(P_Node head_ref);

#endif /* INCLUDE_LINKED_LIST_H_ */
