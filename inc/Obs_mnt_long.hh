#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Cuboid.hh"
#include "Scene_object.hh"

/*!
    \file Obs_mnt_long.hh
        \brief  Definicja klasy Mnt_long.

    Prototypy metod klasy Mnt_long.
*/

/*!
  \brief Klasa modelujaca w programie pojecie gory ze zboczem. Klasa dziedziczy po klasie Cuboid i Scene_object.   

    Klasa posiada:
        - Publiczny konstuktor wieloparametryczny pozwalajacy stworzyc gore ze zboczem w okreslonym miejscu na scenie, o okreslonej skali i numerze ID.
        - Metode pozwalajaca na transformacje bryly prostopadloscianu do postaci gory ze zboczem. 

    Utworzona klasa zawiera pulbiczna metode pozwalajaca na zapis odpowiednio zmodyfikowanej gory ze zboczem do pliku.

    Utworzona klasa zawiera metody przeslaniajace czysto wirtualne metody z klasy Scene_object pozwalajace na:
        - Pobranie nazwy pliku zawierajacego dane o wierzcholkach gory ze zboczem.
        - Pobranie wektora reprezentujacego srodek skosnej sciany boczej gory ze zboczem.
        - Pobranie danych o wymiarach gory ze zboczem.
*/

class Mnt_long: public Cuboid, public Scene_object{
    private:
        /*! \brief Metoda pozwalajaca na modyfikacje rozkladu wierzcholkow loklanych */
        void transform_shape();

    public:
        /*! \brief Konstruktor wieloparametryczny klasy */
        Mnt_long(Vector3D const & position, Vector3D const & scale, unsigned int ID);

        /*! \brief Metoda pozwalajaca zapisac gore ze zboczem do pliku */
        void save_to_file(Vector3D const & position);
        
        /*! \brief Metoda sluzy do pobrania nazwy pliku zawierajacego dane o wierzcholkach gory ze zboczem. */
        std::string const & get_name_of_file() override final;

        /*! \brief Metoda sluzy do pobrania pozycji srodka gory ze zboczem. */
        Vector3D const & get_position() override final;

        /*! \brief Metoda pozwalajca pobrac dane o wymiarach obiektu. */
        Vector3D const & get_size() override final;
};