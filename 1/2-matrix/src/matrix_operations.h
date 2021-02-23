#pragma once

#include "matrix.h"
#include <mutex>

class MulOp
{
public:
    MulOp(const Matrix& A1, const Matrix& A2);
    Matrix calculate();
private:
    bool iteration(Matrix& m_B);
    bool forwardIndex(unsigned& i, unsigned& j);
    void calculate(const unsigned& i, const unsigned& j, Matrix& m_B);
    std::mutex m_mutex;
    unsigned m_i, m_j;
    const Matrix& m_A1;
    const Matrix& m_A2;
};