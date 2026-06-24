class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=n;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l-1>=0 && r+1<n && s[l-1]==s[r+1]){
                l--;
                r++;
                ans++;
            }
            l=i,r=i+1;
            if(s[l]==s[r]){
                ans++;
                while(l-1>=0 && r+1<n && s[l-1]==s[r+1]){
                    l--;
                    r++;
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
