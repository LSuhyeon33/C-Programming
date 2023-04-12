#include <fstream>
#include <cstdlib>
#include "MyRational.h"
using namespace std;

void testSimpleCase();
void testDataFromFile();

int main(void)
{
    testSimpleCase();
    testDataFromFile();
}

void testSimpleCase()
{
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;

    cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;

    // Check arithmetic operators
    cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;
    // Check comparison operators 
    cout << ((frac1 < frac2) ? 1 : 0) << " "
        << ((frac1 <= frac2) ? 1 : 0) << " "
        << ((frac1 > frac2) ? 1 : 0) << " "
        << ((frac1 >= frac2) ? 1 : 0) << " "
        << ((frac1 == frac2) ? 1 : 0) << " "
        << ((frac1 != frac2) ? 1 : 0) << " "
        << ((frac2 < frac3) ? 1 : 0) << " "
        << ((frac2 <= frac3) ? 1 : 0) << " "
        << ((frac2 > frac3) ? 1 : 0) << " "
        << ((frac2 >= frac3) ? 1 : 0) << " "
        << ((frac2 == frac3) ? 1 : 0) << " "
        << ((frac2 != frac3) ? 1 : 0) << endl;
        cout << (frac6 = frac3) << " ";
        cout << (frac6 += frac3) << " ";
        cout << (frac6 -= frac3) << " ";
        cout << (frac6 *= frac3) << " ";
        cout << (frac6 /= frac3) << endl;
        cout << -frac6 << endl;
        frac6 = (++frac4) + 2;
        frac7 = 2 + (frac4++);
        cout << frac4 << " " << frac6 << " " << frac7 << endl;
        frac6 = (--frac4) - 2;
        frac7 = 2 - (frac4--);
        cout << frac4 << " " << frac6 << " " << frac7 << endl;
        cout << 2 * frac3 << " " << frac3 * 2 << " "
            << 2 / frac3 << " " << frac3 / 2 << endl;
}

void testDataFromFile()
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int number;
        inStream >> number;
        long* array = new long[2 * number];
        for (int j = 0; j < number; j++) {
            long num, den;
            inStream >> num >> den;
            array[j * 2] = num;
            array[j * 2 + 1] = den;
        }
        for (int j = 0; j < number - 1; j++) {
            myRational frac1(array[j * 2], array[j * 2 + 1]);
            for (int k = j + 1; k < number; k++) {
                myRational frac2(array[k * 2], array[k * 2 + 1]);
                if (frac1 > frac2) {
                    long temp_num = array[j * 2];
                    long temp_den = array[j * 2 + 1];
                    array[j * 2] = array[k * 2];
                    array[j * 2 + 1] = array[k * 2 + 1];
                    array[k * 2] = temp_num;
                    array[k * 2 + 1] = temp_den;
                }
            }
        }
        for (int j = 0; j < number; j++) {
            myRational frac(array[j * 2], array[j * 2 + 1]);
            cout << frac << " ";
        }
        cout << endl;
    }
    inStream.close();
}
