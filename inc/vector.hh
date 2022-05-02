#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <cmath>

/*!
    \file vector.hh
        \brief Prototyp i definicja szablonu klasy Vector.

    Prototypy i definicje metod szablonu klasy Vector.
*/

/*!
   \brief Szablon klasy modelujacej w programie pojecie wektora.      
    
    Utworzona klasa zawiera:
        - konstruktor bezparametryczny, tworzacy wektor zerowy o zadanej dlugosci. 
        - konstruktor wieloparametryczny, tworzacy wektor o zadanej dlugosci wypelniony warosciami pochodzacymi z parametru - tablicy wartosci typu double.   
        - prywatne pole "size" bedace tablica - zbiorem wspolrzednych. 
        - publiczne przeciazenia operatorow indeksujacych opowiedzialnych za wprowadzanie i odczytywanie wspolrzendych z wektora.
        - przeciazenie operatora dodawania, odejmowania, mnozenia dwoch wektorow i dzielenia wektora razy skalar.      
*/

template <unsigned int Size>
class Vector{
    private:
        /*! \brief Tablica wartosci wektora. */
        double size[Size];     

        /*! \brief Licznik ilosci aktualnie istniejacych instancji obietkow Vector<Size> */
        static unsigned long long counter_actual_vectors;

        /*! \brief Licznik ilosci wszystkich istniejacych instancji obietkow Vector<Size> */
        static unsigned long long counter_all_vectors;
    public:
        /*! \brief Bezparametryczny konstruktor klasy. */
        Vector<Size>();  

        /*! \brief Konstruktor kopiujacy klasy. */
        Vector<Size>(const Vector<Size> & Ob);

        /*! \brief Konstruktor klasy z parametrem. */
        Vector<Size>(double tmp[Size]); 

        /*! \brief Destruktor klasy Vector<Size>. */
        ~Vector<Size>();

        /*! \brief Przeciazenie operatora przypisania */
        Vector<Size> & operator = (const Vector<Size> & Ob);

        /*! \brief Metoda statyczna pozwalajaca pobrac liczbe aktualnie istniejacych instancji obietkow Vector<Size>. */
        static int get_counter_actual_vectors();        

        /*! \brief Metoda statyczna pozwalajaca pobrac liczbe wszystich instancji obietkow Vector<Size>. */
        static int get_counter_all_vectors();      

        /*! \brief Operator dodawania dwoch wektorow. */
        Vector operator + (const Vector &v);   
        
        /*! \brief Operator odejmowania dwoch wektorow. */
        Vector operator - (const Vector &v);    
        
        /*! \brief Operator mnozenia wektora i liczby typu double. */
        Vector operator * (const double &tmp);  
        
        /*! \brief Operator zwielokrotnienia wartosci wektora wartosciami drugiego wektora */
        Vector operator * (const Vector &v);  

        /*! \brief Operator dzielenia wektora i liczby typu double. */
        Vector operator / (const double &tmp); 
        
        /*! \brief Przeciazenia operatora indeksujacego. */
        const double & operator [] (unsigned int index) const; 
        
        /*! \brief Przeciazenia operatora indeksujacego. */
        double & operator [] (unsigned int index);
};

/*! \brief Inicjalizacja pola statycznego counter_all_vecors*/
template <unsigned int Size>
unsigned long long Vector<Size>::counter_all_vectors = 0;

/*! \brief Inicjalizacja pola statycznego counter_actual_vectors*/
template <unsigned int Size>
unsigned long long Vector<Size>::counter_actual_vectors = 0;

/*! \brief Funkcja pomocnicza, pozwala zmierzyc odlegosc pomiedzy dwoma wektorami, tworzacymi nowy wektor */ 
template <unsigned int Size>
double vector_length(Vector<Size> const & vec1, Vector<Size> const & vec2);

/*! \brief Przeciazenie operatora << sluzace do wyswietlana wektora. */ 
template <unsigned int Size>
std::ostream & operator << (std::ostream &out, Vector<Size> const &tmp); 

/*! \brief Przeciazenie operatora >> sluzace do wczytywania wartosci do wektora. */
template <unsigned int Size>
std::istream & operator >> (std::istream &in, Vector<Size> &tmp); 



