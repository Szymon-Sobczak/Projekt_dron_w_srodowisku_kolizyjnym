#include "../tests/doctest/doctest.h"
#include "Hexagonal_prism.hh"


TEST_CASE("Test konstrukora bezparametrycznego dla klasy Cuboid dziedziczacej z Geometrical_solid i przeciazenia operatora indeksujacego i funkcyjnego sluzacego odczytywaniu wartosci wierzcholkow globalnych i lokalnych z prostopadloscianu"){
    Hexagonal_prism Example;
    double val[3] = {ROTOR_SCALE};
    
    std::string name = ("../datasets/Glb_crd_");

    CHECK((Example.Get_Name_of_file_global() == name));

    CHECK ((Example.get_scale()[0] == val[0] && Example.get_scale()[1] == val[1] && Example.get_scale()[2] == val[2]));

    CHECK(( Example(0)[0]==0.5    && Example(0)[1]==0       &&  Example(0)[2]==-0.5  &&
            Example(1)[0]==0.25   && Example(1)[1]==0.433   &&  Example(1)[2]==-0.5  &&
            Example(2)[0]==-0.25  && Example(2)[1]==0.433   &&  Example(2)[2]==-0.5  &&
            Example(3)[0]==-0.5   && Example(3)[1]==0       &&  Example(3)[2]==-0.5  &&
            Example(4)[0]==-0.25  && Example(4)[1]==-0.433  &&  Example(4)[2]==-0.5  &&
            Example(5)[0]==0.25   && Example(5)[1]==-0.433  &&  Example(5)[2]==-0.5  &&
            Example(6)[0]==0.5    && Example(6)[1]==0       &&  Example(6)[2]==0.5   &&
            Example(7)[0]==0.25   && Example(7)[1]==0.433   &&  Example(7)[2]==0.5   &&
            Example(8)[0]==-0.25  && Example(8)[1]==0.433   &&  Example(8)[2]==0.5   &&
            Example(9)[0]==-0.5   && Example(9)[1]==0       &&  Example(9)[2]==0.5   &&
            Example(10)[0]==-0.25 && Example(10)[1]==-0.433 &&  Example(10)[2]==0.5  &&
            Example(11)[0]==0.25  && Example(11)[1]==-0.433 &&  Example(11)[2]==0.5));

    CHECK(( Example[0][0]==0 && Example[0][1]==0 &&  Example[0][2]==0 &&
            Example[1][0]==0 && Example[1][1]==0 &&  Example[1][2]==0 &&
            Example[2][0]==0 && Example[2][1]==0 &&  Example[2][2]==0 &&
            Example[3][0]==0 && Example[3][1]==0 &&  Example[3][2]==0 &&
            Example[4][0]==0 && Example[4][1]==0 &&  Example[4][2]==0 &&
            Example[5][0]==0 && Example[5][1]==0 &&  Example[5][2]==0 &&
            Example[6][0]==0 && Example[6][1]==0 &&  Example[6][2]==0 &&
            Example[7][0]==0 && Example[7][1]==0 &&  Example[7][2]==0 &&
            Example[8][0]==0 && Example[8][1]==0 &&  Example[8][2]==0 &&
            Example[9][0]==0 && Example[9][1]==0 &&  Example[9][2]==0 &&
            Example[10][0]==0 && Example[10][1]==0 &&  Example[10][2]==0 &&
            Example[11][0]==0 && Example[11][1]==0 &&  Example[11][2]==0));
}

TEST_CASE("Test przypiywania wratosci wektorow3D do tablicy wektorow reprezentujacych wspolrzedne lokalne prostopadloscianu, przy uzyciu przeciazenia operatora funkcyjnego"){
    Hexagonal_prism Example;
    double apx1[3]={-20,-15,-10};
    Vector3D v_Apx1(apx1);
    
    CHECK((Example(0)[0]==0.5 && Example(0)[1]==0 && Example(0)[2]==-0.5));

    Example(0) = v_Apx1;

    CHECK(( Example(0)[0]==-20 && Example(0)[1]==-15 && Example(0)[2]==-10));
}

TEST_CASE("Test przypiywania wratosci wektorow3D do tablicy wektorow reprezentujacych wspolrzedne globalne prostopadloscianu, przy uzyciu przeciazenia operatora indeksujacego"){
    Hexagonal_prism Example;
    double apx1[3]={-20,-15,-10};
    Vector3D v_Apx1(apx1);
    
    CHECK(( Example[0][0]==0 && Example[0][1]==0 && Example[0][2]==0));

    Example[0] = v_Apx1;

    CHECK(( Example[0][0]==-20 && Example[0][1]==-15 && Example[0][2]==-10));
}

