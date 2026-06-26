class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int>count(26,0);

        int n=s.size(),m=t.size();

        if(n!=m)return false;

        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for( auto i:count){
            if(i!=0)return false;
        }

        return true;

        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>,vector<string>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]-'a']++;
            }
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto [i,j]:mp){
            ans.push_back(j);
        }

        return ans;
        
    }
};
