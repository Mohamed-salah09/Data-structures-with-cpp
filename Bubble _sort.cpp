#include <iostream>
using namespace std;

void bubble(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {3, 2, 1};

    bubble(arr, 3);

    for (auto n : arr)
    {
        cout << n << " ";
    }

    return 0;
}