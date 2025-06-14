#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create a hash map to store values and their indices
        std::unordered_map<int, int> numMap;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];
            
            // Check if the complement exists in our map
            if (numMap.find(complement) != numMap.end()) {
                // Found a solution - return the indices
                return {numMap[complement], i};
            }
            
            // Store the current number and its index in the map
            numMap[nums[i]] = i;
        }
        
        // No solution found (but problem states there is always one solution)
        return {};
    }
};