/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node*start = head, *current = start,*new_node;
	int c = 0;
	if (head == NULL||K==0)
		return NULL;

	while (current != NULL)
	{
		c++;
		if (c == K)
		{
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> num = K;
			new_node->next = current->next;
			current->next = new_node;
			current = current->next;
			c = 0;

		}
		current = current->next;
	}
	return head;
}
