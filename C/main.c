//
//  main.c
//  C
//
//  Created by OSX on 24.10.17.
//  Copyright © 2017 OSX. All rights reserved.
//
// Шибалов Петр

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void solution1();
void solution2();
void solution3();
void solution4();
void menu();
int main()
{
    int sel = 0;
    do
    {
        menu();
        scanf("%i", &sel);
        switch (sel)
        {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 4:
                solution4();
                break;
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

void solution1()    // 13. * Написать функцию, генерирующую случайное число от 1 до 100.
                    // а) с использованием стандартной функции rand()
{
    srand(time(NULL)); // Инициализация счетчика случайных чисел.
    printf("Случайное число от 1 до 100: %d\n\n", rand() % 100);
}

void solution2()    // 13. * Написать функцию, генерирующую случайное число от 1 до 100.
                    // б) без использования стандартной функции rand()
{
    int x, a, b, m;
    m = 100;
    b = time(NULL)%1234 + 3;
    a = time(NULL)%9888 + 2;
    x = time(NULL)/1234567 + 1;
//    printf("\n a = %d ", a);
//    printf("\n b = %d ", b);
//    printf("\n x = %d \n", x);
    
    x = (a * x + b) % m;

    printf("Случайное число от 1 до 100: %d \n\n", x);
}

void solution3()    // 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
{
    int sel = 0;    // ввод
    int sum = 0;    // сумма введенных чисел
    int kol = 0;    // количество введенных чисел
    do
    {
        printf("введите число или 0 для завершения ввода\n");
        scanf("%d", &sel);
        if (sel != 0) {     // проверка завершения ввода
            if(sel > 0){    // проверка на положительность
                if(sel%2 == 0){     // проверка четности
                    if (sel%10 == 8){   // проверка оканчания на 8
                        kol++;
                        sum = sum + sel;
                    }
                }
            }
        } else {
            if(kol > 0){
                float res = sum/kol + sum%kol;
                printf("среднее: %f , sum: %d, kol %d \n Bye-bye\n", res, sum, kol);
                break;
            } else {
                printf("Не было четных положительных числе оканчивающихся на 8 \n Bye-bye\n");
                break;
            }
            
            
        };
    } while (sel != 0);
}

void solution4(){   //10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
    int sel;
    printf("введите положительное целое число\n");
    scanf("%d", &sel);
    int celoe = sel;
    int chastnoe;
    int mnoshitel = 10;
    int flag = 0;       // изменяется если встречается нечетная цифра
    do{
        chastnoe = celoe%mnoshitel;
        celoe = celoe/mnoshitel;
        if(chastnoe%2 != 0){
            flag++;
            break;
        }
       // printf("%d - %d - %d\n",mnoshitel, celoe, chastnoe);
    } while (celoe > 0);
    if(flag != 0){
        printf("true - есть нечетные цифры\n\n");
    } else {
        printf("false - нет нечетных цифр\n\n");
    }
}

void menu()
{
    printf("1 - rand 1-100 buildin function\n");
    printf("2 - rand 1-100 custom function\n");
    printf("3 - среднее четных положительных оканчивающихся на 8\n");
    printf("4 - входят ли в число нечетные цифры\n");
    printf("0 - exit\n");
}
