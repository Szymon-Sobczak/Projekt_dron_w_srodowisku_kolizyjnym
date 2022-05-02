#include "../tests/doctest/doctest.h"
#include "vector3D.hh"

TEST_CASE("Test licznika wszyskich powstalych w programie wektorow3D oraz metody pozwalajacej na jego odczytanie. "){ 
    double val[3]={1,2,3};
    int Origin_nbr_of_vec = Vector3D::get_counter_all_vectors();

    Vector3D Vec1(val), Vec2;
    
    CHECK((Vector3D::get_counter_all_vectors() == (Origin_nbr_of_vec + 2)));

    Vector3D Vec3;

    CHECK((Vector3D::get_counter_all_vectors() == (Origin_nbr_of_vec + 3)));
}

TEST_CASE("Test licznika aktualnie istnijacych w programie wektorow3D oraz metody pozwalajacej na jego odczytanie. "){ 
    double val[3]={1,2,3};
    int Origin_nbr_of_vec = Vector3D::get_counter_actual_vectors();

    Vector3D Vec1(val), Vec2;
    
    CHECK((Vector3D::get_counter_actual_vectors() == (Origin_nbr_of_vec + 2)));

    Vector3D Vec3;

    CHECK((Vector3D::get_counter_actual_vectors() == (Origin_nbr_of_vec + 3)));

    Vec3.~Vector();

    CHECK((Vector3D::get_counter_actual_vectors() == (Origin_nbr_of_vec + 2)));
}

