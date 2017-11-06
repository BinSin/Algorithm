#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0;i<n;i++) {
		least = i;
		for (j = i + 1; j<n;j++)
			if (list[least]>list[j]) least = j;
		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1;i<n;i++) {
		key = list[i];
		for (j = i - 1;j >= 0 && list[j]>key;j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1;i>0;i--) {
		for (j = 0; j < i; j++)
			if (list[j]>list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap;i <= last;i = i + gap) {
		key = list[i];
		for (j = i - gap;j >= first && key<list[j];j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shell_sort(int list[], int n)
{
	int i, gap;
	for (gap = n / 2;gap>0;gap = gap / 2)
	{
		if ((gap % 2) == 0) gap++;
		for (i = 0;i<gap;i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

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
	free(sorted);
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int compare(const void *arg1, const void *arg2)
{
	if (*(int*)arg1>*(int *)arg2) return 1;
	else if (*(int*)arg1 == *(int*)arg2) return 0;
	else return -1;
}
// �Է�Ÿ�� ����
void selectInputType(int input, int list[], int n) {
	int i;

	if (input == 0) {
		FILE *fp;
		fp = fopen("datafile.txt", "r");
		if (fp == NULL)
		{
			printf("File open�� ���� �߻�\n");
			exit(1);
		}
		fscanf(fp, "%d\n", &n);
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d\n", &list[i]);
		}
	}
	else if (input == 1) {
		printf("������ ���� : ");
		scanf("%d", &n);
		printf("\n");
		for (i = 0; i < n; i++) {
			printf("������ �Է� : ");
			scanf("%d", &list[i]);
		}
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�. 0 �Ǵ� 1�� �Է��� �ּ���.\n");
		exit(0);
	}
	// �Է¹��� ����
	getchar();
}
// ����Ÿ�� ����
void selectSortType(char input, int list[], int n) {
	if (input == 's') {
		selection_sort(list, n);
	}
	else if (input == 'i') {
		insertion_sort(list, n);
	}
	else if (input == 'b') {
		bubble_sort(list, n);
	}
	else if (input == 'h') {
		shell_sort(list, n);
	}
	else if (input == 'm') {
		merge_sort(list, 0, n - 1);
	}
	else if (input == 'q') {
		qsort(list, n, sizeof(int), compare);
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�. ���� ����� �ٽ� �Է��� �ּ���.");
		exit(0);
	}
}
// �������� or �������� ����
void selectUpOrDown(int input, int list[], int n) {
	int i, temp;
	if (input == 0)
		return;
	else if (input == 1) {
		for (i = 0; i < n / 2; i++) {
			SWAP(list[i], list[n - 1 - i], temp);
		}
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�. 0 �Ǵ� 1�� �Է����ּ���.");
		exit(0);
	}
}
// ���
void sort_print(int list[], int n)
{
	int i;
	printf("��� : ");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void main()
{
	int input1 = 0, n = 0, input3 = 0;
	char input2 = 0;
	int list[MAX_SIZE];
	// �����Է� or �����Է�
	printf("���Ͽ��� �Է¹������� 0, ǥ���Է��� �̿��Ϸ��� 1�� �Է��� �ּ���.\n");
	printf("�Է� : ");
	scanf("%d", &input1);

	int i;
	if (input1 == 0) {
		FILE *fp;
		fp = fopen("datafile.txt", "r");
		if (fp == NULL)
		{
			printf("File open�� ���� �߻�\n");
			exit(1);
		}
		fscanf(fp, "%d\n", &n);
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d\n", &list[i]);
		}
	}
	else if (input1 == 1) {
		printf("������ ���� : ");
		scanf("%d", &n);
		printf("\n");
		for (i = 0; i < n; i++) {
			printf("������ �Է� : ");
			scanf("%d", &list[i]);
		}
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�. 0 �Ǵ� 1�� �Է��� �ּ���.\n");
		exit(0);
	}
	// �Է¹��� ����
	getchar();

	printf("\n");
	// ���ļ���
	printf("s: ��������, i: ��������, b: ��������, h: ������, m: �պ�����, q: �� ����\n");
	printf("���Ͻô� ���Ĺ���� �Է��� �ּ���.\n");
	printf("�Է� : ");
	scanf("%c", &input2);
	selectSortType(input2, list, n);
	printf("\n");
	// �������� or ��������
	printf("���������� 0, ���������� 1�� �Է��� �ּ���.\n");
	printf("�Է� : ");
	scanf("%d", &input3);
	selectUpOrDown(input3, list, n);
	printf("\n");
	// ���
	sort_print(list, n);
	printf("\n");
}
