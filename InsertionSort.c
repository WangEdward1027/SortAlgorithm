#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

//直接插入排序

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) { //若arr[i]>=arr[i-1]，则已经有序，没必要移动
			int insertval = arr[i];
			int j;
			for (j = i - 1; j >= 0 && arr[j] > insertval; j--) {
				arr[j + 1] = arr[j]; //元素右移
			} //j < 0 || arr[j] <= insertval
			arr[j + 1] = insertval;
		}
	}
}

int main(void) {
	int arr[] = { 5,4,3,2,1 };
	insertionSort(arr, SIZE(arr));

	for (int i = 0; i < SIZE(arr); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
