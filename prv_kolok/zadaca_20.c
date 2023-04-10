#include <stdio.h>

typedef struct
{
    char ime[100];
    int zdravstveno;
    int pregledi;
}Pacient;

typedef struct
{
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
}MaticenDoktor;

void najuspesen_doktor(MaticenDoktor m[], int n) {
    int index, brojNaPreglediNaNajuspesenDoktor;
    float najgolemaZarabotuvacka = 0;
    for (int i = 0; i < n; i++) {
        float sum = 0;
        int brojNaPregledi = 0;
        for (int j = 0; j < m[i].br_pac; j++) {
            if (m[i].niza[j].zdravstveno == 0) {
                sum += m[i].cena;// * m[i].niza[j].pregledi;
            }
            brojNaPregledi += m[i].niza[j].pregledi;
        }
        if (sum == najgolemaZarabotuvacka)
        {
            if (brojNaPregledi > brojNaPreglediNaNajuspesenDoktor)
            {
                najgolemaZarabotuvacka = sum;
                index = i;
                brojNaPreglediNaNajuspesenDoktor = brojNaPregledi;
            }
        }
        else if (sum > najgolemaZarabotuvacka) {
            najgolemaZarabotuvacka = sum;
            index = i;
            brojNaPreglediNaNajuspesenDoktor = brojNaPregledi;
        }
    }
    printf("%s %.2f %d", m[index].ime, najgolemaZarabotuvacka, brojNaPreglediNaNajuspesenDoktor);
}

int main()
{
    int i, j, n, broj;
    MaticenDoktor md[20];
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        //ime na doktor
        scanf("%s", md[i].ime);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++){
            scanf("%s", md[i].niza[j].ime);
            scanf("%d", &md[i].niza[j].zdravstveno);
            scanf("%d", &md[i].niza[j].pregledi);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}