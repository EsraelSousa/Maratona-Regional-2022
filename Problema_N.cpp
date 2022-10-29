#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
typedef long long ll;
typedef pair<int, int> pii;

int cartas0[MAXN+5], cartas1[MAXN+5];
bool isInvertidas[MAXN+5];
int n = 0;

void insereCarta(set<pii>& conjInvertidas, set<pii>& conjNInvertida, int i, ll& sumConj1, ll& sumConj2, int l){
    if(i < 1 || i>n){
        cout << "Erro i < 1 \n";
        return;
    }
    //cout << i << " valor de i\n";
    int sum = cartas0[i] + cartas1[i];
    set<pii> :: iterator it;
    if(conjInvertidas.size() == l){
        it = conjInvertidas.end();
        it--;
        //cout << it->first << " sum do ultimo\n";
        if(it->first < sum){
            sumConj1  -= it->first;
            conjNInvertida.insert(make_pair(cartas0[it->second], it->second));
            sumConj2 += cartas0[ it->second ];
            isInvertidas[it->second] = false;
            conjInvertidas.erase(it);
            conjInvertidas.insert(make_pair(sum, i));
            isInvertidas[i] = true;
            sumConj1 += sum;
        }
        else{
            conjNInvertida.insert(make_pair(cartas0[i], i));
            sumConj2 += cartas0[i];
        }
    }
    else{
        conjInvertidas.insert(make_pair(sum, i));
        sumConj1 += sum;
        isInvertidas[i] = true;
    }
}

ll getMaxSum(int l, int k){
    ll sumConj1 = 0, sumConj2 = 0;
    set<pii> conjInvertidas, conjNInvertida;
    set<pii> :: iterator it;
    ll ans = 0;
    //cout << k << " valor k\n";
    for(int i=1; i<=k; i++){
        //cout << i << " valor i Princ\n";
        insereCarta(conjInvertidas, conjNInvertida, i, sumConj1, sumConj2, l);
    }
    ans = max(ans, sumConj1 + sumConj2);
    //cout << ans  << ' ' << sumConj1 << ' ' << sumConj2 << " Resposta apos inserir tudo\n";
    for(int i=k; i>1; i--){
        if(isInvertidas[i]){
            it = conjInvertidas.find(make_pair(cartas0[i] + cartas1[i], i));
            sumConj1 -= it->first;
            conjInvertidas.erase(it);
        }
        else{
            //cout << " entra\n";
            it = conjNInvertida.find(make_pair(cartas0[i], i));
            sumConj2 -= it->first;
            conjNInvertida.erase(it);
            //cout << conjNInvertida.size() << " tam conj\n";
        }
        // 5 - 2 - 2 = 
        //cout << n - (k-i) << " posicao pegar\n";
        insereCarta(conjInvertidas, conjNInvertida, n-(k-i), sumConj1, sumConj2, l);
        ans = max(ans, sumConj1 + sumConj2);
        //cout << ans << " respostas parciais\n";
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int l, k;
    int tes;
    //cin >> tes;
    //while(tes--){
    cin >> n;
    //cout << n << " valor n\n";
    for(int i=1; i<=n; i++) cin >> cartas0[i];
    for(int i=1; i<=n; i++) cin >> cartas1[i];
    cin >> k >> l;
    ll aux = getMaxSum(l, k);
    for(int i=1; i<=n/2; i++){
        swap(cartas0[i], cartas0[n-i+1]);
        swap(cartas1[i], cartas1[n-i+1]);
    }
    memset(isInvertidas, 0, sizeof(isInvertidas));
    cout << max(aux, getMaxSum(l, k)) << '\n';
    //}
    return 0;
}
