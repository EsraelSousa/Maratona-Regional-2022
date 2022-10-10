#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int x;
    while(cin >> x){
        if(x!= 0 && x!=1){
            cout << "F\n";
            exit(0);
        }
    }
    cout << "S\n";
    return 0;
}
