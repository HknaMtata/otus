#include "../src/matrix.h"
#include "../src/matrix_utils.h"

int main()
{
    // test case 1
    {
        Matrix A, B;
        rand(A), rand(B);
        print(A), print(B);

        Matrix C = A * B;
        print(C);
    }

    return 0;
}