#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

double findLengh(vector<vector<double>> a) {//массив для координат
    double FullLengh = 0;//вводим полную длинну
    for (int i = 1; i < a.size(); i++) {
        double x = a[i][0] - a[i - 1][0];// нахождение катетов изменения координат(проекций на оси)
        double y = a[i][1] - a[i - 1][1];
        double inlengh = pow(x, 2) + pow(y, 2);// возведение в степень 2
        FullLengh += sqrt(inlengh);//считаем полную длинну
    }
    FullLengh = round(FullLengh * 100) / 100;
    return FullLengh;
}

double findSpeed(double S, double t) {
    double v = S / t;//считаем скорость и кругляем на след строке
    v = round(v * 100) / 100;
    return v;
}

int main()
{
    fstream c;//переменные файлов
    ofstream result;
    c.open("Input.txt");//открываем два файла
    result.open("Output.txt");
    vector<vector<double>> cords;//массив с координатами
    int t = 0;
    for (int i = 0; i < 4; i++) {
        vector<double> a;
        for (int j = 0; j < 2; j++) {
            double b = 0;
            c >> b;
            a.push_back(b);//запись из файла в теле двойного цикла
        }
        cords.push_back(a);
    }
    double time = 0;
    c >> time;
    double len = findLengh(cords);//находим окончательные расстояние и скорость, округляли мы в функциях
    double sp = findSpeed(len, time);
    result << len;
    result << " ";
    result << sp;//записываем в файл оба полученных значения
    c.close();
    result.close();//не забываем закрывать файлы :)
}
