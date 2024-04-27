#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    float unit_price;
    float total_cost;
    int quantity;
} Item;

typedef struct {
    char name[100];
    int quantity;
} Order;

void read_items(const char *filename, Item **items, int *item_count) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    *item_count = file_size / sizeof(Item);
    fseek(file, 0, SEEK_SET);

    *items = (Item *)malloc(file_size);
    fread(*items, sizeof(Item), *item_count, file);

    fclose(file);
}

void write_items(const char *filename, Item *items, int item_count) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(items, sizeof(Item), item_count, file);
    fclose(file);
}

void process_orders(const char *items_file, const char *orders_file) {
    Item *items = NULL;
    int item_count;
    read_items(items_file, &items, &item_count);

    Order *orders = NULL;
    int order_count;
    read_items(orders_file, (Item **)&orders, &order_count);

    for (int i = 0; i < order_count; i++) {
        for (int j = 0; j < item_count; j++) {
            if (strcmp(orders[i].name, items[j].name) == 0) {
                items[j].quantity -= orders[i].quantity;
                items[j].total_cost = items[j].unit_price * items[j].quantity;
                if (items[j].quantity <= 0) {
                    items[j].quantity = -1;
                }
            }
        }
    }

    int new_item_count = 0;
    for (int i = 0; i < item_count; i++) {
        if (items[i].quantity > 0) {
            items[new_item_count++] = items[i];
        }
    }

    write_items(items_file, items, new_item_count);

    free(items);
    free(orders);
}

void test_processing() {
    const char *items_file = "items.bin";
    const char *orders_file = "orders.bin";

    Item initial_items[] = {
            {"Product A", 10.0f, 100.0f, 10},
            {"Product B", 20.0f, 200.0f, 10},
            {"Product C", 30.0f, 300.0f, 10},
    };

    int initial_item_count = sizeof(initial_items) / sizeof(Item);

    write_items(items_file, initial_items, initial_item_count);

    Order orders[] = {
            {"Product A", 5},
            {"Product B", 10},
            {"Product C", 15},
    };

    int order_count = sizeof(orders) / sizeof(Order);
    write_items(orders_file, (Item *)orders, order_count);

    process_orders(items_file, orders_file);

    Item *updated_items = NULL;
    int updated_item_count;
    read_items(items_file, &updated_items, &updated_item_count);

    printf("Updated items in stock:\n");
    for (int i = 0; i < updated_item_count; i++) {
        printf("Name: %s, Quantity: %d, Total Cost: %.2f\n", updated_items[i].name, updated_items[i].quantity, updated_items[i].total_cost);
    }

    free(updated_items);
}

int main() {
    test_processing();
    return 0;
}