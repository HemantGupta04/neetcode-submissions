class Solution {
public:
    bool ischk(char ch) {
        return ((ch>='a' and ch<='z')|(ch>='A' and ch<='Z')|(ch>='0' and ch<='9'));
    }

    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(ischk(s[i]) and ischk(s[j])){
                if(tolower(s[i])!=tolower(s[j]))return false;
                i++;
                j--;
            }
            else if(ischk(s[i])){
                j--;
            }
            else if(ischk(s[j])){
                i++;
            }
            else{
                i++;
                j--;
            }

        }
        return true;
        
    }
};
