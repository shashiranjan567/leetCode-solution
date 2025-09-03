//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for(int i = 0; i < n; i++) {
            //This is actually the concept of monotonic stack
            while(!st.empty() && height[i] > height[st.top()]) {
                //It means "mid" is bounded from left (i.e. height[st.top()]) and right(i.e. height[i])
                int mid = st.top();
                st.pop();

                //But, for bounding mid, we need left (height[st.top()])
                if(st.empty()) {
                    break; //no left bound found
                }
                
                int right = i;
                int left  = st.top();

                int h = min(height[right], height[left]) - height[mid];
                int w = right - left - 1;
                
                water += (h*w);
            }
            st.push(i);
        }

        return water;
    }
};