/*!
    Konstruktor bezparametryczny klasy Vector tworzacy wektor zerowy o zadanej dlugosci.                                              
    Inkrementuje liczbe wszystkich i aktualnie znajdujacych sie w programie obiektow typu Vector<Size>.
    \return Tablice wypelniona wartoscia 0.                                       
*/

template <unsigned int Size>
Vector<Size>::Vector(){
    for (unsigned int i = 0; i < Size; ++i){
        size[i] = 0;
    }
    ++counter_all_vectors;
    ++counter_actual_vectors;
}

/*!
    Konstruktor kopiujacy.   

    \param [in] Ob - wektor do skopiowania. 

    \return Kopie wektora przekazanego poprzez wskaznik.                                                         
*/

template <unsigned int Size>
Vector<Size>::Vector(const Vector<Size> & Ob){
    *this = Ob;
    Ob.counter_all_vectors++;
    Ob.counter_actual_vectors++;
}

/*!
    Konstruktor wieloparametryczny klasy Vector tworzacy wektor o zadanej dlugosci wypelniony warosciami pochodzacymi z parametru - tablicy wartosci typu double.                                                 
    Inkrementuje liczbe wszystkich i aktualnie znajdujacych sie w programie obiektow typu Vector<Size>.
    \param [in] tmp - Jednowymiarowa tablica typu double.                             
                                                             
    \return  Tablice wypelniona wartosciami podanymi w argumencie.                 
*/

template <unsigned int Size>
Vector<Size>::Vector(double tmp[Size]){
    for (unsigned int i = 0; i < Size; ++i){
        size[i] = tmp[i];
    }
   ++counter_all_vectors;
   ++counter_actual_vectors; 
}

/*!
    Destruktor klasy Vector, dekrementuje liczbe aktualnie znajdujacych sie w programie obiektow typu Vector<Size>.
*/

template <unsigned int Size>
Vector<Size>::~Vector(){
    --counter_actual_vectors;
}



/*!
    \return Liczbe (typu int) aktualnie znajdujacych sie w programie obiektow klasy Vector<Size>.
*/

template <unsigned int Size>
int Vector<Size>::get_counter_actual_vectors(){
    return counter_actual_vectors;
}    

/*!
    \return Liczbe (typu int) wszystkich obiektow klasy Vector<Size>, ktore powstaly w trakcie jego dzialania.
*/

template <unsigned int Size>
int Vector<Size>::get_counter_all_vectors(){
     return counter_all_vectors;
}

/*!
    \param [in] Ob - wektor ktory zostanie przypsiany.

    \return wektor o wartosciach identycznych do tego, ktory zostal przekazany jako parametr. 
*/

template <unsigned int Size>
Vector<Size> & Vector<Size>::operator = (const Vector<Size> & Ob){
    for(unsigned int i = 0; i < Size; ++i)
        size[i] = Ob.size[i];
    return *this;
}


/*!
    Realizuje dodawanie dwoch wektorow.                                       
                                                                  
    \param [in] this - pierwszy skladnik dodawania,                                   
    \param [in] v - drugi skladnik dodawania.                                         

    \return Sume dwoch skladnikow przekazanych jako wskaznik na parametr.                                                          
*/

template <unsigned int Size>
Vector<Size>  Vector<Size>::operator + (const Vector<Size> &v){
    Vector result;
    for (unsigned int i = 0; i < Size; ++i){
        result[i] = size[i] + v[i];
    }
    return result;
    ++counter_all_vectors;
    ++counter_actual_vectors;
}

/*!
    Realizuje odejmowanie dwoch wektorow.                                     
                                                                  
    \param [in] this - pierwszy skladnik odejmowania,                                 
    \param [in] v - drugi skladnik odejmowania.                                       
                                                               
    \return Roznice dwoch skladnikow przekazanych jako wskaznik na parametr.                                                          
*/

template <unsigned int Size>
Vector<Size> Vector<Size>::operator - (const Vector<Size> &v){
    Vector result;
    for (unsigned int i = 0; i < Size; ++i){
        result[i] = size[i] - v[i];
    }
    return result; 
}

/*!
    Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               
                                                                   
    \param [in] this - pierwszy skladnik mnozenia (wektor),                           
    \param [in] v - drugi skladnik mnozenia (liczba typu double).                     
                                                                   
    \return Iloczyn dwoch skladnikow przekazanych jako wskaznik na parametr.                                                          
*/

