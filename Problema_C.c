// Problema 3398

#include <stdio.h>
 
int main() {
 
    double cotacao_moeda;
    int qtde_moedas;
    
    scanf("%lf", &cotacao_moeda);
    scanf("%d", &qtde_moedas);
    
    printf("%.2f\n", cotacao_moeda * qtde_moedas);
 
    return 0;
}