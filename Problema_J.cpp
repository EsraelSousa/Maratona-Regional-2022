#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int freq[23];

int getPontos(int x){
	if(x>10) return 10;
	return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n, x;
    int sumM, sumJ;
    for(int i=1; i<14; i++) freq[i] = 4;
    cin >> n; // leitura de n
    
    cin >> sumJ >> x;
    freq[sumJ]--, freq[x]--;
    sumJ = getPontos(sumJ);
    sumJ += getPontos(x);
    
    cin >> sumM >> x;
    freq[sumM]--, freq[x]--;
    sumM = getPontos(sumM);
    sumM += getPontos(x);
    
    for(int i=0; i<n; i++){
    	cin >> x;
        freq[x]--;
        x = getPontos(x);
    	sumJ += x;
    	sumM += x;
    }
    /*
    aqui deve estar o BO
    deve ganhar quem tem 23 pontos
    */
    if(max(sumJ, sumM) + 10 < 23) cout << "-1\n";
    else if(sumJ == sumM){
        int f = 23 - sumM;
        if(freq[f] && f<=10) cout << f << '\n';
        else cout << "-1\n";
    }
    else if(sumJ > sumM){
        for(int i = 24-sumJ; i<=13; i++){
            if(freq[i] && sumJ + getPontos(i) > 23 && sumM + getPontos(i) <= 23){
                cout << i << '\n';
                exit(0);
            }
        }
        cout << "-1\n";
    }
    else{
        for(int i = 23 - sumM; i<=13; i++){
            if(freq[i] && sumM + getPontos(i) <= 23){
                cout << i << '\n';
                exit(0);
            }
        }
        cout << "-1\n";
    }
    return 0;
}
