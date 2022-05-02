#pragma once

/*!
    \file size.hh
        \brief definicje stalych wystepujacych w programie.
*/

/*! \brief Ilosc wiecholkow przetwarzanej figury. */                         
constexpr int CORNERS = 8;  

/*! \brief Warotsc minimalnej roznicy wartosci faktycznej od przyblizonej w programie. */            
constexpr double MAX_VALUE_DIFF = 0.0000000001;   

/*! \brief Ilosc klatek animacji ruchu drona */      
constexpr int FRAMES = 100;  

/*! \brief Wysokosc na jaka wznosi sie dron */ 
constexpr double ALTITUDE = 100;   

/*! \brief Odleglosc na jaka dron odlatuje od pozycji poczatkowej. aby rozpoczac zwiad */ 
constexpr int REACON_RADIUS = 40; 

/*! \brief Skala kadluba */ 
#define FUSELAGE_SCALE 10, 8, 6

/*! \brief Skala rotora */ 
#define ROTOR_SCALE 8, 8, 2 

/*! \brief Skala kamery */ 
#define CAM_SCALE 4, 8, 3