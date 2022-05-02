#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <fstream>
#include <limits>

#ifdef __GNUG__
#pragma implementation
#endif

#include "lacze_do_gnuplota.hh"

using namespace std;

/*!
 * \file lacze_do_gnuplota.cpp
 *
 *  Ostatnia modyfikacja: 2020.06.07
 */


#define DOMYSLNA_SZEROKOSC        1
#define DOMYSLNY_KOLOR            1
#define DOMYSLNY_STYL             7

#define STDIN        0
#define STDOUT       1

namespace PzG {


 std::list<InfoPlikuDoRysowania>  LaczeDoGNUPlota::_InfoPlikow_Glb;



 //============================================================================
 //_____________________ InfoPlikuDoRysowania _________________________________

 /*!
  * Inicjalizuje obiekt.
  *  \param[in] NazwaPliku - nazwa pliku, z którego pobierane będą dane,
  *  \param[in] SposobRys    - rodzaj rysowanych obiektów (linia lub punkty),
  *  \param[in] Szerokosc  - szerokosc linii lub wielkość punktu w zależności
  *                      od rodzaju rysowania.
  *  \param[in] Kolor      - numer koloru jakim ma być rysowny dany element
  *                      graficzny.
  *  \param[in] Styl       - styl rysowania, np. linia ciągła lub przerywana.
  */
 InfoPlikuDoRysowania::InfoPlikuDoRysowania( const char*      NazwaPliku, 
                                             TypSposobuRysowania  SposobRys, 
                                             int              Szerokosc,
                                             int              Kolor,
                                             int              Styl
                                           )
  {
     _NazwaPliku = NazwaPliku;
     _SposobRys = SposobRys;
     _Szerokosc = Szerokosc;    
     _Kolor = Kolor;
     _Styl = Styl;
  }

 //_____________________ InfoPlikuDoRysowania _________________________________
 //============================================================================




 //============================================================================
 //_____________________ LaczeDoGNUPlota ______________________________________




 /*!
  * Odszukuje strukturę zawierającą nazwę pliku, w którym powinny być zapisane
  * współrzędne punktów do rysunku odpowiedniej łamanej lub powierzchni (w zależności 
  * od wcześniejszego wyboru trybu rysowania - patrz metoda
  * \link LaczeDoGNUPlota::ZmienTrybRys ZmienTrybRys()\endlink).
  * \param[in] sNazwaPliku - nazwa pliku, dla którego ma zostać odnaleziony obiekt
  *               zawierające dane określające sposób rysowania łamanej lub powierzchni.
  * \param[in] Dostep - decyduje o tym, czy dany plik będzie szukany wsród plików,
  *                które mają być \e widziane przez wszystkie instancje programu gnuplot,
  *                czy też pośród tych, które są widoczne tylko przez tą instancję, dla
  *                której wywołana zostaje ta metoda. Domyślnie przyjmuje się ten drugi
  *                wariant.
  *
  * \return Jeżeli w liście nazw plików z danymi dla gnuplota zostanie znaleziony
  *         obiekt, który zawiera identyczną nazwę, jak ta przekazana przez parametr
  *         \e  sNazwaPliku, to metoda zwraca wskaźnik do tego obiektu. Jest on zwracany
  *         w trybie tylko do odczytu. W przypadku przecinym zwracany jest 
  *         wskaźnik \p nullptr.
  */
 const InfoPlikuDoRysowania* LaczeDoGNUPlota::ZnajdzNazwePliku(
						    const char                 *sNazwaPliku,
                                                    TypDostepuDoZasobu          Dostep
						 ) const
 {
   const std::list<InfoPlikuDoRysowania>  &_ListaPlikow =
                     (Dostep == DZ_Globalny) ? _InfoPlikow_Glb : _InfoPlikow_Lok;
   for ( const InfoPlikuDoRysowania  &InfoPliku :  _ListaPlikow) {
     if ( InfoPliku.WezNazwePliku() == sNazwaPliku) return &InfoPliku;
   }
   return nullptr;
 }




  
 /*!
  * Usuwa nazwę pliku wraz z informacjami dotyczącymi sposobu rysowania.
  * Nazwa ta jest usuwana, w zależności od wartości drugiego parametru,
  * z listy plików, które \e widziane są tylko przez daną instancję łącza
  * do gnuplota (wartość parametru \p DZ_Lokalny - domyślna) lub z listy plików, 
  * które \e widziane są przez wszystkie instancje łącza (wartość parametru \p DZ_Globalny).
  * \param[in]  wInfoPliku - wskaźnik na obiekt zawierający nazwę pliku i informacje
  *                   dotyczące sposobu rysowania.
  * \param[in]  Dostep - decyduje o tym, czy dany plik będzie szukany i usunięty
  *                z listy plików \e widzianych przez daną instancję łącza do gnuplota
  *                lub będzie szukany i usunięty z listy plików \e widzianych przez 
  *                wszystkie instancje łącza do gnuplota.
  * \retval true - gdy operacja powiodła się,
  * \retval false - w przypadku przeciwnym.
  */
  bool LaczeDoGNUPlota::UsunNazwePliku(  const InfoPlikuDoRysowania*  wInfoPliku,
                                         TypDostepuDoZasobu           Dostep
				      )
 {
   return UsunNazwePliku(wInfoPliku->WezNazwePliku(),Dostep);
 }



 /*!
  * Usuwa nazwę pliku wraz z informacjami dotyczącymi sposobu rysowania.
  * Nazwa ta jest usuwana, w zależności od wartości drugiego parametru,
  * z listy plików, które \e widziane są tylko przez daną instancję łącza
  * do gnuplota (wartość parametru \p DZ_Lokalny - domyślna) lub z listy plików, 
  * które \e widziane są przez wszystkie instancje łącza (wartość parametru \p DZ_Globalny).
  * \param[in]  sNazwaPliku - wskaźnik na nazwę pliku, którego nazwa wraz z informacjami
  *                   dotyczące sposobu rysowania ma zostać usunięta.
  * \param[in]  Dostep - decyduje o tym, czy dany plik będzie szukany i usunięty
  *                z listy plików \e widzianych przez daną instancję łącza do gnuplota
  *                lub będzie szukany i usunięty z listy plików \e widzianych przez 
  *                wszystkie instancje łącza do gnuplota.
  * \retval true - gdy operacja powiodła się,
  * \retval false - w przypadku przeciwnym.
  */
  bool LaczeDoGNUPlota::UsunNazwePliku(
		       const char          *sNazwaPliku,
		       TypDostepuDoZasobu   Dostep
		     )
  {
    return UsunNazwePliku(std::string(sNazwaPliku),Dostep);
  }

  

