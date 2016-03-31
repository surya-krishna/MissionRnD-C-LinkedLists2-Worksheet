/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *start = head, *current = start;
	int len=0,counter=0;
	if (head==NULL)
		return -1;

	while (current != NULL)
	{
		len++;
		current = current->next;
	}

	current = head;
	counter = len;
	while (counter>(len/2+1))
	{
		counter--;
		current = current->next;
	}
	if (len % 2 != 0)
	{
		return (current->num);
	}
	else
	{
		return ((current->num + current->next->num) / 2);
	}
	
}
