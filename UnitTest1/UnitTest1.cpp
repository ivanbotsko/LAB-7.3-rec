#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 7.3 rec/PR 7.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourMatrixFunctionsTests
{
    TEST_CLASS(ProductOfNonNegativeRowsTests)
    {
    public:

        TEST_METHOD(TestProductOfNonNegativeRows)
        {
            const int rowCount = 3;
            const int colCount = 4;

            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

            // Example matrix with rows that don't contain negative elements
            matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; matrix[0][3] = 4;
            matrix[1][0] = 5; matrix[1][1] = 6; matrix[1][2] = 7; matrix[1][3] = 8;
            matrix[2][0] = 9; matrix[2][1] = 10; matrix[2][2] = 11; matrix[2][3] = 12;

            int product = ProductOfNonNegativeRows(matrix, rowCount, colCount, 0);

            // The expected product is 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 = 479001600
            Assert::AreEqual(479001600, product);

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}

