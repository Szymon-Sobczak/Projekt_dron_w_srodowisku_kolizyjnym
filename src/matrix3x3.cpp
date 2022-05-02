
#include "matrix3x3.hh"

/*!
    \file matrix3x3.cpp
        \brief definicje funkcji wypelniajacej Matrix3x3 wartosciaciami macierzy obrotu 3D w osi OX, OY i OZ, dla zadanego kata..
*/

/*! 
    Funkcja wypelnia Matrix3x3 w odpowienim ukladzie, wartosciami funkcji trygonometrycznych tak, aby obracac wokol osi OX.
    
    \param[in] angle - Kat obrotu.

    \return rotation_matrix - macierz3x3 uzupelniona warosciami rotacji wokol osi OX, dla zadanego kata.
*/

Matrix3x3 Fill_matrix_OX (double const angle){
    Matrix3x3 rotation_matrix;
    double angle_radians = angle * M_PI / 180.0;
    rotation_matrix(0,0) = 1;
    rotation_matrix(0,1) = 0;
    rotation_matrix(0,2) = 0;
    rotation_matrix(1,0) = 0;
    rotation_matrix(1,1) = cos(angle_radians);
    rotation_matrix(1,2) = -sin(angle_radians);
    rotation_matrix(2,0) = 0;
    rotation_matrix(2,1) = sin(angle_radians);
    rotation_matrix(2,2) = cos(angle_radians);
    return rotation_matrix;
}

/*! 
    Funkcja wypelnia Matrix3x3 w odpowienim ukladzie, wartosciami funkcji trygonometrycznych tak, aby obracac wokol osi OY.
    
    \param[in] angle - Kat obrotu.

    \return rotation_matrix - macierz3x3 uzupelniona warosciami rotacji wokol osi OY, dla zadanego kata.
*/

Matrix3x3 Fill_matrix_OY (double const angle){
    Matrix3x3 rotation_matrix;
    double angle_radians = angle * M_PI / 180.0;
    rotation_matrix(0,0) = cos(angle_radians);
    rotation_matrix(0,1) = 0;
    rotation_matrix(0,2) = sin(angle_radians);
    rotation_matrix(1,0) = 0;
    rotation_matrix(1,1) = 1;
    rotation_matrix(1,2) = 0;
    rotation_matrix(2,0) = -sin(angle_radians);
    rotation_matrix(2,1) = 0;
    rotation_matrix(2,2) = cos(angle_radians);
    return rotation_matrix;
}

/*! 
    Funkcja wypelnia Matrix3x3 w odpowienim ukladzie, wartosciami funkcji trygonometrycznych tak, aby obracac wokol osi OZ.
    
    \param[in] angle - Kat obrotu.

    \return rotation_matrix - macierz3x3 uzupelniona warosciami rotacji wokol osi OZ, dla zadanego kata.
*/

Matrix3x3 Fill_matrix_OZ (double const angle){
    Matrix3x3 rotation_matrix;
    double angle_radians = angle * M_PI / 180.0;
    rotation_matrix(0,0) = cos(angle_radians);
    rotation_matrix(0,1) = -sin(angle_radians);
    rotation_matrix(0,2) = 0;
    rotation_matrix(1,0) = sin(angle_radians);
    rotation_matrix(1,1) = cos(angle_radians);
    rotation_matrix(1,2) = 0;
    rotation_matrix(2,0) = 0;
    rotation_matrix(2,1) = 0;
    rotation_matrix(2,2) = 1;
    return rotation_matrix;
}
    