#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int list[], int s, int e)
{
	int i, j;
	int item;

	for (i = s + 1;i<e;i++) {
		item = list[i];
		for (j = i - 1;j >= s &&list[j]>item; j--)
			list[j + 1] = list[j];
		list[j + 1] = item;
	}
}

void	sort_Hash(int A[], int s, int e)
{
	if (e <= s)	return;


	if (e - s + 1 <= 5) {
		insertion_sort(A, s, e);
		return;
	}


	// find min, max
	int	i, j, k = 0;
	double	a, b, min, max;
	int y;
	int *B = new int[e - s + 1];

	min = max = A[s];
	for (i = s + 1;i <= e;i++) {
		if (A[i] < min)	min = A[i];
		if (A[i] > max)	max = A[i];
	}

	a = ((double)(e - s)) / (max - min);
	b = -min*a;

	//y=(int)(a*A[i]+b)
	//�� �ؽ̰�  ���� �������� ��
	int	*locn = new int[e - s + 1];
	// �� �ؽ̰��� ���� �迭�� ���� �ε���
	int	*locs = new int[e - s + 1];

	//�ϼ��Ͻÿ�. �� �ؽ̰��� ���ϴ� �����Ϳ� ���� �ٽ� sort_Hash�� �����Ͻÿ�
	for (i = s; i <= e; i++) {
		locn[i] = 0;
		locs[i] = 0;
	}

	for (i = s;i <= e;i++) {
		y = (int)(a * A[i] + b);
		locn[y]++;
		locs[i] = y;
	}
	// �ؽ̰��� �°� B�� A������ �ִ´�.
	for (y = s;y <= e; y++)
		for(i = s; i <=e ; i++)
			if (locs[i] == y) {
				B[k] = A[i];
				k++;
			}
	// B�� ������ A�� �ٽ� �־��ش�.
	for (i = s;i <= e;i++)
		A[i] = B[i];

	for (i = s;i <= 0;) {
		// ������ 0 �̸� ���� �� ����
		if (locn[i] == 0)
			i++;
		// ������ �� ��ŭ sort_Hash�� �ٽ� ���ش�.
		else {
			sort_Hash(A, i, i + locn[i]);
			i += locn[i];
		}
	}

}

void main()
{
	int A[200];
	int i;
	for (i = 0;i<200;i++)
		A[i] = rand() % 100 + 1;
	//A�� ���� sort_Hash�� ȣ���Ͽ� ������ �Ǿ����� Ȯ���Ͻÿ�.
	printf("���� ��\n");
	for (i = 0; i < 200; i++)  {
		if (i % 10 == 0) printf("\n");
		printf("%3d\t", A[i]);
	}
	
	sort_Hash(A, 0, 199);
	printf("\n");
	printf("\n");

	printf("���� ��\n");
	for (i = 0; i < 200; i++) {
		if (i % 10 == 0) printf("\n");
		printf("%3d\t", A[i]);
	}
	printf("\n");
}


