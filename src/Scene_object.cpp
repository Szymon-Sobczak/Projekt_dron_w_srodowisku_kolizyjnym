#include "Scene_object.hh"

/*!
    \file Scene_object.cpp
        \brief Definicje metod klasy Scene_object

    Zawiera definicje metod klasy Scene_object.
*/

/*!
    \param [in] ID - numer ID nowego obiektu sceny.
    \param [in] type - nazwa typu nowego obietku sceny.

    \return Obiekt sceny o okreslonym parametrami ID oraz nazwa.
*/

Scene_object::Scene_object(unsigned int ID, std::string type){    
    object_ID = ID;
    type_of_obj = type;
}

/*!
    \return ID obietku sceny jako wartosc typu int.
*/

int Scene_object::get_obj_ID(){
    return object_ID;
}

/*!
    \return Nazwe typu obiektu sceny jako std::string.
*/
std::string Scene_object::get_type() const{
    return type_of_obj;
}
