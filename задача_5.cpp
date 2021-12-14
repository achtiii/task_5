#include <iostream>

int InputValidation();
void ArrRand(int* arr_, int size_);
void PrintArr(int* arr_, int size_);
int InteralElements(int* arr_, int size_);


int main()
{
    char again;
    do {
        system("cls"); // чистка экрана
        std::cout << "Enter size array: ";  // количество элементов 
        int sizeArr = InputValidation();  // вызов функции проверки корректности введенныхх данных

        int* arr = new int[sizeArr];
        ArrRand(arr, sizeArr); // вызов функции заполнения массива рандомными числами
        PrintArr(arr, sizeArr); // вызов функции вывода массива
        std::cout << "\nBetween the first element " << arr[0] << " and the last element " << arr[sizeArr - 1] << " element: " << InteralElements(arr, sizeArr); // вывод элемента
        std::cout << "\nIf you want to run the program again, enter 'Z'";
        std::cin >> again;
    } while (again == 'Z');
    return 0;
}

int InputValidation()   // проверка корректности введенного значения
{
    bool isCorrectInput = false; // значение изначально ложно
    int element;
    do
    {
        std::cin >> element; // ввод элемента
        if (std::cin.fail()) // проверка элемента
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Input error! Enter again" << std::endl;  // вывод ошибки
        }
        else
            isCorrectInput = true; // если элемент прошел проверку на корректное значение, то значение меняется на истинное
    } while (!isCorrectInput);

    return element;
}

void ArrRand(int* arr_, int size_) // функция заполнения массива случайными числами 
{
    for (int i = 0; i < size_; i++)
        arr_[i] = rand() % 80;
}

void PrintArr(int* arr_, int size_)  // функция вывода массива
{
    std::cout << "Print array: ";
    for (int i = 0; i < size_; i++)
        std::cout << arr_[i] << " ";
}

int InteralElements(int* arr_, int size_)
{
    bool isCheck = false;
    int res = 0;
    if (arr_[0] < arr_[size_ - 1])   // если первое числи массива например 1 а последнее 5 соотвтстенно интервал от 1 до 5

    {
        for (int i = 1; i < size_ - 1 && !isCheck; i++) {
            if (arr_[0]<arr_[i] && arr_[size_ - 1]> arr_[i]) {
                res = i + 1;
                isCheck = true;
            }
        }
    }
    else  // если первое число массива например 5 а последнее 1, интервал от 1 до 5, но первое число входящее в интервал уже другое
    {
        for (int i = 1; i < size_ - 1; i++) {
            if (arr_[0] > arr_[i] && arr_[size_ - 1] < arr_[i]) {
                res = i + 1;
            }
        }
    }

    return res;
}