TEST_CASE("Test metody pozwalajacej na zmiane skali prostopaloscianu. "){
    Hexagonal_prism Example;
     
    double val[3] = {5,6,8}; 
    Vector3D vector(val);
    Example.update_scale(vector);

    CHECK((Example.get_scale()[0] == 5 && Example.get_scale()[1] == 6 && Example.get_scale()[2] == 8));
}
 
TEST_CASE("Test metody pozwalajacej na odczytywanie wartosci kata obrotu prostopadloscianu w osi Z. "){
    Hexagonal_prism Example;
    
    CHECK((Example.get_angle() == 0));
}

TEST_CASE("Test metody pozwalajacej na aktualizowanie wartosci kata obrotu graniastoslupa prawidlowego szesciokatnego w osi Z o podana wartosc. "){
    Hexagonal_prism Example;

    CHECK((Example.get_angle() == 0));

    Example.update_angleZ(40);

    CHECK((Example.get_angle() == 40));

    Example.update_angleZ(-20);

    CHECK((Example.get_angle() == 20));
}

TEST_CASE("Test metody pozwlajacej na transformacje graniastoslupa prawidlowego szesciokatnego z ukladu loklanego do globlanego sceny poprzez uklad kadluba. Graniastososlup nieobrocony"){
    Hexagonal_prism Example;

    double val1[3] = {100,100,3},val2[3] = {5,4,3}; 
    Vector3D center(val1), translation(val2);

    Example.Transform_to_global_coords(translation, center, 0);

    CHECK(( Example[0][0]==109 && Example[0][1]==104 &&  Example[0][2]==5 &&
            Example[1][0]==107 && Example[1][1]==107.464 &&  Example[1][2]==5 &&
            Example[2][0]==103 && Example[2][1]==107.464 &&  Example[2][2]==5 &&
            Example[3][0]==101 && Example[3][1]==104 &&  Example[3][2]==5 &&
            Example[4][0]==103 && Example[4][1]==100.536 &&  Example[4][2]==5 &&
            Example[5][0]==107 && Example[5][1]==100.536  &&  Example[5][2]==5 &&
            Example[6][0]==109 && Example[6][1]==104 &&  Example[6][2]==7 &&
            Example[7][0]==107 && Example[7][1]==107.464 &&  Example[7][2]==7 &&
            Example[8][0]==103 && Example[8][1]==107.464 &&  Example[8][2]==7 &&
            Example[9][0]==101 && Example[9][1]==104 &&  Example[9][2]==7 &&
            Example[10][0]==103 && Example[10][1]==100.536 &&  Example[10][2]==7 &&
            Example[11][0]==107 && Example[11][1]==100.536 &&  Example[11][2]==7));
}

TEST_CASE("Test metody pozwlajacej na transformacje graniastoslupa prawidlowego szesciokatnego z ukladu loklanego do globlanego sceny poprzez uklad kadluba. Drona obroconego o 90 stopni w osi Z"){
    Hexagonal_prism Example;

    double val1[3] = {100,100,3},val2[3] = {5,4,3}; 
    Vector3D center(val1), translation(val2);

    Example.Transform_to_global_coords(translation, center, 90);

    CHECK(( Example[0][0]==96 && Example[0][1]==109 &&  Example[0][2]==5 &&
            Example[1][0]==92.536 && Example[1][1]==107 &&  Example[1][2]==5 &&
            Example[2][0]==92.536 && Example[2][1]==103 &&  Example[2][2]==5 &&
            Example[3][0]==96 && Example[3][1]==101 &&  Example[3][2]==5 &&
            Example[4][0]==99.464 && Example[4][1]==103 &&  Example[4][2]==5 &&
            Example[5][0]==99.464 && Example[5][1]==107  &&  Example[5][2]==5 &&
            Example[6][0]==96 && Example[6][1]==109 &&  Example[6][2]==7 &&
            Example[7][0]==92.536 && Example[7][1]==107 &&  Example[7][2]==7 &&
            Example[8][0]==92.536  && Example[8][1]==103 &&  Example[8][2]==7 &&
            Example[9][0]==96 && Example[9][1]==101 &&  Example[9][2]==7 &&
            Example[10][0]==99.464  && Example[10][1]==103 &&  Example[10][2]==7 &&
            Example[11][0]==99.464  && Example[11][1]==107 &&  Example[11][2]==7));
}