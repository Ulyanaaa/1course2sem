﻿/*
Задача 1.18
Составить функцию, которая определяет, является ли целое число
«совершенным». “Совершенным” называется натуральное число, равное сумме
всех своих делителей (исключая само число). Пример “совершенного” числа:
28 = 1 + 2 + 4 + 7 + 14.
В вызывающей функции main() ввести два числа n и N, n меньше N. На экран
вывести все целые числа из интервала от n до N, которые являются
«совершенными» числами. Функция подсчитывает количество таких чисел в
заданном интервале.
В вызывающей функции main() осуществить при вводе контроль неравенства n
меньше N.
*/


#include <iostream>
using namespace std;

void func(int i, int& res, int& cnt);



int main()
{
    int flag = 0;
    setlocale(LC_ALL, "rus");
    while (flag != 1)
    {
        cout << "Введите промежуток от n до N" << endl;
        int n, N;
        cin >> n >> N;
        while (n >= N)
        {
            cout << "Промежуток не верный, введите повторно" << endl;
            cin >> n >> N;
        }

        int cnt = 0;
        for (int i = n; i != N; i++)
        {
            int res = 0;    // Результатсложения делителей числа
            func(i, res, cnt);
            if (res != 0)
            {
                cout << "Совершенное число № " << cnt << ": " << res << endl;
            }

        }
        cout << "Количество таких чисел : " << cnt << endl;
        cout << "Хотите закончить программу? (Да - 1 / Нет - 0)" << endl;
        cin >> flag;
    }
}



/* Функция находит все делители числа и определяет, явлется ли число "совершенным",
 получает само число, переменную для суммы делителей и счетчик количества сов. чисел
 возвращает количество таких чисел и результат суммы делителей
 */
void func(int i, int& res, int& cnt)
{
    int a = 0;    // Перебор делителей

    // Вычисление суммы делителей числа
    while (a < (i/2))
    {
        a++;
        if ((i % a) == 0)
        {
            res += a;
        }
    }
    
    // Определение совершенного числа и подсчет их кол-ва
    // с суммой делителей
    if (i == res and i != 0 and i != 1)
    {
        cnt += 1;
    }
    else res = 0;
}
