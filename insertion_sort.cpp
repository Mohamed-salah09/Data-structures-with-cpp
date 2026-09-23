#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void insertion(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        swap(arr[j + 1], arr[i]);
    }
}
int main()
{

    vector<int> arr = {4, 5, 6, 8, 8, 7, 10};
    insertion(arr, arr.size());

    // we will print the array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}