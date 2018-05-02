#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define STUDENT_NUMBER 10

typedef struct student {
	int id;
	double eng;
	double math;
}student;
// ���� ���
double eng_average(student s[]) {
	int i;
	double sum = 0;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		sum += s[i].eng;
	}
	return sum / STUDENT_NUMBER;
}
// ���� ���
double math_average(student s[]) {
	int i;
	double sum = 0;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		sum += s[i].math;
	}
	return sum / STUDENT_NUMBER;
}
// ���� ǥ������
double eng_deviation(student s[]) {
	int i;
	double sigma = 0;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		sigma += pow(s[i].eng - eng_average(s), 2);
	}
	return sqrt(sigma / STUDENT_NUMBER - 1);
}
// ���� ǥ������
double math_deviation(student s[]) {
	int i;
	double sigma = 0;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		sigma += pow(s[i].math - math_average(s), 2);
	}
	return sqrt(sigma / STUDENT_NUMBER - 1);
}
// ���� �ְ���
void best_eng_student(student s[]) {
	int i;
	double max = s[0].eng;
	int best_student_number = 0;
	for (i = 1; i < STUDENT_NUMBER; i++) {
		if (s[best_student_number].eng < s[i].eng)
			best_student_number = i;
	}
	printf("�����ְ����л� %d\n", s[best_student_number].id);
	printf("�����ְ����� %.2f\n", s[best_student_number].eng);
}
// ���� �ְ���
void best_math_student(student s[]) {
	int i;
	double max = s[0].math;
	int best_student_number = 0;
	for (i = 1; i < STUDENT_NUMBER; i++) {
		if (s[best_student_number].math < s[i].math)
			best_student_number = i;
	}
	printf("�����ְ����л� %d\n", s[best_student_number].id);
	printf("�����ְ����� %.2f\n", s[best_student_number].math);
}
// �ְ���
void best_total_student(student s[]) {
	int i;
	double max = s[0].math + s[0].eng;
	int best_student_number = 0;
	for (i = 1; i < STUDENT_NUMBER; i++) {
		if (s[best_student_number].math + s[best_student_number].eng
			< s[i].math + s[i].eng)
			best_student_number = i;
	}
	printf("�����ְ����л� %d\n", s[best_student_number].id);
	printf("�����ְ����� %.2f\n", s[best_student_number].math + s[best_student_number].eng);
}
// ���
void print(student s[]) {
	printf("����������� %.2f\n", eng_average(s));
	printf("����������� %.2f\n", math_average(s));
	printf("\n");
	best_eng_student(s);
	printf("\n");
	best_math_student(s);
	printf("\n");
	best_total_student(s);
	printf("\n");
}
// �й� �˻�
int search_id(student s[], int id) {
	int i;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (s[i].id == id) {
			return i;
		}
	}
	return 11;
}
// ���� �˻�
void print_rank(student s[], int id) {
	double s_eng_score = s[id].eng;
	double s_math_score = s[id].math;
	double s_total_score = s_eng_score + s_math_score;
	int eng_rank = 0, math_rank = 0, total_rank = 0;

	int i;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (s_eng_score <= s[i].eng) eng_rank++;
	}
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (s_math_score <= s[i].math) math_rank++;
	}
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (s_eng_score + s_math_score <= s[i].eng + s[i].math)
			total_rank++;
	}
	printf("����� %d\n", eng_rank);
	printf("���м��� %d\n", math_rank);
	printf("�Ѽ��� %d\n", total_rank);
}

void main() {
	student s[STUDENT_NUMBER] = {
		{ 1234, 78, 87 },
		{ 1235, 65, 55 },
		{ 1365, 88, 95 },
		{ 2546, 45, 56 },
		{ 3124, 58, 88 },
		{ 1976, 71, 54 },
		{ 1657, 32, 55 },
		{ 2547, 90, 43 },
		{ 2456, 66, 78 },
		{ 1765, 54, 99 }
	};

	print(s);

	int id = 0;
	printf("�����Ϸ��� -1�� �Է��Ͻÿ�\n\n");
	while (1) {
		printf("�й����Է��Ͻÿ� : ");
		scanf("%d", &id);
		if (id == -1) break;

		id = search_id(s, id);
		if (id == 11) {
			printf("���� �й��Դϴ�.\n\n");
			continue;
		}

		print_rank(s, id);
		printf("\n");
	}
}