#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

//快速排序 (双向分区)

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int Partition(int arr[], int left, int right) {
	//选取基准值
	int pivot = arr[left];
	//双向分区
	int i = left, j = right;
	while (i < j) {
		//先移动j，找＜pivot的元素
		while (i < j && arr[j] >= pivot) {
			j--;
		}  // i == j || arr[j] < pivot
		arr[i] = arr[j];
		//再移动i，找>pivot的元素
		while (i < j && arr[i] <= pivot) {
			i++;
		} // i == j || arr[i] > pivot
		arr[j] = arr[i];
	} // i == j
	arr[i] = pivot;
	return i;
}

void QuickSort(int arr[], int left, int right) {
	//边界条件
	if (left >= right)	 return;
	//递归公式
	int idx = Partition(arr, left, right);
	print_array(arr, 5);
	QuickSort(arr, left, idx-1);
	QuickSort(arr, idx+1, right);
}

void quick_sort(int arr[], int n) {
	//委托的原因：(1)数组不好递归，区间好递归
	//(2)丑陋的内部设计要封装起来，只暴露一个简单易用的接口给用户
	QuickSort(arr, 0, n - 1);
}

int main(void) {
	int arr[] = { 5,4,3,2,1 };
	quick_sort(arr, SIZE(arr));
	
	return 0;
}
