/******************************
 * Автор: Арестова Е.Е.       *
 * Дата: 22.10.2024           *
 * Название: Работа с файлами *
 * Вариант:  №2               *
 ******************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <limits>

using namespace std;

struct Passenger {


    Passenger(string _familia, string _name, string _otchestvo, int _predmet, double _weight) :
        familia{ _familia }, name{ _name }, otchestvo{ _otchestvo }, predmet{ _predmet }, weight{ _weight } {};
    string familia;
    string name;
    string otchestvo;
    int predmet;
    double weight;
};
vector<Passenger> getPassengers(string path) {
  
    vector<Passenger> result;
    fstream file(path);
    if (file.is_open()) {
        string familia, name, otchestvo;
        int predmet;
        double weight;

        while (file >> familia >> name >> otchestvo >> predmet >> weight) {
            result.push_back(Passenger{ familia, name, otchestvo, predmet, weight });
        }
        file.close();
    }
    else {
        cout << "Не удалось открыть файл." << endl;
    }
    return result;
}

void listPassengers(vector<Passenger> passengers) {
    cout << "Список пассажиров: " << endl;
    for (Passenger b : passengers) {
        cout << "Фамилия: " << b.familia << "\n" << "Имя: " << b.name << "\n" << "Отчество: " << b.otchestvo << "\n" 
            << "Предметы: " << b.predmet << "\n" << "Вес: " << b.weight << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string path = "passengers.txt";
    vector<Passenger> passengers = getPassengers(path);

    listPassengers(passengers);
    return 0;
}
