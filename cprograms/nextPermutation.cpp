#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int length = nums.size();
    int end = -1;
    for (int i = length - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            end = i - 1;
            break;
        }
    }

    if (end == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int closerNumber = -1;
    int j;
    for (j = length - 1; j >= 0; j--)
    {
        if (nums[j] > nums[end])
        {
            break;
        }
    }

    // swap the two numbers
    swap(nums[end], nums[j]);

    // sort the  numbers after the end index
    reverse(nums.begin() + end + 1, nums.end());

    return;
}

int main()
{
    vector<int> myvector;
    myvector.push_back(2);
    myvector.push_back(1);
    myvector.push_back(5);
    myvector.push_back(4);
    myvector.push_back(3);
    myvector.push_back(0);
    myvector.push_back(0);

    nextPermutation(myvector);

    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}