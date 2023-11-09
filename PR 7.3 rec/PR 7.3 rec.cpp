#include <iostream>
#include <iomanip>
#include <climits>
#include <time.h>
using namespace std;

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < colCount - 1)
        InputRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    InputRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        InputRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void CreateRow(int** a, const int rowNo, const int colCount,
    const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

int ProductOfNonNegativeRowsHelper(int** a, const int rowNo, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        if (a[rowNo][colNo] >= 0)
        {
            return a[rowNo][colNo] * ProductOfNonNegativeRowsHelper(a, rowNo, colCount, colNo + 1);
        }
        else
        {
            return ProductOfNonNegativeRowsHelper(a, rowNo, colCount, colNo + 1);
        }
    }
    else
    {
        return 1; // base case, product initialized to 1
    }
}

int ProductOfNonNegativeRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo < rowCount)
    {
        int productForRow = ProductOfNonNegativeRowsHelper(a, rowNo, colCount, 0);
        cout << "Product of non-negative elements in row " << rowNo << ": " << productForRow << endl;
        return productForRow * ProductOfNonNegativeRows(a, rowCount, colCount, rowNo + 1);
    }
    else
    {
        return 1; // base case, product initialized to 1
    }
}

int FindMaxSumDiagonalHelper(int** a, const int rowCount, const int colCount, int d, int i)
{
    if (i <= min(d, rowCount - 1))
    {
        int j = d - i;
        return a[i][j] + FindMaxSumDiagonalHelper(a, rowCount, colCount, d, i + 1);
    }
    else
    {
        return 0; // base case, sum initialized to 0
    }
}

int FindMaxSumDiagonal(int** a, const int rowCount, const int colCount, int d)
{
    if (d < rowCount + colCount - 1)
    {
        int sumForDiagonal = FindMaxSumDiagonalHelper(a, rowCount, colCount, d, max(0, d - rowCount + 1));
        cout << "Sum for diagonal " << d << ": " << sumForDiagonal << endl;
        return max(sumForDiagonal, FindMaxSumDiagonal(a, rowCount, colCount, d + 1));
    }
    else
    {
        return 0; // base case, max sum initialized to 0
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Low = -7;
    int High = 7;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // CreateRows(a, rowCount, colCount, Low, High, 0);
    InputRows(a, rowCount, colCount, 0);
    PrintRows(a, rowCount, colCount, 0);

    // Call the recursive function for product of rows without negative elements
    int product = ProductOfNonNegativeRows(a, rowCount, colCount, 0);
    cout << "Product of rows without negative elements: " << product << endl;

    // Call the recursive function for finding max sum among diagonals
    int maxSum = FindMaxSumDiagonal(a, rowCount, colCount, 0);
    cout << "Max sum of diagonals: " << maxSum << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
