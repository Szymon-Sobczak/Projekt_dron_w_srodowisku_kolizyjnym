#include "../tests/doctest/doctest.h"
#include "vector3D.hh"

TEST_CASE("Test odczytywania wartosci wektora3D z uzyciem operatora indeksowania."){
    double values[]={1,2,3},a,b,c;
    Vector3D Vec(values);
    a = Vec[0];
    b = Vec[1];
    c = Vec[2];
    CHECK((a == 1 && b == 2 && c == 3));
}
 
TEST_CASE("Test wprowadzania wartosci do wektora3D z uzyciem operatora indeksowania."){ 
    Vector3D Vec;
    double a=7,b=15,c=20;
    Vec[0]=a;
    Vec[1]=b;
    Vec[2]=c;
    CHECK((Vec[0]==7 && Vec[1]==15 && Vec[2]==20));
}

TEST_CASE("Test konstrukora bezparametrowego dla klasy Vector3D."){
    Vector3D Vec;
    CHECK((Vec[0]==0 && Vec[1]==0 && Vec[2]==0));
}

TEST_CASE("Test konstrukora z argumentem dla klasy Vector3D."){
    double values[]={1,2,3};
    Vector3D Vec(values);
    CHECK((Vec[0]==1 && Vec[1]==2 && Vec[2]==3));
}

TEST_CASE("Test operatora indeksowania - bledna wartosc indeksu podana przy odczytywaniu wartosci z wektora3D."){
    double values[]={1,2,3};
    Vector3D Vec(values);
    WARN_THROWS (Vec[-8]);
}

TEST_CASE("Test operatora indeksowania - bledna wartosc indeksu podana przy przypisywaniu wartosci do wektora3D."){
    double values[]={1,2,3};
    Vector3D Vec(values);
    WARN_THROWS (Vec[-8]=5);
}

TEST_CASE("Test wyswietlenia wartosci wektora3D z uzyciem przeciazenia <<."){
    double values[]={1,2,3};
    Vector3D Vec(values);
    std::ostringstream out;
    out << Vec;
    CHECK ("1.0000000000\t2.0000000000\t3.0000000000\t" == out.str());  
}

TEST_CASE("Test wczytywania wartosci do wektora3D z uzyciem przeciazenia >>."){
    Vector3D Vec;
    std::istringstream input("1 2 3");
    input >> Vec;
    CHECK ((Vec[0] == 1 && Vec[1] == 2 && Vec[2] == 3));  
}

TEST_CASE("Test reakcji na wczytywanie wartosci nie bedacej typu double do wektora3D z uzyciem przeciazenia >>."){
    double values[]={1,2,3};
    Vector3D Vec(values);
    std::istringstream input("Z % .");
    WARN_THROWS (input >> Vec);
}

TEST_CASE("Test dodawania dwoch wektorow przy pomocy przeciazenia operatora +."){
    double values1[]={1,2,3},values2[]={6,8,-7};
    Vector3D Vec1(values1),Vec2(values2);
    Vec1=Vec1+Vec2;
    CHECK ((Vec1[0] == 7 && Vec1[1] == 10 && Vec1[2] == -4));  
}

TEST_CASE("Test odejmowania dwoch wektorow przy pomocy przeciazenia operatora -."){
    double values1[]={1,2,5},values2[]={6,8,-6};
    Vector3D Vec1(values1),Vec2(values2);
    Vec1=Vec1-Vec2;
    CHECK ((Vec1[0] == -5 && Vec1[1] == -6 && Vec1[2] == 11));  
}

TEST_CASE("Test mnozenia wektora3D i liczby typu double przy pomocy przeciazenia operatora *."){
    double values1[]={1,2,3};
    Vector3D Vec1(values1);
    Vec1=Vec1*2;
    CHECK ((Vec1[0] == 2 && Vec1[1] == 4 && Vec1[2] == 6));  
}

TEST_CASE("Test dzielenia wektora3D przez liczbe typu double przy pomocy przeciazenia operatora /."){
    double values1[]={1,2,3};
    Vector3D Vec1(values1);
    Vec1=Vec1/2;
    CHECK ((Vec1[0] == 0.5 && Vec1[1] == 1 && Vec1[2] == 1.5));  
}

TEST_CASE("Test reakcji na dzielenie wektora3D przez 0."){
    double values1[]={1,2,3};
    Vector3D Vec1(values1);
    WARN_THROWS (Vec1 = Vec1 / 0);
}

TEST_CASE("Test funkcji wyznaczajacej dlugosc odcinka pomiedzy dwoma wektorami w 3D."){
    double values1[]={1,2,6},values2[]={12,2,6};
    Vector3D Vec1(values1),Vec2(values2);
    CHECK (vector_length(Vec1,Vec2) == 11);
}