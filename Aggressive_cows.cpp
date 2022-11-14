
bool possible(vector<int> &stalls, int n,int k, int mid)
{
  int cow = 1;
    int pos = stalls[0];
    
    for(int i=0;i<n;i++){
    if( stalls[i]-pos>=mid)
    {
        cow++;
        if(cow==k)
        {
            return true;
        }
        pos = stalls[i];
    }
   }
   return false; 
}




int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    
   int n = stalls.size();
    int s=0, e,mid,ans=-1,maxi=-1;
    
    for(int i = 0; i <n; i++)
    {
        maxi = max(maxi,stalls[i]);
    }
    
    e = maxi;
    mid = s+(e-s)/2;
    
    while(s<=e)
    {
        if(possible(stalls,n,k,mid))
        {
          ans = mid;
          s= mid+1;
        }
        
        else{
            e = mid-1;
        }
        
        mid = s+(e-s)/2;
    }
    return ans;
}
