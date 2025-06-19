#include<bits/stdc++.h>
using namespace std;

//dummy MountainArray class
class MountainArray{
  public:
  int length(){

  }

  int get(int m){

  }
};

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr, int n){
        int s=1,e=n-2;
        while(s<=e){
            int m=(s+e)/2;
            int midEle=mountainArr.get(m),leftEle=mountainArr.get(m-1),rightEle=mountainArr.get(m+1);
            if(midEle>leftEle&&midEle>rightEle) return m;
            else if(midEle>leftEle) s=m+1;
            else e=m-1;
        }
        return -1;
    }
    int findTargetInd(MountainArray &mountainArr, int s, int e, int target){
        if(!s){
            while(s<=e){
                int m=(s+e)/2;
                int ele=mountainArr.get(m);
                if(ele==target) return m;
                else if(ele>target) e=m-1;
                else s=m+1;
            }
            return -1;
        }
        while(s<=e){
            int m=(s+e)/2;
            int ele=mountainArr.get(m);
            if(ele==target) return m;
            else if(ele>target) s=m+1;
            else e=m-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peakInd=findPeak(mountainArr,n);
        int low=findTargetInd(mountainArr,0,peakInd,target);
        if(low!=-1) return low;
        int high=findTargetInd(mountainArr,peakInd+1,n-1,target);
        return high;
    }
};