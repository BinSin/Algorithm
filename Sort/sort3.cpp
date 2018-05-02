#include <stdio.h>
#include <stdlib.h>

int kthSmallest(int k, int list[], int n)
{
	int i, j, num, s;
	for (i = 0; i < n; i++) {
		s = 0;
		for (j = 0; j < n;j++)
			if (list[i] >= list[j])
				s++;
		if (k == s)
			return list[i];
	}

}

void main()
{
	int list[6] = { 3, 6, 9, 2, 7, 5 };
	int k, num;

	printf("몇번째로 작은 값을 출력할 것인지 입력하시오.\n");
	printf("k = ");
	scanf("%d", &k);
	if (k > 6) {
		printf("6이하의 값을 입력해 주세요\n");
		exit(0);
	}
	num = kthSmallest(k, list, 6);
	printf("k번째로 작은 수는 %d 입니다.\n", num);
}