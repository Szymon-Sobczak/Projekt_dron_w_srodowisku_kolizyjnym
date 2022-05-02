#include "../tests/doctest/doctest.h"
#include "Geometrical_solid.hh"

TEST_CASE("Test konstruktora bezparametrycznego klasy Geometrical_solid oraz metod pozwalajacych na pobranie nazwy obietku oraz jego skali. "){
    Geometrical_solid Example; 
    std::string name = ("../datasets/Glb_crd_");

    CHECK((Example.Get_Name_of_file_global() == name));

    CHECK((Example.get_scale()[0] == 0 && Example.get_scale()[1] == 0 && Example.get_scale()[2] == 0 ));
}

TEST_CASE("Test metody pozwalajacej na zaktualizowanie skali. "){
    Geometrical_solid Example;
    double val[3] = {10,-9,2.5}; 
    Vector3D vector(val);
    Example.update_scale(vector);

    CHECK((Example.get_scale()[0] == 10 && Example.get_scale()[1] == -9 && Example.get_scale()[2] == 2.5 ));
}

TEST_CASE("Test metod pozwalajacych na zaktualizowanie i na pobranie nazwy. "){
    Geometrical_solid Example;
    std::string new_file_name = "new_name";
    
    CHECK((Example.Get_Name_of_file_global() == "../datasets/Glb_crd_")); 
    
    Example.update_Name_of_file_global(new_file_name);
    
    CHECK((Example.Get_Name_of_file_global() == "new_name")); 
}