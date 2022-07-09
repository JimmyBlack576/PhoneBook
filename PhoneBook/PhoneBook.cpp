#include <iostream>

using namespace std;

void array_numbers(long long mob[], long long home[], const int SIZE);
void display_arr(long long mob[], long long home[], const int SIZE);
void sort_arr(long long arr[], const int SIZE);
int MainMenu(int choice);

int main()
{
    setlocale(LC_ALL, "ru");
    int choice=0;
    MainMenu(choice);
}

//Главное меню 
int MainMenu(int choice) {
    const int SIZE = 5;
    long long mob[SIZE], home[SIZE];
    bool data = false;
    do {
        cout << " Телефонный справочник. \n\n";
        cout << "Выберите действие: \n"
            << "1. Ввести данные.\n"
            << "2. Отсортировать по мобильным номерам.\n"
            << "3. Отсортировать по домашним номерам.\n"
            << "4. Вывести список номеров на экран.\n"
            << "5. Выход.\n";
        do {
            cin >> choice;
            switch (choice) {
            case 1: array_numbers(mob, home, SIZE, data);
                data = true;
                break;
            case 2:
                if (data)
                    sort_arr(mob, SIZE);
                else
                    cout << "Нет данных!\n\n";
                break;
            case 3:
                if (data)
                    sort_arr(home, SIZE);
                else
                    cout << "Нет данных!\n\n";
                break;
            case 4:
                if (data)
                    display_arr(mob, home, SIZE);
                else
                    cout << "Нет данных!\n\n";
                break;
            case 5: cout << "До свидания!";
                exit(0);
            default: cout << "Нет такого пункта в меню! \n"
                << "Попробуйте снова!\n";
                break;

            }
        } while (choice < 1 || choice>5);
    } while (choice != 5);
    return choice;
}
//Функция ввода данных
void array_numbers(long long mob[], long long home[], const int SIZE) {
    
    for (int i = 0; i < 5; i++) {
        cout << "Введите мобильный номер: ";
        cin >> mob[i];
        cout << "Введите домашний номер: ";
        cin >> home[i];

    }
    cout << "\nДанные сохранены! \n\n";
}
//Функция вывода данных
void display_arr(long long mob[], long long home[], const int SIZE) {
    for (int i = 0; i < 5; i++) {
        cout << mob[i] << "  " << home[i] << endl;
    }

}
//Функция сортировки массива
void sort_arr(long long arr[], const int SIZE) {
    long long temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\nОтсортировано!\n\n";
}
