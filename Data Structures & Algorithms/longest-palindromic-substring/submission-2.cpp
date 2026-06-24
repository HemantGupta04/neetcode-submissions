class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l-1>=0 && r+1<n && s[l-1]==s[r+1]){
                l--;
                r++;
            }
            string temp=s.substr(l,r-l+1);
            // cout<<temp<<endl;
            if(temp.size()>ans.size()){
                ans=temp;
                // cout<<i<<" odd : "<<ans<<endl;
            }
            l=i,r=i+1;
            if(s[l]==s[r]){
                while(l-1>=0 && r+1<n && s[l-1]==s[r+1]){
                    l--;
                    r++;
                }
                string temp2=s.substr(l,r-l+1);
                if(temp2.size()>ans.size()){
                    ans=temp2;
                    // cout<<"even : "<<ans<<endl;
                }
            }

        }
        return ans;
    }
};
