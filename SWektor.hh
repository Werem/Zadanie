#ifndef SWEKTOR_HH
#define SWEKTOR_HH

/*!
 * \file
 * \brief  Definicja szablonu SWektor
 *
 *  Zawiera definicję szablonu SWektor. Pozwala on na
 *  stworzenie instancji klasy wektor o dowolnym wymiarze
 *  oraz typie pól reprezentujących jego współrzędne, dla 
 *  których zdefiniowane są podstawowe działania arytmetyczne.
 */



#include <iostream>



/*!
 * \brief Szablon klasy wektor parametryzowanej wymiarem i typem współrzędnych
 *
 *  Szablon umożliwiający tworzenie instancji typu, który modeluje 
 *  pojęcie wektora. 
 *   \param  STyp - typ pól repezentujących kolejne współrzędne wektora,
 *   \param  SWymiar - wymiar wektora.
 */
template <typename STyp, int SWymiar>
class SWektor {
   /*!
    * \brief Współrzędne wektora
    *
    *  Tablica zawiera kolejne współrzędne wektora.
    */
    STyp  _Wsp[SWymiar];
  public:
   /*!
    * \brief Inicjaliuje obiek wartościami 0.
    *
    *  Inicjaluje wszystkie współrzędne wektora wartością 0.
    */
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }

   /*!
    * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie \e tylko \e do \e odczytu.
    *
    *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie  \e tylko \e do \e odczytu.
    *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
    *
    *  \param[in] Ind - indeks wybranej współrzędnej. Indeksowanie tak jak w przypadku 
    *               tablicy, zaczyna się od 0.
    *  \pre Wartość parametru \e Ind musi być mniejsza niż \e SWymiar.
    *  \return Wartość indeksowanej współrzędnej.
    */
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
   /*!
    * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie \e modyfikacji.
    *
    *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie modyfikacji.
    *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
    *
    *  \param[in] Ind - indeks wybranej współrzędnej. Indeksowanie tak jak w przypadku 
    *               tablicy, zaczyna się od 0.
    *  \pre Wartość parametru \e Ind musi być mniejsza niż \e SWymiar.
    *  \return Referencję do indeksowanej współrzędnej.
    */
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }
   /*!
    * \brief Odejmowanie dwóch wektorów.
    */
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
   /*!
    * \brief Dodanie dwóch wektorów.
    */
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Skl2) const;
   /*!
    * \brief Mnoży wektor przez liczbę.
    */
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
};



/*!
 *  Realizuje odejmowanie dwóch wektorów i zwraca wynik działania.
 *  \param[in] Odjemnik - drugi argument operacji odejmownaia.
 *  \return Wynik operacji odejmowania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}



/*!
 *  Realizuje dodawanie dwóch wektorów i zwraca wynik działania.
 *  \param[in] Skl2 - drugi argument operacji dodwania.
 *  \return Wynik operacji dodawania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Skl2) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Skl2[Ind];
  return Wynik;
}



/*!
 *  Realizuje mnożenie wszystkie współrzędnych wektora przez liczbę.
 *  \param[in] Mnoznik - wartość liczby, przez którą zostaną wymnożone wszystkie
 *                       współrzędne wektora.
 *  \return Wynik operacji mnożenia przez liczbę.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

/*!
 * \brief Wypisuje kolejne współrzędne wektora
 *
 * Do strumienia wyjściowego w formie tekstowej wpisuje wszystkie wartości
 * współrzędnych wektora rozdzielając je spacją.
 * Przykład wyniku operacji
\verbatim
    12.5 1.23 4 6
\endverbatim
 *  \param[in,out]  StrmWyj - strumień wyjściowy, do którego zostają wpisane
 *                            w formie tekstowej wartości kolejnych współrzędnych.
 *  \param[in] W - wektor, którego współrzędne mają zostać wpisane do strumienia.
 *  \return Referencja do strumienia wyjściowego będącego parametrem wywołania
 *          niniejszego przeciążenia operatora <<.
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}

#endif
