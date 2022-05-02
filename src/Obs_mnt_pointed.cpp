#include "Obs_mnt_pointed.hh"

/*!
    \file Obs_mnt_pointed.cpp
        \brief Definicje metod klasy Mnt_pointed

    Zawiera definicje metod klasy Mnt_pointed.
*/

/*!
    Konstrukotr przetwarza bryle prostopadloscianu do postaci gory ze szczytem i zapisuje ja do pliku. 

    \param [in] position - wektor reprezentujacy polozenie srodka przeszkody.
    \param [in] scale - skala gory ze szczytem.
    \param [in] ID - numer ID przeszkody.

    \return Gora ze szczytem o srodku w zadanej pozycji i skali, oraz zapisuje do pliku.
*/

Mnt_pointed::Mnt_pointed(Vector3D const & position, Vector3D const & scale, unsigned int ID) : Cuboid (), Scene_object(ID, "gora ze szczytem") {
    update_scale (scale);
    transform_shape();
    save_to_file(position);
}

/*!
    Metoda zapisuje do pliku, o wygenerowanej automatycznie nazwie, dane o polozeniu wierzcholkow globalnych gory ze szczytem, po uprzednim wyliczeniu ich. 
    Zapis odbywa sie w sposob umozliwajacy wyswietlenie wszystkich scian przeszkody w Gnuplot.   

    \param [in] position - wektor reprezentujacy polozenie srodka przeszkody.
*/

void Mnt_pointed::save_to_file(Vector3D const & position){
    
    Transform_to_global_coords(position);

    std::ofstream  FileStrm;
    Vector3D P1, P2;

    std::string name_of_file = "../datasets/Glb_crd_No_" + std::to_string(get_obj_ID()) + "_mnt_pointed.dat";
    
    update_Name_of_file_global(name_of_file);

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }
    
    P1 = ((*this)[7] + ((*this)[0] + (*this)[1]) / 2) / 2;
    P2 = ((*this)[7] + ((*this)[2] + (*this)[3]) / 2) / 2;

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
    \return Nazwe pliku zawierajacego dane o wierzcholkach gory ze szczytem, jako std::string.
*/

std::string const & Mnt_pointed::get_name_of_file(){
  return Get_Name_of_file_global();
}

/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Vector3D reprezentujacy srodek gory ze szczytem.
*/
Vector3D const & Mnt_pointed::get_position(){
  return get_center();
}

/*! 
    Metoda modelujaca ksztalt gory ze szczytem.
*/

void Mnt_pointed::transform_shape(){
    Vector3D apex = ((*this)(7)  + (*this)(4)) / 2; 
    (*this)(4) = apex;
    (*this)(5) = apex;
    (*this)(6) = apex;
    (*this)(7) = apex;
}

/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Vector3D reprezentujacy skale- wymiary gory ze szczytem.
*/

Vector3D const & Mnt_pointed::get_size(){
    return get_scale();
}