//希尔排序

void ShellSort(int arr[], int n) {
	int gap = n / 2;
	while (gap != 0) {
		//组间插入排序
		for (int i = gap; i < n; i++) {
			int insertval = arr[i];
			int j = i - gap;   //遍历有序区域
			while (j >= 0 && arr[j] > insertval) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = insertval;
		}
		gap /= 2;
	}
	print_array(arr, 10);
}
