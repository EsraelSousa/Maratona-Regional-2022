#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for(int i=0; i<n; i++){
		int j = i;
		while(j<n && s[j] == 'a' && s[j+1] == s[j]) j++;
		if(s[i] == 'a' && j>i)
			ans += j-i+1;
		i = j;
	}
	cout << ans << '\n';
	return 0;
}
