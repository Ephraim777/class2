#include <iostream>

using namespace std;

class Counter {
    int count;
public:
    Counter() : count(1) {}
    Counter(int& count) : count(count) {}
    int CounterUp() {
        this->count++;
        return this->count;
    }
    int CounterDown() {
        this->count--;
        return this->count;
    }
    void PrintCounter() {
        cout << this->count;
    }




};
void Helper(Counter &temp1) {
    bool flag = false;
    while (flag == false) {
        cout << "\nВведите команду ('+', '-', '=' или 'x')\n";
        char symbol;
        cin >> symbol;
        switch (symbol) {
            case '+': temp1.CounterUp(); break;
            case '-': temp1.CounterDown(); break;
            case '=': temp1.PrintCounter(); break;
            case 'x': cout << "Программа завершена\n"; flag = true; return; break;
            default: cout << "Такой команды нет, попробуем еще раз\n"; flag = true; Helper(temp1);

        }

    }
}
int main()
{
    setlocale(LC_ALL, "Russian");

    Counter temp1;
    cout << "Хотите установить начальное число для счетчика ? Да или Нет?\n";
    string answer;
    cin >> answer;
    if (answer == "Да" || answer == "да" || answer == "ДА") {
        cout << "Введите начальное значение для счётчика: ";
        int num;
        cin >> num;
        Counter temp(num);
        temp1 = temp;
    }
    else {

        Counter temp;
        temp1 = temp;
    }
    Helper(temp1);
}