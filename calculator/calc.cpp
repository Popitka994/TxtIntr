#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

void printUsage()
{
    std::cout << "Usage: calculator [--operation operation] number1 number2 ... numberN\n";
    std::cout << "Options:\n";
    std::cout << "  --operation operation: Specify the operation to perform (sr_arif or mediana)\n";
}

double calculateMean(const std::vector<double>& numbers)
{
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

double calculateMedian(std::vector<double>& numbers)
{
    std::sort(numbers.begin(), numbers.end());
    size_t size = numbers.size();
    if (size % 2 == 0) {
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        return numbers[size / 2];
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printUsage();
        return 0;
    }

    std::string operation;
    std::vector<double> numbers;
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--operation") { // Определение операции
            if (i + 1 < argc) { 
                operation = argv[i + 1];
                ++i;
            }
        } else { // Заполнение вектора операндами
            double number = std::stod(arg);
            numbers.push_back(number);
        }
    }

    if (numbers.size() < 5 || numbers.size() > 7) {
        std::cout << "Error: Number of operands should be between 5 and 7.\n";
        return 0;
    }
    
    if (operation == "sr_arif") {
        double mean = calculateMean(numbers);
        std::cout << "Mean: " << std::fixed << std::setprecision(2) << mean << "\n";
    } else if (operation == "mediana") {
        double median = calculateMedian(numbers);
        std::cout << "Median: " << std::fixed << std::setprecision(2) << median << "\n";
    } else {
        std::cout << "Error: Unknown operation.\n";
        return 0;
    }
    
    return 0;
}
