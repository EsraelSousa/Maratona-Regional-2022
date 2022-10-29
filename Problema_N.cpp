#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
typedef long long ll;
typedef pair<ll, int> pii;

ll cartas0[MAXN+5], cartas1[MAXN+5];
bool isInvertidas[MAXN+5];
int n = 0;
priority_queue<pii, vector<pii>, greater<pii>> ordemSairInvertida, ordemSairNInvertida;

void insereCarta(set<pii>& conjInvertidas, set<pii>& conjNInvertida, int i, ll& sumConj1, ll& sumConj2, int l){
    if(i < 1 || i>n){
        cout << "Erro i < 1 \n";
        return;
    }
    //cout << i << " valor de i\n";
    int sum = cartas0[i] + cartas1[i];
    set<pii> :: iterator it;
    if(conjInvertidas.size() == l){
        it = conjInvertidas.find(ordemSairInvertida.top());
        ordemSairInvertida.pop();
        //cout << it->second << " vai sair\n";
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
            ordemSairInvertida.push(make_pair(sum, i));
        }
        else{
            conjNInvertida.insert(make_pair(cartas0[i], i));
            sumConj2 += cartas0[i];
        }
    }
    else{
        conjInvertidas.insert(make_pair(sum, i));
        ordemSairInvertida.push(make_pair(sum, i));
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
    cout << conjInvertidas.size() << ' ' << conjNInvertida.size() << " tamanhos\n";
    //cout << ans  << ' ' << sumConj1 << ' ' << sumConj2 << " Resposta apos inserir tudo\n";
    for(it = conjInvertidas.begin(); it != conjInvertidas.end(); it++) cout << it->second << ' ';
    cout << "* ";
    for(it = conjNInvertida.begin(); it != conjNInvertida.end(); it++) cout << it->second << ' ';
    cout << sumConj1 + sumConj2 << " lin\n";
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
        cout << conjInvertidas.size() << ' ' << conjNInvertida.size() << " tamanhos\n";
        for(it = conjInvertidas.begin(); it != conjInvertidas.end(); it++) cout << it->second << ' ';
        cout << "* ";
        for(it = conjNInvertida.begin(); it != conjNInvertida.end(); it++) cout << it->second << ' ';
        cout << sumConj1 + sumConj2 << " lin\n";
    }
    return ans;
}

int read_int() {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (1) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (1) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int l, k;
    int tes;
    //cin >> tes;
    //while(tes--){
    cin >> n;
    vector<pii> input(n);
    //n = read_int();
    //cout << n << " valor n\n";
    for(int i=1; i<=n; i++)cin >> cartas0[i];// = read_int();
    for(int i=1; i<=n; i++) cin >> cartas1[i];// = read_int();
    cin >> k >> l;
    ll sumT = 0;
    for(int i=0; i<n; i++){
        input[i] = make_pair(cartas0[i+1] + cartas1[i+1], i+1);
        sumT += cartas0[i]  + cartas1[i];;
    }
    cout << sumT << '\n';
    sort(input.begin(), input.end());
    for(int i=0; i<n; i++){
        cout << input[i].first << ' ' <<  input[i].second << '\n';
    }
    //k = read_int(); l = read_int();
    ll aux = getMaxSum(l, k);
    cout << "Encerra pri\n";
    for(int i=1; i<=n/2; i++){
        swap(cartas0[i], cartas0[n-i+1]);
        swap(cartas1[i], cartas1[n-i+1]);
    }
    memset(isInvertidas, 0, sizeof(isInvertidas));
    while(ordemSairInvertida.size()) ordemSairInvertida.pop();
    //cout << max(aux, getMaxSum(l, k)) << '\n';
    printf("%lld\n", max(aux, getMaxSum(l, k)));
    //}
    return 0;
}

/*
10
53580627 697780592 429665569 16172712 200486124 435516652 711503384 868083709 616939240 492192996
746044490 57589903 507886672 433841177 918380467 426664522 281530079 729659740 980794901 914640542
8 6

out esperado = 8792267986

*/
