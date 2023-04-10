#include<stdio.h>
#include<string.h>
typedef struct Tanc{
    char name_tanc[15];
    char country[15];
} Tanc;
typedef struct Tancer{
    char name[20];
    char surname[20];
    Tanc  niza[5];

} Tancer;
void tancuvanje(Tancer *t,int n,char *zemja){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(strcmp(t[i].niza[j].country,zemja) == 0){
                printf("%s %s, %s\n", t[i].name, t[i].surname, t[i].niza[j].name_tanc);
                break;
            }
        }
    }
}

int main()
{
    int i, j, n;
    char zemja[15];
    Tancer tanceri[5];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%s",tanceri[i].name);
        scanf("%s",tanceri[i].surname);
        for(j = 0; j < 3; j++){
            scanf("%s",tanceri[i].niza[j].name_tanc);
            scanf("%s",tanceri[i].niza[j].country);
        }
    }
    scanf("%s",zemja);
    tancuvanje(tanceri, n, zemja);
    return 0;
}