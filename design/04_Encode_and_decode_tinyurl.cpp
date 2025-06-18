#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    map<string,string> stl;
    map<string,string> lts;
    string base62="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string domain="http://tinyurl.com/";

    string getCode(){
        string res="";
        for(int i=0;i<6;i++) res+=base62[rand()%62];
        return res;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(lts.count(longUrl)) return lts[longUrl]+domain;
        string code=getCode();
        while(stl.count(code)) code=getCode();
        lts[longUrl]=code;
        stl[code]=longUrl;
        return domain+code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code=shortUrl.substr(domain.size());
        return stl.count(code)?stl[code]:"";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));