#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/** This function is allocating the dynamic memory to the node...
*    @param Pass a pointer-to-lined-list. it can change the memory address stored at that memory location.
*    @return none
*/
void linked_list_dynamic_init(P_Node * p_node)
{
	* p_node = (P_Node)malloc(sizeof(Node));
}

/** This function is printing contents of linked list starting from the given node...
*    @param Starting node.
*    @return none
*/
void printList(P_Node head)
{
	P_Node temp = head;

	// Protect
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = (P_Node) temp->next;
    }
    printf("\n");
}

/** This function is printing middle of linked list...
*    @param Starting node.
*    @return none
*/
void printList_middle(P_Node head_ref, int total_node)
{
	int sum_node = 1;

	P_Node p_fast_node = head_ref;
	P_Node p_slow_node = head_ref;

	if(head_ref != NULL) {
		while (p_fast_node != NULL && p_fast_node->next != NULL) {
			p_fast_node = (P_Node) p_fast_node->next;
			p_fast_node = (P_Node) p_fast_node->next;
			p_slow_node = (P_Node) p_slow_node->next;
			sum_node += 2;
		}
		printf("The meddle elements is: %d \n", p_slow_node->data);
	}

	total_node = sum_node;
	printf("Total of nodes: %d", total_node);

}

/** This function is pushing a new node at the front...
*    @param Pass a pointer-to-struct. it can change the memory address stored at that memory location.
*    @param Assign data to a new node.
*    @return none
*/
void linked_list_push_node(P_Node* head_ref, int data)
{
	P_Node init_node = (P_Node)malloc(sizeof(Node));

	init_node->data = data;
	init_node->next = (struct Node*) (* head_ref);
	(* head_ref) = init_node;
}

/** This function is reversing the linked list...
*    Reverse function (Input: 1->2->3->4->NULL; Output: NULL<-1<-2<-3<-4)
*
* 	 1. Initialize three pointers: prev (NULL), curr (head),  next (NULL).
* 	 2. Iterate trough the linked list.
* 	 - next = curr->next // store next node
* 	 - curr->next = prev // actual reserving happens
*
* 	 3. One step forward
* 	 - prev = curr
* 	 - curr = next
*
*    @param Pass a pointer-to-lined-list. it can change the memory address stored at that memory location.
*    @return none
*/
void linked_list_reverse(P_Node * head_ref)
{

	P_Node prev = NULL;
	P_Node curr = * head_ref;
	P_Node next = NULL;

	while (curr != NULL) {
		// store next node
		next = (P_Node) curr->next;

		// reverse
		curr->next = (struct Node *) prev;

		// One step forward
		prev = curr;
		curr = next;

	}
	*head_ref = prev;
}


