class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        map<int,vector<int>>m1;
        map<int,vector<int>>m2;
        int mxm=0;
        for(int i=0;i<intervals.size();i++){
            int len=intervals[i][1]-intervals[i][0]+1;
            m1[intervals[i][0]].push_back(len);
            m2[intervals[i][1]+1].push_back(len);
            mxm=max(mxm,intervals[i][1]);
        }
        map<int,int>mp;
        vector<int>ans(mxm+1,-1);
        ans[0]=0;
        for(int i=1;i<=mxm;i++){
            if(m1.find(i)!=m1.end()){
                for(int j=0;j<m1[i].size();j++){
                    mp[m1[i][j]]++;
                }
            }
            if(m2.find(i)!=m2.end()){
                for(int j=0;j<m2[i].size();j++){
                    mp[m2[i][j]]--;
                    if(mp[m2[i][j]]==0){
                        mp.erase(m2[i][j]);
                    }
                }
            }
            if(mp.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=(mp.begin()->first);
            }


        }
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        vector<int>write(queries.size());
        for(int i=0;i<queries.size();i++){
            if(queries[i]>mxm){
                write[i]=-1;
            }
            else{

                write[i]=ans[queries[i]];
            }

        }



        return write;
        
    }
};