#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Cuboid.hh"
#include "Scene_object.hh"

/*!
    \file Obs_plateau.hh
        \brief  Definicja klasy Plateau.

    Prototypy metod klasy Plateau.
*/

/*!
  \brief Klasa modelujaca w programie pojecie plaskowyzu. Klasa dziedziczy po klasie Cuboid i Scene_object.   

    Klasa posiada:
        - Publiczny konstuktor wieloparametryczny pozwalajacy stworzyc plaskowyz w okreslonym miejscu na scenie, o okreslonej skali i numerze ID.

    Utworzona klasa zawiera publiczna metode pozwalajaca na zapis odpowiednio zmodyfikowanego plaskowyzu do pliku.

    Utworzona klasa zawiera metody przeslaniajace czysto wirtualne metody z klasy Scene_object pozwalajace na:
        - Pobranie nazwy pliku zawierajacego dane o wierzcholkach plaskowyzu.
        - Pobranie wektora reprezentujacego srodek plaskowyzu.
        - Pobranie danych o wymiarach plaskowyzu.
*/

class Plateau: public Cuboid, public Scene_object{
    public:
        /*! \brief Konstruktor wieloparametryczny klasy */
        Plateau(Vector3D const & position, Vector3D const & scale, unsigned int ID);
        
        /*! \brief Metoda pozwalajaca zapisac plaskowyz do pliku */
        void save_to_file(Vector3D const & position);

        /*! \brief Metoda sluzy do pobrania nazwy pliku zawierajacego dane o wierzcholkach plaskowyzu. */
        std::string const & get_name_of_file() override final;

        /*! \brief Metoda sluzy do pobrania pozycji srodka plaskowyzu. */
        Vector3D const & get_position() override final;

        /*! \brief Metoda pozwalajca pobrac dane o wymiarach obiektu. */
        Vector3D const & get_size() override final;
};