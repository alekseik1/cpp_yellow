#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <fstream>


class Matrix {
private:
    int num_rows = 0;
    int num_cols = 0;
    std::vector<std::vector<int>> v;

    void resetMatrix(int num_rows, int num_cols) {
        if (num_rows < 0 or num_cols < 0) {
            throw std::out_of_range("Number should be > 0");
        }
        this->num_rows = num_rows;
        this->num_cols = num_cols;
        this->v.erase(this->v.begin(), this->v.end());
        for(auto i = 0; i < num_rows; i++) {
            std::vector<int> vec = std::vector<int>();
            for(auto j = 0; j < num_cols; j++)
                vec.push_back(0);
            v.push_back(vec);
        }
    }

    bool validRange(int row=0, int col=0) const {
        return (row <= num_rows) && (col <= num_cols);
    }

    bool dimensionsEqual(const Matrix& other) const {
        bool is_empty1 = (this->num_rows == 0) || (this->num_cols == 0);
        bool is_empty2 = (other.num_rows == 0) || (other.num_cols == 0);
        if(is_empty1 || is_empty2)
            return (is_empty1 && is_empty2);
        return (this->num_rows == other.num_rows) && (this->num_cols == other.num_cols);
    }
public:
    Matrix() = default;
    Matrix(int num_rows, int num_cols) { resetMatrix(num_rows, num_cols); }
    void Reset(int a, int b) { resetMatrix(a, b); }
    int GetNumRows() const { return num_rows; }
    int GetNumColumns() const { return num_cols; }

    int& At(int row, int col) {
        if(validRange(row, col))
            return v.at(row).at(col); 
        else
            throw std::out_of_range("Exceeded size");
    }

    int At(int row, int col) const {
        if(validRange(row, col))
            return v.at(row).at(col); 
        else
            throw std::out_of_range("Exceeded size");
    }

    friend std::istream& operator>>(std::istream& in, Matrix& m) {
        int rows, cols;
        in >> rows >> cols;
        m.resetMatrix(rows, cols);
        for(auto i = 0; i < rows; i++) {
            for(auto j = 0; j < cols; j++)
                in >> m.v[i][j];
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
        out << "rows: " << m.num_rows << "; cols: " << m.num_cols << std::endl;
        for(auto i = 0; i < m.num_rows; i++) {
            for(auto j = 0; j < m.num_cols; j++)
                out << m.v[i][j] << " ";
            out << std::endl;
        }
        return out;
    }

    bool operator==(const Matrix& other) const {
        if(!(this->dimensionsEqual(other)))
            return false;
        for(auto i = 0; i < this->num_rows; i++)
            for(auto j=0; j<this->num_cols; j++)
                if(this->v[i][j] != other.v[i][j])
                    return false;
        return true;
    }

    Matrix operator+(const Matrix& other) const {
        if(!(this->dimensionsEqual(other))) {
            std::stringstream ss;
            ss << "Dimension issue: " << this->num_rows << " " << this->num_cols << std::endl;
            ss << other.num_rows << " " << other.num_cols << std::endl;
            throw std::invalid_argument(ss.str());
        }
        Matrix result = Matrix(this->num_rows, this->num_cols);
        for(auto i=0; i < this->num_rows; i++)
            for(auto j=0; j < this->num_cols; j++)
                result.v[i][j] = this->v[i][j] + other.v[i][j];
        return result;
    }

};


int main(int argc, char *argv[])
{
    Matrix m1 = Matrix();
    Matrix m2 = Matrix();
    std::cin >> m1;
    std::cin >> m2;
    std::cout << "m1 is: " << std::endl << m1;
    std::cout << "m2 is: " << std::endl << m2;
    std::cout << "m1 equals m2: " << (m1==m2) << std::endl;
    std::cout << "m1 + m2 = " << std::endl << m1 + m2 << std::endl;
    return 0;
}
