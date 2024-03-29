class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int fast = nums[0];
        int slow = nums[0];
        
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast != slow);
        
        slow = nums[0];
        
        while(slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};