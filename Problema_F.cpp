#include <bits/stdc++.h>

using namespace std;

/*
a ideia é dada uma palavra da entrada, ela vai possuir um *,
nessa posição vamos colocar todas as letras possiveis [a, b]
e adicionar no conjunto de todas as palavras.
Após fazer isso para todas as palavras, vamos ordena-lás
para computar a resposta dada uma palavra na posição i
vamos buscar a primeira palavra na posição j tal que j > i,
como o conjunto esta ordenado podemos fazer com busca binária.
*/ 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, c, p;
	vector<string> palavras; // conjunto de todas as palavras possiveis
	string palavra, ans_palavra;
	int ans_qtd = 0; // qtd que a resposta aparece
	cin >> n >> c; // qtd palavras e tamanho de cada palavra
	for(int i=0; i<n; i++){
		cin >> palavra;
		p = 0;
		while(palavra[p] != '*' && p<c) p++; // pego o indice que esta o  *
		// agora vou substituir o * por todas as possibilidades de letras e adicionar no conjunto de palavras
		palavra[p] ='a';
		while(palavra[p] <= 'z'){
			palavras.push_back(palavra); // adiciono no fim do vetor
			palavra[p]++;
		}
	}
	// agora ordenamos todas as palavras
	sort(palavras.begin(), palavras.end());
	// agora computamos nossa resposta
	// vai ser algo no mesmo raciocinio do problema A
	for(int i=0; i<(int)palavras.size(); i++){
		int qtd = (int)(upper_bound(palavras.begin()+i, palavras.end(), palavras[i]) - (palavras.begin()+i)); // upper_bund retorna um 
                                                                                                               // ponteiro para a 1ª palavra diferente
		if(qtd > ans_qtd){ // vejo se a qtd que aparece é maior, se for igual eu não pego pq tem que ser a menor lexico.
			ans_palavra = palavras[i];
			ans_qtd = qtd;
		}
		i += qtd-1; // dou um salto na qtd de palavras repetidas
	}
	cout << ans_palavra << ' ' << ans_qtd << '\n'; // mostro a resposta
	return 0;
}
