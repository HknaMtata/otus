#include "matrix.h"
#include <cstring>
#include "matrix_operations.h"

Matrix::Matrix()
{
    for(unsigned i = 0; i < dims; i++)
        for(unsigned j = 0; j < dims; j++)
            set(i, j, 0);
}

bool Matrix::operator==(const Matrix& other) const
{
    return memcmp(&other, &m_matrix, sizeof(m_matrix)) == 0;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    return MulOp(*this, other).calculate();
}

int Matrix::get(const unsigned& i, const unsigned& j) const
{
    if(!indexIsVald(i, j))
        throw;
    return m_matrix[i][j];
}

bool Matrix::set(const unsigned& i, const unsigned& j,  const int& val)
{
    if(!indexIsVald(i, j))
        throw;
    m_matrix[i][j] = val;
    return true;
}

bool Matrix::indexIsVald(const unsigned& i, const unsigned& j) const
{
    return !(dims <= i || dims <= j);
}