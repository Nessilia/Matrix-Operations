#include <iostream>
#include "VMath.h"

int main() {
   
    Matrix3D identity(1, 0, 0, 0, 1, 0, 0, 0, 1);
    Matrix3D example(1, 2, 3, 4, 5, 6, 7, 8, 9);

    std::cout << "Identity Matrix:" << std::endl;
    PrintMatrix(identity);

    std::cout << "Matrix Determinant: " << Determinant(example) << std::endl;

    Matrix3D transposed = Transpose(example);
    std::cout << "Matrix Transpose Result:" << std::endl;
    PrintMatrix(transposed);

    Matrix3D scaled = Scale(example, 2);
    std::cout << "Matrix Scaling Result:" << std::endl;
    PrintMatrix(scaled);

    Matrix3D rotated = RotateZ(example, PI / 4); // Rotate 45 degrees
    std::cout << "Matrix Rotation around Z-axis Result:" << std::endl;
    PrintMatrix(rotated);

    Matrix3D inverse = Inverse(identity);
    std::cout << "Matrix Inverse Result:" << std::endl;
    PrintMatrix(inverse);

    return 0;
}