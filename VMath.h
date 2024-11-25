#pragma once

#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846f

struct Matrix3D {
   
    float m[3][3]; 

    Matrix3D(float m00 = 0, float m01 = 0, float m02 = 0,
        float m10 = 0, float m11 = 0, float m12 = 0,
        float m20 = 0, float m21 = 0, float m22 = 0) {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
    }
};

float Determinant(const Matrix3D& lhs);
Matrix3D Inverse(const Matrix3D& lhs);
Matrix3D Transpose(const Matrix3D& lhs);
Matrix3D Scale(const Matrix3D& lhs, float scalar);
Matrix3D RotateZ(const Matrix3D& lhs, float angle);
void PrintMatrix(const Matrix3D& matrix);
