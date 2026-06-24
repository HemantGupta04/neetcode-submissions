class Solution {
public:

    bool f(string s1,string s2,string s3,int i,int j,int k,int change,int a,int b){
        if(k==s3.size()){
            if(i==s1.size() && j==s2.size() && abs(a-b)<=1) return true;
            else return false;
        }
        if(i<s1.size() && j<s2.size()&&s3[k]==s1[i] && s3[k]==s2[j]){
            if(change==1){
                return f(s1,s2,s3,i+1,j,k+1,1,a,b)|f(s1,s2,s3,i,j+1,k+1,2,a+1,b);
            }
            else{
                return f(s1,s2,s3,i+1,j,k+1,1,a,b+1)|f(s1,s2,s3,i,j+1,k+1,2,a,b);
            }
        }
        else if(i<s1.size()&&s3[k]==s1[i]){
            if(change==1){
                return f(s1,s2,s3,i+1,j,k+1,1,a,b);
            }
            else{
                return f(s1,s2,s3,i+1,j,k+1,1,a+1,b);
            }
        }
        else if(j<s2.size()&&s3[k]==s2[j]){
            if(change==2){
                return f(s1,s2,s3,i,j+1,k+1,2,a,b);
            }
            else{
                return f(s1,s2,s3,i,j+1,k+1,2,a,b+1);
            }

        }
        else {
            return false;
        }



    }
    bool isInterleave(string s1, string s2, string s3) {
        int s=s1.size();
        int t=s2.size();
        int q=s3.size();
        if(s+t!=q){
            return false;
        }
        if(s==0 && t==0 && q==0) return true;
        if(s3[0]==s1[0] && s3[0]==s2[0]){
            return f(s1,s2,s3,1,0,1,1,1,0)|f(s1,s2,s3,0,1,1,2,0,1);
        }
        else if(s3[0]==s1[0]){
            return f(s1,s2,s3,1,0,1,1,1,0);
        }
        else if(s3[0]==s2[0]){
            return f(s1,s2,s3,0,1,1,2,0,1);
        }
        else{
            return false;
        }

        
    }
};
