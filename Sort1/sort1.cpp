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
// 입력타입 선택
void selectInputType(int input, int list[], int n) {
	int i;

	if (input == 0) {
		FILE *fp;
		fp = fopen("datafile.txt", "r");
		if (fp == NULL)
		{
			printf("File open에 오류 발생\n");
			exit(1);
		}
		fscanf(fp, "%d\n", &n);
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d\n", &list[i]);
		}
	}
	else if (input == 1) {
		printf("데이터 갯수 : ");
		scanf("%d", &n);
		printf("\n");
		for (i = 0; i < n; i++) {
			printf("데이터 입력 : ");
			scanf("%d", &list[i]);
		}
	}
	else {
		printf("잘못 입력하셨습니다. 0 또는 1을 입력해 주세요.\n");
		exit(0);
	}
	// 입력버퍼 비우기
	getchar();
}
// 정렬타입 선택
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
		printf("잘못 입력하셨습니다. 정렬 방식을 다시 입력해 주세요.");
		exit(0);
	}
}
// 오름차순 or 내림차순 선택
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
		printf("잘못 입력하셨습니다. 0 또는 1을 입력해주세요.");
		exit(0);
	}
}
// 출력
void sort_print(int list[], int n)
{
	int i;
	printf("결과 : ");
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
	// 파일입력 or 직접입력
	printf("파일에서 입력받으려면 0, 표준입력을 이용하려면 1을 입력해 주세요.\n");
	printf("입력 : ");
	scanf("%d", &input1);

	int i;
	if (input1 == 0) {
		FILE *fp;
		fp = fopen("datafile.txt", "r");
		if (fp == NULL)
		{
			printf("File open에 오류 발생\n");
			exit(1);
		}
		fscanf(fp, "%d\n", &n);
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d\n", &list[i]);
		}
	}
	else if (input1 == 1) {
		printf("데이터 갯수 : ");
		scanf("%d", &n);
		printf("\n");
		for (i = 0; i < n; i++) {
			printf("데이터 입력 : ");
			scanf("%d", &list[i]);
		}
	}
	else {
		printf("잘못 입력하셨습니다. 0 또는 1을 입력해 주세요.\n");
		exit(0);
	}
	// 입력버퍼 비우기
	getchar();

	printf("\n");
	// 정렬선택
	printf("s: 선택정렬, i: 삽입정렬, b: 버블정렬, h: 쉘정렬, m: 합병정렬, q: 퀵 정렬\n");
	printf("원하시는 정렬방식을 입력해 주세요.\n");
	printf("입력 : ");
	scanf("%c", &input2);
	selectSortType(input2, list, n);
	printf("\n");
	// 오름차순 or 내림차순
	printf("오름차순은 0, 내림차순은 1을 입력해 주세요.\n");
	printf("입력 : ");
	scanf("%d", &input3);
	selectUpOrDown(input3, list, n);
	printf("\n");
	// 출력
	sort_print(list, n);
	printf("\n");
}
