#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currentSum += nums[i];
        if (nums[i] > currentSum)
        {
            currentSum = nums[i];
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> myvector = {-2, -1};

    int max = maxSubArray(myvector);

    std::cout << max;
}