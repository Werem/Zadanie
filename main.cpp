/*!
 * \file
 * \brief Zawiera wywołanie funkcji main
 *
 * Główny moduł programu wraz z wywołaniem funkcji main.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"


using namespace std;



int main()
{
  char                  Znak;
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
  ObiektGraficzny       Ob;
  ObiektGraficzny		Linia;
 
  Ob.InicjalizujKsztalt();



   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("figury/linia.dat", PzG::RR_Ciagly, 2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  double x = 0, y = 0;
  float vX = 0, vY = 0;
  float kat = 0.0f;
  float skala = 1.0f;
  bool a = true;
  while (a) {
	  //Ob.SprawdzGranice(vX, vY);
	  Ob.DodajWektorLinii(x, y);
	  Ob.ZmienKat(kat);
	  if (!Ob.ZapiszDoPliku("figury/robot.dat")) return 1;
	  if (!Ob.ZapiszLinie("figury/linia.dat")) return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
	  Znak = getchar();
	  if (Znak == 'p')
		  a = false;
	  if (Znak == 'a' || Znak == 'A')
		  kat -= 0.5f;
	  if (Znak == 'd' || Znak == 'D')
		  kat += 0.5f;
	  if (Znak == 'w' || Znak == 'W') {
		  vX += cos(kat) * 2.0f;
		  vY += sin(kat) * 2.0f;
	  }
	  if (Znak == 's' || Znak == 'S') {
		  vX -= cos(kat) * 2.0f;
		  vY -= sin(kat) * 2.0f;
	  }
	  if (Znak == 'e' || Znak == 'E') {
		  skala += 0.2f;
		  Ob.ZmienSkale(skala);
	  }
	  if (Znak == 'q' || Znak == 'Q') {
		  skala -= 0.2f;
		  Ob.ZmienSkale(skala);
	  }
	  Ob.ZmienPolozenie(x, y);
	  x += vX;
	  y += vY;
  }

}
