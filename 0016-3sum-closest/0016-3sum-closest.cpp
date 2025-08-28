class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Step 1: sort the array
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2]; // initialize with first three numbers

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closestSum if current is closer to target
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            // Move pointers
            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return target; // exact match
            }
        }
    }

    return closestSum;
    }
};