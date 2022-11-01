#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e5;
typedef long long ll;
typedef pair<int, int> pii;
 
#define mp make_pair
 
int cartas0[MAXN+5], cartas1[MAXN+5];
bool isInvertidas[MAXN+5];
int n = 0;

ll getMaxSum(int l, int k){
    ll sumConj1 = 0, sumConj2 = 0;
    set<pii> conjInvertidas, conjNInvertida;
    set<pii> :: iterator it;
    ll ans = 0;
    // coloca todo mundo
    for(int i=1; i<=k; i++){
        sumConj1 += cartas0[i];
        if(conjInvertidas.size() == l){
            it = conjInvertidas.end();
            it--;
            if(-it->first < cartas1[i]){
                sumConj2 -= (-it->first);
                isInvertidas[it->second] = false;
                isInvertidas[i] = true;
                conjNInvertida.insert(mp(-cartas1[it->second], it->second));
                conjInvertidas.erase(it);
                conjInvertidas.insert(mp(-cartas1[i], i));
                sumConj2 += cartas1[i];
            }else{
                conjNInvertida.insert(mp(-cartas1[i], i));
            }
        }
        else{
            conjInvertidas.insert(mp(-cartas1[i], i));
            sumConj2 += cartas1[i];
            isInvertidas[i] = true;
        }
        
    }

    ans = max(ans, sumConj1 + sumConj2);

    for(int i=k; i>=1; i--){
        sumConj1 -= cartas0[i];
        sumConj1 += cartas0[n-(k-i)];

        // procuro o conjunto que ela está
        if(isInvertidas[i]) it = conjInvertidas.find(mp(-cartas1[i], i));
        else
            it = conjNInvertida.find(mp(-cartas1[i], i));
        
        // agora apaga
        if(isInvertidas[i]) conjInvertidas.erase(it);
        else conjNInvertida.erase(it);

        // se ela era invertida a soma dela esta em sumConj2, então tira
        if(isInvertidas[i]) sumConj2 -= cartas1[i];
        isInvertidas[i] = false;
        // agora coloco a nova carta
        if(conjInvertidas.size() < l){ // tirei um cara que estava invertido
            // o que é melhor? pegar alguém de 1 ate i-1, ou de n - (k-i)
            if(conjNInvertida.size()){ // tem alguém lá
                it = conjNInvertida.begin();
                if((-it->first) > cartas1[n-(k-i)]){ // alguem das cartas não invertida é melhor que a nova carta
                    conjInvertidas.insert(mp(it->first, it->second));
                    sumConj2 += (-it->first);
                    isInvertidas[it->second] = true;

                    conjNInvertida.erase(it);
                    conjNInvertida.insert(mp(-cartas1[n-(k-i)], n-(k-i)));
                    isInvertidas[n-(k-i)]=false;
                }
                else{
                    conjInvertidas.insert(mp(-cartas1[n-(k-i)], n-(k-i)));
                    sumConj2 += cartas1[n-(k-i)];
                    isInvertidas[n-(k-i)] = true;
                }
            }
            else{
                conjInvertidas.insert(mp(-cartas1[n-(k-i)], n-(k-i)));
                sumConj2 += cartas1[n-(k-i)];
            }
        }
        else{// vou colocar nas não invertidas
            it = conjInvertidas.end();
            it--;
            if(-it->first < cartas1[n-(k-i)]){ // alguem das cartas não invertida é melhor que a nova carta
                sumConj2 -= cartas1[it->second];
                conjNInvertida.insert(mp(-cartas1[it->second], it->second));
                isInvertidas[it->second] = false;
                conjInvertidas.erase(it);
                sumConj2 += cartas1[n-(k-i)];
                conjInvertidas.insert(mp(-cartas1[n-(k-i)], n-(k-i)));
                isInvertidas[n-(k-i)] = true;
            }
            else{
                conjNInvertida.insert(mp(-cartas1[n-(k-i)], n-(k-i)));
            }
        }

        ans = max(ans, sumConj1 + sumConj2);
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
    int l, k;
    int tes;
    n = read_int();
    for(int i=1; i<=n; i++) cartas0[i] = read_int();
    for(int i=1; i<=n; i++) cartas1[i] = read_int();
    k = read_int(); l = read_int();
    printf("%lld\n", getMaxSum(l, k));   
    return 0;
}
