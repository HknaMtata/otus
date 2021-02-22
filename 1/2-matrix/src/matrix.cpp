#include "matrix.h"
#include <cstring>

Matrix::Matrix()
{
    memset(m_matrix, 0, sizeof(m_matrix));
}

bool Matrix::operator==(const Matrix& other) const
{
    return memcmp(&other, &m_matrix, sizeof(m_matrix)) == 0;
}

int Matrix::get(const unsigned& i, const unsigned& j) const
{
    if(!indexIsVald(i, j))
        return -1;
    return m_matrix[i][j];
}

bool Matrix::set(const unsigned& i, const unsigned& j,  const int& val)
{
    if(!indexIsVald(i, j))
        return false;
    m_matrix[i][j] = val;
    return true;
}

bool Matrix::indexIsVald(const unsigned& i, const unsigned& j) const
{
    return !(dims <= i || dims <= j);
}