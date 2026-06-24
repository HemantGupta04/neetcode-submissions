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
};
