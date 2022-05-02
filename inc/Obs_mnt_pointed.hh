#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Cuboid.hh"
#include "Scene_object.hh"

/*!
    \file Obs_mnt_pointed.hh
        \brief  Definicja klasy Mnt_pointed.

    Prototypy metod klasy Mnt_pointed.
*/

/*!
  \brief Klasa modelujaca w programie pojecie gory ze szczytem. Klasa dziedziczy po klasie Cuboid i Scene_object.   

    Klasa posiada:
        - Publiczny konstuktor wieloparametryczny pozwalajacy stworzyc gore ze szczytem w okreslonym miejscu na scenie, o okreslonej skali i numerze ID.
        - Metode pozwalajaca na transformacje bryly prostopadloscianu do postaci gory ze szczytem. 

    Utworzona klasa zawiera publiczna metode pozwalajaca na zapis odpowiednio zmodyfikowanej gory ze szczytem do pliku.

    Utworzona klasa zawiera metody przeslaniajace czysto wirtualne metody z klasy Scene_object pozwalajace na:
        - Pobranie nazwy pliku zawierajacego dane o wierzcholkach gory ze szczytem.
        - Pobranie wektora reprezentujacego srodek gory ze szczytem.
        - Pobranie danych o wymiarach gory ze szczytem.
*/

class Mnt_pointed: public Cuboid, public Scene_object{
    private:
        /*! \brief Metoda pozwalajaca na modyfikacje rozkladu wierzcholkow loklanych */
        void transform_shape();

    public:
        /*! \brief Konstruktor wieloparametryczny klasy */
        Mnt_pointed(Vector3D const & position, Vector3D const & scale, unsigned int ID);

        /*! \brief Metoda pozwalajaca zapisac gore ze szczytem do pliku */
        void save_to_file(Vector3D const & position);

        /*! \brief Metoda sluzy do pobrania nazwy pliku zawierajacego dane o wierzcholkach gory ze szczytem. */
        std::string const & get_name_of_file() override final;
        
        /*! \brief Metoda sluzy do pobrania pozycji srodka gory ze szczytem. */
        Vector3D const & get_position() override final;

        /*! \brief Metoda pozwalajca pobrac dane o wymiarach obiektu. */
        Vector3D const & get_size() override final;
};