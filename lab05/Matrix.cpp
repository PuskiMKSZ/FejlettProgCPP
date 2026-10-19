#include "Matrix.h"
#include <random>
#include <iomanip>

// 1. Alapértelmezett és paraméteres konstruktor
Matrix::Matrix(int rows, int cols) : mRows(rows), mCols(cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::out_of_range("A matrix meretei csak pozitiv egesz szamok lehetnek!");
    }
    mElements.resize(mRows * mCols, 0.0);
}

// 2. Másoló konstruktor (Copy Constructor)
Matrix::Matrix(const Matrix& other)
    : mRows(other.mRows), mCols(other.mCols), mElements(other.mElements) {}

// 3. Áthelyező konstruktor (Move Constructor)
Matrix::Matrix(Matrix&& other) noexcept
    : mRows(other.mRows), mCols(other.mCols), mElements(std::move(other.mElements)) {
    other.mRows = 0;
    other.mCols = 0;
}

// 4. Másoló értékadás (Copy Assignment)
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = other.mElements;
    }
    return *this;
}

// 5. Áthelyező értékadás (Move Assignment)
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = std::move(other.mElements);

        other.mRows = 0;
        other.mCols = 0;
    }
    return *this;
}

// 6. Feltöltő metódus konstans értékkel
void Matrix::fillMatrix(double value) {
    std::fill(mElements.begin(), mElements.end(), value);
}

// 7. Feltöltő metódus véletlenszerű értékekkel [a, b] intervallumból
void Matrix::randomMatrix(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(a, b);

    for (auto& elem : mElements) {
        elem = dis(gen);
    }
}

// 8. Kiíratás stream-re
void Matrix::printMatrix(std::ostream& os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << std::setw(8) << mElements[i * mCols + j] << " ";
        }
        os << "\n";
    }
}

// 9. Összeadás operátor (+)
Matrix operator+(const Matrix& x, const Matrix& y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw std::out_of_range("Az osszeadashoz a matrixok meretenek meg kell egyezniuk!");
    }
    Matrix result(x.mRows, x.mCols);
    for (size_t i = 0; i < x.mElements.size(); ++i) {
        result.mElements[i] = x.mElements[i] + y.mElements[i];
    }
    return result;
}

// 10. Szorzás operátor (*)
Matrix operator*(const Matrix& x, const Matrix& y) {
    if (x.mCols != y.mRows) {
        throw std::out_of_range("A szorzashoz az elso matrix oszlopainak szama meg kell egyezzen a masodik sorainak szamaval!");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < x.mCols; ++k) {
                sum += x.mElements[i * x.mCols + k] * y.mElements[k * y.mCols + j];
            }
            result.mElements[i * y.mCols + j] = sum;
        }
    }
    return result;
}

// 11. Extraktor operátor (>>) beolvasáshoz
std::istream& operator>>(std::istream& is, Matrix& mat) {
    for (auto& elem : mat.mElements) {
        is >> elem;
    }
    return is;
}

// 12. Inserter operátor (<<) kiíratáshoz
std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    mat.printMatrix(os);
    return os;
}

// 13. Indexelő operátorok (Hagyományos [] -> pointert ad vissza a sor elejére)
double* Matrix::operator[](int row) {
    return &mElements[row * mCols];
}

const double* Matrix::operator[](int row) const {
    return &mElements[row * mCols];
}

// 14. Biztonságos indexelés (Kerek zárójel operátor)
double& Matrix::operator()(int row, int col) {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Index tullpes a matrixban!");
    }
    return mElements[row * mCols + col];
}

const double& Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Index tullpes a matrixban!");
    }
    return mElements[row * mCols + col];
}
