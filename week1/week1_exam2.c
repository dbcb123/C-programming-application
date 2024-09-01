#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main() {
	int number[SIZE];
	int total = 0;
	int max, min;
	float avg = 0.0;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 100) + 1;
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	for (int i = 0; i < SIZE; i++) {
		total += number[i];
	}
	avg = (float)total / SIZE;
	
	//강좌 원본 : 배열 값으로 최대 최소 구하기
	max = number[0];
	min = number[0];
	
	for (int i = 1; i < SIZE; i++) {
		if (max < number[i]) max = number[i];
		if (min > number[i]) min = number[i];
	}

	printf("avg = %f, max = %d, min = %d\n", avg, max, min);

	//추가 실습 : 인덱스 값으로 최대 최소 구하기
	max = 0;
	min = 0;

	for (int i = 1; i < SIZE; i++) {
		if (number[max] < number[i]) max = i;
		if (number[min] > number[i]) min = i;
	}

	printf("avg = %f, max = %d, min = %d\n", avg, number[max], number[min]);
	return 0;
}