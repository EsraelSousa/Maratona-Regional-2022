#include <bits/stdc++.h>

using namespace std;

int freq[30][15];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n, c, ans_qtd=0;
    cin >> n >> c;
    string ans_palavra;
    vector<string> palavras(n+5);
    for(int i=1; i<=n; i++){
        cin >> palavras[i];
        for(int j=0; j<c; j++){
            if(palavras[i][j] == '*') freq[0][j]++; // linha especial para asteriscos
            else freq[ palavras[i][j]-'a'+1 ][j]++; // ocorrencia da letra i na posição j
        }
    }

    // agora vamos computar nossa resposta
    for(int i=1; i<=n; i++){
        int p = 0;
        while(palavras[i][p] != '*') p++; // pego qual a posição da palavra tem um * pq ele é especial pois pode ser qualquer letra
        // agora vamos ver a menor qtd de vezes que uma letra aparece na quela posição da palavra, não contamos * nessa contagem
        int qtd = 1e9; // um número infinito para pegar o menor
        for(int j=0; j<c; j++){
            if(j == p) continue; // posição do * na palavra
            qtd = min(qtd, freq[ palavras[i][j] - 'a'+1 ][j]);
        }
        // agora vamos tentar modicar os caracteres na posição *
        // O * pode substituir qualquer caractere [a, b] e pegamos o que aparece mais
        int aparece_mais = 0;
        char c = 'a';
        for(int k=1; k<=26; k++){
            if(freq[k][p]+1 > aparece_mais){ // isso faz com que pegamos a menor lexi.
                aparece_mais = freq[k][p]+1;
                c = (char)(k-1+'a');
            }
        }
        qtd = max(qtd, aparece_mais); // isso tem que provar
        palavras[i][p] = c; // substituir pelo melhor caractere
        if(ans_qtd == qtd){ // tenho a mesma qtd de vezes, mas pego a menor lexi.
            ans_palavra = min(ans_palavra, palavras[i]);
        }
        else if(qtd > ans_qtd){
            ans_qtd = qtd;
            ans_palavra = palavras[i];
        }
    }
    cout << ans_palavra << ' ' << ans_qtd << '\n';
    return 0;
}
