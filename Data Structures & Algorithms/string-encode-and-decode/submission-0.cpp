class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs.size();i++){
            int len = strs[i].size();
            ans += to_string(len);
            ans += "#";
            ans += strs[i];
        }
        cout<<ans<<endl;

        return ans;

    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        int n=s.size();
        while(i<n){
            int len=0;
            string temp;
            while(i<n and s[i]!='#'){
                len*=10;
                len+=(s[i]-'0');
                i++;
            }
            i++;
            while(len and i<n){
                temp.push_back(s[i]);
                i++;
                len--;
            }
            ans.push_back(temp);
            
        }
        return ans;

    }
};