 /*!
  * Usuwa nazwę pliku wraz z informacjami dotyczącymi sposobu rysowania.
  * Nazwa ta jest usuwana, w zależności od wartości drugiego parametru,
  * z listy plików, które \e widziane są tylko przez daną instancję łącza
  * do gnuplota (wartość parametru \p DZ_Lokalny - domyślna) lub z listy plików, 
  * które \e widziane są przez wszystkie instancje łącza (wartość parametru \p DZ_Globalny).
  * \param[in]  NazwaPliku - nazwa pliku, która wraz z informacjami
  *                   dotyczące sposobu rysowania ma zostać usunięta.
  * \param[in]  Dostep - decyduje o tym, czy dany plik będzie szukany i usunięty
  *                z listy plików \e widzianych przez daną instancję łącza do gnuplota
  *                lub będzie szukany i usunięty z listy plików \e widzianych przez 
  *                wszystkie instancje łącza do gnuplota.
  * \retval true - gdy operacja powiodła się,
  * \retval false - w przypadku przeciwnym.
  */
  bool LaczeDoGNUPlota::UsunNazwePliku( const std::string     &NazwaPliku,
                                        TypDostepuDoZasobu     Dostep
				      )
 {
   unsigned int IloscUsunietych = 0;
   
   /*!
    * \brief Ma znaczenie pomocnicze, zdefiniowana została na potrzeby
    *        operacji usuwania plików.
    */
   class TakaSamaNazwa {
      /*!
       * \brief Ilość usuniętych elmentów
       *
       * Przechowuje ilość usuniętych elmentów. Jeśli wszystko jest dobrze
       * wartość tego pola powinna być równa 1.
       */
       unsigned int *_wIloscUsunietych;
       string       _NazwaPliku;
    public:
      TakaSamaNazwa(const string &NazwaPliku, unsigned int *wIloscUsunietych):
                      _wIloscUsunietych(wIloscUsunietych),  _NazwaPliku(NazwaPliku) {}
      unsigned int WezIlosc() const { return *_wIloscUsunietych; }
      bool operator () (const InfoPlikuDoRysowania& InfoPliku) const
       { return (InfoPliku.WezNazwePliku() == _NazwaPliku) ? (++*_wIloscUsunietych, true) : false; }
   };


   
   TakaSamaNazwa  WarunekUsuniecia(NazwaPliku,&IloscUsunietych);
   switch (Dostep) {
    case DZ_Globalny: _InfoPlikow_Glb.remove_if(WarunekUsuniecia);  break;
    case DZ_Lokalny:  _InfoPlikow_Lok.remove_if(WarunekUsuniecia);  break;
   }
   if (WarunekUsuniecia.WezIlosc() > 1) {
     cerr << " Ostrzezenie:" << endl
	  << " !!!  Ilosc elementow o tej samej nazwie jest wieksza niz 1." << endl
	  << " !!!  Dodawana nazwa pliku powinna zawsze byc unikalna." << endl
	  << " !!!  Jesli tak nie jest, nie powoduje to bledu, jednak operacja" << endl
	  << " !!!  rysowania jest wykonywana nadmiarowo." << endl;
   }
   return WarunekUsuniecia.WezIlosc() > 0;
 }





  
  
 void LaczeDoGNUPlota::WyswietlajKomunikatyBledow( bool  WyswietlajKomunikaty )
 {
  _WyswietlajKomunikatyOBledach =  WyswietlajKomunikaty;
 }


  LaczeDoGNUPlota::~LaczeDoGNUPlota() 
  {}


 bool LaczeDoGNUPlota::PrzeslijDoGNUPlota(const char *Komunikat)
 {
  int Ilosc = strlen(Komunikat);
  int IloscPrzeslanych;
  
  while (((IloscPrzeslanych = write(_Wejscie_GNUPlota,Komunikat,Ilosc)) != -1)
          && Ilosc > 0) {
    Komunikat += IloscPrzeslanych;
    Ilosc -= IloscPrzeslanych;
  }
  if (Ilosc > 0) {
    KomunikatBledu("!!! Przeslanie polecenia do GNUPlota nie powiodlo sie.");
    return false;
  }
  return true;
 }




 LaczeDoGNUPlota::LaczeDoGNUPlota() 
 { 
   _PokazOs_OX = _PokazOs_OY = true;

   _TrybRys = TR_2D;
   WyswietlajKomunikatyBledow();
   _Wyjscie_GNUPlota = _Wejscie_GNUPlota = -1; 
   UstawZakresX(-350,350);
   UstawZakresY(-350,350);
   UstawZakresZ(-200,200);
   UstawRotacjeXZ(60,30);
   UstawSkaleXZ(1,1);
 }



/*!
 * \brief Funkcja pomocnicza, sprawdza czy plik o podanej nazwie jest na dysku.
 *
 * Funkcja pomocnicza, sprawdza czy plik o podanej nazwie jest na dysku
 * i może być otwarty od odczytu.
 * \param[in] sNazwaPliku - nazwa pliku, którego istnienie ma być sprawdzone.
 * \retval true - plik istnieje na dysku i może być otwarty do odczytu.
 * \retval false - w przypadku przeciwnym.
 */
 bool CzyJestPlik(char const *sNazwaPliku)
 {
  struct stat buf;

  if (stat(sNazwaPliku,&buf)) return false;
  if (!(S_ISREG(buf.st_mode))) return false;
  if (!(buf.st_mode & S_IRUSR)) return false;
  return true;
 }




 //-------------------------------------------------------------------------
 // Powoduje dodanie do listy plikow zawierajacych dane dla gnuplota,
 // nowej nazwy pliku.
 //
 // PRE:  NazwaPliku  - nazwa pliku z danymi dla gnuplota.
 // POST:
 //  Zwraca wartosc:
 //     true - jezeli istnieje plik o nazwie zawartej w zmiennej NazwaPliku.
 //             Zostaje on ponadto dodany do listy plikow z danymi 
 //             dla gnuplota.
 //    fasle - Jezeli nie istnieje plik o nazwie zawartej w zmiennej
 //            NazwaPliku. Zadne dodatkowe dzialanie nie jest realizowane.
 //
/*
 bool LaczeDoGNUPlota::DodajNazwePliku( const char      * NazwaPliku,
                                        TypSposobRysoowania   SposobRys,
                                        int               Szerokosc
                                      )
 {
  bool rezultat = true;

  if (!CzyJestPlik(NazwaPliku)) {
    string Komunikat = "!!! Ostrzezenie: Brak pliku ";
    Komunikat += NazwaPliku;
    //TMP    KomunikatBledu(Komunikat.c_str());
    rezultat = false;
  }

  _InfoPlikow.push_back(InfoPlikuDoRysowania(NazwaPliku,SposobRys,Szerokosc));
  return rezultat;
 }
*/

 InfoPlikuDoRysowania&  LaczeDoGNUPlota::DodajNazwePliku(
                                    const char         *NazwaPliku,
                                    bool                SprawdzIstnienie,
                                    TypDostepuDoZasobu  Dostep
                                  )
 {
  if (SprawdzIstnienie && !CzyJestPlik(NazwaPliku)) {
    cerr << "!!! Ostrzezenie: Brak pliku " << NazwaPliku << endl;
  }

  InfoPlikuDoRysowania Info(NazwaPliku,SR_Ciagly,DOMYSLNA_SZEROKOSC);

  if (Dostep == DZ_Globalny) {  
    _InfoPlikow_Glb.push_back(Info);
    return  _InfoPlikow_Glb.back();
  }
  _InfoPlikow_Lok.push_back(Info);
  return _InfoPlikow_Lok.back();;
 }



/*!
 *
 */
 InfoPlikuDoRysowania& LaczeDoGNUPlota::DodajNazwePliku_PunktyRoznejWielkosci(
                                               const char         *NazwaPliku,
                                               bool                SprawdzIstnienie,
                                               TypDostepuDoZasobu  Dostep
                                            )
 {
  if (SprawdzIstnienie && !CzyJestPlik(NazwaPliku)) {
    cerr << "!!! Ostrzezenie: Brak pliku: " << NazwaPliku << endl;
  }

  InfoPlikuDoRysowania Info(NazwaPliku,SR_PunktowyNiejednorodny,
                                       DOMYSLNA_SZEROKOSC,
                                       DOMYSLNY_KOLOR,
	                               DOMYSLNY_STYL);
  if (Dostep == DZ_Globalny) {  
    _InfoPlikow_Glb.push_back(Info);
    return  _InfoPlikow_Glb.back();
  }
  _InfoPlikow_Lok.push_back(Info);
  return _InfoPlikow_Lok.back();;
 }



/*!
 *
 */
 InfoPlikuDoRysowania& LaczeDoGNUPlota::DodajNazwePliku_Lamana(
                                          const char         *NazwaPliku,
                                          bool                SprawdzIstnienie,
                                          TypDostepuDoZasobu  Dostep
                                         )
 {
     return DodajNazwePliku(NazwaPliku,SprawdzIstnienie,Dostep)
            .ZmienSposobRys(SR_Ciagly);
 }



/*!
 *
 */
 InfoPlikuDoRysowania& LaczeDoGNUPlota::DodajNazwePliku_JednakowePunkty(
                                            const char         *NazwaPliku,
                                            bool                SprawdzIstnienie,
                                            TypDostepuDoZasobu  Dostep
                                           )
 {
   return DodajNazwePliku(NazwaPliku,SprawdzIstnienie,Dostep)
            .ZmienSposobRys(SR_Punktowy);
 }


