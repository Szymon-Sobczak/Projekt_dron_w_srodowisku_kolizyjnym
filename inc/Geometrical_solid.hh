#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "vector3D.hh"

/*!
    \file Geometrical_solid.hh
        \brief  Definicja klasy Geometrical_solid.

    Prototypy funkcji i metod klasy Geometrical_solid.
*/

/*!
    \brief Klasa modelujaca w programie pojecie bryły geometrycznej.

    Klasa posiada:
        - prywatne pole "Name_of_file_global" typu std::string, opisujace nazwe obiektu.
        - prywatne pole Scale typu Vector3D reprezentujace skale obiektu.
        - publiczny konstruktor domyśly, nadajacy poczatkowa nazwe oraz skale.
    
    Klasa posiada publiczne metody pozwalajace na:
        - pobranie aktualnej skali obiektu.
        - aktualizacje skali obiektu.
        - aktualizacje nazwy obiektu.                                                        
*/

class Geometrical_solid{
    private:
        /*! \brief Pole typu std::strig reprezentujace nazwe obiektu */
        std::string Name_of_file_global;

        /*! \brief Wektor3D reprezentujacy skale bryly geometrycznej */
        Vector3D Scale;

    public:
        /*! \brief Bezparametryczny konstrukotr klasy*/
        Geometrical_solid();

        /*! \brief Metoda pozwalajaca na pobranie nazwy bryly geometrycznej */
        std::string const & Get_Name_of_file_global(); 

        /*! \brief Metoda pozwalajaca na aktualizacje nazwy bryly geometrycznej */
        void update_Name_of_file_global(std::string const & new_name);

        /*! \brief Metoda pozwalajaca na aktualizacje skali bryly geometrycznej */
        void update_scale(Vector3D const & new_scale);

        /*! \brief Metoda pozwalajaca na pobranie skali bryly geometrycznej */
        Vector3D const & get_scale();
};