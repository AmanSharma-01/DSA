class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry=0, sum=0;
        string ans = "";
        
        while(i>=0 || j>= 0 || carry) {
            sum = carry + (i >=0 ? a[i]-'0' : 0) + (j>=0 ? b[j]-'0' : 0);
            carry = sum > 1 ? 1 : 0;
            ans += to_string(sum%2);
            i--,j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};