 //-------------------------------------------------------------------------
 // Informuje, czy połączenie z programem gnuplot zostało zainicjowane.
 // 
 bool LaczeDoGNUPlota::CzyPolaczenieJestZainicjowane() const
 {
  return _Wejscie_GNUPlota > -1 && _Wyjscie_GNUPlota > -1;
 }


 void LaczeDoGNUPlota::KomunikatBledu(const char *Komunikat) const
 {
  if (!CzyWyswietlacKomunikaty()) return;
  cerr << Komunikat << endl;
 }


#define ROZ_LINII   120



 bool LaczeDoGNUPlota::Inicjalizuj()
 {
  if (CzyPolaczenieJestZainicjowane()) return true;
  if (!UtworzProcesPotomny()) return false;

  return PrzeslijDoGNUPlota("\n");
 }


/*!
 *  Inicjalizuje połączenie z programem \e gnuplot. Realizowane jest to
 *  poprzez rozwidlenie procesu i uruchomienie jako procesu potomnego
 *  programu \e gnuplot. Komunikacja z programem \e gnuplot realizowana jest
 *  poprzez przejęcie jego wejścia i wyjścia standardowego.
 *
 *  \retval true - gdy połączenie z programem \e gnuplot zostało poprawnie
 *               zainicjalizowane lub gdy już wcześniej było 
 *               zainicjalizowane.
 *  \retval false - gdy proces inicjalizacji połączenia zakończył się
 *               niepowodzeniem.
 */
 bool LaczeDoGNUPlota::UtworzProcesPotomny()
 {
  int indesk[2],outdesk[2];

  if (pipe(indesk) == -1 || pipe(outdesk) == -1) {
    KomunikatBledu(
      "### Niemozliwe utworzenie kanalow komunikacyjnych do podprocesow.");
    exit(1);
  }

  switch (fork()) {
    case -1: KomunikatBledu("### Niemozliwe rozwidlenie procesu.");
             exit(1);
    case  0: 
       /* Start potomka */

       if (close(STDIN) == -1) { 
         KomunikatBledu("### Blad przy zamykaniu strumienia wejsciowego.");
         exit(1);
       }
       if (dup(outdesk[STDIN]) == -1) {
         KomunikatBledu("### Blad duplikacji kanalu wejsciowego.");  
         exit(1);
       }
       
       if (close(STDOUT) == -1) { 
         KomunikatBledu(
            "### Blad zamkniecia kanalu standardowego kanalu wyjsciowego."); 
         exit(1);
       }
       if (dup(indesk[STDOUT]) == -1) {
         KomunikatBledu("### Blad duplikacji kanalu wyjsciowego.");  
         exit(1);
       }       
       if (close(outdesk[STDIN]) == -1) {
         KomunikatBledu("### Blad zamkniecia kanalu wejsciowego.");
         exit(1);
       }
       if (close(outdesk[STDOUT]) == -1) {
         KomunikatBledu("### Blad zamkniecia kanalu wyjsciowego.");
         exit(1);
       }
       if (close(indesk[STDIN]) == -1) {
         KomunikatBledu("### Blad zamkniecia duplikatu kanalu wejsciowego.");
         exit(1);
       }
       if (close(indesk[STDOUT]) == -1) {
         KomunikatBledu("### Blad zamkniecia duplikatu kanalu wyjsciowego.");
         exit(1);
       }
       char Tab[3];
       read(STDIN,Tab,1);
       write(STDOUT,"\n",1); 
       const char *Comm;

       execlp(Comm = "gnuplot","gnuplot",NULL);

       KomunikatBledu("!!! Blad:"); 
       KomunikatBledu("!!! W procesie potomnym nie mogl zostac."); 
       KomunikatBledu("!!! uruchomiony program gnuplot."); 
       KomunikatBledu("!!! Nastapilo przerwanie dzialania procesu potomnego."); 
       KomunikatBledu("!!! Jednym z mozliwych powodow problemu moze byc"); 
       KomunikatBledu("!!! Brak programu gnuplot w szukanej sciezce."); 
       KomunikatBledu("!!! Do uruchomienia programu gnuplot bylo uzyte polecenie:");
       KomunikatBledu(Comm);
       exit(1);

    default:
       if (close(outdesk[STDIN]) == -1 || close(indesk[STDOUT]) == -1) { 
         KomunikatBledu(" Blad zamkniecia outpipe[STDIN], inpipe[STDOUT]."); 
       }

       fcntl(indesk[STDIN],F_SETFL,O_NDELAY);
       _Wyjscie_GNUPlota  = indesk[STDIN];
       _Wejscie_GNUPlota =  outdesk[STDOUT];
  }
  return true;
 }




