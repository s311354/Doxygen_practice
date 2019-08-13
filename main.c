#include <stdio.h>
#include <stdlib.h>

#include "definition.h"
#include "struct_process.h"
#include "linked_list.h"

// Basic linked list
/* We have the linked list ready.

 +---+---+     +---+---+     +----+------+
 | 1 | o----->| 2 | o-----> | 3 | NULL |
 +---+---+     +---+---+     +----+------+

 */
int main() {

	/**** Structure  ****/
	// Access Pointer
	STRUCTTAG tag;
	PSTRUCTTAG p_tag;
	int total_node = 0;
	p_tag = &tag;

	// initial the structure (example)
	struct_init(p_tag, 1, 2);
	printf("member B at structure = %d, at printer structure = %d\n",
			tag.memberB, p_tag->memberB);

	/**** Two linked Lists  ****/
	// First linked list
	P_Node head = init_Node(1);
	P_Node second = init_Node(2);
	P_Node third = init_Node(3);
	P_Node four = init_Node(4);

	// Second linked list
	P_Node head_branch = init_Node(2);
	P_Node second_branch = init_Node(2);
	P_Node third_branch = init_Node(2);
	P_Node four_branch = init_Node(4);

	// Link the structure
	head->next = (struct Node *) second;
	second->next = (struct Node *) third;
	third->next = NULL;

	// Link the branch
	head_branch->next = (struct Node *) second_branch;
	second_branch->next = (struct Node *) third_branch;
	third_branch->next = (struct Node *) four_branch;
	four_branch->next = (struct Node *) third;

	printf("Print Linked list \n");
	printList(head);

	printf("Print the length of list \n");
	printList_len(head);

	// Reverse the linked list
	linked_list_reverse(&head);

	printf("Print reversed Linked list \n");
	printList(head);

	// Push a new node
	linked_list_push_node(&head, 3);
	linked_list_push_node(&head, 5);

	printf("Print Linked list \n");
	printList(head);

	printf("Print middle node \n");
	printList_middle(head, total_node);

	printf("Print the intersection point of two linked list: \n");
	linked_list_get_Intersection_top(head, head_branch);

	// Create a loop in linked list
	third->next = (struct Node *) four;
	four->data = 4;
	four->next = head->next;

	linked_list_find_loop(head);

	return 0;
}
