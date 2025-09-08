//Approach-1
//T.C : O(m * (m + nlogn)
//S.C : O(n)
class Solution {
    int m, n;
    bool isValid(int seconds, vector<int> changeIndices, vector<int> nums) {

        vector<int> lastPosition(n+1, -1);

        for (int i = 0; i <= seconds; i++) {
            int idx = changeIndices[i];
            lastPosition[idx] = i+1; //Timing is 1 based
        }

        for(int i = 1; i <= n; i++) {
            if(lastPosition[i] == -1) { //index i was not there in the range till seconds
                return false;
            }
        }

        map<int, int> positionIndexMap; //so that it's kept in sorted order
        for(int i = 1; i <= n; i++) {
            int position = lastPosition[i];
            positionIndexMap[position] = i;
        }

        int used_till = 0;
        for (auto& [position, index] : positionIndexMap) {

            int req = 1 + nums[index-1]; //+1 is for marking it when it becomes 0
            if (used_till + req > position) 
                return false;

            used_till += req;
        }

        return true;
    }
    
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        m = changeIndices.size();
        n = nums.size();

        for (int time = 0; time < m; time++) {
            if(isValid(time, changeIndices, nums)) 
                return time+1; //1 based index
        }
        
        return -1;
    }
};

/*
//Approach-2 (Replace main for loop with Binary Search on answer (time))
//T.C : O(log(m) * (m + nlogn)
//S.C : O(n)
class Solution {

    int m, n;
    bool isValid(int seconds, vector<int> changeIndices, vector<int> nums) {

        vector<int> lastPosition(n+1, -1);

        for (int i = 0; i <= seconds; i++) {
            int idx = changeIndices[i];
            lastPosition[idx] = i+1;
        }

        for(int i = 1; i <= n; i++) {
            if(lastPosition[i] == -1) { //index i was not there in the range till seconds
                return false;
            }
        }

        map<int, int> positionIndexMap; //so that it's kept in sorted order
        for(int i = 1; i <= n; i++) {
            int position = lastPosition[i];
            positionIndexMap[position] = i;
        }

        int used_till = 0;
        for (auto& [position, index] : positionIndexMap) {
            int req = 1 + nums[index-1]; //+1 is for marking it when it becomes 0
            if (used_till + req > position) 
                return false;

            used_till += req;
        }

        return true;
    }
    
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        m = changeIndices.size();
        n = nums.size();

        int time_left  = 0;
        int time_right = m-1;
        int result     = -1;

        while(time_left <= time_right) {
            int time_mid = time_left + (time_right - time_left)/2;

            if(isValid(time_mid, changeIndices, nums)) {
                result = time_mid+1;
                time_right = time_mid-1;
            } else {
                time_left = time_mid+1;
            }
        }
        
        return result;
    }
};
*/



