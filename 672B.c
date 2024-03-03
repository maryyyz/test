#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    getchar();
    char str[n];
    gets(str);

    if(n > 26){
        printf("-1");
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(str[i] == str[j]){
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}