 bool LaczeDoGNUPlota::RysujDoPliku(const char *NazwaPliku)
 {
  if (!CzyPolaczenieJestZainicjowane()) {
    if (!Inicjalizuj()) return false;
  }
  string Polecenie = "\n\n\nset output '";
  Polecenie += NazwaPliku;
  Polecenie += "\n set term png\n";
  if (!PrzeslijDoGNUPlota(Polecenie.c_str())) {
    KomunikatBledu("!!! Rysunek nie moze byc utworzony.");
    return false;
  }

  bool Wynik = Rysuj();
  if (!PrzeslijDoGNUPlota("\n\n\nset output \nset term x11\n")) {
    KomunikatBledu("!!! Wyjscie dla gnuplot'a nie zostalo poprawnie\n"
                   "!!! przestawione na STDOUT.\n");
    return false;
  }
  return Wynik;
 }








  
 /*!
  * \brief Funkcja pomocnicza, dopisuje do polecenia wpisy związane z rysowaniem z pliku.
  *
  * Funkcja pomocnicza, dopisuje do polecenia wpisy związane z rysowaniem z pliku.
  * \param[in,out] IterNazw - iterator listy nazw plików, od miejsca wkazywanego przez
  *                           iterator rozpoczyna się dopisywanie wpisów rysowania
  *                           z wykorzystaniem danych zawartych w plikach.
  * \param[in]     IterKonca - itrator końca, który wyznacza miejsce zakończenia dopisywania
  *                           wpisów rysowania z plików.
  * \param[in,out] Polecenie - zawartość polecenia dla gnuplota, do którego dopisywane są
  *                           wpisy rysowania z poszczególnych plików.
  * \param[in,out] wwSep     - pośredni wskaźnik na separator wpisów. Po dodaniu pierwszego
  *                           wpisu separator jest zmieniany na ciąg ", ".
  * \retval true - operacja powiodła się,
  * \retval false - w przypadku przeciwnym.
  */
 bool DopiszRysowanieZPlikow( list<InfoPlikuDoRysowania>::const_iterator        &IterNazw,
                              const list<InfoPlikuDoRysowania>::const_iterator  &IterKonca,
                              std::string                                 &Polecenie, 
                              char const                                **wwSep 
                            )
 {
  bool           Res = false;
  ostringstream  TStrmWy;

  for (; IterNazw != IterKonca; ++IterNazw ) {
       if (IterNazw->WezSposobRys() == SR_PunktowyNiejednorodny) continue;

       Polecenie += *wwSep;
       Polecenie += " \'";
       Polecenie += IterNazw->WezNazwePliku();
       (Polecenie += '\'') += " notitle ";

       TStrmWy.str("");
       switch (IterNazw->WezSposobRys()) {
        case SR_Ciagly:
	   TStrmWy << "w l " << " lt " << IterNazw->WezStyl()
                   << " lw " << IterNazw->WezSzerokosc()
	           << " lc " << IterNazw->WezKolor();
           break;

        case SR_Punktowy:
	   TStrmWy << "w p " << " pt " << IterNazw->WezStyl()
                   << " ps " << IterNazw->WezSzerokosc()
	           << " lc " << IterNazw->WezKolor();
	   break;

	case SR_PunktowyNiejednorodny:
	   break;
       }
/*
       (IterNazw->WezSposobRys() == SR_Ciagly ? " w l" : " w p pt 5");
       if  (IterNazw->WezSposobRys() == SR_Ciagly) 
                                OSStrm << " lw " << IterNazw->WezSzerokosc();
                           else OSStrm << " ps " << IterNazw->WezSzerokosc();
*/
       Polecenie += TStrmWy.str();
       *wwSep = ", ";
       Res = true;
  }
  return Res;
 }


/*!
 * Tworzy napis będący parametrami dla polecenie \e plot programu,
 * \e gnuplot. Parametry te pozwalają na rysowanie brył, których
 *  współrzędne wierzchołków zawarte są w plikach.
 *  Nazwy tych plików muszą być wcześniej dołączone do kolejki 
 *  plików poprzez zastosowanie polecenia
 *   \link LaczeDoGNUPlota::DodajNazwePliku DodajNazwePliku()\endlink.
 *  
 * \param[in,out] Polecenie - dopisywana jest do niego sekwencja znaków
 *                  tworzących parametry dla polecenia \e plot.
 * \param[in,out] wwSep - zawiera znak separatora między poszczególnymi
 *              parametrami. Jeżeli parametry listy nazw plików
 *              są generowane jako pierwsze, to zmienna ta musi 
 *              być wskaźnikiem do wskaźnika na łańcuch: " ".
 * \retval true - jeśli lista nazw plików nie jest pusta.
 * \retval false - w przypadku przeciwnym.
 * \post Jeżeli  lista nazw plików nie jest pusta, to poprzez
 *              parametr \e Sep zostaje udostępniony łańcuch: ", ".
 */
 bool LaczeDoGNUPlota::DopiszRysowanieZPlikow( std::string   &Polecenie, 
                                                char const  **wwSep 
                                             )
 {
  list<InfoPlikuDoRysowania>::const_iterator IterNazw  = _InfoPlikow_Glb.begin();
  list<InfoPlikuDoRysowania>::const_iterator IterKonca = _InfoPlikow_Glb.end();
  bool Res = true;

  if (!_InfoPlikow_Glb.empty()) {
    Res = PzG::DopiszRysowanieZPlikow(IterNazw,IterKonca,Polecenie,wwSep);
  }

  if (_InfoPlikow_Lok.empty()) return Res;

  IterNazw  = _InfoPlikow_Lok.begin();
  IterKonca = _InfoPlikow_Lok.end();
  return  PzG::DopiszRysowanieZPlikow(IterNazw,IterKonca,Polecenie,wwSep) || Res;
 }



/*!
 * \brief Modeluje zestaw informacji będący atrybutami rysowania
 *
 * 
 */
 class AtrybutyRysowania {
   /*!
    * \brief Identyfikuje kolor rysowania
    *
    * Przechowuje wartość, która identyfikuje kolor rysowania.
    */
    int  _Kolor;
   /*!
    * \brief Określa rozmiar elementu graficznego
    *
    * Przechowuje wartość, która determinuje rozmiar rysowanego obiektu
    * graficznego, np. punktu.
    */
    int  _Rozmiar;
    /*!
     * \brief Styl rysowanego elementu
     *
     *  Przechowuje informację o typie rysowanego punktu.
     *  Jeśli rysowana jest linia, to wartość ta określa typ rysowanej
     *  linii (ciągła, kreskowana, kropkowana itd.). Jeśli rysowane
     *  są obiekty punktowe, to określa ona typ rysowanego puntku (krzyżyk,
     *  kropka, kólko itd.).
     *
     * Informację o stylach rysowanych obiektów odpowiadających poszczególnym 
     * wartościom
     * można uzyskać poprzez wywołanie programu \e gnuplot, a następnie
     * wykonania polecenia \e test na poziomie interakcji z programem
     * \e gnuplot. Style rysowanych obiektów odpowiadające poszczególnym 
     * numerom są widoczne
     * po prawej stronie wyświetlonego okienka.
     */     
    int  _Styl;

  public:
    AtrybutyRysowania()
	 {  _Styl = _Rozmiar = _Kolor = 0; }

    /*!
     * \brief Porównuje wszystkie pola atrybutów
     *
     *  Porównuje dwa atrybuty względem wszystkich pól
     *  w następującej kolejności: rozmiar, kolor i styl.
     *  Przy sortowaniu pozwala to zgrupować obok siebie 
     *  te elementy, które mają takie same wartości pól.
     * \param[in] Atryb - obiekt, które pola 
     *                  \link AtrybutyRysowania::_Rozmiar _Rozmiar\endlink,
     *                  \link AtrybutyRysowania::_Kolor _Kolor\endlink
     *                  oraz mają \link AtrybutyRysowania::_Styl _Styl\endlink
     *                  mają zostać porównane z analogicznymi polami obiektu \p *this.
     * \retval true - jeśli dla któregoś z wykonywanych porównań w następującej kolejności:
     *           \link AtrybutyRysowania::_Rozmiar _Rozmiar\endlink,
     *           \link AtrybutyRysowania::_Kolor _Kolor\endlink,
     *           \link AtrybutyRysowania::_Styl _Styl\endlink; będzie prawdziwa relacja 
     *           mniejszości w sensie wartości liczbowych. Jeśli ta relacja nie zachodzi
     *           dla pierwszego pola, to dla drugiego uznaje się, że jest spełniona pod
     *           warunkiem, że dla wartości dwóch pierwszych pól są równe.
     * \retval false - w przypadku przeciwnym.
     */
    bool operator < (const AtrybutyRysowania& Atryb) const
     {  return _Rozmiar < Atryb._Rozmiar ? true :
                     _Kolor < Atryb._Kolor ? true :
	               _Styl < Atryb._Styl; 
     }
   /*!
    * \brief Porównuje wszystkie pola
    *
    * Porównuje wszystkie pola. Równość zachodzi wtedy, gdy
    * wartości wszystkich pól są takie same.
    * \param[in] Atryb - obiekt, z którym dokonane zostanie prównanie.
    * \retval true - wartości wszystkich atrybutów są równe.
    * \retval false - w przypadku przeciwnym.
    */
    bool operator == (const AtrybutyRysowania& Atryb) const
     {
        return  _Rozmiar == Atryb._Rozmiar &&
                  _Kolor == Atryb._Kolor   &&
                   _Styl == Atryb._Styl;
     }

    /*!
     * \brief Udostępnia styl rysowania
     *
     * Udostępnia wartość parametru określającego styl rysowania
     * danego elementu graficznego (tzn. linii lub punktu).
     * \return Przechowywana wartość definiująca styl rysowania.
     */
    int WezStyl() const { return _Styl; }
    /*!
     * \brief Udostępnia kolor rysowania
     *
     * Udostępnia wartość parametru określającego kolor rysowania
     * danego elementu graficznego (tzn. linii lub punktu).
     * \return Przechowywana wartość koloru.
     */
    int WezKolor() const { return _Kolor; }
    /*!
     * \brief Udostępnia rozmiar rysowania
     *
     * Udostępnia wartość parametru określającego rozmiar rysowanego
     * danego elementu graficznego. W przypadku linii jest to jej grubość,
     * zaś w przypdku punktu rozmiar okręgu.
     * \return Przechowywana wartość rozmiaru.
     */
    int WezRozmiar() const { return _Rozmiar; }

