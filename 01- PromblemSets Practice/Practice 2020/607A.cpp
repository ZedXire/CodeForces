//Mark XXVI
#include<bits/stdc++.h>

#define big(x) greater<x>()
#define ll long long int
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" : "<<x<<"\n";
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,b,c) for(i=b; i<c; ++i)
#define rrep(i,b,c) for(i=b; i>=c; --i)

#define M 998244353
#define LINF 1e18
#define INF INT_MAX
int i,j;
using namespace std;


void solve()
{
  ll n,k;
  cin>>n;
  map<int,int> mp;
  int a[n],b[n];
  rep(i,0,n) cin>>a[i]>>b[i],mp[a[i]+1]=b[i];

  int nd[1000005]={};
  rep(i,1,1000005)
    if(!mp[i]) nd[i]=nd[i-1];
    else  nd[i]=1+nd[max(0,i-mp[i]-1)];
  
  int ma=0;
  rep(i,1,1000005) ma=max(ma,nd[i]);
  deb(ma)
  cout<<n-ma<<endl;
}

int main()
{
  //Skipped in presense of online judge.
  #ifndef ONLINE_JUDGE
  freopen("/home/zeddie/Documents/input.txt","r",stdin);
  freopen("/home/zeddie/Documents/output.txt","w",stdout);
  freopen("/home/zeddie/Documents/error.txt","w",stderr);
  #endif

  IOS()
  ll t=1;
  //cin>>t;
  while(t--)
    solve();
}