#include<stdio.h>
#include<ctype.h>

struct Student {
    char name[20];
    char surname[20];
    int index;
    int points;
};
typedef struct Student Student;

void sort (Student array[],int n){

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n-i-1; ++k) {
            if(array[k].points < array[k+1].points){
                Student pom = array[k];
                array[k] = array[k+1];
                array[k+1] = pom;
            }
        }
    }
}
int main (){
    Student array[100];
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",&array[i].name);
        array[i].name[0] = toupper(array[i].name[0]);
        scanf("%s",&array[i].surname);
        array[i].surname[0] = toupper(array[i].surname[0]);
        scanf("%d",&array[i].index);
        array[i].points = 0;
        int points = 0;
        for (int j = 0; j < 4; ++j) {
            scanf("%d",&points);
            array[i].points += points;

        }
    }
    sort(array,n);
    for (int i = 0; i < n; ++i) {
        printf("%s %s %d %d\n",array[i].name,array[i].surname,
               array[i].index,array[i].points);
    }
    return 0;
}