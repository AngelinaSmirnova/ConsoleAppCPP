#include "AlgorithmOfEquation.h"//������������ ����, ��� ������������� ������� �� ������ AlgorithmOfEquation
#include "Equation.h"//������������ ����, ��� ������������� ������� �� ������ Equation
#include <iostream>//������������ ����, ������� ��������� ����������� ������� �����-������ ����������
using namespace std;//������������� ������������ ����������� ������������� ����
Equation equ;//������� ����� ������ Equation
//��������� ����� �� ������������� ����� AlgorithmOfEquation.h � ����� �������
void AlgorithmOfEquation::Algorithm(int number, int i, float start, float end,
    float eps, float x0, float xn, float a, float b, float c)
{
    setlocale(LC_ALL, "RUSSIAN");//������� ��� ������ � ������ �������� ����� � �������
    //���� ����� ������� �� ����� ������� ����������, �� ����� ��� �����
    if (equ.EquationF(number, start, a, b, c) * equ.EquationF(number, end, a, b, c) > 0)
        cout << "������! �� �������� ��������� ������ ���!\n";//����� ������ � �������
    else
    {
        //��� ������ ��������� ����� ��������� f(x0)*d2f(x0)>0 ?
        if (equ.EquationF(number, start, a, b, c) * equ.DerivativeTwo(number, end, a, b) > 0) x0 = start;
        else x0 = end;//��������, ���� �� ���������� �������� �������
        // ������� ������ �����������
        xn = x0 - equ.EquationF(number, x0, a, b, c) / equ.DerivativeOne(number, x0, a, b);
        cout << ++i << "-�� �������� = " << xn << "\n";//����� ������ � �������
        while (fabs(x0 - xn) > eps) // ���� �� ��������� ����������� ��������, ����� ���������� ���������
        {
            x0 = xn;//���������� �������� ����������� ���������� ��������
            //��������������� ������� �������
            xn = x0 - equ.EquationF(number, x0, a, b, c) / equ.DerivativeOne(number, x0, a, b);
            cout << ++i << "-�� �������� = " << xn << "\n";//����� ������ � �������
        }
        cout << "������ = " << xn << endl;//����� ������ � �������
        float xRound = round(xn);//��������� ���������� ��������
        //����� ���������� ����������� � �������
        cout << "���������� ����������� ���������� ����� ����� +-" << fabs(xRound - xn) << endl;
        float xInaccuracy = (xRound - xn) / xn * 100;//��������� ������������� �����������
        //����� ������������� ����������� � �������
        cout << "������������� ����������� ����� " << fabs(xInaccuracy) << "%";
    }
}