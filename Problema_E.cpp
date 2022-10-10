#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1e6+5;

vector<set<int>> alts(MAXA);

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, h, ans = 0, posicao;
	int maior = 0, menor = 1e6;
	set<int> :: iterator it; //um ponteiro
	cin >> n; // qtd balao
	for(int i=1; i<=n; i++){
		cin >> h;
		maior = max(maior, h);
		menor = min(menor, h);
		alts[h].insert(i); // posicao do balao com altura h
	}
	// contar a qtd flecha necesaaria
	for(int i=maior; i>=menor; i--){
		while(alts[i].size()){// tenho que jogar flechas enquanto tiver baloes nessa altuta
			ans++; //aumento a qtd de flecha necessaria
			h = i-1;
			it = alts[i].begin();
			posicao = *it;
			//cout << posicao << '\n';
			alts[i].erase(it); // apaga (estourou o primeiro balao de altura i)
			
			it = alts[h].lower_bound(posicao);
			
			// vejo se tem algum balao de altura i-1 que aparece depois desse balao
			while(it != alts[h].end()){
				posicao = *it;
				alts[h].erase(it);
				h--;
				it = alts[h].lower_bound(posicao);
			}
			
		}
	}
	cout << ans << '\n';
	return 0;
}
