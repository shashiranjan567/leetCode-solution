class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int left = 0, result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];

            // Total required if all elements between left and right became nums[right]
            long long required = (long long)(right - left + 1) * nums[right];

            // If we need more than k operations, shrink window
            while (required - total > k) {
                total -= nums[left];
                left++;
                required = (long long)(right - left + 1) * nums[right];
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
