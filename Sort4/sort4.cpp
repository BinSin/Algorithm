#include <stdio.h>
#include <stdlib.h>

void kmerge(int list[], int left, int mid, int right, int kk)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;
	int *
	int *sorted = (int*)malloc(sizeof(int)*(right + 1));

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i>mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void kmerge_sort(int list[], int left, int right, int k)
{
	int i, kmid;
	if (left<right) {
		kmid = (left + right) / k;
		for (i = 0; i < k - 1; i++) {
			kmerge_sort(list, left, kmid, k);
			if (k - 2 != i) {
				left = kmid + 1;
				kmid += left;
			}
		}
		kmerge_sort(list, kmid+1, right, k);
		kmerge(list, left, kmid, right, k);
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
	int list[10] = { 3, 7, 9, 10, 15, 2, 4, 20, 1, 8 };
	kmerge_sort(list, 0, 9, 2);
	sort_print(list, 10);
}