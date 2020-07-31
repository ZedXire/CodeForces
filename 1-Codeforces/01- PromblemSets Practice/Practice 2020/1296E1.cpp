//Mark XXVII
#include<bits/stdc++.h>

#define big(x) greater<x>()
#define ll long long int
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define PI 3.14159265
#define deb(x) cerr<<#x<<" : "<<x<<"\n";
#define deball(x) for(auto iit:x) cerr<<iit<<" ";cerr<<"\n";
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,b,c) for(i=b; i<c; ++i)
#define rrep(i,b,c) for(i=b; i>=c; --i)

#define M 998244353
#define LINF 1e18
#define INF INT_MAX
using namespace std;

int i,j,n,m;
vector<int> adj[201],col(201,0),vis(201,0);

bool dfs(int node, int c){
  vis[node]=1;
  col[node]=!c;
  for(auto child: adj[node]){
    if(!vis[child]){
      if(!dfs(child, !c)) return false;
    }
    else if(col[child]!=c) return false;
  }
  return true;
}

void solve(){
  string s;
  cin>>n>>s;
  rep(i,0,n-1)
    rep(j,i+1,n)
      if(s[i]>s[j]){
        adj[i+1].pb(j+1);
        adj[j+1].pb(i+1);
      }
  rep(i,1,n+1) 
    if(!vis[i]) 
       if(dfs(i,1)) { cout<<"NO\n"; return; }
  cout<<"YES\n";
  rep(i,1,n+1) cout<<col[i];
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
  // cin>>t;
  while(t--)
    solve();
} 