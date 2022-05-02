#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "Geometrical_solid.hh"

/*!
    \file Hexagonal_prism.hh
        \brief  Definicja klasy Hexagonal_prism.

    Prototypy funkcji i metod klasy Hexagonal_prism, dziedziczacej z klasy Geometrical_solid.
*/

/*!
    \brief Klasa modelujaca w programie pojecie graniastoslupa prawidlowego szesciokatnego, ktorego wierzcholki i centrum sa wyrazone za pomoca wektorow.

    Klasa posiada:
        - Prywatne pole "Local_corners" bedace tablica wektorow, opisuje ono wektorowo pozycje wierzcholkow lokalnych graniastoslupa prawidlowego szesciokatnego.
        - Prywatne pole "Global_corners" bedace tablica wektorow, opisuje ono wektorowo pozycje wierzcholkow globalnych graniastoslupa prawidlowego szesciokatnego.
        - Prywatne pole "center_of_prism" bedace wektorem, opisuje ono wektorowo pozycje globalnego srodka graniastoslupa prawidlowego szesciokatnego.
        - Prywatne pole "Roration_angle_Zaxis" opisujace obrot rotora w osi Z. 
        - Publiczny konstruktor domyśly, nadajacy graniastoslupowi wartosci wierzcholkow lokalnych.
    
    Klasa posiada publiczne metody pozwalajace na:
        - Transformacje prostopadlosiacnu z ukladu lokalnego do ukladu globalnego, przechodzac przez uklad graniastoslupa prawidlowego szesciokatnego.
        - Aktualizajce kata obrotu graniastoslupa prawidlowego szesciokatnego.
        - Przeciazenie operatorow indeksujacych, umozliwajacych odczytywanie i zmiane wartosci reprezentujacych wierzcholki graniastoslupa prawidlowego szesciokatnego w ukladzie globalnym.   
        - Pobranie aktualngo kata obrotu graniastoslupa prawidlowego szesciokatnego.                                                        
*/

class Hexagonal_prism: public Geometrical_solid{
    private:
        /*! \brief Wektor3D reprezentujacy srodek graniastoslupa prawidlowego szesciokatnego w przestrzeni globalnej. */
        Vector3D center_of_prism;

        /*! \brief Tablica wektorow3D reprezentujacych rozklad wierzcholkow graniastoslupa prawidlowego szesciokatnego w ukladzie lokalnym. */
        Vector3D Local_corners[12]; 

        /*! \brief Tablica wektorow3D reprezentujacych rozklad wierzcholkow graniastoslupa prawidlowego szesciokatnego w ukladzie globalnym. */
        Vector3D Global_corners[12]; 

        /*! \brief Wartosc double reprezentujaca kat obrotu graniastoslupa prawidlowego szesciokatnego w osi Z. */
        double Roration_angle_Zaxis;
        
    public:
        /*! \brief Bezparametryczny konstrukotr klasy. */
        Hexagonal_prism();
        
        /*! \brief Metoda pozawlajaca na transforamacje graniastoslupa prawidlowego szesciokatnego z ukladu lokalnego do globalnego sceny, z przejsciem przez uklad prostopadloscianu. */
        void Transform_to_global_coords(Vector3D const & vec, Vector3D const & position_of_drone, double const & drone_angle);

        /*! \brief Metoda pozwalaja na aktualizowanie kata obrotu graniastoslupa prawidlowego szesciokatnego. */
        void update_angleZ(double const & additional_angle);

        /*! \brief Metoda pozwaljaca pobrac aktualny kat obrotu graniastoslupa prawidlowego szesciokatnego. */
        double get_angle() const;

        /*! \brief Przeciazenie operatora indeksujacego. */
        const Vector3D & operator [] (int index) const;         
        
        /*! \brief Przeciazenie operatora indeksujacego. */
        Vector3D & operator [] (int index);

        /*! \brief Przeciazenie operatora funkcyjnego */
        const Vector3D & operator () (int index) const;         
        
        /*! \brief Przeciazenie operatora funkcyjnego */
        Vector3D & operator () (int index);
};