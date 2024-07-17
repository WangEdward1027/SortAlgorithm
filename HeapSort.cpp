//堆排序

#include <iostream> 
using std::cout;
using std::endl;

void print(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i ,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//3.堆化:堆顶元素不断下坠到合适位置
void heapify(int arr[], int i, int n){
    while(i < n){
        //求当前结点i、左孩子、右孩子,这三个结点中的最大值
        int maxIdx = i;
        int lchild = 2*i+1;
        int rchild = 2*i+2;
        if(lchild < n && arr[lchild] > arr[maxIdx]){
            maxIdx = lchild;
        }
        if(rchild < n && arr[rchild] > arr[maxIdx]){
            maxIdx = rchild;
        }
        //如果最大值是根结点,调整提前结束
        if(maxIdx == i)    break;
        //如果不是,交换根结点和最大值结点
        swap(arr, i ,maxIdx);
        //调整maxIdx结点,继续下坠
        i = maxIdx;
    }
}

//2.构建大顶堆
void buildHeap(int arr[], int n){
    //找到第一个非叶子结点i: lchild(i) = 2i+1 < n, 2i+1 <= n-1
    //2i <= n-2,  i <= n/2 -1
    //从后往前依次构建大顶堆
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, i ,n);
    }
}

//1.堆排序
void HeapSort(int arr[], int n){
    //1.构建大顶堆
    buildHeap(arr, n);
    //2.初始化无序区的长度
    int len = n;
    //3.交换堆顶元素和无序区最后一个元素,直到len == 1
    while(len > 1){
        swap(arr, 0, len-1);
        len--;
        heapify(arr, 0, len); //堆化
    }
}

int main()
{
    int arr[] = {11,33,55,77,99,88,66,44,22,0};
    int len = sizeof(arr)/sizeof(arr[0]); //求静态数组的长度
    HeapSort(arr, len);
    print(arr, len);
    return 0;
}
