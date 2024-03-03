#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 1001

int compare(const void *a, const void *b){
    return *((char *) a) - *((char *) b);
}

int main(){
    int n;
    char s[1001];
    char m[1001];
    scanf("%d\n %s\n %s", &n, s, m);

    qsort(s, n, sizeof(char), compare);
    qsort(m, n, sizeof(char), compare);

    int cnt = 0;
    int j = 0;

    for(int i = 0; i < n; i++){
        while (j < n && s[i] > m[j]){
            j++;
        }
        if(j >= n){
            cnt++;
        }
        j++;
    }
    printf("%d\n", cnt);
    cnt = 0;
    j = 0;
    for(int i = 0; i < n; i++){
        while(j < n && s[i] >= m[j]){
            j++;
        }
        if(j < n){
            cnt++;
        }
        j++;
    }
    printf("%d\n", cnt);
    return 0;
}