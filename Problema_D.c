// Problema 3399

#include <stdio.h>

int main()
{
    int valor1, valor2, valor3, enesimo_valor;

    scanf("%d%d%d%d", &valor1, &valor2, &valor3, &enesimo_valor);

    int dif = valor3 - valor2;

    int valor_n = valor3;

    for (int i = 3; i < enesimo_valor; i++)
        valor_n += dif;

    printf("%d\n", valor_n);

    return 0;
}