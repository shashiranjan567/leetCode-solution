class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // Edge case: if needle is longer than haystack
        if (m > n) return -1;

        // Loop through haystack
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            // Compare substring of haystack with needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we matched the whole needle
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
};