    /*!
     * \brief Zmienia styl rysowania
     *
     * Zmienia parametr determinujący styl rysowania obiektu
     * graficznego.
     * \param[in] Styl - wartość identyfikująca nowy styl rysowania.
     * \return Referencja do zmodyfikowanego obiektu \p *this.
     */
    AtrybutyRysowania& ZmienStyl(int Styl) { _Styl = Styl; return *this;}
    /*!
     * \brief Zmienia kolor rysowania
     *
     * Zmienia parametr determinujący kolor rysowania obiektu
     * graficznego.
     * \param[in] Kolor - nowa wartość określająca nowy kolor rysowania.
     * \return Referacja do zmodyfikowanego obiektu \p *this.
     */
    AtrybutyRysowania& ZmienKolor(int Kolor) { _Kolor = Kolor; return *this;}
    /*!
     * \brief Zmienia rozmiar rysowania
     *
     * Zmienia parametr determinujący rozmiar rysowania obiektu
     * graficznego.
     * \param[in] Rozmiar - nowa wartość dla rysowanych elementów graficznych, np. punktów.
     * \return Referacja do zmodyfikowanego obiektu \p *this.
     */
    AtrybutyRysowania& ZmienRozmiar(int Rozmiar) 
                                          { _Rozmiar = Rozmiar; return *this;}
 };


/*!
 * \brief Klasa pomocnicza, pozwala modelować wektor dwuwymiarowy
 *
 * Modeluje wektor dwuwymiarowy wraz z podstawymi operacjami.
 */
 class Wektor2f {
    public:
     /*!
      * \brief Współrzędna x-owa wektora
      *
      * Zawiera wartość współrzędnej x-owej wektora.
      */
      float  x;
     /*!
      * \brief Współrzędna y-owa wektora
      *
      * Zawiera wartość współrzędnej y-owej wektora.
      */   
      float  y;

     /*!
      * \brief Inicjalizuje współrzędne wektora wartościami 0
      *
      * Inicjalizuje współrzędne wektora wartościami 0.
      */
      Wektor2f(): x(0), y(0) {}
     /*!
      * \brief Inicjalizuje współrzędne wektora wartościami parametrów.
      *
      * Inicjalizuje współrzędne wektora wartościami parametrów.
      * \param[in] x - wartość, którą ma być zainicjalizowana współrzędna x-owa.
      * \param[in] y - wartość, którą ma być zainicjalizowana współrzędna y-owa.
      */   
      Wektor2f(float x, float y): x(x), y(y) {}
     /*!
      * \brief Dodanie i podstawienie do współrzędnych, wartości innego wektora
      *
      * Dodanie i podstawienie do współrzędnych, wartości innego wektora.
      * \param[in] Skl - wektor, które współrzędne mają zostać dodane, do 
      *                  wektora \p *this.
      * \return referencję do wektora \p *this, dla którego wywołana zostaje ta metoda. 
      */
      Wektor2f& operator += (const Wektor2f& Skl) 
                       { x += Skl.x;  y += Skl.y;  return *this; }

     /*!
      * \brief Dodanie do współrzędnych, wartości innego wektora
      *
      * Dodanie o współrzędnych, wartości innego wektora.
      * \param[in] Skl2 - drugi argument operacji dodawania, którego współrzędne mają zostać dodane,
      *                  do wektora \p *this.
      * \return wynik operacji dodawania, który jest sumą wektora \p *this i \e Skl2.
      */   
      Wektor2f  operator + (Wektor2f Skl2) const
                       { return Skl2 += *this; }

     /*!
      * \brief Mnożenie przez liczbę współrzędnych wektora i ich podstawienie
      *
      * Mnożenie przez liczbę współrzędnych wektora i ich podstawienie.
      * \param[in] Arg - liczba, przez którą mają być pomnożone współrzędne wektora, a
      *                  następnie podstawione w miejsce starych współrzędnych.
      * \return referencję do wektora \p *this, dla którego wywołana zostaje ta metoda. 
      */
      Wektor2f& operator *= (float Arg) 
                       { x *= Arg;  y *= Arg;  return *this; }

     /*!
      * \brief Mnożenie przez liczbę współrzędnych wektora
      *
      * Mnożenie przez liczbę współrzędnych wektora.
      * \param[in] Arg - liczba, przez którą mają być pomnożone współrzędne wektora.
      * \return wektora, który zawiera wynik wykonanej operacji.
      */   
      Wektor2f  operator * (float Arg) const 
                       { return Wektor2f(*this) *= Arg; }

     /*!
      * \brief Modyfikuje współrzędne wektora
      *
      * Modyfikuje współrzędne wektora.
      * \param[in] x - nowa wartość współrzędnej x-owej,
      * \param[in] y - nowa wartość współrzędnej y-owej.
      */
      void Zmien(float x, float y) {  Wektor2f::x = x;  Wektor2f::y = y; }
 };


/*!
 * \brief Wczytuje wartości współrzędnych
 *
 * Wczytuje wartości współrzędnych. Najpierw jest czytana współrzędna \e x,
 * a później \e y.
 * \param[in,out] StrmWe - strumień wejściowy, na którym ma być wykonana
 *                         dana operacja.
 * \param[out] Wspolrz - zawiera wczytane wartości współrzędnych, o ile
 *                       operacja czytania powiodła się.
 * \return Strumień \e StrmWe, który jest parametrem wejściowym.
 *         Jego stan jest zmieniony ze względu na wykonaną operację czytania.
 */
 istream& operator >> (istream& StrmWe, Wektor2f &Wspolrz)
 {
   return StrmWe >> Wspolrz.x >> Wspolrz.y;
 }


/*!
 * \brief Modeluje zestaw informacji o rysowanych punktach
 *
 * Klasa ma charakter pomocniczy i modeluje zestaw informacji
 * o punktach, które mają być rysowane. Informacje te określają
 * styl rysowania punktu, kolor oraz jego rozmiar, jak też
 * współrzędne tego punktu.
 */
 class InfoPunktyDoRysowania {
    /*!
     * \brief Atrybuty rysowania elementu graficznego
     *
     * Pole zawiera wartości parametrów determinujące sposób
     * rysowania danego elementu graficznego.
     */
    AtrybutyRysowania  _Atryb;
    /*!
     * \brief Współrzędne punktu
     *
     * Współrzędne punktu, który ma być rysowany.
     */
    Wektor2f      _Wspolrz;
    /*!
     * \brief Przechowuje etykietę punktu
     *
     * Przechowuje etykietę, która może być wyświetlona razem z danym
     * punktem.
     */
    string             _Etykieta;
    /*!
     * \brief Współrzędne etykiety
     *
     * Współrzędne etykiety.
     */
     Wektor2f           _WspolrzEtykiety;

     /*!
      * \brief Stałe przesunięcie etykiety wzgl. punktu
      *
      * Stałe przesunięcie etykiety względem współrzędnych punktu
      */
    static  Wektor2f   _PrzesEtykiety_WzgWspoPunktu;
     /*!
      * \brief Współczynnik przesunięcia etykiety
      *
      * Współczynnik przesunięcia względem rozmiaru punktu.
      */
    static  Wektor2f   _PrzesEtykiety_WzgRozmPunktu;

     /*!
      * \brief Wyznacza współrzędne położenia etykiety
      *
      * Wyznacza współrzędne położenia etykiety.
      * \return Wyznaczone współrzędne etykiety.
      */
    Wektor2f  WyznaczWspolrzEtykiety() const
     {
       return _PrzesEtykiety_WzgRozmPunktu * _Atryb.WezRozmiar() + 
              _PrzesEtykiety_WzgWspoPunktu + WezWspolrz();
     }

   public:
    /*!
     * \brief Inicjalizuje obiekt
     *
     *  Inicjalizuje obiekt determinując współrzędne rysowanego punktu,
     *  atrybuty jego rysowania, oraz treść etykiety.
     *  \param[in] Wspolrz - współrzędne rysowanego punktu,
     *  \param[in] Atryb - atrybuty rysowania,
     *  \param[in] sEtykieta - treść etykiety.
     */
     InfoPunktyDoRysowania( const Wektor2f           &Wspolrz, 
                            const AtrybutyRysowania  &Atryb,
                            const char*               sEtykieta
                          ):
	  _Atryb(Atryb), _Wspolrz(Wspolrz), _Etykieta(sEtykieta) 
       {
          UstawWspolrzEtykietyDlaPrzesuniecia(5,5);
       }

