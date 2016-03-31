/*
Follow up for H-Index: What if the citations array is sorted in ascending order? 
Could you optimize your algorithm?

Hint:
Expected runtime complexity is in O(log n) and the input is sorted.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(citations[mid] < (int)citations.size() - mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return (int)citations.size() - left;
    }
};
