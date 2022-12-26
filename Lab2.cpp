#include "Labs.h"
time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> s, e;
const int n = 100;

void Create(int* arr, int* arr_) {
    cout << "Создан неотсортированный массив из 100 элементов: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 198 - 99;
        arr_[i] = arr[i];
    }
}
void ShowMass(int* arr) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void Sort2(int* arr) {
    int nm = n - 1;
    cout << "Получен отсортированный массив из 100 элементов: ";
    s = steady_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            if (arr[nm - j] < arr[nm - (j + 1)]) {
                swap(arr[nm - j], arr[nm - (j + 1)]);
            }
        }
    }
    e = steady_clock::now();
    ShowMass(arr);
    cout << endl << "Время сортировки (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << "\n";
    system("pause");
    system("cls");
}
void MaxMin(int* arr, int* arr_, int* max, int* min) {
    *max = arr[0];
    *min = arr[0];
    s = steady_clock::now();
    *max = arr[n - 1];
    *min = arr[0];
    e = steady_clock::now();
    cout << "Максимальный элемент массива: " << *max << endl << "Минимальный элемент массива: " << *min;
    cout << endl << "Время поиска в отсортированном массиве (наносекунды): " << duration_cast<nanoseconds>(e - s).count();

    s = steady_clock::now();
    for (int i = 0; i < n; i++) {
        if (arr_[i] > *max) {
            *max = arr_[i];
        }
        if (arr_[i] < *min) {
            *min = arr_[i];
        }
    }
    e = steady_clock::now();
    cout << endl << "Время поиска в неотсортированном массиве (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << "\n";
    system("pause");
    system("cls");
}
void Mid(int* arr, int* arr_, int* max, int* min) {
    int sr = *max + *min;
    int k = 0;
    if ((sr % 2) != 0) {
        sr += 1;
    }
    sr /= 2;
    cout << "Среднее значение max и min: " << sr << endl << endl;
    cout << "Отсортированный массив" << endl;
    ShowMass(arr);
    cout << "\nИндексы равных элементов: ";
    s = steady_clock::now();
    for (int i = 0; i < n; i++) {
        if (arr[i] == sr) {
            cout << i << " ";
            k++;
        }
        if (arr[i] > sr) {
            e = steady_clock::now();
            cout << endl << "Кол-во равных элементов: " << k;
            cout << endl << "Время поиска (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << "\n\n";
            break;
        }
    }
    k = 0;
    cout  << "Неотсортированный массив\n";
    ShowMass(arr_);
    cout << "\nИндексы равных элементов: ";
    s = steady_clock::now();
    for (int i = 0; i < n; i++) {
        if (arr[i] == sr) {
            cout << i << " ";
            k++;
        }
    }
    e = steady_clock::now();
    cout << endl << "Кол-во равных элементов: " << k;
    cout << endl << "Время поиска (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << "\n";
    system("pause");
    system("cls");
}
void More(int* arr) {
    int a;
    int k = 0;
    cout << "Введите число: ";
    cin >> a;
    for (int i = 0; i < n; i++) {
        if (arr[i] < a) {
            k++;
        }
        else {
            break;
        }
    }
    cout << endl << "Чисел меньше " << a << ": " << k;
    cout << "\n";
    system("pause");
    system("cls");
}
void Less(int* arr) {
    int b;
    int k = 0;
    cout << "Введите число: ";
    cin >> b;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > b) {
            k++;
        }
        else {
            break;
        }
    }
    cout << endl << "Чисел больше " << b << ": " << k;
    cout << "\n";
    system("pause");
    system("cls");
}
void Change(int* arr) {
    ShowMass(arr);
    cout << "\n";
    int i1, i2;
    cout << "Введите индекс 1 элемента: ";
    cin >> i1;
    cout << endl << "Введите индекс 2 элемента: ";
    cin >> i2;
    s = steady_clock::now();
    swap(arr[i1], arr[i2]);
    e = steady_clock::now();
    cout << endl << "Время замены элементов (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << endl;
    cout << "Получен массив: ";
    ShowMass(arr);
    cout << "\n";
    system("pause");
    system("cls");
}
void Lab2() {	
	srand(time(NULL));
	setlocale(0, "");
    int arr[n], arr_[n], r;
    int min, max;
    int* pmin = &min;
    int* pmax = &max;
    Create(arr, arr_);
    ShowMass(arr);
    cout << "\n";
    system("pause");
    system("cls");
	while (true) {
        //Меню
        cout << "          Меню\n" <<
            "1. создать новый массив\n" <<
            "2. отсортировать массив\n" <<
            "3. найти максимальный и минимальный элемент массива\n" <<
            "4. найти среднее значение max и min, кол-ао элементов, равных ему, и их индексы\n" <<
            "5. найти кол-во элементов отсортированного массива, меньше введённого вами числа\n" <<
            "6. найти кол-во элементов отсортированного массива, больше введённого вами числа\n" <<
            "7. поменять местами элементы массива\n" <<
            "0. Вернулься к выбору лабораторной работы\n" <<
            "Ваш выбор: ";
        cin >> r;
        switch (r) {
        case 1:
            system("cls");
            Create(arr, arr_);
            ShowMass(arr);
            cout << "\n";
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            Sort2(arr);
            break;
        case 3:
            system("cls");
            MaxMin(arr, arr_, pmax, pmin);
            break;
        case 4:
            system("cls");
            Mid(arr, arr_, pmax, pmin);
            break;
        case 5:
            system("cls");
            More(arr);
            break;
        case 6:
            system("cls");
            Less(arr);
            break;
        case 7:
            system("cls");
            Change(arr);
            break;
        case 0:
            return;
        }
	}
}
