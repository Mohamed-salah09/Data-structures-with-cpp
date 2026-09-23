#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binary_search(vector<int> &arr, int n, int target)
{
    int left = 0;
    int right = arr.size();
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    // we will create an unsorted vector
    vector<int> arr = {8, 4, 6, 5, 2, 4};
    sort(arr.begin(), arr.end());
    int index = binary_search(arr, arr.size(), 2);
    cout << "the index is " << index << endl;
}