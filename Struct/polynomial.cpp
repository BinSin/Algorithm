#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 101

typedef struct {
	int degree;
	double coef[MAX_DEGREE];
} polynomial;

double eval(polynomial p, int x)
{
	int d = p.degree;
	double px = 0;
	for (int i = 0; i <= d; i++) {
		px += p.coef[i] * pow(x, d - i);
	}
	return px;
}

void remove_max_degree(polynomial *p)
{
	// degree가 1 이하이면 0이 되게 리턴
	if (p->degree < 1) {
		p->coef[0] = 0;
		return;
	}
	
	int d = p->degree;

	int i = 1;
	int n = 1;
	while(1) {
		if (p->degree < 1) break;
		if (p->coef[i++] == 0) {
			p->degree--;
			n++;
		}
		else
			break;
	}
	p->degree--;
	int m = n;
	for (i = 0; i < n; i++) {
		p->coef[i] = p->coef[m++];
	}
}

void main()
{
	double px;
	polynomial p = { 5, { 10, 0, 0, 0, 6, 1} };
	px = eval(p, 2);
	printf("p(x)=%f\n", px);

	remove_max_degree(&p);
	px = eval(p, 2);
	printf("p(x)=%f\n", px);

	remove_max_degree(&p);
	px = eval(p, 2);
	printf("p(x)=%f\n", px);

	remove_max_degree(&p);
	px = eval(p, 2);
	printf("p(x)=%f\n", px);
}
