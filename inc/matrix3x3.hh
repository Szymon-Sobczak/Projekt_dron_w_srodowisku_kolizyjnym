#pragma once

#include "matrix.hh"

/*!
    \file matrix3x3.hh
        \brief Plik zawierajacy definicje konkretyzacji szablonu klasy Matrix do instancji Matrix3x3 - macierzy kwadratowej o wielkosci 3. 
    Oraz trzy prototypy funkcji wypelniajace Matrix3x3 wartosciaciami macierzy obrotu w 3D w osi OX,OY i OZ dla zadanego kata.
*/

/*! \brief Konkretyzacja szablonu klasy Matrix do instancji  Matrix3x3 - macierzy kwadratowej o wielkosci 3. */
typedef Matrix<3> Matrix3x3;

/*! \brief Funkcja wypelniajaca Matrix3x3 wartosciaciami macierzy obrotu 3D w osi OX, dla zadanego kata. */
Matrix3x3 Fill_matrix_OX (double const angle);  

/*! \brief Funkcja wypelniajaca Matrix3x3 wartosciaciami macierzy obrotu 3D w osi OY, dla zadanego kata. */
Matrix3x3 Fill_matrix_OY (double const angle);  

/*! \brief Funkcja wypelniajaca Matrix3x3 wartosciaciami macierzy obrotu 3D w osi OZ, dla zadanego kata. */
Matrix3x3 Fill_matrix_OZ (double const angle);  
