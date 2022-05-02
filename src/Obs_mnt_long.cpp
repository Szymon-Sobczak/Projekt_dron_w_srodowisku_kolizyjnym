#include "Obs_mnt_long.hh"

/*!
    \file Obs_mnt_long.cpp
        \brief Definicje metod klasy Mnt_long

    Zawiera definicje metod klasy Mnt_long.
*/

/*!
    Konstrukotr przetwarza bryle prostopadloscianu do postaci gory ze zboczem i zapisuje ja do pliku. 

    \param [in] position - wektor reprezentujacy polozenie srodka przeszkody.
    \param [in] scale - skala  gory ze zboczem.
    \param [in] ID - numer ID przeszkody.

    \return Gora ze zboczem o srodku nachylonego boku w zadanej pozycji i skali, oraz zapisuje do pliku.
*/

Mnt_long::Mnt_long(Vector3D const & position, Vector3D const & scale, unsigned int ID) : Cuboid (), Scene_object(ID, "gora z grania") {
    update_scale (scale);
    transform_shape();
    save_to_file(position);
}


/*!
    Metoda zapisuje do pliku, o wygenerowanej automatycznie nazwie, dane o polozeniu wierzcholkow globalnych gory ze zboczem, po uprzednim wyliczeniu ich. 
    Zapis odbywa sie w sposob umozliwajacy wyswietlenie wszystkich scian przeszkody w Gnuplot.   

    \param [in] position - wektor reprezentujacy polozenie srodka nachylonego boku przeszkody.
*/

void Mnt_long::save_to_file(Vector3D const & position){
    
    Transform_to_global_coords(position);

    std::ofstream  FileStrm;
    Vector3D P1,P2;

    std::string name_of_file = "../datasets/Glb_crd_No_" + std::to_string(get_obj_ID()) + "_mnt_long.dat";
    
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
    \return Nazwe pliku zawierajacego dane o wierzcholkach gory ze zboczem, jako std::string.
*/
std::string const & Mnt_long::get_name_of_file(){
  return Get_Name_of_file_global();
}

/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Vector3D reprezentujacy srodek nachylonego boku gory ze zboczem.
*/

Vector3D const & Mnt_long::get_position(){
  return get_center();
}

/*! 
    Metoda modelujaca ksztalt gory ze zboczem.
*/

void Mnt_long::transform_shape(){
    (*this)(4) = (*this)(5);
    (*this)(6) = (*this)(7);
}


/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    \return Vector3D reprezentujacy skale- wymiary gory ze zboczem.
*/

Vector3D const & Mnt_long::get_size(){
    Vector3D tmp = get_scale();
    return get_scale();
}