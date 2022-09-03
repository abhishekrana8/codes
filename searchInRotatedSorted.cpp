int pivot(vector<int> arr)
{
    int n = arr.size();
    int s = 0, e = n-1;
    int mid= s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0])
        {
           s = mid+1;
        }
        else
        {
            e = mid;
        }
         mid= s+(e-s)/2;
    }

    return s;
}


int binary(vector<int>nums , int target,int s,int e)
{
    int n = nums.size();
    int mid =s+(e-s)/2;
    while(s<=e ){
        if(nums[mid]==target)
        {
            return mid;
        }
       if(nums[mid]>target)
       {
           e = mid-1;
       }
        else
        {
            s= mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
     int   n = nums.size();
       
        int pivots = pivot(nums);
  
        if(target>=nums[pivots] && target<=nums[n-1])
        {
            return binary(nums,target,pivots,n-1);
        }
        else {
            return binary(nums,target,0,pivots-1);
        }
        
    }
};
