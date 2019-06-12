#include <bits/stdc++.h>
using namespace std;

int a[1000001];
map<int,int> mi;

int main()
{
    
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=1;
        mi.clear();
        
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int l=1;
        
        mi[a[1]]=1;
        
        for(int i=2;i<=n;i++)
        {
            int mark=mi[a[i]];
            if(mark>=l)
                l=mark+1;
            ans=max(ans,i-l+1);
            mi[a[i]]=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
