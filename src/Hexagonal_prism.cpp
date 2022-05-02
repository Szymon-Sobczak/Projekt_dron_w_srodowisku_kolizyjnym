#include "Hexagonal_prism.hh"

/*!
    \file Hexagonal_prism.cpp
        \brief Definicje metod klasy Hexagonal_prism

    Zawiera definicje funkcji i metod klasy Hexagonal_prism.
*/

/*!
    Domyślny konstruktor obiektu typu Hexagonal_prism. 
    Nadaje domyślne wartosci wierzcholkow lokalnych graniastoslupowi prawidlowemu szesciokatnemu. 
    Ustawia kat obrotu graniastoslupa w osi Z na wartosc 0.     
    Ustawia domsylna skale graniastoslupa.         
                                                                                                                                              
    \return graniastoslupup o srodku w ukladzie loklanym w punkcie (0, 0, 0), o wszystkich bokach dlugosci 1.        
*/

Hexagonal_prism::Hexagonal_prism(){
    double values[3] = {ROTOR_SCALE};
    Vector3D rotor_scale(values);
    update_scale(rotor_scale);

    double v_Apx1[3]={0.5,0,-0.5},v_Apx2[3]={0.25,0.433,-0.5},v_Apx3[3]={-0.25,0.433,-0.5},v_Apx4[3]={-0.5,0,-0.5},
           v_Apx5[3]={-0.25,-0.433,-0.5},v_Apx6[3]={0.25,-0.433,-0.5},v_Apx7[3]={0.5,0,0.5},v_Apx8[3]={0.25,0.433,0.5},
           v_Apx9[3]={-0.25,0.433,0.5},v_Apx10[3]={-0.5,0,0.5},v_Apx11[3]={-0.25,-0.433,0.5},v_Apx12[3]={0.25,-0.433,0.5};
    Vector3D Apx1(v_Apx1),Apx2(v_Apx2),Apx3(v_Apx3),Apx4(v_Apx4),Apx5(v_Apx5),Apx6(v_Apx6),
             Apx7(v_Apx7),Apx8(v_Apx8),Apx9(v_Apx9),Apx10(v_Apx10),Apx11(v_Apx11),Apx12(v_Apx12);
    
    Local_corners[0] = Apx1;
    Local_corners[1] = Apx2;
    Local_corners[2] = Apx3;
    Local_corners[3] = Apx4;
    Local_corners[4] = Apx5;
    Local_corners[5] = Apx6;
    Local_corners[6] = Apx7;
    Local_corners[7] = Apx8;
    Local_corners[8] = Apx9;
    Local_corners[9] = Apx10;
    Local_corners[10] = Apx11;
    Local_corners[11] = Apx12;

    Roration_angle_Zaxis = 0;
}

/*!
    Metoda realizuje przechodzenie pomiedzy ukladem loklanym graniastoslupa prawidlowego szesciokatnego do ukladu globalnego sceny poprzez uklad lokalny prostopdloscianu. 
    
    \param [in] vec - wektor przesuniecia rotora w ukladzie prostopadloscianu.
    \param [in] position_of_drone - wektor przesuniecia rotora w ukladzie globalnym.
    \param [in] drone_angle - kat obrotu drona. 
*/

void Hexagonal_prism::Transform_to_global_coords(Vector3D const & vec, Vector3D const & position_of_drone,double const & drone_angle){
    center_of_prism = position_of_drone;
    Matrix3x3 Rotation_matrix = Fill_matrix_OZ(drone_angle), Animation_matrix = Fill_matrix_OZ(Roration_angle_Zaxis);
    for (unsigned int i=0; i < 12; ++i)
        Global_corners [i] = Rotation_matrix * (Animation_matrix * (Local_corners[i] * get_scale()) + vec) + center_of_prism ;
}

/*!                                                                                                         
    \param[in] index - index wierzcholka globalnego graniastoslupa prawidlowego szesciokatnego.                                             
                                                                   
    \return Wartosc wierzcholka globalnego graniastoslupa prawidlowego szesciokatnego w danym miejscu wektora jako stala.                
*/

const Vector3D & Hexagonal_prism::operator [] (int index) const{
    if (index < 0 || index >= 12) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka graniastoslupa");
    } 
    return Global_corners[index];
}

/*!                                                                                                 
    \param[in]  index - index wierzcholka globalnego graniastoslupa prawidlowego szesciokatnego.                                             
                                                                  
    \return Wartosc wierzcholka globalnego graniastoslupa prawidlowego szesciokatnego w danym miejscu wektora.                           
*/

Vector3D & Hexagonal_prism::operator [] (int index){
    if (index < 0 || index >= 12){
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka graniastoslupa");
    } 
    return const_cast <Vector3D &> (const_cast <const Hexagonal_prism *> (this)->operator[](index));
}


/*!                                                                                                         
    \param[in] index - index wierzcholka lokalnego graniastoslupa prawidlowego szesciokatnego.                                             
                                                                   
    \return Wartosc wierzcholka lokalnego graniastoslupa prawidlowego szesciokatnego w danym miejscu wektora jako stala.                
*/

const Vector3D & Hexagonal_prism::operator () (int index) const{
    if (index < 0 || index >= 12) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka graniastoslupa");
    } 
    return Local_corners[index];
}

/*!                                                                                                 
    \param[in]  index - index wierzcholka lokalnego graniastoslupa prawidlowego szesciokatnego.                                             
                                                                  
    \return Wartosc wierzcholka lokalnego graniastoslupa prawidlowego szesciokatnego w danym miejscu wektora.                           
*/

Vector3D & Hexagonal_prism::operator () (int index){
    if (index < 0 || index >= 12) {
        throw std::runtime_error("Bledna wartosc indeksu wierzcholka graniastoslupa");
    } 
    return const_cast <Vector3D &> (const_cast <const Hexagonal_prism *> (this)->operator()(index));
}

/*! 
    Zadany dodatkowy kat obrotu graniastoslupa prawidlowego szesciokatnego zostanie zsumowany z aktualnym katem obrotu graniastoslupa.

    \param [in] additional_angle - dodtkowy kat, o ktory raniastoslup prawidlowy szesciokatny zostanie obrocony.
*/

void Hexagonal_prism::update_angleZ(double const & additional_angle){
    Roration_angle_Zaxis += additional_angle;
    if(Roration_angle_Zaxis >=360)
        Roration_angle_Zaxis -=360;
 }

 /*! 
    Metoda zwraca aktualny kat obrotu graniastoslupa prawidlowego szesciokatnego.

    \return Kat obrou graniastoslupa prawidlowego szesciokatnego, jako wartosc typu double.
*/

double Hexagonal_prism::get_angle() const{
    return Roration_angle_Zaxis;
}