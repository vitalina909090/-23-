#include <iostream>
#include <Windows.h>
#include <fstream>
#include <algorithm> 
using namespace std;

struct Pers {
    string name;
    string last_name;
    int ball;
};

bool Poriv(Pers n1, Pers n2){
    return n1.ball > n2.ball;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    ifstream file("list.txt");
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return 1;
    }

    Pers* array = new Pers[10];
    int kill = 0;
    for (int i = 0; i < 10; i++){
        if (file >> array[i].name >> array[i].last_name >> array[i].ball) {
            kill++;
        }
        else break;
    }
    file.close();

    sort(array, array + kill, Poriv);
    for (int i = 0; i < kill; i++) {
        cout << i + 1 << ") " << array[i].name << " " << array[i].last_name << " " << array[i].ball << endl;
    }

    delete []array;
}
