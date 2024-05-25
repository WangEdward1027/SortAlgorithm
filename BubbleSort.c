#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

//冒泡排序

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void Bubble(int A[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (A[j] > A[j+1]) {
				swap(&A[j], &A[j+1]);
			}
		}
	}
}

int main(void) {
	int arr[] = { 5,4,8,7,2,6,1,3,9,10 };
	Bubble(arr, SIZE(arr));

	for (int i = 0; i < SIZE(arr); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
