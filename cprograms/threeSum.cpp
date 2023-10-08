#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); i++)
    {
        set<int> numberSet;

        for (int j = i + 1; j < nums.size(); j++)
        {
            int third = -(nums[i] + nums[j]);
            if (numberSet.find(third) != numberSet.end())
            {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                st.insert(triplet);
            }
            numberSet.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> myvector;
    myvector.push_back(-1);
    myvector.push_back(0);
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(-1);
    myvector.push_back(-4);

    vector<vector<int>> outputVector = threeSum(myvector);
    for (const std::vector<int> &innerVector : outputVector)
    {
        // Iterate over the inner vector
        for (int num : innerVector)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}