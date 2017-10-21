#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
	int n; cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	sort(a,a+n);
	long long ans = a[n-1]*a[n-2];
	cout << ans << endl;
}
