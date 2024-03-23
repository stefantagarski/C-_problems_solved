//За програмски јазик да се употреби C.

// Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

// Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
// - Идентификациски број (int)
// - Платена сума (int)
// - Провизија (int)
// - Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

// Ограничување: 0 < N < 100

// Структура на влезните податоци:
// N
// id1 sum1 commission1 type1
// ...
// idn sumn Commissionn typen


#include <stdio.h>

enum TransactionType {
    debitna = 0,
    kreditna = 1
};

struct Transaction {
    int id;
    int sum;
    int provision;
    enum TransactionType type;
};

typedef struct Transaction transaction;

int main() {
    int n;
    transaction f;
    int flag = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &f.id, &f.sum, &f.provision, (int*) &f.type);
        if (f.type == kreditna) {
            printf("%d %d \n", f.id, f.sum + f.provision);
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("No credit card transaction");
    }

    return 0;
}
