/**
 * // This is MountainArray's API interface.
 * // You should not implement it or speculate about its implementation.
 *
 * class MountainArray {
 * public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &arr, int n) {

        int low = 0, high = n - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(arr.get(mid) < arr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    int searchAscending(MountainArray &arr,
                        int low, int high, int target) {

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if(val == target)
                return mid;

            if(val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int searchDescending(MountainArray &arr,
                         int low, int high, int target) {

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if(val == target)
                return mid;

            if(val > target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int findInMountainArray(int target,
                            MountainArray &mountainArr) {

        int n = mountainArr.length();

        int peak = findPeak(mountainArr, n);

        int left = searchAscending(
            mountainArr, 0, peak, target
        );

        if(left != -1)
            return left;

        return searchDescending(
            mountainArr, peak + 1, n - 1, target
        );
    }
};