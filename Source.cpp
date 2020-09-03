#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int autowrite(void)
{
    int tb, te, i, n, e, * mas, min = 99999999, max = 0;

    printf("Введи размер массива: ");
    scanf_s("%d", &n);
    printf("Введи число для определения диапазона массива (+/-): ");
    scanf_s("%d", &e);
    e++;
    srand(time(0));
    mas = (int*)malloc(n * sizeof(int));

    printf("Массив: \n");
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
    printf("\nМинимальное число: %d", min);
    printf("\nМаксимальное число: %d", max);
    max = max - min;
    printf("\nРазница между максимальным и минимальным числами составляет: %d", max);
    printf("\nНажмите ENTER для выхода в главное меню... \n");
    _getch();
    return 0;
    
}

int selfwrite(void)
{
    int i, n, * mas, min = 99999999, max = 0;
    printf("Введи размер массива: ");
    scanf_s("%d", &n);
    mas = (int*)malloc(n * sizeof(int));
    printf("Введи элементы массива: \n");
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
    printf("\nМинимальное число: %d", min);
    printf("\nМаксимальное число: %d", max);
    max = max - min;
    printf("\nРазница между максимальным и минимальным числами составляет: %d", max);
    printf("\nНажмите ENTER для выхода в главное меню... \n");
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
            "|| 1 : Ввести массив               ||\n"
            "|| 2 : Автоматический ввод массива ||\n"
            "|| 3 : Загрузить из файла          ||\n"
            "|| 0 : Закрыть программу           ||\n"
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

