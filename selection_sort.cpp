#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selection(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }
}
int main()
{

    vector<int> arr = {4, 5, 6, 8, 8, 7, 10};
    selection(arr, arr.size());

    // we will print the array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}