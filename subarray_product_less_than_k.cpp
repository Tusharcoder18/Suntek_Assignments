
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, long int k)
{
    int count = 0;
    int i, j, product, len = nums.size();

    for (i = 0; i < len; i++)
    {
        // Increment for single subarrays
        if (nums[i] < k)
            count++;
        product = nums[i];

        for (j = i + 1; j < len; j++)
        {
            // Calculate product for subarrays with multiple elements
            product = product * nums[j];

            // Increment if product is less than k
            if (product < k)
                count++;
            else
                break;
        }
    }

    return count;
}

int main()
{
    int n, temp;
    vector<int> nums;
    long int k;

    // Inputs
    printf("Enter size of input array");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> k;

    int result = solve(nums, k);
    cout << result << endl;

    return 0;
}
