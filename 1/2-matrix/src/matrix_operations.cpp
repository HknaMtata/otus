#include "matrix_operations.h"
#include <iostream>
#include <thread>
#include <vector>

MulOp::MulOp(const Matrix& A1, const Matrix& A2)
    : m_i(0)
    , m_j(0)
    , m_A1(A1)
    , m_A2(A2)
{
}

Matrix MulOp::calculate()
{
    Matrix m_B;

    auto f = [this, &m_B](){
        while(iteration(m_B)) {}
    };

    const unsigned threadsCount = 4;
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < threadsCount; i++)
        threads.push_back(std::thread(f));

    for (auto& th : threads)
        th.join();

    return m_B;
}

bool MulOp::iteration(Matrix& m_B)
{
    unsigned i = 0, j = 0;
    if(!forwardIndex(i, j))
        return false;
    calculate(i, j, m_B);
    return true;
}

bool MulOp::forwardIndex(unsigned& i, unsigned& j)
{
    const std::lock_guard<std::mutex> lock(m_mutex);
    if(m_i == dims && m_j == dims)
        return false;
    i = m_i, j = m_j;
    if(++m_j == (dims - 1))
        ++m_i, m_j = 0;
    return true;
}

void MulOp::calculate(const unsigned& i, const unsigned& j, Matrix& m_B)
{
    int res = 0;
    for(unsigned k = 0; k < dims; ++k)
        res += m_A1.get(i, k) * m_A2.get(k, j);
    m_B.set(i, j, res);
}