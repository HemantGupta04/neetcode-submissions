class Solution {
public:
    bool f(const string &s,const string &p,int i,int j){
        int n=s.size();
        int m=p.size();
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0){
            int k=j;
            while(k>=0){
                if(p[k]>='a' && p[k]<='z' || p[k]=='.'){
                    if(p[k+1]!='*'){
                        return false;
                    }
                }
                k--;
            }
            return true;
            
        }
        int ans=false;
        if(s[i]==p[j]){
            ans|=f(s,p,i-1,j-1);
        }
        else if(p[j]=='.'){
            ans|=f(s,p,i-1,j-1);
        }
        else if(p[j]=='*'){
            // if(j==0) return true;
            j--;
            ans|=f(s,p,i,j-1);
            if(j>=0){
             while(s[i]==p[j] || p[j]=='.'){
                ans|=f(s,p,i,j);
                i--;
                if(i<0)break;
             }
            }
        }
        return ans;

    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return f(s,p,n-1,m-1);
        
    }
};
