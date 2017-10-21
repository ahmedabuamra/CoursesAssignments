/* O(N) solution *//* :D */
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
	int n; cin >> n;
	for(int i = 0 ; i < n ;i++) cin >> a[i];
	int ind1 = -1 , ind2 = -1;
	for(int i = 0 ; i < n ; i++)
		if(ind1 == -1 || a[i] > a[ind1])
			ind1 = i;

	for(int i = 0 ; i < n ; i++)
		if((ind2 == -1 || a[i] > a[ind2]) && (ind1 != ind2))
			ind2 = i;

	long long ans = (long long)a[ind1] * (long long)a[ind2];
	cout << ans << endl;
}

/* O(Nlog(N)) Solution *//*
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
	int n; cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	sort(a,a+n);
	long long ans = (long long)(a[n-1])*(long long)(a[n-2]);
	cout << ans << endl;
}*/
