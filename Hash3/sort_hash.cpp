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
	//각 해싱값  대한 데이터의 수
	int	*locn = new int[e - s + 1];
	// 각 해싱값에 대한 배열의 시작 인덱스
	int	*locs = new int[e - s + 1];

	//완성하시오. 각 해싱값에 속하는 데이터에 대해 다시 sort_Hash를 적용하시오
	for (i = s; i <= e; i++) {
		locn[i] = 0;
		locs[i] = 0;
	}

	for (i = s;i <= e;i++) {
		y = (int)(a * A[i] + b);
		locn[y]++;
		locs[i] = y;
	}
	// 해싱값에 맞게 B에 A값들을 넣는다.
	for (y = s;y <= e; y++)
		for(i = s; i <=e ; i++)
			if (locs[i] == y) {
				B[k] = A[i];
				k++;
			}
	// B의 값들을 A에 다시 넣어준다.
	for (i = s;i <= e;i++)
		A[i] = B[i];

	for (i = s;i <= 0;) {
		// 데이터 0 이면 다음 것 수행
		if (locn[i] == 0)
			i++;
		// 데이터 수 만큼 sort_Hash를 다시 해준다.
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
	//A를 찍어보고 sort_Hash를 호출하여 정렬이 되었는지 확인하시오.
	printf("정렬 전\n");
	for (i = 0; i < 200; i++)  {
		if (i % 10 == 0) printf("\n");
		printf("%3d\t", A[i]);
	}
	
	sort_Hash(A, 0, 199);
	printf("\n");
	printf("\n");

	printf("정렬 후\n");
	for (i = 0; i < 200; i++) {
		if (i % 10 == 0) printf("\n");
		printf("%3d\t", A[i]);
	}
	printf("\n");
}


