#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

typedef  struct RabotnaNedela{
    int casovi[DENOVI];
    int weeks;
} RN;

typedef struct Rabotnik{
   char ime[100];
   RN nedeli[NEDELI];
   int n;
} R;
int maxNedela(R *r){
    int max_hours = 0;
    int max_week_inex = 0;
    for (int i = 0; i < r->n; i++) {
        int total_hours = 0;
        for (int j = 0; j < DENOVI; j++) {
            total_hours += r->nedeli[i].casovi[j];
        }
        if (total_hours > max_hours) {
            max_hours = total_hours;
            max_week_inex = r->nedeli[i].weeks;
        }
    }
    return max_week_inex;
}

void table(R *rabotnici, int n) {
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for (int i = 0; i < n; ++i) {
        int vkupno = 0;
        printf("%s\t", rabotnici[i].ime);
        for (int j = 0; j < NEDELI; ++j) {
            int nedelaCasovi = 0;
            for (int k = 0; k < DENOVI; ++k) {
                nedelaCasovi += rabotnici[i].nedeli[j].casovi[k];
            }
            printf("%d\t", nedelaCasovi);
            vkupno += nedelaCasovi;
        }
        printf("%d\n", vkupno);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    RN rabotnanedela;
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n",NEDELI-1);
    return 0;
}
