#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOMAIN_LENGTH 100

void splitDomain(char *domain, char **subdomains) {
    int len = strlen(domain);
    int dot_count = 0;
    for (int i = 0; i < len; i++) {
        if (domain[i] == '.') {
            dot_count++;
        }
    }

    char *token = strtok(domain, ".");
    int i = dot_count;
    while (token != NULL) {
        subdomains[i--] = token;
        token = strtok(NULL, ".");
    }
}

char** subdomainVisits(char **cpdomains, int cpdomainsSize, int* returnSize) {
    char **result = (char **)malloc(sizeof(char *) * cpdomainsSize * 3);
    *returnSize = 0;

    for (int i = 0; i < cpdomainsSize; i++) {
        char *cpdomain = cpdomains[i];
        char *token = strtok(cpdomain, " ");
        int count = atoi(token);
        char *domain = strtok(NULL, " ");

        char *subdomains[MAX_DOMAIN_LENGTH];
        splitDomain(domain, subdomains);

        int subdomains_count = 0;
        while (subdomains[subdomains_count] != NULL) {
            char *subdomain = (char *)malloc(MAX_DOMAIN_LENGTH * sizeof(char));
            strcpy(subdomain, subdomains[subdomains_count]);
            for (int j = subdomains_count + 1; j <= MAX_DOMAIN_LENGTH && subdomains[j] != NULL; j++) {
                strcat(subdomain, ".");
                strcat(subdomain, subdomains[j]);
            }
            result[(*returnSize)++] = subdomain;
            subdomains_count++;
        }
    }

    return result;
}

void printResult(char **result, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("\"%s\"", result[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void testSubdomainVisits() {
    char *cpdomains1[] = {"9001 discuss.codeforces.com"};
    int size1;
    char **result1 = subdomainVisits(cpdomains1, 1, &size1);
    printf("Input: [\"9001 discuss.codeforces.com\"]\nOutput: ");
    printResult(result1, size1);

    char *cpdomains2[] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    int size2;
    char **result2 = subdomainVisits(cpdomains2, 4, &size2);
    printf("\nInput: [\"900 google.mail.com\", \"50 yahoo.com\", \"1 intel.mail.com\", \"5 wiki.org\"]\nOutput: ");
    printResult(result2, size2);
}

int main() {
    testSubdomainVisits();
    return 0;
}