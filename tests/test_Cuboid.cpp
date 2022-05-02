#include "../tests/doctest/doctest.h"
#include "Cuboid.hh"

TEST_CASE("Test konstrukora bezparametrycznego dla klasy Cuboid dziedziczacej z Geometrical_solid i przeciazenia operatora indeksujacego i funkcyjnego sluzacego odczytywaniu wartosci wierzcholkow globalnych i lokalnych z prostopadloscianu"){
    Cuboid Example;
    double val[3] = {FUSELAGE_SCALE};

    std::string name = ("../datasets/Glb_crd_");

    CHECK((Example.Get_Name_of_file_global() == name));

    CHECK ((Example.get_scale()[0] == val[0] && Example.get_scale()[1] == val[1] && Example.get_scale()[2] == val[2]));

    CHECK(( Example(0)[0]==-0.5 && Example(0)[1]==0.5  &&  Example(0)[2]==-0.5 &&
            Example(1)[0]==-0.5 && Example(1)[1]==-0.5 &&  Example(1)[2]==-0.5 &&
            Example(2)[0]==0.5  && Example(2)[1]==0.5  &&  Example(2)[2]==-0.5 &&
            Example(3)[0]==0.5  && Example(3)[1]==-0.5 &&  Example(3)[2]==-0.5 &&
            Example(4)[0]==0.5  && Example(4)[1]==0.5  &&  Example(4)[2]==0.5  &&
            Example(5)[0]==0.5  && Example(5)[1]==-0.5 &&  Example(5)[2]==0.5  &&
            Example(6)[0]==-0.5 && Example(6)[1]==0.5  &&  Example(6)[2]==0.5  &&
            Example(7)[0]==-0.5 && Example(7)[1]==-0.5 &&  Example(7)[2]==0.5));

    CHECK(( Example[0][0]==0 && Example[0][1]==0 &&  Example[0][2]==0 &&
            Example[1][0]==0 && Example[1][1]==0 &&  Example[1][2]==0 &&
            Example[2][0]==0 && Example[2][1]==0 &&  Example[2][2]==0 &&
            Example[3][0]==0 && Example[3][1]==0 &&  Example[3][2]==0 &&
            Example[4][0]==0 && Example[4][1]==0 &&  Example[4][2]==0 &&
            Example[5][0]==0 && Example[5][1]==0 &&  Example[5][2]==0 &&
            Example[6][0]==0 && Example[6][1]==0 &&  Example[6][2]==0 &&
            Example[7][0]==0 && Example[7][1]==0 &&  Example[7][2]==0));
}

TEST_CASE("Test przypiywania wratosci wektorow3D do tablicy wektorow reprezentujacych wspolrzedne lokalne prostopadloscianu, przy uzyciu przeciazenia operatora funkcyjnego"){
    Cuboid Example;
    double apx1[3]={-20,-15,-10};
    Vector3D v_Apx1(apx1);
    
    CHECK((Example(0)[0]==-0.5 && Example(0)[1]==0.5 && Example(0)[2]==-0.5));

    Example(0) = v_Apx1;

    CHECK(( Example(0)[0]==-20 && Example(0)[1]==-15 && Example(0)[2]==-10));
}

TEST_CASE("Test przypiywania wratosci wektorow3D do tablicy wektorow reprezentujacych wspolrzedne globalne prostopadloscianu, przy uzyciu przeciazenia operatora indeksujacego"){
    Cuboid Example;
    double apx1[3]={-20,-15,-10};
    Vector3D v_Apx1(apx1);
    
    CHECK(( Example[0][0]==0 && Example[0][1]==0 && Example[0][2]==0));

    Example[0] = v_Apx1;


    CHECK(( Example[0][0]==-20 && Example[0][1]==-15 && Example[0][2]==-10));
}

TEST_CASE("Test metody pozwalajacej na zmiane skali prostopaloscianu. "){
    Cuboid Example;
     
    double val[3] = {5,6,8}; 
    Vector3D vector(val);
    Example.update_scale(vector);

    CHECK((Example.get_scale()[0] == 5 && Example.get_scale()[1] == 6 && Example.get_scale()[2] == 8));
}
 
TEST_CASE("Test metody pozwalajacej na odczytywanie wartosci kata obrotu prostopadloscianu w osi Z. "){
    Cuboid Example;
    
    CHECK((Example.get_angle() == 0));
}

TEST_CASE("Test metody pozwalajacej na aktualizowanie wartosci kata obrotu prostopadloscianu w osi Z o podana wartosc. "){
    Cuboid Example;

    CHECK((Example.get_angle() == 0));

    Example.update_angleZ(40);

    CHECK((Example.get_angle() == 40));

    Example.update_angleZ(-20);

    CHECK((Example.get_angle() == 20));
}

TEST_CASE("Test metody pozwlajacej na transformacje prostopadloscianu z ukladu loklanego do globlanego sceny. "){
    Cuboid Example;

    double val[3] = {100,100,3}; 
    Vector3D vector(val);

    Example.Transform_to_global_coords(vector);

    CHECK(( Example[0][0]==95  && Example[0][1]==104 &&  Example[0][2]==0 &&
            Example[1][0]==95  && Example[1][1]==96  &&  Example[1][2]==0 &&
            Example[2][0]==105 && Example[2][1]==104 &&  Example[2][2]==0 &&
            Example[3][0]==105 && Example[3][1]==96  &&  Example[3][2]==0 &&
            Example[4][0]==105 && Example[4][1]==104 &&  Example[4][2]==6 &&
            Example[5][0]==105 && Example[5][1]==96  &&  Example[5][2]==6 &&
            Example[6][0]==95  && Example[6][1]==104 &&  Example[6][2]==6 &&
            Example[7][0]==95  && Example[7][1]==96  &&  Example[7][2]==6));
}