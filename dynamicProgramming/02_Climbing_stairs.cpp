#include<bits/stdc++.h>
using namespace std;

using i64=long long;

class Solution {
public:
    int climbStairs(int n) {
        if(!n) return 1;
        i64 last=1,curr=2;
        for(int i=1;i<n;i++){
            i64 temp=last+curr;
            last=curr;
            curr=temp;
        }
        return last;
    }
};