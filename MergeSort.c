#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 10

//归并排序

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int temp[N];

void Merge(int arr[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	//复制
	for (i = left; i <= right; i++)		temp[i] = arr[i];
	
	while (i <= mid && j <= right) {
		if (temp[i] <= temp[j]) {
			arr[k++] = temp[i++];
		}else {
			arr[k++] = temp[j++];
		}
	}
	
	while (i <= mid)	arr[k++] = temp[i++];
	while (j <= right)	arr[k++] = temp[j++];
}

void MergeSort(int arr[], int left, int right) {
	//边界条件
	if (left >= right)	return;
	//递归公式
	int mid = left + (right - left >> 1);
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}

void merge_sort(int arr[], int n) {
	MergeSort(arr, 0, n - 1);
}

int main(void) {
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	merge_sort(arr, N);
	print_array(arr, N);
	return 0;
}