    /*!
     * \brief Wpisuje nowe współrzędne
     *
     * Wpisuje nowe współrzędne jako przesunięcie względem położenie puntku.
     * \param[in] x - nowa względna współrzędna x-owa etykiety,
     * \param[in] y - nowa względna współrzędna y-owa etykiety.
     */
     void UstawWspolrzEtykietyDlaPrzesuniecia(float x, float y)
       {
	  _WspolrzEtykiety = _Wspolrz;
          _WspolrzEtykiety.x += x;   _WspolrzEtykiety.y += y;
	  _WspolrzEtykiety = WyznaczWspolrzEtykiety(); 
       }
    /*!
     * \brief Udostępnia etykietę danego punktu
     *
     * Udostępnia etykietę danego punktu.
     * \return Referencja do etykiety w trybie tylko do odczytu.
     */
     const string& WezEtykiete() const { return _Etykieta; }
    /*!
     * \brief Udostępnia wspólrzędne etykiety
     *
     * Udostępnia wspólrzędne etykiety.
     * \return Referencja do współrzędnych etykiety w trybie tylko do odczytu.
     */
     const Wektor2f&  WezWspolrzEtykiety() const 
                                       {  return _WspolrzEtykiety; }
    /*!
     * \brief Porównuje tylko wg atrbutów
     *
     * Prównywane są tylko i wyłacznie same atrybuty.
     * \param[in] Info - obiekt, które pole \link InfoPunktyDoRysowania::_Atryb _Atryb\endlink
     *                   ma być prównane z analogicznym polem obiektu \p *this.
     * \return Wynik porównania zgodnie implementacją operatora '<' dla klasy
     *         AtrybutyRysowania.
     */
     bool operator < (const InfoPunktyDoRysowania& Info) const
                                 {  return _Atryb < Info._Atryb; }
    /*!
     * \brief Udostępnia atrybuty rysowania
     *
     * Udostępnia atrybuty rysowania danego elementu graficznego.
     * \return Referancja atrybutów rysowania w trybie tylko do odczytu
     */
    const AtrybutyRysowania& WezAtrybuty() const { return _Atryb; }
    /*!
     * \brief Udostępnia atrybuty do zmiany
     *
     * Udostępnia do zmiany atrybuty rysowania danego elementu
     * graficznego.
     * \return Referancja atrybutów rysowania pozwalająca na ich modyfikację.
     */
    AtrybutyRysowania& OtworzAtrybuty() { return _Atryb; }
    /*!
     * \brief Udostępnia współrzędne rysowania
     *
     * Udostępnia współrzędne rysowania danego elementu graficznego.
     * \return Referancja do współrzędnych punktu w trybie tylko do odczytu.
     */
    const Wektor2f& WezWspolrz() const { return _Wspolrz; }
    /*!
     * \brief Udostępnia współrzędne do zmiany
     *
     * Udostępnia do zmiany współrzędne rysowania danego elementu
     * graficznego.
     *
     * \return Referancja do współrzędnych punktu, które można modyfikować.
     */
    Wektor2f& OtworzWspolrz() { return _Wspolrz; }
    /*!
     * \brief Dopisuje do etykiety numer
     */
    void DodajDoEtykiety(int Num);
   /*!
    * \brief Zmienia współrzędne etykiety względem współrzędnych punktu.
    */
    InfoPunktyDoRysowania& ZmienPrzesEtykiety_WzgWspoPunktu( float   x,
                                                             float   y
                                                           );
   /*!
    * \brief  Zmienia współrzędne etykiety względem rozmiaru punktu.
    */
    InfoPunktyDoRysowania& ZmienPrzesEtykiety_WzgRozmPunktu( float   x,
                                                             float   y
                                                           );
 };




Wektor2f InfoPunktyDoRysowania::_PrzesEtykiety_WzgWspoPunktu(0.5,0.5);
Wektor2f InfoPunktyDoRysowania::_PrzesEtykiety_WzgRozmPunktu(0.26,0.26);


/*!
 * Zmienia współrzędne etykiety względem współrzędnych punktu.
 * \param[in] x - względna współrzędna x-owa etykiety,
 * \param[in] y - względna współrzędna y-owa etykiety.
 * \return Refencja do zmodyfikowanego obiektu \p *this.
 */
InfoPunktyDoRysowania& InfoPunktyDoRysowania::ZmienPrzesEtykiety_WzgWspoPunktu(
                                                           float   x,
                                                           float   y
                                                        )
{
  _PrzesEtykiety_WzgWspoPunktu.Zmien(x,y);   return *this;
}


/*!
 * Zmienia współrzędne etykiety względem rozmiaru punktu.
 * \param[in] x - względna współrzędna x-owa etykiety,
 * \param[in] y - względna współrzędna y-owa etykiety.
 * \return Refencja do zmodyfikowanego obiektu \p *this.
 */
InfoPunktyDoRysowania& InfoPunktyDoRysowania::ZmienPrzesEtykiety_WzgRozmPunktu(
                                                           float   x,
                                                           float   y
                                                        )
{
  _PrzesEtykiety_WzgRozmPunktu.Zmien(x,y);  return *this;
}




/*!
 * Dopisuje do etykiety numer.
 * \param[in] Num - liczba, która ma być dopisana do etykiety punktu.
 */
 void InfoPunktyDoRysowania::DodajDoEtykiety(int Num)
 {
   ostringstream   StrmWy;
   StrmWy << Num;
   _Etykieta += StrmWy.str();
 }



