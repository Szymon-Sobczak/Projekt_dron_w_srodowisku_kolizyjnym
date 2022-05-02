#include "../tests/doctest/doctest.h"
#include "Drone.hh"

TEST_CASE("Test konstruktora klasy z parametrem oraz metod do pozyskiwania wartosci wektora polozenia drona oraz kata orientacji drona."){
    double val[3]={100,100,3};
    Vector3D center(val);
    Drone Example(center,0);
    CHECK((Example.get_position()[0] ==100 && Example.get_position()[1] == 100 && Example.get_position()[2] == 3));    
}

TEST_CASE("Test metody pozwalajacej na pobranie kata obrotu drona. "){
    double val[3]={100,100,3};
    Vector3D center(val);
    Drone Example(center,0);

    CHECK((Example.get_angle() == 0));    
}

TEST_CASE("Test metody pozwalajacej na aktualizacje kata obrotu drona. "){
    double val[3]={100,100,3};
    Vector3D center(val);
    Drone Example(center,0);

    CHECK((Example.get_angle() == 0)); 

    Example.update_angle(45);   

    CHECK((Example.get_angle() == 45)); 

    Example.update_angle(-20);   

    CHECK((Example.get_angle() == 25)); 
}