class Solution {
public:
   /* int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
        }
        return minHeap.top();
        
    }*/
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> maxHeap;
        for(int i = 0; i < nums.size();i++){
            maxHeap.push(nums[i]);
        }

        for(int i = 1; i < k; i++){

            maxHeap.pop();

        }
        
        return maxHeap.top();

    }
};