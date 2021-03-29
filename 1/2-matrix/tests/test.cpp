#include <gtest/gtest.h>

#include "matrix.h"
#include "matrix_utils.h"

TEST(Matrix, mul)
{
    Matrix A, B;
    Matrix C; // Result
    Matrix D; // Expected result
    for(unsigned i = 0; i < dims; i++) for(unsigned j = 0; j < dims; j++) A.set(i, j, 2);
    for(unsigned i = 0; i < dims; i++) for(unsigned j = 0; j < dims; j++) B.set(i, j, 4);
    for(unsigned i = 0; i < dims; i++) for(unsigned j = 0; j < dims; j++) D.set(i, j, 24);

    ASSERT_NO_THROW(C = A * B;);
    ASSERT_EQ(C, D);
}