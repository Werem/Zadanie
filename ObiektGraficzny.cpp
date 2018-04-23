/*!
 * \file
 * \brief Zawiera definicje metod klasy ObiektGraficzny
 *
 * Zawiera definicje metod klasy ObiektGraficzny
 * wraz z ich opisem.
 */

#include <fstream>
#include "ObiektGraficzny.hh"


using namespace std;


/*!
 * Przypisuje wartości współrzędnych poszczególnym wierzchołkom.
 *
 * Uwaga:Ta metoda to tylko tymczasowe rozwiązanie. Ona powinna
 *       być w klasie pochodnej.
 */
void ObiektGraficzny::InicjalizujKsztalt()
{
  _TabWierz[0][0] =   0;  _TabWierz[0][1]=   0;
  _TabWierz[1][0] =  30;  _TabWierz[1][1]=   0;
  _TabWierz[2][0] =   0;  _TabWierz[2][1]= -30;
  _TabWierz[3][0] = -30;  _TabWierz[3][1]= -30;
  _TabWierz[4][0] = -30;  _TabWierz[4][1]=  30;
  _TabWierz[5][0] =   0;  _TabWierz[5][1]=  30;
  _TabWierz[6][0] =  30;  _TabWierz[6][1]=   0;

  _Globalne[0][0] =   0;  _Globalne[0][1] = 0;
  _Globalne[1][0] =  30;  _Globalne[1][1] = 0;
  _Globalne[2][0] =   0;  _Globalne[2][1] = -30;
  _Globalne[3][0] = -30;  _Globalne[3][1] = -30;
  _Globalne[4][0] = -30;  _Globalne[4][1] = 30;
  _Globalne[5][0] =   0;  _Globalne[5][1] = 30;
  _Globalne[6][0] =  30;  _Globalne[6][1] = 0;
  _Skala = 1.0f;
}



/*!
 *  Zmiania współrzędne położenia punktu, względem którego tworzony
 *  jest obrys obiektu.
 *  \param[in] x - współrzędna x-owa nowego położenia.
 *  \param[in] y - współrzędna y-owa nowego położenia.
 */
void ObiektGraficzny::ZmienPolozenie(double x, double y)
{
  _PolozenieObiektu[0] = x;
  _PolozenieObiektu[1] = y;  

  Wektor2D W_glob;
  int i = 0;
  for (const Wektor2D& W_lok : _TabWierz) {
	  float sinus = sin(_Kat);
	  float cosinus = cos(_Kat);
	  float x = W_lok[0] * _Skala;
	  float y = W_lok[1] * _Skala;
	  W_glob[0] = x * cosinus - y * sinus + _PolozenieObiektu[0];
	  W_glob[1] = x * sinus + y * cosinus + _PolozenieObiektu[1];
	  _Globalne[i++] = W_glob;
  }
}
void ObiektGraficzny::ZmienKat(float kat) { _Kat = kat; };
void ObiektGraficzny::ZmienSkale(float skala) { _Skala = skala; }

//void ObiektGraficzny::SprawdzGranice(float& vX, float& vY) {
//	for (const Wektor2D& W_glob : _Globalne) 
//	{
//		if(W_glob[0] < )
//	}
//}

/*!
 * Zapisuje do strumienia współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{
  for (const Wektor2D&  W_glob : _Globalne) {
      StrmWy << W_glob << endl;
  }
  return !StrmWy.fail();
}


/*!
 * Zapisuje do pliku współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
  ofstream   StrmWy(sNazwaPliku);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
	 << "' nie powiodlo sie." << endl
	 << endl;
    return false;
  }
  return ZapiszDoStrumienia(StrmWy);
}

void ObiektGraficzny::DodajWektorLinii(float x, float y) {
	Wektor2D wektor;
	wektor[0] = x;
	wektor[1] = y;
	_WektoryLinii.push_back(wektor);
}
bool ObiektGraficzny::ZapiszLinie(const char* sNazwaPliku) {

	ofstream   StrmWy(sNazwaPliku);

	if (!StrmWy.is_open()) {
		cerr << endl
			<< "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
			<< "' nie powiodlo sie." << endl
			<< endl;
		return false;
	}

	for (int i = 0; i < _WektoryLinii.size(); i++)
	{
		StrmWy << _WektoryLinii[i] << endl;
	}
	return !StrmWy.fail();
}
