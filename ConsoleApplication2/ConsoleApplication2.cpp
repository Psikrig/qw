

#include <Windows.h>
#include <random>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string reverseString(const string& str)
{

    string reversedStr;
    for (int i = str.length() - 1; i >= 0; --i)
    {
        reversedStr += str[i];
    }
    return reversedStr;
}

string removeGlasni(const string& str) {
    string result = str;
    result.erase(remove_if(result.begin(), result.end(),
        [](char c) { return string("аоыеуяёюэиАОЫЕУЯЮЭИЁ").find(c) != string::npos; }), result.end());
    return result;
}

string removeSoglasni(const string& str) {
    string result = str;
    result.erase(remove_if(result.begin(), result.end(),
        [](char c) { return string("цкнгшщзхъйфвпрлджчсмтбьЦЙКНГШЩЗХЪФВПРЛДЖЭЧСМТЬБ").find(c) != string::npos; }), result.end());
    return result;
}

string shuffleString(const std::string& str) {
    string shuffledStr = str;
    random_device rd;
    mt19937 g(rd());
    shuffle(shuffledStr.begin(), shuffledStr.end(), g);
    return shuffledStr;
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    string inputStr;
    int choice;

    do {
        cout << "Выберите действие:" << endl;
        cout << "1. Реверс строки" << endl;
        cout << "2. Удаление гласных из слова" << endl;
        cout << "3. Удаление согласных из слова" << endl;
        cout << "4. Случайное перемешивание букв в слове" << endl;
        cout << "5. Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите строку: ";
            cin.ignore();
            getline(cin, inputStr);
            cout << "Строка задом наперед: " << reverseString(inputStr) << endl;
            break;
        case 2:
            cout << "Введите слово: ";
            cin >> inputStr;
            cout << "Результат после удаления гласных: " << removeGlasni(inputStr) << endl;
            break;
        case 3:
            cout << "Введите слово: ";
            cin >> inputStr;
            cout << "Результат после удаления согласных: " << removeSoglasni(inputStr) << endl;
            break;
        case 4:
            cout << "Введите слово: ";
            cin >> inputStr;
            cout << "Результат случайного перемешивания букв: " << shuffleString(inputStr) << endl;
            break;
        case 5:
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 5);

    return 0;
}