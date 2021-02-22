#pragma once

#include "matrix.h"
#include <mutex>

class MulOp
{
public:
    MulOp(const Matrix& A1, const Matrix& A2, Matrix& B);
    void calculate();
private:
    bool iteration();
    bool forwardIndex(unsigned& i, unsigned& j);
    void calculate(const unsigned& i, const unsigned& j);
    std::mutex m_mutex;
    unsigned m_i, m_j;
    const Matrix& m_A1, m_A2;
    Matrix& m_B;
};