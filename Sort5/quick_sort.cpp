#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int *kpartition(int list[], int left, int right, int k)
{
	int temp, i;
	int *pivot = (int *)malloc(sizeof(int));
	int *low = (int *)malloc(sizeof(int));
	int *high = (int *)malloc(sizeof(int));
	
	for (i = 0; i < k - 1; i++) {
		low[i] = left + k - 1;
		high[i] = right + 1;
		pivot[i] = list[left + i];
	}

	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void kquick_sort(int list[], int left, int right, int k)
{
	if (left < right) {
		int i;
		int *list = (int *)malloc(sizeof(int));
		list = kpartition(list, left, right, k);
		for (i = 0; i < k;i++)
			kquick_sort(list, left, list[i], k);
		kquick_sort(list, list[i-1] + 2, right, k);
	}
}

void sort_print(int list[], int n)
{
	int i;
	printf("°á°ú : ");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void main()
{
	int list[10] = { 2, 6, 8, 9, 5, 1, 10, 13, 11, 3};
	kquick_sort(list, 0, 9, 2);
	sort_print(list, 10);
}