/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.
INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node*start1 = head1, *start2 = head2,*current1=head1,*current2=head2,*new_node,*temp;
	int f = 0;
	
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else
	if (head1 == NULL)
		return head2;
	else
	if (head2 == NULL)
		return head1;

	while (current1->next != NULL&&current2!=NULL)
	{
			if (current1->num <= current2->num)
			{
				if (current1->next != NULL && current1->next->num >= current2->num)
				{
					new_node = (struct node*)malloc(sizeof(struct node));
					new_node->num = current2->num;
					new_node->next = current1->next;
					current1->next = new_node;
					current2 = current2->next;
				}
				current1 = current1->next;
			}
			else
			{
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->num = current2->num;
				new_node->next = current1;
				current1 = new_node;
				current2 = current2->next;
				head1 = current1;
			}
		
	}
	if(current2 != NULL)
	{
		
		current1->next = current2;
	}
	return head1;
}
