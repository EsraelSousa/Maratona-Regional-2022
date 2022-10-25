// Problema 3407

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

    int numero_itens, qtde_bolinhos, entrada;

    cin >> numero_itens >> qtde_bolinhos;

    int qtde_bolinhos_natan = 0;
    for (int i = 0; i < numero_itens; i++)
    {
        cin >> entrada;

        if (entrada == 1)
            qtde_bolinhos_natan++;
    }

    if (qtde_bolinhos_natan == qtde_bolinhos) 
        cout << "Tudo certo.\n";
    else
    {
        int qtde_bolinhos_samuel = 0;
        for (int i = 0; i < numero_itens; i++)
        {
            cin >> entrada;

            if (entrada == 1)
                qtde_bolinhos_samuel++;
        }

        if (qtde_bolinhos_samuel == qtde_bolinhos)
            cout << "Pegou de Samuel.\n";
        else
            cout << "Pegou de um estranho.\n";
    
    }

    return 0;
}