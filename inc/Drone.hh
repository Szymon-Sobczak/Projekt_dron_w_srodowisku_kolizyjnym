#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <unistd.h>

#include "Scene_object.hh"
#include "lacze_do_gnuplota.hh"
#include "Cuboid.hh"
#include "Hexagonal_prism.hh"

/*!
    \file Drone.hh
        \brief  Definicja klasy Drone.

    Prototypy funkcji i metod klasy Drone.
*/

/*!
    \brief Klasa modelujaca w programie pojecie drona.
    Dron jest reprezentowany przez prostopadloscian- kadlub, cztery graniastoslupy prawidlowe szesciokatne- rotory oraz dodatkowy element reprezentujacy kamere przednia.

    Klasa posiada:
        - prywatne pole "drone_location" bedace wektorem, opisuje ono wektorowo pozycje globalnego srodka drona.
        - prywatne pole "rotors" bedace tablica czteroelementowa obiektow Hexagonal_prism, reprezentuje ono zbior rotorow drona.
        - prywatne pole "fuselage" bedace typu Cuboid, reprezentuje ono kadlub drona.
        - prywatne pole "front_camera" bedace typu Hexagonal_prism, reprezentuje ono dodatkowa bryle wyrozniajaca front drona.
        - prywatne pole "orientation_angle" opisujace obrot drona w osi Z. 
        - publiczny konstruktor z parametrm, ktory okresla pozycje poczatkowa drona.
    
    Klasa posiada prywatne metody pozwalajace na:
        - Obliczenie i zapisanie danych o wierzcholkach globalnych kadluba do pliku.
        - Obliczenie i zapisanie danych o wierzcholkach globalnych pojedynczego rotora do pliku.
        - Obliczenie i zapisanie danych o wierzcholkach globalnych dodatkowego obiektu wyrozniajacego front drona do pliku.

    Klasa posiada publiczne metody pozwalajace na:
        - Pobranie informacji o polozeniu srodka drona- wektora3D.
        - Zaplanowanie sciezki pojedynczego przelotu oraz zwiadu i zapisanie jej do pliku.
        - Poruszanie sie dronem w ukladzie globalnym, sceny w gore, dol, boki oraz obrot.
        - Aktualizacje kata obrotu drona w osi Z. 
        - Zapis polaczonej bryly drona do pliku.     
        - Pobranie nazwy pliku zawierajacego dane o kadlubie.  
        - Sprawdzenie czy dany dron koliduje z innym obiektem sceny.
        - Pobranie wymiarow reprezentujacych drona.                                            
*/

class Drone: public Scene_object{
    private:
        /*! \brief Wektor3D reprezentujacy srodek graniastoslupa prawidlowego szesciokatnego w przestrzeni globalnej. */
        Vector3D drone_location;

        /*! \brief Wektor3D reprezentujacy promien drona- najmiejszego okregu obejmujacego rzut calej jego bryly. */
        Vector3D drone_radius;
        
        /*! \brief Pole typu Cuboid reprezentujace kadlub drona. */
        Cuboid fuselage;

        /*! \brief Tablica Hexagonal_prism reprezentuja zbior rotorow drona. */
        Hexagonal_prism rotors[4];
    
        /*! \brief Pole typu Hexagonal_prism reprezentujace kamere przednia drona, dodatkowy element wyrozniajacy przod. */
        Hexagonal_prism front_camera; 

        /*! \brief Wartosc double reprezentujaca kat obrotu drona w osi Z. */
        double orientation_angle;
        
        /*! \brief Metoda realizujaca obliczanie i zapisywanie danych o wierzcholkach globalnych kadluba do pliku. */
        void Calculate_and_save_to_file_fuselage();
        
        /*! \brief Metoda realizujaca obliczanie i zapisywanie danych o wierzcholkach globalnych wybranego rotora do pliku .*/
        void Calculate_and_save_to_file_rotor(unsigned int index, Vector3D const & Trasnlation);
        
        /*! \brief Metoda realizujaca obliczanie i zapisywanie danych o wierzcholkach globalnych kamery przedniej do pliku. */
        void Calculate_and_save_to_file_front_camera(Vector3D const & Trasnlation);

    public:
        /*! \brief Konstrukotr klasy z parametrem. */
        Drone(Vector3D const & location, unsigned int ID);


        /*! \brief Metoda pozwalajaca zaktualizowac kat obrotu drona o wybrany kat. */
        void update_angle(double const & additional_angle);

        /*! \brief Metoda pozwaljaca pobrac aktualny kat obrotu drona */
        double get_angle() const;
        
        /*! \brief Metoda wyznaczajaca, zapisujaca oraz rysujaca sciezke pojedynczego przelotu. */
        void plan_path(double const & angle, double const & distance, Vector3D const & position, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda wyznaczajaca, zapisujaca oraz rysujaca sciezke zwiadu. */
        void plan_reacon(PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca przelot drona w pionie. */
        void go_verical(double const & altitude, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca obrot drona w osi Z. */
        void rotate_drone(double const & user_angle, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca przelot drona w poziomie. */
        void go_horizontal(double const & distance, double const & user_angle, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca zapis calego drona do pliku. */
        void Calculate_and_save_to_file_drone();

        /*! \brief Metoda pozwalajca pobrac nazwe obiektu sceny - drona */
        std::string const & get_name_of_file() override final;

        /*! \brief Metoda pozwalajca pobrac pozycje obiektu sceny - drona */
        Vector3D const & get_position() override final;

        /*! \brief Metoda pozwalajaca na sprawdzenie, czy dany dron koliduje z wybranym obiektem sceny. */
        bool detect_collision(const std::shared_ptr<Scene_object> Obj_ptr) override final;

        /*! \brief Metoda pozwalajca pobrac dane o wymiarach obiektu. */
        Vector3D const & get_size() override final;
};  