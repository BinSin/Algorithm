#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int eng;
	int math;
}student;

typedef student element;

typedef struct ListNode {
	element data; //또는 student data;
	ListNode *link;
}ListNode;

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

ListNode *create_node(element data, ListNode *link) {
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
		fprintf(stderr, "할당 오류\n");
	new_node->data = data;
	new_node->link = link;

	return new_node;
}

void insert_sort(ListNode **phead, element e)
{
	ListNode *p = *phead;

	if (*phead == NULL || p->data.id > e.id) {
		insert_node(phead, NULL, create_node(e, NULL));
	}
	else {
		while (p->link != NULL && p->link->data.id <= e.id) {
			p = p->link;
		}
		insert_node(phead, p, create_node(e, NULL));
	}
}

void display(ListNode *h)
{
	ListNode *p = h;
	while (p) {
		printf("(번호: %d, 영어: %d, 수학: %d)\n", p->data.id, p->data.eng, p->data.math);
		p = p->link;
	}
}

void merge_list(ListNode *head1, ListNode *head2, ListNode **head3)
{	
	ListNode *h1, *h2;
	h1 = head1;
	h2 = head2;
	*head3 = h1;

	while (h2) {
		insert_sort(head3, h2->data);
		h2 = h2->link;
	}
}

void main()
{
	element a[5] = { {134,88,65}, {125,95,90}, {145,70,55}, {128,75,50}, {129,60,60} };
	element b[5] = { {124,78,55}, {135,65,70}, {147,80,85}, {115,95,90}, {144,90,80} };
	ListNode *head1 = NULL, *head2 = NULL, *head3 = NULL;
	
	for (int i = 0;i < 5;i++) {
		insert_sort(&head1, a[i]);
		insert_sort(&head2, b[i]);
	}
	printf("1반\n");
	display(head1);
	printf("\n");

	printf("2반\n");
	display(head2);
	printf("\n");

	printf("1반과 2반\n");
	merge_list(head1, head2, &head3);
	display(head3);
}