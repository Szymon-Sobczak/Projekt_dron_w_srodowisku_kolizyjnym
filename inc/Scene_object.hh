#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <memory>
#include <algorithm>

#include "Geometrical_solid.hh"


/*!
    \file Scene_object.hh
        \brief  Definicja klasy Scene_object.

    Prototypy metod klasy Scene_object.
*/

/*!
  \brief Klasa modelujaca w programie pojecie obiektu sceny.   

    Klasa posiada:
        - Prywatne pole "object_ID" reprezentuje numer identyfikacyjny obiektu sceny.
        - Prywatne pole "type_of_obj" reprezentuje nazwe typu obiektu sceny.
        - Publiczny konstuktor wieloparametryczny pozwalajacy stworzyc obiekt sceny o okreslonym ID i nazwie.
        - Publiczny destruktor wirtualny.

    Utworzona klasa zawiera publiczne metody pozwalajace na:
        - Pobranie numeru ID obiektu sceny.
        - Pobranie nazwy typu obiektu sceny.

    Utworzona klasa zawiera metody czysto wirtualne pozwalajace na:
        - Pobranie nazwy pliku obiektu sceny z klas pochodnych.
        - Pobranie wektora reprezentujacego srodek obiektu sceny z klas pochodnych.
        - Sprawdzenie kolizji obiektu sceny z innymi obiektami sceny. 
        - Pobranie wymiarow, ktore reprezentuja obiekty.
*/

class Scene_object{
    private:
        /*! \brief Pole typu int, reprezentuje numer identyfikacyjny obiektu sceny */
        int object_ID;

        /*! \brief Pole typu std::string, reprezentuje nazwe typu obiektu sceny */
        std::string type_of_obj;
    
    public:
        /*! \brief Konstruktor wieloparametryczny */
        Scene_object(unsigned int ID, std::string type);

        /*! \brief Destrukor wirtualny */
        virtual ~Scene_object() {};

        /*! \brief Metoda pozwalajaca pobrac nazwe typu obiektu sceny. */
        std::string get_type() const;

        /*! \brief Metoda pozwalajaca pobrac numer ID obiektu sceny. */
        int get_obj_ID();

        /*! \brief Metoda czysto wirtualna, stanowi interfejs pozwalajacy pobierac nazwy plikow bryl. */
        virtual std::string const & get_name_of_file() = 0;
        
        /*! \brief Metoda czysto wirtualna, stanowi interfejs pozwalajacy pobierac wektor pozycji srodka bryly. */
        virtual Vector3D const & get_position() = 0;

        /*! \brief Metoda czysto wirtualna, stanowi interfejs pozwalajacy pobierac wymiary drona - promien, przeszkody- skale. */
        virtual Vector3D const & get_size() = 0;
    
        /*! \brief Metoda czysto wirtualna, stanowi interfejs pozwalajacy na sprawdzanie kolizji obiektow z innymi obiektami. */
        virtual bool detect_collision(const std::shared_ptr<Scene_object> Obj_ptr) {(void)Obj_ptr; return false;}
};