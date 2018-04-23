#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include "Wektor2D.hh"
#include <vector>
#include <math.h>

using namespace std;

/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny {
  /*!
   * \brief Współrzędne pozycji obiektu
   *
   *  Zawiera współrzędne punktu względem, którego podane są
   *  współrzędne punktów obrysu obiektu.
   */
   Wektor2D   _PolozenieObiektu;
   vector<Wektor2D> _WektoryLinii;

   float _Kat;
   float _Skala;
  /*!
   * \brief Tablica wierzchołków
   *
   *  
   */
   Wektor2D   _TabWierz[7]; // To jest tylko tymczasowe rozwiązanie.
                            // Tu należy użyć szablonu wektor.
   Wektor2D   _Globalne[7];

  public:
  /*!
   * \brief Inicjalizacja współrzędnych wierzchołków
   */
   void InicjalizujKsztalt();
  /*!
   * \brief Metoda zapisuje do pliku współrzędne wierzchołków
   */
   bool ZapiszDoPliku(const char* sNazwaPliku) const;
   //void SprawdzGranice(float& vX, float& vY);
  /*!
   * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
   */   
   bool ZapiszDoStrumienia(std::ostream& StrmWy) const;
  /*!
   * \brief Zmiania współrzędne położenia obiektu
   */
  void ZmienPolozenie(double x, double y);
  void ZmienKat(float kat);
  void ZmienSkale(float skala);

  void DodajWektorLinii(float x, float y);
  bool ZapiszLinie(const char* sNazwaPliku);
};


#endif
