// Problema 3408

#include <bits/stdc++.h>

using namespace std;

long long int converterStringParaInt(string valor_str, int tamanho_str)
{
    long long int soma = 0;
    for (int i = 0, j = tamanho_str - 1; i < tamanho_str; i++, j--)
        soma += (valor_str[i] - '0') * pow(10, j);
    
    return soma;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

    int numero_teste, soma = 0;;

    cin >> numero_teste;

    while (numero_teste--)
    {
        string entrada, auxiliar_str;

        cin >> entrada;

        for (int i = 0; i < entrada.size(); i++)
        {
            if (entrada[i] >= 48 && entrada[i] <= 57)
            {
                auxiliar_str.push_back(entrada[i]);
            }
        }

        soma += converterStringParaInt(auxiliar_str, auxiliar_str.size());
    }

    cout << soma << '\n';

    return 0;
}