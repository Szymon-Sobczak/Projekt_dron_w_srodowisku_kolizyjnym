#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "matrix3x3.hh"
#include "vector3D.hh"

TEST_CASE("Test konstrukora bezparametrycznego dla klasy Matrix3x3."){
    Matrix3x3 Example;
    CHECK((Example(0,0)==1 && Example(0,1)==0 && Example(1,0)==0 && Example(1,1)==1));
}

TEST_CASE("Test konstrukora z argumentem dla klasy Matrix3x3. Stworzenie macierzy3x3."){ 
    Matrix3x3 Example[3][3];
    CHECK((sizeof(Example)/sizeof(Matrix3x3)==9));
}

TEST_CASE("Test wczytywania do oraz odczytywania wartosci macierzy3x3 z uzyciem operatora funkcyjnego."){
    double values_M[3][3]={1,2,3,4,5,6,7,8,9};
    Matrix3x3 Example(values_M);
    CHECK((Example(0,0) == 1 && Example(0,1) == 2 && Example(0,2) == 3 && 
           Example(1,0) == 4 && Example(1,1) == 5 && Example(1,2) == 6 && 
           Example(2,0) == 7 && Example(2,1) == 8 && Example(2,2) == 9));
}
 
TEST_CASE("Test wyswietlenia wartosci macierzy3x3 z uzyciem przeciazenia <<."){
    double values_M[3][3]={1,2,3,4,5,6,7,8,9};
    Matrix3x3 Example(values_M);
    std::ostringstream out;
    out << Example;
    CHECK(" 1.0000000000\t 2.0000000000\t 3.0000000000\t 4.0000000000\t 5.0000000000\t 6.0000000000\t 7.0000000000\t 8.0000000000\t 9.0000000000\t" == out.str());
}

TEST_CASE("Test wczytywania wartosci do macierzy3x3 z uzyciem przeciazenia >>."){
    Matrix3x3 Example;
    std::istringstream input("1 2 3 4 5 6 7 8 9");
    input >> Example;
    CHECK((Example(0,0) == 1 && Example(0,1) == 2 && Example(0,2) == 3 && 
           Example(1,0) == 4 && Example(1,1) == 5 && Example(1,2) == 6 && 
           Example(2,0) == 7 && Example(2,1) == 8 && Example(2,2) == 9));
}

TEST_CASE("Test reakcji na wczytywanie wartosci nie bedacej typu double do macierzy3x3 z uzyciem przeciazenia >>."){
    Matrix3x3 Example;
    std::istringstream input("1 % 3 Z a ^ f 8 7");
    WARN_THROWS(input >> Example);
}

TEST_CASE("Test porownania dwoch takich samych macierzy z uzyciem przeciazenia operatora porowania ==."){
    double values_M1[3][3]={1,2,3,4,5,6,7,8,9};
    Matrix3x3 Example1(values_M1), Example2(values_M1);
    CHECK((Example1 == Example2));
}

TEST_CASE("Test porownania dwoch roznych macierzy z uzyciem przeciazenia operatora porowania ==."){
    double values_M1[3][3]={1,2,3,4,5,6,7,8,9},values_M2[3][3]={1,5,7,4,6,5,4,8,1};
    Matrix3x3 Example1(values_M1), Example2(values_M2);
    CHECK(!(Example1 == Example2));
}

TEST_CASE("Test mnozenia macierzy3x3 i wektora przy pomocy przeciazenia operatora *."){
    double values_V[]={5,10,15}, values_M[3][3]={1,2,3,4,5,6,7,8,9};
    Vector3D Vec(values_V);
    Matrix3x3 Example(values_M);
    Vec = Example * Vec;
    CHECK((Vec[0] == 70 && Vec[1] == 160 && Vec[2] == 250));
}

TEST_CASE("Test mnozenia macierzy3x3 i macierzy3x3 przy pomocy przeciazenia operatora *."){
    double values_M1[3][3]={1,2,3,4,5,6,7,8,9}, values_M2[3][3]={9,5,-3,2,8,9,-4,2,1}, values_result[3][3]={1,27,18,22,72,39,43,117,60};
    Matrix3x3 Example1(values_M1), Example2(values_M2), Result(values_result); 
    CHECK((Result == (Example1 * Example2)));
}

TEST_CASE("Test dzielenia macierzy3x3 przez skalar przy pomocy przeciazenia operatora /."){
    double values_M1[3][3]={4,6,8,-12,16,-24,32,48,50}, values_result[3][3]={2,3,4,-6,8,-12,16,24,25};;
    Matrix3x3 Example1(values_M1), Result(values_result);
    
    CHECK((Result == Example1 / 2));
}

TEST_CASE("Test reakcji metody przeciazenia operatora / na dzielenie macierzy przez zero. "){
    double values_M1[3][3]={4,6,8,-12,16,-24,32,48,50};
    Matrix3x3 Example1(values_M1);
    WARN_THROWS(Example1 = Example1 / 0);
}

TEST_CASE("Test dodawania dwoch macierzy3D przy pomocy przeciazenia operatora +."){
    double values_M1[3][3]={4,6,-8,12,8,10,16,9,7}, values_M2[3][3]={2,3,4,-6,8,12,16,-4,10}, values_result[3][3]={6,9,-4,6,16,22,32,5,17};
    Matrix3x3 Example1(values_M1),Example2(values_M2),Result(values_result);
    CHECK((Result == Example1 + Example2));
}


TEST_CASE("Test funkcji wypelnijacej macierz3x3 odpowiednimi wartosciami funkcji tryg. dla podanego w stopniach kata dla obrotu w osi OX."){
    double values_result[3][3]={1,0,0,0,0,-1,0,1,0};
    Matrix3x3 Example, Result(values_result);
    Example = Fill_matrix_OX(90);
    CHECK((Result == Example));
}

TEST_CASE("Test funkcji wypelnijacej macierz3x3 odpowiednimi wartosciami funkcji tryg. dla podanego w stopniach kata dla obrotu w osi OY."){
    double values_result[3][3]={0,0,1,0,1,0,-1,0,0};
    Matrix3x3 Example, Result(values_result);
    Example = Fill_matrix_OY(90);
    CHECK((Result == Example));
}

TEST_CASE("Test funkcji wypelnijacej macierz3x3 odpowiednimi wartosciami funkcji tryg. dla podanego w stopniach kata dla obrotu w osi OZ."){
    double values_result[3][3]={0,-1,0,1,0,0,0,0,1};
    Matrix3x3 Example, Result(values_result);
    Example = Fill_matrix_OZ(90);
    CHECK((Result == Example));
}

TEST_CASE("Test funkcji wypelniajacej macierz2D wartosciami macierzy obrotu dla zadanego kata, poprzez porownanie, z uzyciem przeciazenia operatora porownania, iloczynu dwoch macierzy dla przeciwnych katow na podstawie obrotu w osi OX."){
    Matrix3x3 Example1, Example2, Result, Unit_matrix;
    Example1 = Fill_matrix_OY(60);
    Example2 = Fill_matrix_OY(-60);
    Result = Example1 * Example2;
    CHECK((Result == Unit_matrix));
}

TEST_CASE("Test dzialania metody przywracajacej dowolna macierz do postaci macierzy jednostkowej."){
    double values_M1[3][3]={1,2,3,4,5,6,7,8,9};
    Matrix3x3 Example1(values_M1),Unit_matrix;
    Example1.reset_matrix();
    CHECK((Example1==Unit_matrix));
}