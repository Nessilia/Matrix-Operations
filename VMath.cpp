#include "VMath.h"

void PrintMatrix(const Matrix3D& matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix.m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

float Determinant(const Matrix3D& lhs) {
    return lhs.m[0][0] * (lhs.m[1][1] * lhs.m[2][2] - lhs.m[1][2] * lhs.m[2][1])
        - lhs.m[0][1] * (lhs.m[1][0] * lhs.m[2][2] - lhs.m[1][2] * lhs.m[2][0])
        + lhs.m[0][2] * (lhs.m[1][0] * lhs.m[2][1] - lhs.m[1][1] * lhs.m[2][0]);
}

Matrix3D Inverse(const Matrix3D& lhs) {
    float det = Determinant(lhs);
    if (det == 0) {
        std::cerr << "Matrix is singular and cannot be inverted." << std::endl;
        return Matrix3D(); 
    }
    float invDet = 1.0f / det;

    Matrix3D result;
    result.m[0][0] = invDet * (lhs.m[1][1] * lhs.m[2][2] - lhs.m[1][2] * lhs.m[2][1]);
    result.m[0][1] = invDet * (lhs.m[0][2] * lhs.m[2][1] - lhs.m[0][1] * lhs.m[2][2]);
    result.m[0][2] = invDet * (lhs.m[0][1] * lhs.m[1][2] - lhs.m[0][2] * lhs.m[1][1]);

    result.m[1][0] = invDet * (lhs.m[1][2] * lhs.m[2][0] - lhs.m[1][0] * lhs.m[2][2]);
    result.m[1][1] = invDet * (lhs.m[0][0] * lhs.m[2][2] - lhs.m[0][2] * lhs.m[2][0]);
    result.m[1][2] = invDet * (lhs.m[0][2] * lhs.m[1][0] - lhs.m[0][0] * lhs.m[1][2]);

    result.m[2][0] = invDet * (lhs.m[1][0] * lhs.m[2][1] - lhs.m[1][1] * lhs.m[2][0]);
    result.m[2][1] = invDet * (lhs.m[0][1] * lhs.m[2][0] - lhs.m[0][0] * lhs.m[2][1]);
    result.m[2][2] = invDet * (lhs.m[0][0] * lhs.m[1][1] - lhs.m[0][1] * lhs.m[1][0]);

    return result;
}

Matrix3D Transpose(const Matrix3D& lhs) {
    return Matrix3D(lhs.m[0][0], lhs.m[1][0], lhs.m[2][0],
        lhs.m[0][1], lhs.m[1][1], lhs.m[2][1],
        lhs.m[0][2], lhs.m[1][2], lhs.m[2][2]);
}

Matrix3D Scale(const Matrix3D& lhs, float scalar) {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = lhs.m[i][j] * scalar;
        }
    }
    return result;
}
Matrix3D RotateZ(const Matrix3D& lhs, float angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);

    Matrix3D rotationMatrix(
        cosAngle, -sinAngle, 0,
        sinAngle, cosAngle, 0,
        0, 0, 1
    );

    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.m[i][j] += lhs.m[i][k] * rotationMatrix.m[k][j];
            }
        }
    }
    return result;
}