//-_- joss implementation

/**
   ques chilo-->
   alice remove element less than or equal to k-i+1
   r bob kono ekta element ar sathe k-i+1 add korbe
   bt ekhane k ta main jeta binary search use kore ber korsi..

   1 1 2
   suppose k=2..i=1 k-i+1=2 remove 2 or less
   1 1
   add 2..
   1 3

   i=2 k-i+1=1 remove 1
   3
   add 1
   4

**/

#include<bits/stdc++.h>
using namespace std;
#define int long long

bool Possible(vector<int> a,int n,int k){
    multiset<int> s;
    for(auto i:a)
    {
        s.insert(i);
    }

    for(int i=1;i<=k;i++)
    {
        if(s.empty())return false;
        int req=k-i+1;
        auto ii=s.upper_bound(req);
        if(ii==s.begin())return false;
        ii--;

        s.erase(ii);
        if(!s.empty())
        {
            ii=s.begin();
            int v=(*ii);
            v+=(req);
            s.erase(ii);
            s.insert(v);
        }
    }
    return true;
}

 main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int k;
        int low=0,high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(Possible(a,n,mid))
            {
                k=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        cout<<k<<endl;
    }

}
