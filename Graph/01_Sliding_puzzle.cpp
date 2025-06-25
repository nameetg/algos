#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<int,vector<int>> m;
        string s="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++) s+=(board[i][j]+'0');
        }
        m[0]={1,3};
        m[1]={0,4,2};
        m[2]={1,5};
        m[3]={0,4};
        m[4]={3,1,5};
        m[5]={4,2};
        queue<tuple<int,string,int>> q;
        int fi=-1;
        for(int i=0;i<s.length();i++) if(s[i]=='0') fi=i;
        q.push({fi,s,0});
        map<string,int> v;
        v[s]=1;
        while(q.size()){
            int idx=get<0>(q.front());
            string b=get<1>(q.front());
            int len=get<2>(q.front());
            q.pop();
            if(b=="123450") return len;
            for(int e:m[idx]){
                swap(b[e],b[idx]);
                if(!v.count(b)){
                    q.push({e,b,len+1});
                    v[b]++;
                }
                swap(b[e],b[idx]);
            }
        }
        return -1;
    }
};