 /*!
  * \brief Skrócona nazwa typu listy punktów, które mają być rysowane
  *
  *  Jest to skrócona nazwa typu listy punktów, które mają być rysowane.
  */
 typedef list<InfoPunktyDoRysowania>  TypListaPunktow;


/*!
 * \brief Wczytuje z pliku listę punktów
 *
 *  Wczytuje z pliku listę punktów, które mogą się różnić rozmiarem.
 *  Dane w pliku zapisywane są w postaci tekstowej wg następującego schematu:
 \verbatim
     x_1  y_1  rozmiar_1
     x_2  y_2  rozmiar_2
      ...
     x_n  y_n  rozmiar_n
 \endverbatim
 * gdzie \e x_i, \e y_i, \e rozmiar_i to współrzędna \e x-owa, \e y-owa
 * oraz rozmiar \e i-tego punktu.
 * Dopuszczalne jest również wstawianie komentarzy jedno liniowych.
 * Musi się on jednak rozpoczynać od początku linii znakiem \p #.
 *  \param[in] NazwaPliku - nazwa pliku, z którego mają być wczytane informacje
 *                      dotyczące punktów.
 *  \param[in,out] ListaPkt - lista punktów, do której składowane są wczytane dane
 *                   o punktach.
 *  \param[in] Kolor      - numer koloru jakim ma być rysowny dany element
 *                      graficzny.
 *  \param[in] Styl       - styl rysowania, np. rysowanie punktu jako kropki lub krzyżyka.
 *  \param[in] sEtykieta  - etykietę, która może być wyświetlona razem z danym
 *                      punktem.
 *
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
 bool WczytajListeRoznychPunktow( const char*        NazwaPliku, 
                                  TypListaPunktow   &ListaPkt,
                                  int                Kolor,
                                  int                Styl,
                                  const char*        sEtykieta 
                                )
 {
   ifstream  StrmWe(NazwaPliku);

   if (!StrmWe.is_open()) {
     cerr << ":(  Nie mozna otworzyc do odczytu pliku:" << endl;
     cerr << ":(      " << NazwaPliku << endl;
     return false;
   }

   Wektor2f            Wspolrz;
   int                 Rozmiar;
   AtrybutyRysowania   Atryb;
   char                Znak;
   int                 Ilosc = 0;

   Atryb.ZmienKolor(Kolor).ZmienStyl(Styl);

   while (StrmWe >> Znak) {
       if (Znak == '#') { 
         StrmWe.ignore(numeric_limits<streamsize>::max(),'\n');
         continue;
       }
       StrmWe.unget();
       if (!(StrmWe >> Wspolrz >> Rozmiar)) break;
       Atryb.ZmienRozmiar(Rozmiar);
       ListaPkt.push_back(InfoPunktyDoRysowania(Wspolrz,Atryb,sEtykieta));
       ++Ilosc;
   }

   if (Ilosc  < 0) return false;
   if (Ilosc == 1) return true;

   TypListaPunktow::reverse_iterator Iter = ListaPkt.rbegin();
   for (; Ilosc > 0; --Ilosc, ++Iter) {
     Iter->DodajDoEtykiety(Ilosc);
   }
   return true;
 }

 /*!
  * \brief Dopisuje do tworzonego polenia dla gnuplota wpisy ustawiające etykiety punktów
  *
  *  Dopisuje do tworzonego polenia dla gnuplota wpisy ustawiające etykiety punktów.
  *  \param[in] ListaPkt - lista punktów, dla których mają zostać dopisane etykiety.
  *  \param[in,out] Comm - polecenie, do którego dopisywane są wpisy rysowania odpowiednich
  *                        etykiet.
  *  \retval true - wpisy ryowania etykie zostały dopisane.
  *  \retval false - lista punktów jest pusta i wpisy nie zostały dopisane.
  */
 bool DopiszUstawieniaEtykiet( const TypListaPunktow &ListaPkt,
			       std::string     &Comm
                             )
 {
   if (ListaPkt.empty()) return false;

   ostringstream      StrmWy;

   TypListaPunktow::const_iterator  Iter = ListaPkt.begin();
   StrmWy << " unset label\n";
   for ( ;
         Iter != ListaPkt.end();
         ++Iter) {
       StrmWy << " set label \"" << Iter->WezEtykiete() << "\" at "
              << Iter->WezWspolrzEtykiety().x << ","
              << Iter->WezWspolrzEtykiety().y << endl;
   } 
   Comm = StrmWy.str() + Comm;
   return true;
 }


/*!
 * \brief Dopisuje do polecenia rysowania wpisy z nazwami plików, w których są
 *        współrzędne punktów.
 *
 *  Dopisuje do polecenia rysowania dla \p gnuplota wpisy z nazwami plików, w których są
 *  współrzędne punktów.
 *  \param[in] ListaPkt - lista punktów, które mają zostać narysowane,
 *  \param[in,out] Comm - tworzone polecenie dla \p gnuplota, w którym mają pojawić się
 *                        wpisy z nazwami plików z danymi punktów do rysowania.
 *  \param[in]  Sep - wskaźnik na separator, jaki ma zostać użyty w liście wpisów
 *                    tworzonego polecenia dla gnuplota.
 *  \retval true - lista punktów nie jest pusta i wpisy zostały dodane.
 *  \retval false - lista punktów jest pusta, tym samym wpisy nie zostały dodane.
 */
 bool DopiszRysowaniePunktowZListy( TypListaPunktow &ListaPkt,
                                    std::string     &Comm,
                                    const char      *Sep
                                  )
 {
   TypListaPunktow::const_iterator  Iter = ListaPkt.begin(); 

   if (Iter == ListaPkt.end()) return false;


   AtrybutyRysowania  Atryb;

   if (Sep)  Comm += Sep;

   ostringstream      StrmWy;

   Atryb = Iter->WezAtrybuty();
   StrmWy << " \'-\' notitle w p ps " << Atryb.WezRozmiar()
          << " pt " << Atryb.WezStyl();
     //  << " lc " << Atryb.WezKolor();

   for ( ++Iter;
         Iter != ListaPkt.end();
         ++Iter ) {
       if (Atryb == Iter->WezAtrybuty()) continue;
       Atryb = Iter->WezAtrybuty();
       StrmWy << ", \'-\' notitle w p ps " << Atryb.WezRozmiar()
              << " pt " << Atryb.WezStyl();
       // << " lc " << Atryb.WezKolor();
   }
   StrmWy << endl;

   Iter = ListaPkt.begin(); 
   Atryb = Iter->WezAtrybuty();
   StrmWy << Iter->WezWspolrz().x << " " << Iter->WezWspolrz().y << endl;

   for ( ++Iter;
         Iter != ListaPkt.end();
         ++Iter ) {
       if (Atryb == Iter->WezAtrybuty()) {
         StrmWy << Iter->WezWspolrz().x << " " << Iter->WezWspolrz().y << endl;
         continue;
       }
       StrmWy << " e\n";
       Atryb = Iter->WezAtrybuty();
       StrmWy << Iter->WezWspolrz().x << " " << Iter->WezWspolrz().y << endl;
   }
   StrmWy << "e\n\n";
   Comm += StrmWy.str();
   return true;
 }



/*!
 * \brief Dodaje do listy rysowanych punktów, punkty o różnych rozmiarach
 *
 * Dopisuje do listy punktów, które mają być rysowane, punkty traktowane jako niejednorodne,
 * a więc mogące mieć różne rozmiary.
 * \param[in] IterNazw - iterator nazw plików z punktami niejednorodnymi, wyznacza pierwszy
 *                       element, który ma być dodany do listy rysowanych punktów.
 * \param[in] IterKonca - iterator końca listy dopisywanych punktów.
 * \param[in,out] ListaPunktow - lista punktów do rysowania, do której ma być dopisany
 *                         zbiór nazw plików zawierających punkty niejednorodne.
 */
 void DopiszRysowanieZRoznychPunktow( 
                           list<InfoPlikuDoRysowania>::const_iterator  &IterNazw,
                           list<InfoPlikuDoRysowania>::const_iterator  &IterKonca,
                           list<InfoPunktyDoRysowania>                 &ListaPunktow
                        )
 {
   for (; IterNazw != IterKonca; ++IterNazw ) {
      if (IterNazw->WezSposobRys() != SR_PunktowyNiejednorodny) continue;

      WczytajListeRoznychPunktow( IterNazw->WezNazwePliku().c_str(),
                                  ListaPunktow,
                                  IterNazw->WezKolor(), IterNazw->WezStyl(),
                                  IterNazw->WezEtykiete().c_str()
	                        );
   }
 }


/*!
 * Tworzy napis będący parametrami dla polecenie \e plot programu,
 * \e gnuplot. Parametry te pozwalają na rysowanie brył, których
 *  współrzędne wierzchołków zawarte są w plikach.
 *  Nazwy tych plików muszą być wcześniej dołączone do listy
 *  plików poprzez zastosowanie polecenia
 *   \link LaczeDoGNUPlota::DodajNazwePliku DodajNazwePliku()\endlink.
 *  
 * \param[in,out] Polecenie - dopisywana jest do niego sekwencja znaków
 *                  tworzących parametry dla polecenia \e plot.
 * \param[in] Sep - zawiera znak separatora między poszczególnymi
 *              parametrami. Jeżeli parametry listy nazw plików
 *              są generowane jako pierwsze, to zmienna ta musi 
 *              być wskaźnikiem do wskaźnika na łańcuch: " ".
 * \retval true - jeśli lista nazw plików nie jest pusta.
 * \retval false - w przypadku przeciwnym.
 * \post Jeżeli  lista nazw plików nie jest pusta, to poprzez
 *              parametr \e Sep zostaje udostępniony łańcuch: ", ".
 */
 bool LaczeDoGNUPlota::DopiszRysowanieZRoznychPunktow( 
                                                std::string  &Polecenie, 
                                                char const   *Sep 
                                             )
 {
  string  UstawieniaEtykiet;

  list<InfoPunktyDoRysowania>  ListaPunktow;

  list<InfoPlikuDoRysowania>::const_iterator IterNazw  = _InfoPlikow_Glb.begin();
  list<InfoPlikuDoRysowania>::const_iterator IterKonca = _InfoPlikow_Glb.end();

  PzG::DopiszRysowanieZRoznychPunktow(IterNazw,IterKonca,ListaPunktow); 

  IterNazw  = _InfoPlikow_Lok.begin();
  IterKonca = _InfoPlikow_Lok.end();

  PzG::DopiszRysowanieZRoznychPunktow(IterNazw,IterKonca,ListaPunktow); 

  if (ListaPunktow.empty()) return false;
  ListaPunktow.sort();

  DopiszUstawieniaEtykiet(ListaPunktow, Polecenie);
  return DopiszRysowaniePunktowZListy(ListaPunktow, Polecenie, Sep);
 }





 void LaczeDoGNUPlota::UstawRotacjeX( float KatX_st )
 {
   _Xrotacja = KatX_st;
   _Preambula_RotacjaSkala = ZapiszUstawienieRotacjiISkali();
 }
  

