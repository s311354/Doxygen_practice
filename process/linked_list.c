#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/** This function is allocating the dynamic memory to the node...
 *    @param Pass a pointer-to-lined-list.
 *    @return none
 */
P_Node init_Node(int data) {
	P_Node tmp = (P_Node) malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

/** This function is printing contents of linked list starting from the given node...
 *    @param Starting node.
 *    @return none
 */
void printList(P_Node head) {
	P_Node temp = head;

	// Protect
	while (temp != NULL) {
		printf("%d  ", temp->data);
		temp = (P_Node) temp->next;
	}
	printf("\n");
}

/** This function is printing length of linked list starting from the given node...
 *    @param Starting node.
 *    @return none
 */
int printList_len(P_Node head) {
	P_Node temp = head;
	int len = 0;

	// Protect
	while (temp != NULL) {
		len++;
		temp = (P_Node) temp->next;
	}

	printf("%d \n", len);

	return len;
}

/** This function is printing middle of linked list...
 *    @param Starting node.
 *    @return none
 */
void printList_middle(P_Node head_ref, int total_node) {
	int sum_node = 1;

	P_Node p_fast_node = head_ref;
	P_Node p_slow_node = head_ref;

	if (head_ref != NULL) {
		while (p_fast_node != NULL && p_fast_node->next != NULL) {
			p_fast_node = (P_Node) p_fast_node->next;
			p_fast_node = (P_Node) p_fast_node->next;
			p_slow_node = (P_Node) p_slow_node->next;
			sum_node += 2;
		}
		printf("The meddle elements is: %d \n", p_slow_node->data);
	}

	total_node = sum_node;
	printf("Total of nodes: %d \n", total_node);

}

/** This function is pushing a new node at the front...
 *    @param Pass a pointer-to-struct. it can change the memory address stored at that memory location.
 *    @param Assign data to a new node.
 *    @return none
 */
void linked_list_push_node(P_Node* head_ref, int data) {
	P_Node init_node = (P_Node) malloc(sizeof(Node));

	init_node->data = data;
	init_node->next = (struct Node*) (*head_ref);
	(*head_ref) = init_node;
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
void linked_list_reverse(P_Node * head_ref) {

	P_Node prev = NULL;
	P_Node curr = *head_ref;
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

/** This function is finding the loop in a the given linked list...
 *    @param Starting node.
 *    @return none
 */
void linked_list_find_loop(P_Node head_ref) {
	P_Node p_fast_node = head_ref;
	P_Node p_slow_node = head_ref;

	int loop_cut = 0;

	if (head_ref != NULL) {
		while (p_fast_node != NULL && p_fast_node->next != NULL) {
			p_fast_node = (P_Node) p_fast_node->next;
			p_fast_node = (P_Node) p_fast_node->next;
			p_slow_node = (P_Node) p_slow_node->next;

			loop_cut++;
			/* If slow_p and fast_p meet at some point
			 then there is a loop */
			if (p_slow_node == p_fast_node)
				break;

		}
	}

	printf("Total of loop node is: %d \n", loop_cut);
}

/** This function is used to get the intersection point of two linked lists...
 *    @param First node.
 *    @param Second node.
 *    @return none
 */
void linked_list_get_Intersection_top(P_Node head_ref1, P_Node head_ref2) {
	int len1 = printList_len(head_ref1);
	int len2 = printList_len(head_ref2);
	int diff_len, result;

	if (len1 > len2) {
		diff_len = len1 - len2;
		result = linked_list_get_Intersection(diff_len, head_ref1, head_ref2);
	} else {
		diff_len = len2 - len1;
		result = linked_list_get_Intersection(diff_len, head_ref2, head_ref1);
	}

	printf("The node of intersection is: %d \n", result);

}

/** This function is used to traverse two linked lists and fine the node of intersection...
 *    @param First node.
 *    @param Second node.
 *    @return The node of intersection
 */
int linked_list_get_Intersection(int diff_len, P_Node head_ref1,
		P_Node head_ref2) {

	int i;
	P_Node current_1 = head_ref1;
	P_Node current_2 = head_ref2;

	// Align two linked lists
	for (i = 0; i < diff_len; ++i) {
		if (current_1 == NULL) {
			return -1;
		}
		current_1 = (P_Node) current_1->next;
	}

	// Traverse both the lists and fine the intersection point
	while (current_1 != NULL && current_2 != NULL) {
		if (current_1 == current_2)
			return current_1->data;

		current_1 = (P_Node) current_1->next;
		current_2 = (P_Node) current_2->next;
	}

	return -1;
}
