#pragma warning (disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 128

typedef struct student
{
	char ime[15];
	char prezime[15];
	double bodovi;
	double relbodovi;

}student;

int UnosPodataka(student s[MAX], int a)
{
    FILE* f = NULL;
    int i = 0;

    f = fopen("studenti.txt", "r");
    if (f == NULL)
    {
        printf("Neuspjesno otvaranje datoteke.");
        return -1;
    }

    for (i; i < a; i++)
        fscanf(f, " %s %s %lf", s[i].ime, s[i].prezime, &s[i].bodovi);

    fclose(f);
    return 0;
}

int main()
{
	FILE* f = NULL;
	student* s = NULL;
	int a = 0;
    int empty = 0;
    char p[MAX];
    int i;
    double maxbod;

	
    f = fopen("studenti.txt", "r");

	s = (student*)malloc(a * sizeof(student));

    if (f == NULL)
    {
        printf("Neuspjesno otvaranje datoteke.");
        return -1;
    }
    empty = getc(f);
    if (empty == EOF)
    {
        printf("Datoteka je prazna.");
        return -1;
    }
    while (!feof(f))
    {
        fgets(p, MAX, f);
        a++;
    }
    fclose(f);

    f = fopen("studenti.txt", "r");

    if (s == NULL)
    {
        printf("Neuspjesno alociranje memorije.");
        return -1;
    }

    UnosPodataka(s, a);

    for (i = 0; i < a; i++)
        if (maxbod < s[i].bodovi)
            maxbod = s[i].bodovi;

    printf(" Ime\t\tPrezime\t\tBodovi\t\tRelativni bodovi\n");
    for (i = 0; i < a; i++)
        printf(" %s\t\t%s\t\t%.2lf\t\t%.2lf\n", s[i].ime, s[i].prezime, s[i].bodovi, (s[i].bodovi / maxbod) * 100);

    free(s);
    return 0;
	
}