#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for (int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int x = 0, y = 0, k = left;

    while (x < n1 && y < n2)
    {
        if (arr1[x] <= arr2[y])
            arr[k++] = arr1[x++];
        else
            arr[k++] = arr2[y++];
    }

    while (x < n1)
        arr[k++] = arr1[x++];

    while (y < n2)
        arr[k++] = arr2[y++];

    delete[] arr1;
    delete[] arr2;
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}