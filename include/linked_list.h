#ifndef INCLUDE_LINKED_LIST_H_
#define INCLUDE_LINKED_LIST_H_

/** Dummy Linked list
 */
typedef struct Node_T {
	int data;
	struct Node * next;
} Node, *P_Node;

/** Dummy Doubly Linked list
 */
typedef struct Du_Node_T {
	int data;
	struct Node* prev;
	struct Node* next;
} Du_Node, *P_Du_Node;

P_Node init_Node (int data);
void printList(P_Node head);
void printList_len(P_Node head);
void printList_middle(P_Node head_ref, int total_node);
void linked_list_push_node(P_Node* head_ref, int data);
void linked_list_reverse(P_Node* head_ref);
void linked_list_find_loop(P_Node head_ref);

#endif /* INCLUDE_LINKED_LIST_H_ */
