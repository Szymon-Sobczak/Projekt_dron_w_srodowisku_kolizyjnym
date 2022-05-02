#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "Geometrical_solid.hh"

/*!
    \file Cuboid.hh
        \brief  Definicja klasy Cuboid.

    Prototypy funkcji i metod klasy Cuboid, dziedziczacej z klasy Geometrical_solid.
*/

/*!
    \brief Klasa modelujaca w programie pojecie prostopadloscianu, ktorego wierzcholki i centrum sa wyrazone za pomoca wektorow.

    Klasa posiada:
        - prywatne pole "Local_corners" bedace tablica wektorow, opisuje ono wektorowo pozycje wierzcholkow lokalnych prostopadloscianu.
        - prywatne pole "Global_corners" bedace tablica wektorow, opisuje ono wektorowo pozycje wierzcholkow globalnych prostopadloscianu.
        - prywatne pole "Center_of_solid" bedace wektorem, opisuje ono wektorowo pozycje globalnego srodka prostopadloscianu.
        - prywatne pole "Roration_angle_Zaxis" opisujace obrot prostopadloscianu w osi Z. 
        - publiczny konstruktor domyśly, nadajacy prostopadloscianowi wartosci wierzcholkow lokalnych.
    
    Klasa posiada publiczne metody pozwalajace na:
        - Transformacje prostopadlosiacnu z ukladu lokalnego do ukladu globalnego.
        - Aktualizajce kata obrotu prostopadloscianu.
        - Przeciazenie operatorow indeksujacych, umozliwajacych odczytywanie i zmiane wartosci reprezentujacych wierzcholki prostopadloscianu w ukladzie globalnym.   
        - Pobranie aktualngo kata obrotu prostopadloscianu.     
        - Pobranie aktualngo polozenia srodka prostopadloscianu.                                                    
*/

class Cuboid: public Geometrical_solid{
    private:
        /*! \brief Wektor3D reprezentujacy srodek prostopadloscianu w przestrzeni globalnej */
        Vector3D Center_of_solid;

        /*! \brief Tablica wektorow3D reprezentujacych rozklad wierzcholkow prostopadloscianu w ukladzie lokalnym */
        Vector3D Local_corners[8]; 

        /*! \brief Tablica wektorow3D reprezentujacych rozklad wierzcholkow prostopadloscianu w ukladzie globalnym */
        Vector3D Global_corners[8]; 

        /*! \brief Wartosc double reprezentujaca kat obrotu prostopadloscianu w osi Z */
        double Roration_angle_Zaxis;

    public:
        /*! \brief Bezparametryczny konstrukotr klasy */
        Cuboid();
        
        /*! \brief Metoda pozawlajaca na transforamacje prostopadloscianu z ukladu lokalnego do globalnego sceny */
        void Transform_to_global_coords(Vector3D const & vec);

        /*! \brief Metoda pozwalaja na aktualizowanie kata obrotu prostopadloscianu */
        void update_angleZ(double const & additional_angle);

        /*! \brief Metoda pozwaljaca pobrac aktualny kat obrotu prostopadloscianu */
        double get_angle() const;

        /*! \brief Metoda pozwalaja na pobranie pozycji srodka prostopadloscianu */
        Vector3D const & get_center();
        
        /*! \brief Przeciazenie operatora indeksujacego */
        const Vector3D & operator [] (int index) const;         
        
        /*! \brief Przeciazenie operatora indeksujacego */
        Vector3D & operator [] (int index);

        /*! \brief Przeciazenie operatora funkcyjnego */
        const Vector3D & operator () (int index) const;         
        
        /*! \brief Przeciazenie operatora funkcyjnego */
        Vector3D & operator () (int index);
};