 void LaczeDoGNUPlota::UstawRotacjeZ( float KatZ_st )
 {
   _Zrotacja = KatZ_st;
   _Preambula_RotacjaSkala = ZapiszUstawienieRotacjiISkali();
 }


 void LaczeDoGNUPlota::UstawRotacjeXZ( float KatX_st, float KatZ_st )
 {
   _Xrotacja = KatX_st;  _Zrotacja = KatZ_st;
   _Preambula_RotacjaSkala = ZapiszUstawienieRotacjiISkali();
 }



 void LaczeDoGNUPlota::UstawSkaleX( float skala_x )
 {
   _Xskala = skala_x;
   _Preambula_RotacjaSkala = ZapiszUstawienieRotacjiISkali();
 }


 void LaczeDoGNUPlota::UstawSkaleZ( float skala_z )
 {
   _Zskala = skala_z;
   _Preambula_RotacjaSkala = ZapiszUstawienieRotacjiISkali();
 }


 void LaczeDoGNUPlota::UstawSkaleXZ( float skala_x, float skala_z )
 {
   _Xskala = skala_x;  _Zskala = skala_z;
   _Preambula_RotacjaSkala = ZapiszUstawienieRotacjiISkali();
 }


 //-------------------------------------------------------------------------
 //  Jezeli lista plikow nie jest pusta, to generuje sekwencje polecen
 //  dla programu gnuplot majaca na celu narysowanie plaszczyzn na
 //  na podstawie danych zawartych w plikach z listy. 
 //
 //  PRE:  Na liscie plikow nie powinna byc pusta. Nazwy plikow na niej
 //        mozna umiescic za pomoca metody 'DodajNazwe'.
 //        Metoda nie wymaga wcześniejszego zainicjowania połączenia
 //        z gnuplotem.
 //  POST: true   - gdy zostaja poprawnie wyslane polecenia dla gnuplota.
 //                 Nie oznacza to jednak, ze proces rysowania zakończył
 //                 się pomyślnie.
 //       false   - gdy połączenie z gnuplotem nie moze zostac poprawnie
 //                 zainicjalizowane lub gdy lista plikow jest pusta.
 //
 bool LaczeDoGNUPlota::Rysuj()
 {
  if (!CzyPolaczenieJestZainicjowane()) {
    if (!Inicjalizuj()) return false;
  }

  string Polecenie;

  BudujPreambulePoleceniaRysowania(Polecenie);

  char const *Sep = "";
  bool TrzebaRysowac = DopiszPlikiDoPoleceniaRysowania(Polecenie,&Sep);
  /*

  */
  TrzebaRysowac = DopiszRysowanieZPlikow(Polecenie,&Sep) || TrzebaRysowac;
  TrzebaRysowac = DopiszRysowanieZRoznychPunktow(Polecenie,Sep) 
                      || TrzebaRysowac;
  if (!TrzebaRysowac) return false;
 /*
  cerr << "Polecenie: =============================================" << endl;
  cerr << Polecenie << endl;
   cerr << "-----------------------------" << endl;
 */
  Polecenie += "\npause -1\n";

  return PrzeslijDoGNUPlota(Polecenie.c_str());
 }



 void  LaczeDoGNUPlota::BudujPreambulePoleceniaRysowania(std::string &Preambula)
 {
  switch (_TrybRys) {
   case TR_2D: BudujPreambule_2D(Preambula); break;
   case TR_3D: BudujPreambule_3D(Preambula); break;
  }
 }



 void  LaczeDoGNUPlota::BudujPreambule_2D(std::string &Preambula)
 {
  Preambula.clear();
  Preambula.reserve(1000);
  if (!_Preambula_RotacjaSkala.empty()) {
    Preambula = _Preambula_RotacjaSkala;
    _Preambula_RotacjaSkala.clear();
  }
  Preambula = "\n\n";

  if (_PokazOs_OX) Preambula += "set xzeroaxis lt 0 lw 1\n";
  if (_PokazOs_OY) Preambula += "set yzeroaxis lt 0 lw 1\n";

  Preambula += ZapiszUstawienieZakresu('x');
  Preambula += ZapiszUstawienieZakresu('y');
  Preambula += "\nplot ";
 }



 void  LaczeDoGNUPlota::BudujPreambule_3D(std::string &Preambula)
 {
  Preambula.clear();
  Preambula.reserve(1000);
  if (!_Preambula_RotacjaSkala.empty()) {
    Preambula = _Preambula_RotacjaSkala;
    _Preambula_RotacjaSkala.clear();
  }
  Preambula += "\n\n"
                       "set xlabel \"X\"\n"
                       "set ylabel \"Y\"\n"
                       "set zlabel \"Z\"\n"
                       "set parametric\n"
                       "set isosamples 9\n"
                       "set urange [-180:180]\n"
                       "set vrange [-90:90]\n";  

  if (_PokazOs_OX) Preambula += "set xzeroaxis lt 0 lw 1\n";
  if (_PokazOs_OY) Preambula += "set yzeroaxis lt 0 lw 1\n";

  Preambula += ZapiszUstawienieZakresu('x');
  Preambula += ZapiszUstawienieZakresu('y');
  Preambula += ZapiszUstawienieZakresu('z');
  //  Preambula += ZapiszUstawienieRotacjiISkali();
  Preambula += "set hidden3d\nsplot ";
 }



std::string LaczeDoGNUPlota::ZapiszUstawienieZakresu(char Os) const
{
  ostringstream strm;
  float Min, Max;

  switch (Os) {
   case 'x':  Min = Xmin();  Max = Xmax();  break;
   case 'y':  Min = Ymin();  Max = Ymax();  break;
   case 'z':  Min = Zmin();  Max = Zmax();  break;
   default: cerr << "!!! Blad w 'ZapiszUstawienieZakresu' niedozwolony"
                    " znak: " << Os << endl;
            return "";
  }
  strm << "set " << Os << "range [" <<  Min << ":" << Max << "]\n";
  return strm.str();
}



std::string LaczeDoGNUPlota::ZapiszUstawienieRotacjiISkali() const
{
  ostringstream strm;
  strm << "set view " << RotacjaX() << "," << RotacjaZ() 
       << "," << SkalaX() << "," << SkalaZ() << endl;
  return strm.str();
}




/*!
 * \brief Usuwa ostatnia nazwę pliku z listy plików do rysowania.
 *
 *  Funkcja ma charakter pomocniczy. Usuwa ostatnią nazwę z listy nazw plików
 *  z danymi przeznaczonych do rysowania.
 *  \param[in] Lista - lista plików, z której ma zostać usunięty ostatni element.
 */
 void UsunOstatniaNazwePliku(list<InfoPlikuDoRysowania>& Lista)
 {
   if (Lista.empty()) return;
   list<InfoPlikuDoRysowania>::iterator IterNazw = Lista.end();
   Lista.erase(--IterNazw);
 }

 //-------------------------------------------------------------------------
 //  Metda usuwa ostatnia nazwe z listy nazw plikow.
 //
 void LaczeDoGNUPlota::UsunOstatniaNazwe_ListaLokalna()
 {
   PzG::UsunOstatniaNazwePliku(_InfoPlikow_Lok);
 }


 //-------------------------------------------------------------------------
 //  Metda usuwa ostatnia nazwe z listy nazw plikow.
 //
 void LaczeDoGNUPlota::UsunOstatniaNazwe_ListaGlobalna()
 {
   PzG::UsunOstatniaNazwePliku(_InfoPlikow_Glb);
 }



 //-------------------------------------------------------------------------
 //  Metda calkowicie kasuje zawartosc listy nazw plikow.
 //
 void LaczeDoGNUPlota::UsunWszystkieNazwyPlikow()
 {
  _InfoPlikow_Lok.clear();
  _InfoPlikow_Glb.clear();
 }

 //_____________________ LaczeDoGNUPlota ______________________________________
 //============================================================================


} //___ Koniec przestrzeni nazw: PzG ____________________________________________
