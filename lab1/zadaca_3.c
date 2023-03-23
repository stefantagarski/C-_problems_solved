//Да се креира структура Item во која што ќе се чуваат податоци за еден производ од продавница. За производот ќе се чуваат информации за име и цена на производот.
//Потоа, да се креира структура ShoppingCart во која што ќе  се чуваат податоци за id на кошничката и сите производи кои се дел од таа кошничка за купување.
//На почетокот се внесува број N што озналува колку кошнички ќе се читаат од влез.
//Да се направат функциите:
//void printAveragePriceOfLowestItems(...):
//која што ќе ги земе производите со најмала цена од секоја кошничка, ќе ја пресмета нивната средна вредност и ќе ја испечати.
//void printHighestPricedItem(...):
//кoja што за секоја кошничка ќе го испечати името на производот со најголема цена и id-то на кошничката од кој што доаѓа тој производ.

#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    char *name;
    int price;
} Item;

typedef struct ShoppingCart {
    int id;
    Item *items;
    int numItems;
} ShoppingCart;

void printAveragePriceOfLowestItems(ShoppingCart *carts, int n){
    int sum =0;
    for(int i = 0; i < n; i++) {
        int lowest = 999;
        for (int j = 0; j < carts[i].numItems; j++) {
            Item item = *(carts[i].items + j);
            if(item.price < lowest){
                lowest = item.price;
            }
        }
        sum += lowest;
    }

    printf("Average: %.2f\n", (float)sum/n);
}


void printHighestPricedItem(ShoppingCart *carts, int n){
    int id;
    char *str;
    int max = -1;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < carts[i].numItems; j++) {
            Item item = *(carts[i].items + j);
            if(item.price > max){
                id = carts[i].id;
                str = item.name;
                max = item.price;
            }
        }
    }

    printf("Shopping cart id: %d\n", id);
    printf("Product: %s\n", str);
}

int main() {
    int n;
    scanf("%d", &n);

    ShoppingCart carts[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &carts[i].id);
        scanf("%d", &carts[i].numItems);


        Item *tmp = (Item*) malloc(carts[i].numItems * sizeof(Item));

        for (int j = 0; j < carts[i].numItems; j++) {
            char *str = (char*) malloc(50*sizeof(char));
            char c;
            scanf(" %c", &c);
            int z=0;
            while(c!='\n'){
                str[z] = c;
                z++;
                scanf("%c", &c);
            }
            str[z] = '\0';
            tmp[j].name = str;
            scanf("%d", &tmp[j].price);
        }
        carts[i].items = tmp;
    }

    printAveragePriceOfLowestItems(carts, n);
    printHighestPricedItem(carts, n);

    return 0;
}
