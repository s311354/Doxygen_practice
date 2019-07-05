#include <stdio.h>
#include <stdlib.h>

#include "definition.h"
#include "struct_process.h"
#include "linked_list.h"

int main()
{

	// Access Pointer
	STRUCTTAG tag;
	PSTRUCTTAG p_tag;
	p_tag = &tag;

	// initial the structure (example)
	struct_init(p_tag, 1, 2);

	printf("%d,%d\n",tag.memberB, p_tag->memberB);

	//Linked list
	/* 	sdata has been assigned to data part of third
		block (block pointed by third). And next pointer
		of the third block is made NULL to indicate
		that the linked list is terminated here.

		We have the linked list ready.

			head
				|
				|
			+---+---+     +---+---+     +----+------+
			| 1 | o----->| 2 | o-----> | 3 | NULL |
			+---+---+     +---+---+     +----+------+


		Note that only head is sufficient to represent
		the whole list. We can traverse the complete
		list by following next pointers. */

	P_Node head 	= NULL;
	P_Node second 	= NULL;
	P_Node third 	= NULL;

	// Allocated 3 static memories
	linked_list_dynamic_init(&head);
	linked_list_dynamic_init(&second);
	linked_list_dynamic_init(&third);

	// Assign the value and link the structure
	head->data = 1;
	head->next = (struct Node *) second;

	second->data = 2;
	second->next = (struct Node *) third;

	third->data = 3;
	third->next = NULL;

	printf("Print Linked list \n");
	printList(head);

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
	printList_middle(head);

	return 0;
}
