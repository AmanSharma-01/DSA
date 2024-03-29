class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1), count(n, 1);
        int maxLen=1;
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                    if(len[j]+1 > len[i]) {
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    } else if(len[j]+1 == len[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++) {
            if(len[i] == maxLen) {
                ans += count[i];
            }
        }
        
        return ans;
    }
};