//Mark XXXIV
#include<bits/stdc++.h>

#define ll              long long
#define mp              make_pair
#define pb              push_back
#define lb              lower_bound
#define ub              upper_bound
#define all(x)          x.begin(), x.end()
#define big(x)          greater<x>()

#define sp              fixed<<setprecision
#define vi              vector<int>
#define vvi             vector<vi>
#define vll				vector<ll>
#define pi              pair<int,int>
#define vpi             vector<pi>
#define F               first
#define S               second

// #define endl            "\n"
#define PI              3.14159265
// #define M               100000000
#define LINF            LONG_MAX
#define NL              LONG_MIN
#define INF             INT_MAX
#define NI              INT_MIN

#define IOS()           ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x)          cerr<<#x<<" : "<<x<<"\n";
#define deball(x)       for(auto iit:x) cerr<<" "<<iit;cerr<<"\n";
#define rep(i,b,c)      for(i=b; i<c; ++i)
#define rrep(i,b,c)     for(i=b; i>=c; --i)

using namespace std;
//Code begins from here!!

void solve() {
	int n, m, x;
	cin >> n >> m >> x;
	vi a(n), ans(n);
	vpi v;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		v.pb({a[i], i});
	}

	sort(all(v));
	priority_queue<pi> pq;

	for (int i = 0; i < n; ++i) {
		if (i < m) {
			pq.push({ -v[i].first, i + 1});
			ans[v[i].second] = i + 1;
		}
		else {
			auto z = pq.top();
			pq.pop();
			int h = abs(z.F), ind = z.S;
			h += v[i].F;
			ans[v[i].S] = ind;
			pq.push({ -h, ind});
		}
	}

	int mi = 0;
	while (!pq.empty()) {
		auto z = pq.top();
		pq.pop();

		if (!mi) mi = abs(z.F);
		else {
			if (abs(z.F) - mi > x) {
				cout << "NO" << endl;
				return;
			}
			else mi = min(mi, abs(z.F));
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
	cout << endl;

}

signed main() {
#ifndef ONLINE_JUDGE
	freopen ( "/home/zeddie/Documents/input.txt", "r", stdin );
	freopen ( "/home/zeddie/Documents/output.txt", "w", stdout );
	freopen ( "/home/zeddie/Documents/error.txt", "w", stderr );
#endif
	IOS()
	int t = 1;
	cin >> t;

	for (int i = 0; i < t; ++i)
		solve();
}

