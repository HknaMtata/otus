#include "../src/matrix.h"
#include "../src/matrix_operations.h"
#include "../src/matrix_utils.h"

int main()
{
    // test case 1
    {
        Matrix A, B, C;
        rand(A), rand(B);
        print(A), print(B);

        MulOp op(A, B, C);
        op.calculate();
        print(C);
    }

    return 0;
}