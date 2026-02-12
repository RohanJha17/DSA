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
    int findPeak(MountainArray& mountainArr){
        int low=0, high = mountainArr.length()-1;
        while(low < high){
            int mid = low + (high-low)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
    int binarySearchAsc(MountainArray& mountainArr, int low, int high, int target){
        while(low <= high){
            int mid = low + (high-low)/2;

            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    int binarySearchDec(MountainArray& mountainArr, int low, int high, int target){
        while(low <= high){
            int mid = low + (high-low)/2;

            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);

        int left = binarySearchAsc(mountainArr, 0, peak, target);
        if(left != -1)
            return left;
        
        return binarySearchDec(mountainArr, peak+1, mountainArr.length()-1, target);
    }
};