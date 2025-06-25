#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        map<string,int> m;
        for(string &s:words) m[s]++;
        map<string,bool> dp;
        function<bool(string )> f=[&](string word)-> bool{
            if(dp.count(word)) return dp[word];
            for(int i=1;i<=word.length();i++){
                string pref=word.substr(0,i);
                string suff=word.substr(i,word.length()-i);
                if(m.count(pref)&&(m.count(suff)||f(suff))) return dp[word]=true;
            }
            return dp[word]=false;
        };
        for(string &word:words){
            if(f(word)) res.push_back(word);
        }
        return res;
    }
};