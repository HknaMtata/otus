// #include "../src/matrix.h"
// #include "../src/matrix_utils.h"

// int main()
// {
//     // test case 1
//     {
//         Matrix A, B;
//         rand(A), rand(B);
//         print(A), print(B);

//         Matrix C = A * B;
//         print(C);
//     }

//     return 0;
// }

#include "matrix.h"
#include "matrix_utils.h"

#include <gtest/gtest.h>

TEST(Matrix, mul)
{
    Matrix A, B;
    Matrix C; // Result
    Matrix D; // Expected result
    for(unsigned i = 0; i < dims; i++) for(unsigned j = 0; j < dims; j++) A.set(i, j, 2);
    for(unsigned i = 0; i < dims; i++) for(unsigned j = 0; j < dims; j++) B.set(i, j, 4);
    for(unsigned i = 0; i < dims; i++) for(unsigned j = 0; j < dims; j++) D.set(i, j, 24);

    ASSERT_NO_THROW({ C = A * B; });
    ASSERT_EQ(C, D);
}