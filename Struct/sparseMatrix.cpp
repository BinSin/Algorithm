#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 10 
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	// 행의 개수
	int cols;	// 열의 개수
	int terms; 	// 0이 아닌 항의 개수
} SparseMatrix;

SparseMatrix change(SparseMatrix *m, int x, int y)
{
	SparseMatrix *c;
	c = (SparseMatrix *)malloc(sizeof(SparseMatrix));

	int i, j;
	for (i = 0; i < m->terms; i++) {
		if (m->data[i].row == x) {
			for (j = 0; j < m->terms; j++) {
				if (m->data[j].row == x) {
					c->data[i] = m->data[j];
					c->data[i].row = y;
				}
			}
		}
		else if (m->data[i].row == y) {
			for (j = 0; j < m->terms; j++) {
				
				if (m->data[j].row == y) {
					printf("%d\n", m->data[j].row);
					c->data[i] = m->data[j];
					c->data[i].row = x;
				}
			}
		}
		else {
			c->data[i] = m->data[i];
		}
	}

	return *c;
}

void MatrixPrint(SparseMatrix m)
{
	int i;
	printf("{");
	if (m.terms > 1) {
		for (i = 0;i < m.terms - 1;i++) {
			printf("((%d,%d),%d), ", m.data[i].col, m.data[i].row, m.data[i].value);
		}
		printf("((%d,%d),%d)}\n", m.data[i].col, m.data[i].row, m.data[i].value);
	}
	else
		printf("}\n");
}

// 주함수
void main()
{
	SparseMatrix m1 = { { { 1,1,5 },{ 2,2,9 } }, 3,3,2 };
	SparseMatrix m2 = { { { 0,0,5 },{ 2,2,9 } }, 3,3,2 };
	SparseMatrix m3;

	MatrixPrint(m1);
	//MatrixPrint(m2);

	m3 = change(&m1, 0, 1);
	//m2 = change(&m2, 0, 1);
	
	MatrixPrint(m3);
	//MatrixPrint(m2);
}