template <unsigned int Size>
Vector<Size> Vector<Size>::operator * (const double &tmp){
    Vector result;
    for (unsigned int i = 0; i < Size; ++i){
        result[i] = size[i] * tmp;
    }
    return result;
}

/*!
    Realizuje zwielokrotnienie wartosci pol wektora przez odpowaidajace pola drugiego wektora.               
                                                                   
    \param [in] this - pierwszy skladnik zwielokrotnienia (wektor),                           
    \param [in] v - drugi skladnik zwielokrotnienia (wektor).                     
                                                                   
    \return Wektor poczatkowy zwielokrotniony o wartosici drugiego wektora.                                                          
 */

template <unsigned int Size>
Vector<Size> Vector<Size>::operator * (const Vector<Size> &v){
    Vector result;
    for (unsigned int i = 0; i < Size; ++i){
        result[i] = size[i] * v[i];
    }
    return result;
}

/*!
    Realizuje dzielenie wektora przez skalar.                                       
                                                                 
    \param [in] this - licznik dzielenia,                                             
    \param [in] v - mianownik dzielenia.                                              
                                                                    
    \return Iloraz dwoch skladnikow przekazanych jako wskaznik na parametr.                                                          
*/

template <unsigned int Size>
Vector<Size> Vector<Size>::operator / (const double &tmp){
    Vector result;
    if (tmp == 0)
        throw std::runtime_error("Wykonano dzielenie przez 0");
    for (unsigned int i = 0; i < Size; ++i){
        result[i] = size[i] / tmp;
    }
    return result;
}

/*!
    Funktor wektora.                                                          
                                                                   
    \param [in] index - index wektora.                                                
                                                                   
    \return Wartosc wektora w danym miejscu tablicy jako stala.                   
*/

template <unsigned int Size>
const double & Vector<Size>::operator [] (unsigned int index) const{
    if (index >= Size)
        throw std::runtime_error("Bledna wartosc indeksu wektora");
    return size[index];
}

/*!
    Funktor wektora.                                                          
                                                                  
    \param [in] index - index wektora.                                                
                                                                     
    \return Wartosc wektora w danym miejscu tablicy.                              
 */
template <unsigned int Size>
double & Vector<Size>::operator[](unsigned int index){
    if (index >= Size)
        throw std::runtime_error("Bledna wartosc indeksu wektora");
    return const_cast <double &> (const_cast <const Vector *> (this)->operator[](index));
}

/*!
    Funkcja wykonujaca operacje przeciazenia operatora <<. Funkcja sluzy do wypisywania na wskazany strumien wyjsciowy, wartosci wektora.                                                      

    \param [in] out - strumien wejsciowy,                                             
    \param [in] tmp - wektor.   

    \return Wypisane wartosci wskazanego wektora, w odpowiedniej formie na wskazane wyjscie.                                                        
 */
template <unsigned int Size>
std::ostream & operator << (std::ostream &out, Vector<Size> const &tmp){
    for (unsigned int i = 0; i < Size; ++i) {
        out << std::fixed << std::setprecision(10) << tmp[i]<< "\t";
    }
    return out;
}

/*!
    Funkcja wykonujaca operacje przeciazenia operatora >>. Funkcja sluzy do wprowadzania wartosci wektora ze wskazanego strumienia wejsciowego.                                                  
                                                             
    \param [in]    in - strumien wyjsciowy,                                              
    \param [in]    tmp - wektor.    

    \return Wczytany obiekt- wektor.                                                      
 */

template <unsigned int Size>
std::istream & operator >> (std::istream &in, Vector<Size> &tmp){
    for (unsigned int i = 0; i < Size; ++i){
        in >> tmp[i];
    }
    if (in.fail())
        throw std::runtime_error("Podano wartosc nie bedaca typu double ");
    std::cout << std::endl;
    return in;
}

/*!
    Pozwala wyznaczyc dlugosci pomiedzy wekorami.

    \param [in] vec1 - wektor poczatkowy.
    \param [in] vec2 - wektor koncowy.

    \return odleglosc pomiedzy wektorami w postaci liczby typu double.
*/ 

template <unsigned int Size>
double vector_length(Vector<Size> const & vec1, Vector<Size> const & vec2){
    double temp=0;
    for (unsigned int i = 0; i < Size; ++i)
        temp += pow(vec2[i] - vec1[i],2);
    return sqrt(temp);
}
