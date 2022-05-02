## Opis
Program jest schematyczną wizualizacją przemieszczania się dronów na powierzchni planety w środowisku kolizyjnym. Użytkownik może zadawać ścieżkę przelotu wybranego z dronów czy nakazać wykonanie zwiadu. Dron reaguje na przeszkody ustawione na powierzchni planety, unika ich, gdy może w nie wpaść - znajdując sobie autonomicznie nowe miejsce od wskazanego przez użytkownika. Obiekty na powierzchni mogą być dowolnie dodawane, jak i usuwane przez użytkownika. 

## Uwaga
Program został stworzony w oparciu o język C++ zgodnie z paradygmatem programowania obiektowego. Program jest przeznaczony do działania na systemie Linux.

## Uruchamianie Programu
 * Aby móc poprawnie skompilować program należy najpierw stworzyć katalog build, o ile go nie ma, a następnie użyć programu cmake poleceniem `cmake ..` do stworzenia pliku makefile w katalogu `build/`.
 * Następnie należy użyć Makefile poleceniem `make`, aby skompilować program po wcześniejszym poprawnym stworzeniu pliku `Makefile` z pomocą cmake w katalogu `build/`. 
 * Po poprawnym skompilowaniu, aby uruchomić program, należy użyć polecenia `./main` w katalogu `build/`.

## Uruchamianie testów programu
 * Testy jednostkowe programu uruchamiają się po wpisaniu do terminala `./unit_tests` po poprawnej kompilacji z użyciem pliku Makefile w katalogu `build/`.

## Generowanie dokumentacji w Doxygen
 * Aby wygenerować pliki dokumentacji Doxygen, w postaci HTML, należy skorzystać z pliku konfiguracyjnego `Doxyfile.in` znajdującego się w głównym katalogu repozytorum. Aby to zrobić, należy skorzystać z polecenia `doxygen Doxyfile.in` w głównym katalogu repozytorium. Wygenerowane pliki będą znajdowały się w katalogu `dox/`. Do wygenerowania dokumentacji można również skorzystać z kreatora doxywizard lub cmake poleceniem `doxygen` w katalogu `build/`. 

## Wcześniej wygenerowana dokumentacja
 * Repozytorum posiada wcześniej wygenerowane najaktualniejsze pliki dokumentacji (w języku polskim) w katalogu `dox/`. Aby uruchomić stronę główną dokumetnacji należy uruchomić plik `./dox/html/index.html`

## Wymagania
Wymagane: cmake, gnuplot, doxygen + dot