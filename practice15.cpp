#include <iostream>
#include <string>

using namespace std;

void calculateAverage(int* arr, int size)
{
    int evenSum = 0;
    int evenCount = 0;
    int oddSum = 0;
    int oddCount = 0;

    for (int* ptr = arr; ptr < arr + size; ptr++)
    {
        if (*ptr % 2 == 0)
        {
            evenSum += *ptr;
            evenCount++;
        }
        else
        {
            oddSum += *ptr;
            oddCount++;
        }
    }

    cout << "\n--- Seredni znachennya ---" << endl;

    if (evenCount > 0)
        cout << "Serednye parnykh elementiv: "
             << static_cast<double>(evenSum) / evenCount << endl;
    else
        cout << "Parnykh elementiv nemae." << endl;

    if (oddCount > 0)
        cout << "Serednye neparnykh elementiv: "
             << static_cast<double>(oddSum) / oddCount << endl;
    else
        cout << "Neparnykh elementiv nemae." << endl;
}

void findLongestAndShortest(string* arr, int size)
{
    if (size <= 0)
    {
        cout << "Masiv ryadkiv porozhniy." << endl;
        return;
    }

    string* longest = arr;
    string* shortest = arr;

    for (string* ptr = arr + 1; ptr < arr + size; ptr++)
    {
        if (ptr->length() > longest->length())
            longest = ptr;

        if (ptr->length() < shortest->length())
            shortest = ptr;
    }

    cout << "\n--- Rezultat ryadkiv ---" << endl;
    cout << "Naydovshiy ryadok: " << *longest << endl;
    cout << "Rozmir: " << longest->length() << endl;
    cout << "Naykorotshiy ryadok: " << *shortest << endl;
    cout << "Rozmir: " << shortest->length() << endl;
}

void calculateSum(double* arr, int size)
{
    double sum = 0;

    for (double* ptr = arr + size - 1; ptr >= arr; ptr--)
    {
        sum += *ptr;
    }

    cout << "\n--- Suma elementiv ---" << endl;
    cout << "Suma: " << sum << endl;
}

void runAverage()
{
    int size;

    cout << "\nVvedit rozmir masivu: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Nekorektniy rozmir." << endl;
        return;
    }

    int* numbers = new int[size];

    cout << "Vvedit " << size << " cilykh chyseliv:" << endl;

    for (int* ptr = numbers; ptr < numbers + size; ptr++)
    {
        cin >> *ptr;
    }

    calculateAverage(numbers, size);

    delete[] numbers;
}

void runStrings()
{
    int size;

    cout << "\nVvedit kilkist ryadkiv: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Nekorektniy rozmir." << endl;
        return;
    }

    cin.ignore();

    string* texts = new string[size];

    cout << "Vvedit " << size << " ryadkiv:" << endl;

    for (string* ptr = texts; ptr < texts + size; ptr++)
    {
        getline(cin, *ptr);
    }

    findLongestAndShortest(texts, size);

    delete[] texts;
}

void runSum()
{
    int size;

    cout << "\nVvedit rozmir masivu: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Nekorektniy rozmir." << endl;
        return;
    }

    double* numbers = new double[size];

    cout << "Vvedit " << size << " chysel:" << endl;

    for (double* ptr = numbers; ptr < numbers + size; ptr++)
    {
        cin >> *ptr;
    }

    calculateSum(numbers, size);

    delete[] numbers;
}

void showMenu()
{
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Serednye parnykh ta neparnykh" << endl;
    cout << "2. Naydovshiy ta naykorotshiy ryadok" << endl;
    cout << "3. Suma chysel z plavayuchoyu krapkoyu" << endl;
    cout << "0. Vykhid" << endl;
    cout << "==========================" << endl;
    cout << "Vash vybir: ";
}

int main()
{
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                runAverage();
                break;

            case 2:
                runStrings();
                break;

            case 3:
                runSum();
                break;

            case 0:
                cout << "\nPrograma zavershena." << endl;
                break;

            default:
                cout << "\nNekorektniy vybir." << endl;
        }

    } while (choice != 0);

    return 0;
}
