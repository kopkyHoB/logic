#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int matrix(void) 
{
    int mas[10][10], e, i, j, sum = 0, k=0;
    printf("Введи число для определения диапазона массива: ");
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
        printf("Строка: %d Сумма: %d\n", k, sum);

    }
    printf("\nНажмите ENTER для выхода в главное меню... \n");
    _getch();
    return 0;
}
    
int autowrite(void)
{
    int i, n, e, *mas, min = 99999999, max = 0;

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

int str(void)
{
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "Rus");
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        int i;
        bool ch = 0;
        struct student
        {
            char famil[20];
            char name[20], facult[20];
            int Nomzach;
        } 
        stud[3];
        struct student_search //дополнительная структура для поиска студента по основной структуре
        {
            char famil_search[20];
            char name_search[20], facult_search[20];
            int Nomzach_search;
        } 
        stud_search;
        for (i = 0; i < 3; i++)
        {
            printf("Введите фамилию студента\n"); 
            scanf("%20s", stud[i].famil);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Введите имя студента %s\n", stud[i].famil); 
            scanf("%20s", stud[i].name);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Введите название факультета студента %s %s\n", stud[i].famil, stud[i].name); 
            scanf("%20s", stud[i].facult);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Введите номер зачётной книжки студента %s %s\n", stud[i].famil, stud[i].name); 
            scanf("%d", &stud[i].Nomzach);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Cтудент №%d %s %s обучается на факультете %s, номер зачётной книжки %d \n", i, stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
        }
        printf("\n=======ПОИСК СТУДЕНТА ПО КРИТЕРИЯМ=======\n");
        printf("Введите фамилию студента (для пропуска введите 0):\n"); 
        scanf("%20s", stud_search.famil_search);
        printf("Введите имя студента (для пропуска введите 0): \n"); 
        scanf("%20s", stud_search.name_search);
        printf("Введите название факультета студента (для пропуска введите 0): \n"); 
        scanf("%20s", stud_search.facult_search);
        printf("Введите номер зачётной книжки студента (для пропуска введите 0): \n"); 
        scanf("%d", &stud_search.Nomzach_search);
        
        for (i = 0; i < 3; i++) {
            if (strcmp(stud[i].famil, stud_search.famil_search) == 0 
                || strcmp(stud[i].name, stud_search.name_search) == 0
                || strcmp(stud[i].facult, stud_search.facult_search) == 0 
                || stud[i].Nomzach == stud_search.Nomzach_search) 
            {
                printf("Искомый студент - %s, %s, %s, находится под номером - %d", stud[i].famil, stud[i].name, stud[i].facult, i);
                ch = 1;
            }
        }
        if (ch == 0) {
            printf("ТАКОГО СТУДЕНТА НЕ СУЩЕСТВУЕТ!");
        }
    }
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
    while (c < '0' || c > '4')
    {
        printf(
            "::=================================::\n"
            "|| 1 : Ввести массив               ||\n"
            "|| 2 : Автоматический ввод массива ||\n"
            "|| 3 : Двумерный массив            ||\n"
            "|| 4 : Структура                   ||\n"
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

        case '3':
            matrix();
            break;

        case '4':
            str();
            break;
        }
}