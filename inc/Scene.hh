#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <list>
#include <memory>
#include <algorithm>


#include "Scene_object.hh"
#include "Drone.hh"

#include "Obs_plateau.hh"
#include "Obs_mnt_long.hh"
#include "Obs_mnt_pointed.hh"

#include "lacze_do_gnuplota.hh"

/*!
    \file Scene.hh
        \brief  Definicja klasy Scene.

    Prototypy funkcji i metod klasy Scene.
*/

/*! 
  \brief Klasa modelujaca w programie pojecie Sceny.   

    Klasa posiada:
        - Prywatne pole "Drone_list" bedace lita std::shared_ptr <Drone> - reprezentuje zbior dronow znajdujacych sie na scenie.
        - Prywatne pole "Obstacle_list" bedace lita std::shared_ptr <Scene_object> - reprezentuje zbior przeszkod w znajdujacych sie na scenie.
        - Prywatne pole "Objects_list" bedace lita std::shared_ptr <Scene_object> - reprezentuje zbior wszyskich obietkow znajdujacych sie na scenie.
        - Prywatne pole "tab_of_properties_d1" bedace zbiorem wskaznikow na PzG::InfoPlikuDoRysowania, reprezentuje ono zbior ustawien rysowania drona 1. w Gnuplot.
        - Prywatne pole "tab_of_properties_d2" bedace zbiorem wskaznikow na PzG::InfoPlikuDoRysowania, reprezentuje ono zbior ustawien rysowania drona 2. w Gnuplot.
        - Prywatne pole "nbr_of_active_drone" typu unsigned int okreslajace, ktory z dronow jest obecnie aktywny. 
        - Prywatne pole "Number_of_drones" reprezentuje ono ilosc wszyskich powstalych dronow na scenie.
        - Prywatne pole "Number_of_obstacles" reprezentuje ono ilosc wszyskich powstalych przeszkod na scenie.
        - Prywatne pole "Link" okreslajce wskaznik na lacze do gnuplota.
        - Publiczny konstruktor z parametrem, ktory okresla lacze do gnuplota.
 
    Utworzona klasa zawiera publiczne metody pozwalajace na:
        - Zmiane aktywnego drona.
        - Pobranie informacji i modyfikacje danych aktywnego drona.
        - Dodanie do sceny trzech roznych przeszkod terenowych.
        - Wypisanie danych o wszystkich przeszkodach znajdujacych sie na scenie. 
        - Usuniecie wybranej przeszkody. 
        - Sprawdzenie czy wybrany dron wchodzi w kolizje z innymi obiektami na scenie.
*/

class Scene{
    private:
        /*! \brief Pole typu  std::list reprezentujace zbior dronow na scenie */
        std::list <std::shared_ptr <Drone>> Drone_list;

        /*! \brief Pole typu  std::list reprezentujace zbior przeszkod na scenie */
        std::list <std::shared_ptr <Scene_object>> Obstacle_list;
        
        /*! \brief Pole typu  std::list reprezentujace zbior wszystkich obiektow na scenie */
        std::list <std::shared_ptr <Scene_object>> Objects_list;

        /*! \brief Pole typu PzG::InfoPlikuDoRysowania reprezentujace zbior ustawien rysowania drona nr 1 w Gnuplot */
        PzG::InfoPlikuDoRysowania *Tab_of_properties_d1[6];

        /*! \brief Pole typu PzG::InfoPlikuDoRysowania reprezentujace zbior ustawien rysowania drona nr 2 w Gnuplot */
        PzG::InfoPlikuDoRysowania *Tab_of_properties_d2[6];

        /*! \brief Pole typu unsigned int reprezentujace liczbe kolejnych dronow na scenie */
        unsigned int Number_of_drones = 0;

        /*! \brief Pole typu unsigned int reprezentujace liczbe kolejnych przeszkod na scenie */
        unsigned int Number_of_obstacles = 0;

        /*! \brief Pole typu PzG::LaczeDoGNUPlota lacze do Gnuplot */
        PzG::LaczeDoGNUPlota * Link_to_gnuplot;

        /*! \brief Pole typu unsigned int, opisujace numer obecnie aktywnego drona */
        unsigned int Nbr_of_active_drone;

    public:
        /*! \brief Konstrukotr klasy z parametrem */
        Scene(PzG::LaczeDoGNUPlota * Link);

        /*! \brief Destruktor klasy */
        ~Scene();

        /*! \brief Metoda sluzaca zmianie numeru aktywnego drona */
        void choose_drone(int active_drone);

        /*! \brief Metoda sluzaca probraniu wskaznika na aktywnego drona */
        std::shared_ptr <Drone> use_active_drone();

        /*! \brief Metoda pozwalajaca dodac nowego drona do sceny */
        void add_new_drone(Vector3D const & position);
        
        /*! \brief Metoda pozwalajaca dodac nowa przeszkode - plaskowyz do sceny */
        void add_obstacle_plateau(Vector3D const & position, Vector3D const & scale);
  
        /*! \brief Metoda pozwalajaca dodac nowa przeszkode - zbocze do sceny */
        void add_obstacle_mnt_long(Vector3D const & position, Vector3D const & scale);

        /*! \brief Metoda pozwalajaca dodac nowa przeszkode - gore ze szczytem do sceny */
        void add_obstacle_mnt_pointed(Vector3D const & position, Vector3D const & scale);

        /*! \brief Metoda pozwalajaca wylistowac wszystkie przeszkody na scenie */
        void list_obstacles();
        
        /*! \brief  Metoda pozwalajaca usunac wybrana przeszkode ze sceny */
        void delete_obstacle(int obstacle_ID); 

        /*! \brief Metoda pozwalajaca na sprawdzenie czy wybrany dron, wchodzi w kolizje z innymi obiektami sceny */
        bool check_if_drone_collides(int drone_ID);
};