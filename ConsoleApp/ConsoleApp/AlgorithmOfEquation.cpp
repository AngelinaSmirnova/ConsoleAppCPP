#include "AlgorithmOfEquation.h"//«аголовочный файл, дл€ использовани€ методов из класса AlgorithmOfEquation
#include "Equation.h"//«аголовочный файл, дл€ использовани€ методов из класса Equation
#include <iostream>//«аголовочный файл, который управл€ет стандартным потоком ввлда-вывода информации
using namespace std;//»спользование компил€тором стандартное пространнство имен
Equation equ;//создаем обект класса Equation
//ќбъ€вл€ем метод из заголовочного файла AlgorithmOfEquation.h с телом функции
void AlgorithmOfEquation::Algorithm(int number, int i, float start, float end,
    float eps, float x0, float xn, float a, float b, float c)
{
    setlocale(LC_ALL, "RUSSIAN");//‘ункци€ дл€ чтени€ и вывода русского €зыка в консоль
    //если знаки функции на кра€х отрезка одинаковые, то здесь нет корн€
    if (equ.EquationF(number, start, a, b, c) * equ.EquationF(number, end, a, b, c) > 0)
        cout << "ќшибка! Ќа заданном интервале корней нет!\n";//вывод данных в консоль
    else
    {
        //дл€ выбора начальной точки провер€ем f(x0)*d2f(x0)>0 ?
        if (equ.EquationF(number, start, a, b, c) * equ.DerivativeTwo(number, end, a, b) > 0) x0 = start;
        else x0 = end;//действие, если не выполнитс€ основное условие
        // считаем первое приближение
        xn = x0 - equ.EquationF(number, x0, a, b, c) / equ.DerivativeOne(number, x0, a, b);
        cout << ++i << "-а€ итераци€ = " << xn << "\n";//вывод данных в консоль
        while (fabs(x0 - xn) > eps) // пока не достигнем необходимой точности, будет продолжать вычисл€ть
        {
            x0 = xn;//начальному значению присваиваем полученное значение
            //непосредственно формула Ќьютона
            xn = x0 - equ.EquationF(number, x0, a, b, c) / equ.DerivativeOne(number, x0, a, b);
            cout << ++i << "-а€ итераци€ = " << xn << "\n";//вывод данных в консоль
        }
        cout << " орень = " << xn << endl;//вывод данных в консоль
        float xRound = round(xn);//округл€ем полученное значение
        //вывод абсолютной погрешности в консоль
        cout << "јбсолютна€ погрешность вычислени€ корн€ равна +-" << fabs(xRound - xn) << endl;
        float xInaccuracy = (xRound - xn) / xn * 100;//вычисл€ем относительную погрешность
        //вывод относительной погрешности в консоль
        cout << "ќтносительна€ погрешность равна " << fabs(xInaccuracy) << "%";
    }
}