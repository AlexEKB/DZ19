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

    //������ 1
    cout << "������ 1.\n������� ��� �����: ";
    cin >> a >> b;
    cout << " ���������� ����� �������� = " << NOD(a, b) << endl;


    // ������ 2
    cout << "������ 2.\n";
    cout << "������� �����: ";
    cin >> a;
    cout << "������������ ����� " << resurveNumber(a) << endl;

       
    // ������ 3
    cout << "������ 3.\n";
    cout << "����������� ������:\n";
    int z1[10] = { 47, 11, 8, 3, 70, 7, 12, 7, 3, 69 };
    showArr(z1, 10); 
    cout << "\b\b\n";
    cout << "������� ����� �� �������: ";
    cin >> a;
    cout << sortArray(z1, 10, a) << endl;
    showArr(z1, 10);
    cout << endl;
      


    //������ 4
    cout << "������ 4.\n������� ��� ����� : ";
    cin >> x >> y;
    int z2[10];
    showArray(z2, 10, x, y);
    cout << endl;

    


    return 0;
}

//������ 1
int NOD(int num1, int num2) {
    int num;
    if (num1 == num2)   // ���� ����� �����, ��� ������
        return num1;
    int d = num1 - num2; // ������� �������� �����
    if (d < 0) {      // ���� �������� �������������,
        d = -d;     // ������ ����
        num = NOD(num1, d); // �������� ������� NOD() ��� ���� ���������� �����
    }
    else {      // ���� �������� n1-n2 �������������
        num = NOD(num2, d); // �������� ������� NOD() ��� ���� ���������� �����
    }
    return num;
}

//������ 2
int resurveNumber(int a) {
    int b = 0;
    while (a) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b;
}

// ������ 3
template <typename T> T sortArray(T arr[], int length, T a) {
    int key = -1;
    for (int i = 0; i < length; i++)
        if (arr[i] == a) {
            key = i;
            break;
        }

    sort(arr + key + 1, arr + length);

    cout << "������ ������� ����� " << a << " � ������� = ";
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