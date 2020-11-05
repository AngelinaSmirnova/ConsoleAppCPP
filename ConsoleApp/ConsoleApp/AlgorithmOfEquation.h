//Заголовочный файл прототипа класса AlgorithmOfEquation.cpp
#pragma once
class AlgorithmOfEquation//Объявляем класс для алгоритма решения уравнения
{
	//перечисляем методы класса с идентификаторами доступа
	public:
		//объявляем прототип метода для алгоритма решения уравнения
		void Algorithm(int number, int i, float start, float end, float eps,
			float x0, float xn, float a, float b, float c);
};