#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Set {
    Node* head;
} Set;

Set* createSet() {
    Set* set = (Set*)malloc(sizeof(Set));
    set->head = NULL;
    return set;
}

void insert(Set* set, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (set->head == NULL) {
        set->head = newNode;
    } else {
        Node* current = set->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void intersect(Set* setA, Set* setB, Set* result) {
    Node* currentA = setA->head;
    while (currentA != NULL) {
        int data = currentA->data;
        Node* currentB = setB->head;
        while (currentB != NULL) {
            if (currentB->data == data) {
                insert(result, data);
                break;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
}

void printSet(Set* set) {
    if (set->head == NULL) {
        printf("No possible routes\n");
    } else {
        Node* current = set->head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void deleteSet(Set* set) {
    Node* current = set->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

int main() {
    int n;
    scanf("%d", &n);

    Set* possibleRoutes = createSet();
    Set* allRoutes = createSet();

    for (int i = 0; i < n; i++) {
        int r;
        scanf("%d", &r);

        Set* currentRoutes = createSet();

        for (int j = 0; j < r; j++) {
            int route;
            scanf("%d", &route);
            insert(currentRoutes, route);
            insert(allRoutes, route);
        }

        if (i == 0) {
            while (currentRoutes->head != NULL) {
                insert(possibleRoutes, currentRoutes->head->data);
                currentRoutes->head = currentRoutes->head->next;
            }
        } else {
            Set* result = createSet();
            intersect(possibleRoutes, currentRoutes, result);
            deleteSet(possibleRoutes);
            possibleRoutes = result;
        }

        deleteSet(currentRoutes);
    }

    printSet(possibleRoutes);

    deleteSet(possibleRoutes);
    deleteSet(allRoutes);

    return 0;
}