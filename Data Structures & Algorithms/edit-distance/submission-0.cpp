class Solution {
public:
    int f(string &word1, string &word2,int n,int m){
        int s=word1.size();
        int t=word2.size();
        if(n<0) return m+1;
        if(m<0)return n+1;
        int ans;
        if(word1[n]==word2[m]) {
            ans=f(word1,word2,n-1,m-1);
        }
        else{
            ans=1+min({f(word1,word2,n-1,m),f(word1,word2,n-1,m-1),f(word1,word2,n,m-1)});
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return f(word1,word2,n-1,m-1);
        
    }
};
