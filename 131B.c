#include <stdio.h>

int main(){
    int number_clients;
    scanf("%d", &number_clients);

    long long array[25] = {0};
    int count = 0;
    long long sum = 0;

    for (int i=0; i < number_clients; i++){
        int client_parameter;
        scanf("%d", &client_parameter);

        if (client_parameter == 0) {
            sum += count;
            count++;
        } else {
            array[client_parameter+10]++;
        }
    }

    for (int i=0; i < 10; i++){
        sum = sum + array[i] * array[20-i];
    }

    printf("%lld", sum);

    return 0;
}