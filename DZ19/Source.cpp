#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>


using namespace std;


int NOD(int num1, int num2);
int resurveNumber(int a);
template <typename T> void showArray(T arr[], int length, int a, int b);
template <typename T> void showArr(T array[], int length);
template <typename T> T sortArray(T arr[], int length, T a);


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int a, b, x, y;

    //Задача 1
    cout << "Задача 1.\nВведите два числа: ";
    cin >> a >> b;
    cout << " Наибольший общий делитель = " << NOD(a, b) << endl;


    // Задача 2
    cout << "Задача 2.\n";
    cout << "Введите число: ";
    cin >> a;
    cout << "Перевернутое число " << resurveNumber(a) << endl;

       
    // Задача 3
    cout << "Задача 3.\n";
    cout << "Изначальный массив:\n";
    int z1[10] = { 47, 11, 8, 3, 70, 7, 12, 7, 3, 69 };
    showArr(z1, 10); 
    cout << "\b\b\n";
    cout << "Введите число из массива: ";
    cin >> a;
    cout << sortArray(z1, 10, a) << endl;
    showArr(z1, 10);
    cout << endl;
      


    //Задача 4
    cout << "Задача 4.\nВведите два числа : ";
    cin >> x >> y;
    int z2[10];
    showArray(z2, 10, x, y);
    cout << endl;

    


    return 0;
}

//Задача 1
int NOD(int num1, int num2) {
    int num;
    if (num1 == num2)   // если числа равны, НОД найден
        return num1;
    int d = num1 - num2; // Находим разность чисел
    if (d < 0) {      // если разность отрицательная,
        d = -d;     // меняем знак
        num = NOD(num1, d); // вызываем функцию NOD() для двух наименьших чисел
    }
    else {      // если разность n1-n2 положительная
        num = NOD(num2, d); // вызываем функцию NOD() для двух наименьших чисел
    }
    return num;
}

//Задача 2
int resurveNumber(int a) {
    int b = 0;
    while (a) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b;
}

// Задача 3
template <typename T> T sortArray(T arr[], int length, T a) {
    int key = -1;
    for (int i = 0; i < length; i++)
        if (arr[i] == a) {
            key = i;
            break;
        }

    sort(arr + key + 1, arr + length);

    cout << "Первая позиция числа " << a << " в массиве = ";
    return key;
}



template <typename T> void showArr(T array[], int length) {  
    cout << "[ ";
    for (int i = 0; i < length; i++)
        cout << array[i] << ", ";
    cout << "\b\b]\n";
}


template <typename T> void showArray(T arr[], int length, int x, int y) {
    cout << "[";
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % (y - x + 1) + x;
        cout << arr[i] << ", ";
    }
    cout << "\b\b]\n";
}