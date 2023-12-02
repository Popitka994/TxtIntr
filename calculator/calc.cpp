#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

void Instruction()
{
    cout << "Использование: ./calc [--operation operation] number1 number2 ... numberN.\n";
    cout << "Операция подсчетаф среднего арифметического: --operation sr_arif. Операция медианы: --operation mediana.\n";
    cout << "Количество операндов может варьироваться от 5 до 7.\n";
}

double sr_arif(const vector<double>& numbers)
{
    double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

double calcmedian(vector<double>& numbers)
{
    double middle_value;
    if (numbers.size()%2!=0) middle_value=numbers[numbers.size()/2];
    if (numbers.size()%2==0) middle_value=(numbers[numbers.size()/2]+numbers[(numbers.size()/2)-1])/2;
    return middle_value;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        Instruction();
        return 0;
    }

    string operation;
    vector<double> numbers;
    
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--operation") {
            if (i + 1 < argc) { 
                operation = argv[i + 1];
                ++i;
            }
        } else {
            double number = stod(arg);
            numbers.push_back(number);
        }
    }

    if (numbers.size() < 5 || numbers.size() > 7) {
        cout << "Ошибка: Количество операндов может варьироваться от 5 до 7!\n";
        return 0;
    }
    
    if (operation == "sr_arif") {
        double mean = sr_arif(numbers);
        cout << "Среднее арифметическое = " << fixed << setprecision(2) << mean << "\n";
    } else if (operation == "mediana") {
        double median = calcmedian(numbers);
        cout << "Медиана = " << fixed << setprecision(2) << median << "\n";
    } else {
        cout << "Ошибка: неизвестная операция!.\n";
        return 0;
    }
    
    return 0;
}
