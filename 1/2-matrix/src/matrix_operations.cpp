#include "matrix_operations.h"
#include <iostream>
#include <thread>
#include <vector>

MulOp::MulOp(const Matrix& A1, const Matrix& A2, Matrix& B)
    : m_i(0)
    , m_j(0)
    , m_A1(A1)
    , m_A2(A2)
    , m_B(B)
{
}

void MulOp::calculate()
{
    auto f = [this](){
        while(iteration()) {}
    };

    const unsigned threadsCount = 4;
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < threadsCount; i++)
        threads.push_back(std::thread(f));

    for (auto& th : threads) {
        try {
            th.join();
        } catch (const std::system_error &ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}

bool MulOp::iteration()
{
    unsigned i = 0, j = 0;
    if(!forwardIndex(i, j))
        return false;
    calculate(i, j);
    return true;
}

bool MulOp::forwardIndex(unsigned& i, unsigned& j)
{
    const std::lock_guard<std::mutex> lock(m_mutex);
    if(m_i == (dims - 1) && m_j == (dims - 1))
        return false;
    i = m_i, j = m_j;
    if(++m_j == dims)
        ++m_i, m_j = 0;
    return true;
}

void MulOp::calculate(const unsigned& i, const unsigned& j)
{
    int res = 0;
    for(unsigned k = 0; k < dims; ++k)
        res += m_A1.get(i, k) * m_A2.get(k, j);
    m_B.set(i, j, res);
}