#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

//简单选择排序

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void SelectionSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {  //n-1趟
		int minIdx = i;
		//寻找最小值的下标
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[minIdx])  minIdx = j;
		}
		//交换
		if (minIdx != i) {
			swap(&A[i], &A[minIdx]);
		}
	}
}

int main(void) {
	int arr[] = { 5,4,3,2,1 };
	SelectionSort(arr, SIZE(arr));

	for (int i = 0; i < SIZE(arr); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
