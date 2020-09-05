
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int matrix(void) {
    int mas[10][10], e, i, j, sum = 0, k=0;
    printf("����� ����� ��� ����������� ��������� �������: ");
    scanf_s("%d", &e);
    e++;
    srand(time(0));
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            mas[i][j] = rand() % e;
            printf("%3d", mas[i][j]);
   
        }
        printf("\n");
    }
    for (i = 0; i < 10; ++i) {
        sum = 0;
        k++;
        for (j = 0; j < 10; ++j) {
            sum += mas[i][j];
        }
        printf("������: %d �����: %d\n", k, sum);

    }
    printf("\n������� ENTER ��� ������ � ������� ����... \n");
    _getch();
    return 0;
}
    
/*
double **a; // ����� ������� ����������
int m, n;   // ������� �������: m �����, n ��������
int i;
. . .
// ������������� ������ ��� ������ ����������
a = (double **) malloc(m * sizeof(double *));

for (i = 0; i < m; ++i) {
    // ������������� ������ ��� ������ � �������� i
    a[i] = (double *) malloc(n * sizeof(double));
}
for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            mas[i][j] = rand() % e;
            printf("%5d", mas[i][j]);
        }
        printf("\n \n");
    }
    printf("\n������� ENTER ��� ������ � ������� ����... \n");
    _getch();
    return 0;
*/

int autowrite(void)
{
    int i, n, e, * mas, min = 99999999, max = 0;

    printf("����� ������ �������: ");
    scanf_s("%d", &n);
    printf("����� ����� ��� ����������� ��������� ������� (+/-): ");
    scanf_s("%d", &e);
    e++;
    srand(time(0));
    mas = (int*)malloc(n * sizeof(int));

    printf("������: \n");
    for (i = 0; i < n; i++) {
        mas[i] = rand() % e;
        printf("%d ", mas[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (mas[i] < min)
            min = mas[i];
    }
    for (i = 0; i < n; i++)
    {
        if (mas[i] > max)
            max = mas[i];
    }
    printf("\n����������� �����: %d", min);
    printf("\n������������ �����: %d", max);
    max = max - min;
    printf("\n������� ����� ������������ � ����������� ������� ����������: %d", max);
    printf("\n������� ENTER ��� ������ � ������� ����... \n");
    _getch();
    return 0;
    
}

int selfwrite(void)
{
    int i, n, * mas, min = 99999999, max = 0;
    printf("����� ������ �������: ");
    scanf_s("%d", &n);
    mas = (int*)malloc(n * sizeof(int));
    printf("����� �������� �������: \n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf_s("%d", &mas[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d, ", mas[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (mas[i] < min)
            min = mas[i];
    }
    for (i = 0; i < n; i++)
    {
        if (mas[i] > max)
            max = mas[i];
    }
    printf("\n����������� �����: %d", min);
    printf("\n������������ �����: %d", max);
    max = max - min;
    printf("\n������� ����� ������������ � ����������� ������� ����������: %d", max);
    printf("\n������� ENTER ��� ������ � ������� ����... \n");
    _getch();
    return 0;
}

int Menu(void)
{
    system("CLS");
    int c = 0;
    setlocale(LC_ALL, "Rus");
    while (c < '0' || c > '3')
    {
        printf(
            "::=================================::\n"
            "|| 1 : ������ ������               ||\n"
            "|| 2 : �������������� ���� ������� ||\n"
            "|| 3 : ��������� ������            ||\n"
            "|| 0 : ������� ���������           ||\n"
            "::=================================::\n"
            "> ");
        c = _getch();
        system("cls");
    }
    return c;
}

void main(void)
{
    int Select;
    while ((Select = Menu()) != '0' && Select != 27)
        switch (Select)
        {
        case '1':
            selfwrite();
            break;

        case '2':
            autowrite();
            break;

        case '3':
            matrix();
            break;
        }
}

