#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    //srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
     srand(time(NULL));
    int tes =1;
    //printf("10\n");
    while(tes--){
    int n = 10000; //10000rand() % 20 + 1; 
    printf("%d\n", n);
    //set<int> used;
    for(int i = 0; i < n; ++i) {
        printf("%d ", 1 + rand() % 20);
    }
    printf("\n");
    for(int i = 0; i < n; ++i) {
        printf("%d ", 1 + rand() % 20);
    }
    int l = rand() % n+1, k = rand() % n +1;
    if(l>k) swap(l, k);
    printf("\n%d %d\n", k, l);
    //puts("");
    }
    
}
