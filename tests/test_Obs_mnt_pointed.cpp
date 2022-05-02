#include "../tests/doctest/doctest.h"
#include "Obs_mnt_pointed.hh"

TEST_CASE("Test kostrukotra klasy Mnt_pointed oraz metod pozwalajacych na wymodelowanie ksztaltu gory oraz pobranie numeru ID oraz nazwy typu obiektu dziedziczacego po Scene_object. "){
    double positon_val[3] = {150,100,15}, scale_val[3] = {60,60,30};
    Vector3D position(positon_val), scale(scale_val);
    Mnt_pointed Example(position,scale,99);

    CHECK((Example.get_position()[0] == 150 && Example.get_position()[1] == 100 && Example.get_position()[2] == 15 ));
 
    CHECK((Example.get_scale()[0] == 60 && Example.get_scale()[1] == 60 && Example.get_scale()[2] == 30));

    CHECK(( Example(0)[0]==-0.5 && Example(0)[1]==0.5  &&  Example(0)[2]==-0.5 &&
            Example(1)[0]==-0.5 && Example(1)[1]==-0.5 &&  Example(1)[2]==-0.5 &&
            Example(2)[0]==0.5  && Example(2)[1]==0.5  &&  Example(2)[2]==-0.5 &&
            Example(3)[0]==0.5  && Example(3)[1]==-0.5 &&  Example(3)[2]==-0.5 &&
            Example(4)[0]==0  && Example(4)[1]==0  &&  Example(4)[2]==0.5  &&
            Example(5)[0]==0 && Example(5)[1]==0 &&  Example(5)[2]==0.5  &&
            Example(6)[0]==0 && Example(6)[1]==0  &&  Example(6)[2]==0.5  &&
            Example(7)[0]==0 && Example(7)[1]==0 &&  Example(7)[2]==0.5));

    CHECK(( Example[0][0]==120 && Example[0][1]==130 &&  Example[0][2]==0 &&
            Example[1][0]==120 && Example[1][1]==70 &&  Example[1][2]==0 &&
            Example[2][0]==180 && Example[2][1]==130 &&  Example[2][2]==0 &&
            Example[3][0]==180 && Example[3][1]==70 &&  Example[3][2]==0 &&
            Example[4][0]==150 && Example[4][1]==100 &&  Example[4][2]==30 &&
            Example[5][0]==150 && Example[5][1]==100 &&  Example[5][2]==30 &&
            Example[6][0]==150 && Example[6][1]==100  &&  Example[6][2]==30 &&
            Example[7][0]==150 && Example[7][1]==100 &&  Example[7][2]==30));
}

