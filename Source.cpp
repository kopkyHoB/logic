#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int autowrite(void)
{
    int tb, te, i, n, e, * mas, min = 99999999, max = 0;

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
            "|| 3 : ��������� �� �����          ||\n"
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
        }
}

