#include "Obs_plateau.hh"

/*!
    \file Obs_plateau.cpp
        \brief Definicje metod klasy Plateau

    Zawiera definicje metod klasy Plateau.
*/

/*!
    Konstrukotr przetwarza bryle prostopadloscianu do postaci plaskowyzu i zapisuje go do pliku. 

    \param [in] position - wektor reprezentujacy polozenie srodka przeszkody.
    \param [in] scale - skala plaskowyzu.
    \param [in] ID - numer ID przeszkody.

    \return Plaskowyz o srodku w zadanej pozycji i skali, oraz zapisuje do pliku.
*/

Plateau::Plateau(Vector3D const & position, Vector3D const & scale, unsigned int ID) : Cuboid (), Scene_object(ID, "plaskowyz") {
    update_scale (scale);
    save_to_file(position);
}

/*!
    Metoda zapisuje do pliku, o wygenerowanej automatycznie nazwie, dane o polozeniu wierzcholkow globalnych plaskowyzu, po uprzednim wyliczeniu ich. 
    Zapis odbywa sie w sposob umozliwajacy wyswietlenie wszystkich scian przeszkody w Gnuplot.   

    \param [in] position - wektor reprezentujacy polozenie srodka przeszkody.
*/

void Plateau::save_to_file(Vector3D const & position){
    
    Transform_to_global_coords(position);

    std::ofstream  FileStrm;
    Vector3D P1,P2;

    std::string name_of_file = "../datasets/Glb_crd_No_" + std::to_string(get_obj_ID()) + "_plateau.dat";
    
    update_Name_of_file_global(name_of_file);

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }
    
    P1 = ((*this)[0] + (*this)[7])/2;
    P2 = ((*this)[2] + (*this)[5])/2;

    FileStrm << P1 << std::endl
             << (*this)[6] << std::endl
             << (*this)[4] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;

    FileStrm << P1 << std::endl
             << (*this)[7] << std::endl
             << (*this)[5] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << (*this)[1] << std::endl
             << (*this)[3] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << (*this)[0] << std::endl
             << (*this)[2] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << (*this)[6] << std::endl
             << (*this)[4] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm.close();
}

/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Nazwe pliku zawierajacego dane o wierzcholkach plaskowyzu jako std::string.
*/

std::string const & Plateau::get_name_of_file(){
  return Get_Name_of_file_global();
}

/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Vector3D reprezentujacy srodek plaskowyzu.
*/

Vector3D const & Plateau::get_position(){
  return get_center();
}


/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Vector3D reprezentujacy skale- wymiary plaskowyzu.
*/

Vector3D const & Plateau::get_size(){
    return get_scale();
}