#include<iostream>
using namespace std;

int binarySearch(int target, int array[], int size){
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target)
            return mid;
        if (array[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main(){
    int a[] = {1,2,3,4,5,6};
    int target = 4;
    int size = sizeof(a)/sizeof(a[0]);
    int index = binarySearch(target, a, size);
    if(index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";
    return 0;
}
