#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shell_sort(vector<int> &arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2) // we will go through the even indicies
    {
        for (int i = gap; i < n; i++)
        {
            int current = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > current)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = current;
        }
    }
}

int main()
{
    vector<int> arr = {4, 5, 6, 8, 8, 7, 10};

    shell_sort(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}