#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//堆排序 HeapSort

#define SWAP(arr, i ,j){	\
	int temp = arr[i];		\
	arr[i] = arr[j];		\
	arr[j] = temp;			\
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//3.堆化
//i：需要调整的结点索引    n：索引的最大范围
void heapify(int arr[], int i, int n) {
	while (i < n) {
		//求根、左、右 三个元素的最大值
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int maxIdx = i;
		if (lchild < n && arr[lchild] > arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < n && arr[rchild] > arr[maxIdx]) {
			maxIdx = rchild;
		}
		//如果最大值是根结点，调整提前结束
		if (maxIdx == i)	break;  
		//如果不是，交换根结点和最大值结点
		SWAP(arr, i, maxIdx);	
		//调整maxIdx结点，继续下坠
		i = maxIdx;					
	} //i >= n || maxIdx == i
}

//2.构建大顶堆
void build_heap(int arr[], int n) {
	//找到第一个非叶子结点i: lchild(i) = 2i+1 < n，2i+1 <= n-1, 2i <= n-2， i <= n/2 - 1
	//从后往前依次构建大顶堆
	for (int i = n/2-1; i >= 0; i--) {
		heapify(arr, i, n);
	}
}

//1.堆排序
void heap_sort(int arr[], int n) {
	//1.构建大顶堆
	build_heap(arr, n);
	//print_array(arr, 10); //调试信息
	//2.初始化无序区的长度
	int len = n;
	//3.交换堆顶元素和无序区最后一个元素，直到 len == 1
	while (len > 1) {
		SWAP(arr, 0, len-1);
		len--;
		heapify(arr, 0, len);	//堆化
		//print_array(arr, 10); //调试信息
	}
}

int main(void) {
	//int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
	heap_sort(arr, 10);
	print_array(arr, 10);

	return 0;
}
