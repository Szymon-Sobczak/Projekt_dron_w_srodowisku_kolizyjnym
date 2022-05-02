#include "Cuboid.hh"

/*!
    \file Cuboid.cpp
        \brief Definicje metod klasy Cuboid.

    Zawiera definicje funkcji i metod klasy Cuboid.
*/

/*!
    Domyślny konstruktor obiektu typu Cuboid. 
    Nadaje domyślne wartosci wierzcholkow lokalnych prostopadloscianowi. 
    Ustawia kat obrotu prostopadloscianu w osi Z na wartosc 0.     
    Ustawia domsylna skale prostopadloscianu.         
                                                                                                                                              
    \return Prostopaloscian o srodku w ukladzie loklanym w punkcie (0, 0, 0), o wszystkich bokach dlugosci 1.        
*/

Cuboid::Cuboid(){
    double values[3] = {FUSELAGE_SCALE};
    Vector3D fusledge_scale(values);
    
    update_scale(fusledge_scale);

    double v_Apx1[3]={-0.5,0.5,-0.5},v_Apx2[3]={-0.5,-0.5,-0.5},v_Apx3[3]={0.5,0.5,-0.5},v_Apx4[3]={0.5,-0.5,-0.5},
           v_Apx5[3]={0.5,0.5,0.5},v_Apx6[3]={0.5,-0.5,0.5},v_Apx7[3]={-0.5,0.5,0.5},v_Apx8[3]={-0.5,-0.5,0.5};
    Vector3D Apx1(v_Apx1),Apx2(v_Apx2),Apx3(v_Apx3),Apx4(v_Apx4),Apx5(v_Apx5),Apx6(v_Apx6),Apx7(v_Apx7),Apx8(v_Apx8);
    
    Local_corners[0] = Apx1;
    Local_corners[1] = Apx2;
    Local_corners[2] = Apx3;
    Local_corners[3] = Apx4;
    Local_corners[4] = Apx5;
    Local_corners[5] = Apx6;
    Local_corners[6] = Apx7;
    Local_corners[7] = Apx8;

    Roration_angle_Zaxis = 0;
}

/*!
    Metoda realizuje przechodzenie pomiedzy ukladem loklanym prostopadloscianu do ukladu globalnego sceny. 

    \param [in] vec - wektor przesuniecia globalnego srodka prostopadloscianu.
*/

void Cuboid::Transform_to_global_coords(Vector3D const & vec){
    Center_of_solid = vec;

    Matrix3x3 Rotation_matrixZ = Fill_matrix_OZ(Roration_angle_Zaxis);
    for (unsigned int i=0; i < 8; ++i)
        Global_corners [i] = Rotation_matrixZ * (Local_corners[i] * get_scale()) + Center_of_solid;
}

/*!                                                                                                         
    \param[in] index - index wierzcholka globalnego prostopadloscianu.                                             
                                                                   
    \return Wartosc wierzcholka globalnego prostopadloscianu w danym miejscu wektora jako stala.                
*/

const Vector3D & Cuboid::operator [] (int index) const {
    if (index < 0 || index >= CORNERS) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka prostopadloscianu");
    } 
    return Global_corners[index];
}

/*!                                                                                                 
    \param[in]  index - index wierzcholka globalnego prostopadloscianu.                                             
                                                                  
    \return Wartosc wierzcholka globalnego prostopadloscianu w danym miejscu wektora.                           
*/

 Vector3D & Cuboid::operator[](int index) {
    if (index < 0 || index >= CORNERS) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka prostopadloscianu");
    } 
    return const_cast <Vector3D &> (const_cast <const Cuboid *> (this)->operator[](index));
}

/*!                                                                                                         
    \param[in] index - index wierzcholka lokalnego prostopadloscianu.                                             
                                                                   
    \return Wartosc wierzcholka lokalnego prostopadloscianu w danym miejscu wektora jako stala.                
*/

const Vector3D & Cuboid::operator () (int index) const{
    if (index < 0 || index >= CORNERS) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka prostopadloscianu");
    } 
    return Local_corners[index];
}

/*!                                                                                                 
    \param[in]  index - index wierzcholka lokalnego prostopadloscianu.                                             
                                                                  
    \return Wartosc wierzcholka lokalnego prostopadloscianu w danym miejscu wektora.                           
*/

 Vector3D & Cuboid::operator () (int index) {
    if (index < 0 || index >= CORNERS) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka prostopadloscianu");
    } 
    return const_cast <Vector3D &> (const_cast <const Cuboid *> (this)->operator()(index));
}

/*! 
    Zadany dodatkowy kat obrotu prostopadloscianu zostanie zsumowany z aktualnym katem obrotu prostopadloscianu.

    \param [in] additional_angle - dodtkowy kat, o ktory prostopadloscian zostanie obrocony.
*/

void Cuboid::update_angleZ(double const & additional_angle){
     Roration_angle_Zaxis += additional_angle;
}

/*! 
    Metoda zwraca aktualny kat obrotu prostopadloscianu.

    \return Kat obrou prostopadloscianu, jako wartosc typu double.
*/

double Cuboid::get_angle() const{
    return Roration_angle_Zaxis;
}

/*! 
    Metoda zwraca aktualne polozenie srodka postopadloscianu.

    \return Wspolrzedne polozenia srodka prostopadloscianu, jako wartosc typu Vector3D.
*/

Vector3D const & Cuboid::get_center(){
    return Center_of_solid;
}