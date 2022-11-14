bool possible(vector<int> &boards, int n , int k, int mid)
{
    int paint = 1;
    int kaam = 0;
    
    for(int x = 0 ; x<n; x++)
    {
        if(paint > k) {
            return false;
        }
        if(kaam+boards[x]<=mid)
        {
            kaam = kaam +boards[x];
        }
        else 
        {
             paint++;
            if(paint>k ||  boards[x]>mid )
            {
                return false;
            }
            kaam=  boards[x];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
  int s=0, mid;
    int ans=-1, e;
    int sum = 0;
    int n =boards.size();
    for(int x = 0;  x<n; x++)
    {
        sum += boards[x];
    }
    e= sum;
    
    mid = s+(e-s)/2;
    
    while(s<=e)
    {
      if(possible(boards,n,k,mid))
      {
           ans =  mid;
          e = mid-1;
      }
        else
        {
            s = mid+1;
            
        }
        
     mid = s+(e-s)/2;
    }
    
    return ans;
}
