#include <stdio.h>
#include <stdbool.h>

#define MAX_LAPTOPS 100
#define MAX_STORES 100

typedef struct {
    char company[100];
    float monitor_size;
    int is_touch;
    int price;
} Laptop;

typedef struct {
    char store_name[100];
    char location[100];
    Laptop niza[MAX_LAPTOPS];
    int n;
} ITStore;

void print_store_info(ITStore store) {
    printf("%s %s\n", store.store_name, store.location);
    for (int i = 0; i < store.n; i++) {

        printf("%s %g %d\n", store.niza[i].company, store.niza[i].monitor_size, store.niza[i].price);
    }
}

void najeftina_ponuda(ITStore niza[], int n) {
    int minPrice = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < niza[i].n; j++) {

            if (niza[i].niza[j].is_touch && (minPrice == -1 || niza[i].niza[j].price < minPrice)) {
                minPrice = niza[i].niza[j].price;
                index = i;
            }
        }
        printf("Najeftina ponuda ima prodavnicata:\n%s %s\n",niza[index].store_name,niza[index].location);
        printf("Najniskata cena iznesuva: %d\n",minPrice);
    }
//    if (index != -1) {
//        ITStore cheapest_store = niza[index];
//        printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", cheapest_store.store_name, cheapest_store.location);
//        printf("Najniskata cena iznesuva: %d\n", minPrice);
//    }
}

int main() {
    int num_stores;
    scanf("%d", &num_stores);
    ITStore stores[MAX_STORES];
    for (int i = 0; i < num_stores; i++) {

        scanf("%s", stores[i].store_name);
        scanf("%s", stores[i].location);
        scanf("%d", &stores[i].n);
        for (int j = 0; j < stores[i].n; j++) {
            scanf("%s", stores[i].niza[j].company);
            scanf("%f", &stores[i].niza[j].monitor_size);
            scanf("%d", &stores[i].niza[j].is_touch);
            scanf("%d", &stores[i].niza[j].price);
        }
    }

    for (int i = 0; i < num_stores; i++) {

        print_store_info(stores[i]);
    }

    najeftina_ponuda(stores, num_stores);

    return 0;
}
