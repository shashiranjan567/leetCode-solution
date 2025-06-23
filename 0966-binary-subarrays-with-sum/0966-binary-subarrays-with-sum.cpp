class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map <int, int> prefixSumCount;

        prefixSumCount[0] = 1;

        int sum = 0, count = 0;

        for (int i : nums){
            sum += i;

            if (prefixSumCount.find(sum - goal)  != prefixSumCount.end()){
                count += prefixSumCount[sum - goal];
            }

            prefixSumCount[sum]++;
        }
        return count;
    }
};