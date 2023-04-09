#include <stdio.h>
#include <stdbool.h>
typedef struct Vozenje{
    char nameOfRide[100];
    int duration;
    float price;
    int student_popust;

} Vozenje;

typedef struct ZabavenPark{
    char nameOfPark[100];
    char location[100];
    Vozenje niza[100];
    int n;
} ZabavenPark;
void print(ZabavenPark *niza,int n){
    for (int i = 0; i < n; ++i) {
        printf("%s %s\n",niza[i].nameOfPark,niza[i].location);
        for (int j = 0; j < niza[i].n; ++j) {
            printf("%s %d %.2f\n",niza[i].niza[j].nameOfRide,niza[i].niza[j].duration,niza[i].niza[j].price);
        }
    }
}
void najdobar_park(ZabavenPark * niza, int n)
{
    int i,j, maxI=0, maxV=0,maxVremetraenje= 0;

    for(i=0;i<n;i++)
    {
        int count=0;
        int vreme=0;
        for(j=0;j<niza[i].n;j++)
        {
            if(niza[i].niza[j].student_popust==1)
                count++;
            vreme+= niza[i].niza[j].duration;
        }
        if(count>maxV)
        {
            maxV = count;
            maxI = i;
            maxVremetraenje = vreme;
        }
        else if(count==maxV&&vreme>maxVremetraenje)
        {
            maxI = i;
            maxVremetraenje = vreme;
        }
    }
    printf("Najdobar park: %s %s\n",niza[maxI].nameOfPark,niza[maxI].location);
}

int main() {
    int i, j, n;
    //kreiraj niza od maksimum 100 zabavni parkovi
    ZabavenPark ff[100];
    scanf("%d", &n);
    //citanje na podatocite
    for (i = 0; i < n; i++){
        //ime na festivalot
        scanf("%s", ff[i].nameOfPark);
        //mesto
        scanf("%s", ff[i].location);
        //broj na filmovi
        scanf("%d", &ff[i].n);

        for (j = 0; j < ff[i].n; j++){
            scanf("%s", ff[i].niza[j].nameOfRide);  			/* Ime na filmot */
            scanf("%d", &ff[i].niza[j].duration); 		/* Vremetraenje   */
            scanf("%f", &ff[i].niza[j].price); 	/* Cena */
            scanf("%d", &ff[i].niza[j].student_popust);	/* Popust */

        }


    }
    print(ff, n);
    najdobar_park(ff,n);
    return 0;
}
