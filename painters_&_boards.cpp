#include <bits/stdc++.h> 
 bool possible(vector<int> &pages, int n, int b, int mid)
 {
     int student = 1;
     int page = 0;
     
     for(int x = 0 ; x<n ; x++)
     {
          if(student >b)
         {

             return false;
         }
       
         if(page+pages[x]<=mid)
         {
             page = page+pages[x];
         }
         else 
         {
             student ++;
                 if(student > b || pages[x]>mid)
                 {
                       return false;
                 }
             page =pages[x];
             
         }
        
    
      }
       return true;
 }
int allocateBooks(vector<int> &pages, int n, int b)
{
    if(b>n)
    {
      return -1;
    }

   int s = 0, mid ;
    int e,sum=0;
    int ans=-1;
   for(int x=0 ;x<n; x++)
   {
   sum+=pages[x];
   }
    e =sum;
    
    mid = s+(e-s)/2;
        
       while (s<=e)
       {
            if(possible(pages,n, b,mid))
            {
                ans  =  mid;
                e = mid-1;
            }
             else{
                 s= mid+1;
             }    
           mid =s+(e-s)/2;
       }
    return ans;    
}
