#pragma once

static const unsigned dims = 3;

class Matrix
{
public:
    Matrix();

    bool operator==(const Matrix&) const;
    Matrix operator*(const Matrix&) const;

    int get(const unsigned& i, const unsigned& j) const;
    bool set(const unsigned& i, const unsigned& j, const int& val);
private:
    bool indexIsVald(const unsigned& i, const unsigned& j) const;
    int m_matrix[dims][dims];
};