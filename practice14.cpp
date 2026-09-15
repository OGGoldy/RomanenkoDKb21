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

int main()
{
    int intSize;

    cout << "Vvedit rozmir masivu cilykh chyseliv: ";
    cin >> intSize;

    int* numbers = new int[intSize];

    cout << "Vvedit " << intSize << " cilykh chyseliv:" << endl;

    for (int* ptr = numbers; ptr < numbers + intSize; ptr++)
    {
        cin >> *ptr;
    }

    calculateAverage(numbers, intSize);

    delete[] numbers;


    int stringSize;

    cout << "\nVvedit kilkist ryadkiv: ";
    cin >> stringSize;

    cin.ignore();

    string* texts = new string[stringSize];

    cout << "Vvedit " << stringSize << " ryadkiv:" << endl;

    for (string* ptr = texts; ptr < texts + stringSize; ptr++)
    {
        getline(cin, *ptr);
    }

    findLongestAndShortest(texts, stringSize);

    delete[] texts;


    int doubleSize;

    cout << "\nVvedit rozmir masivu chysel z plavayuchoyu krapkoyu: ";
    cin >> doubleSize;

    double* values = new double[doubleSize];

    cout << "Vvedit " << doubleSize << " chysel:" << endl;

    for (double* ptr = values; ptr < values + doubleSize; ptr++)
    {
        cin >> *ptr;
    }

    calculateSum(values, doubleSize);

    delete[] values;

    return 0;
}
