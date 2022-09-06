class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        vector<int> lm(n, 0), rm(n, 0);
        lm[0]=height[0];
        rm[n-1]=height[n-1];
        for(int i=1;i<n;i++) {
            lm[i] = max(lm[i-1], height[i]);
            rm[n-1-i] = max(rm[n-i], height[n-1-i]);
        }
        for(int i=n-2;i>=0;i--) {
        }
        
        for(int i=0;i<n;i++) {
            ans += min(rm[i], lm[i])-height[i];
        }
        return ans;
    }
};