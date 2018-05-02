#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;  //���ȣ
	int col;   //����ȣ
	int value; //��
}element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

typedef struct {
	int rows;//���� ����
	int cols;//���� ����
	ListNode *head;//���Ḯ��Ʈ�� ����
	ListNode *tail;//���Ḯ��Ʈ�� ��. ������ ���� ����� ������ ������ ����
}ListHeader;

void init(ListHeader *plist, int rows, int cols)
{
	plist->rows = rows;
	plist->cols = cols;
	plist->head = NULL;
	plist->tail = NULL;
}

void insert_node_last(ListHeader *plist, element data)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}
	temp->data = data;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
}

void print_matrix(ListHeader *plist)
{
	ListNode *p = plist->head;
	do {
		printf("{(%d, %d) %d}\n", p->data.row, p->data.col, p->data.value);
	} while (p = p->link);
	printf("\n");
}

// �� ����� ������ ���ϴ� �Լ�
void matrix_add(ListHeader *list1, ListHeader *list2, ListHeader *list3)
{
	ListNode *l1, *l2;

	l1 = list1->head;
	l2 = list2->head;

	while (l1 && l2) {
		if (l1->data.col < l2->data.col) {
			insert_node_last(list3, l1->data);
			l1 = l1->link;
		}
		else if (l1->data.col > l2->data.col) {
			insert_node_last(list3, l2->data);
			l2 = l2->link;
		}
		else {
			if (l1->data.row < l2->data.row) {
				insert_node_last(list3, l1->data);
				l1 = l1->link;
			}
			else if (l1->data.row > l2->data.row) {
				insert_node_last(list3, l2->data);
				l2 = l2->link;
			}
			else {
				element e1, e2, e3;
				e1 = l1->data; e2 = l2->data;
				e3.col = e1.col;
				e3.row = e1.row;
				e3.value = e1.value + e2.value;

				insert_node_last(list3, e3);
				l1 = l1->link;
				l2 = l2->link;
			}
		}
	}

	if (l1 == NULL) {
		while (l2) {
			insert_node_last(list3, l2->data);
			l2 = l2->link;
		}
	}
	else {
		while (l1) {
			insert_node_last(list3, l1->data);
			l1 = l1->link;
		}
	}
}

// ��ġ ���
void transposed_matrix(ListHeader *list, ListHeader *trans_list)
{
	init(trans_list, list->cols, list->rows);
	ListNode *l = list->head;

	for (int i = 0; i < list->cols; i++) {
		while(l) {
			if (l->data.col == i) {
				element e;
				e.col = l->data.row;
				e.row = l->data.col;
				e.value = l->data.value;
				insert_node_last(trans_list, e);
			}
			l = l->link;
		}
		l = list->head;
	}
}


void main()
{
	ListHeader list1, list2, list3, list4, trans_list3, trans_list4;
	init(&list1, 3, 3);
	init(&list2, 3, 3);
	init(&list3, 3, 3);
	init(&list4, 3, 4);
	
	insert_node_last(&list1, { 0,0,1 });
	insert_node_last(&list1, { 1,1,2 });
	insert_node_last(&list1, { 2,2,3 });

	insert_node_last(&list2, { 0,1,1 });
	insert_node_last(&list2, { 1,1,3 });
	insert_node_last(&list2, { 2,0,1 });

	insert_node_last(&list4, { 0,0,2 });
	insert_node_last(&list4, { 1,1,3 });
	insert_node_last(&list4, { 1,3,4 });
	insert_node_last(&list4, { 2,0,-3 });
	insert_node_last(&list4, { 2,3,1 });
	
	printf("list1\n");
	print_matrix(&list1);

	printf("list2\n");
	print_matrix(&list2);

	matrix_add(&list1, &list2, &list3);
	printf("list3\n");
	print_matrix(&list3);

	transposed_matrix(&list3, &trans_list3);
	printf("transposed list3\n");
	print_matrix(&trans_list3);
	
	printf("list4\n");
	print_matrix(&list4);

	transposed_matrix(&list4, &trans_list4);
	printf("transposed list4\n");
	print_matrix(&trans_list4);

}