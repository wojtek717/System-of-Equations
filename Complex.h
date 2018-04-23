#ifndef SYSTEMOFEQUATIONS_COMPLEX_H
#define SYSTEMOFEQUATIONS_COMPLEX_H

#include <iostream>
#include <cmath>

class Complex
{
public:
    Complex() = default;

    /* Konstruktor tworzacy nowe obiekty o klasie Zespolona
     * [IN](float) rzeczywista - rzeczywista wartosc liczby zespolonej
     * [IN](float) urojona - urojona wartosc liczby zespolonej */
    Complex(float rzeczywista, float urojona);

    /* Metoda obliczajaca modul liczby zespolonej
     * [RETURN](float) modul liczby zespolonej */
    float Modul();

    /* Metoda oblicza sprzezenie liczby zespolonej
     * [RETURN](Zespolona) Sprzezona liczba zespolona */
    Complex Sprzezenie();

    /* Metody pozwalajace wczytac lub odczytac wartosc rzeczywista liczby zespolonej */
    float GetReal() const;
    void SetReal(float);

    /* Metody pozwalajace wczytac lub odczytac wartosc urojona liczby zespolonej */
    float GetImaginary() const;
    void SetImaginary(float);

    float GetArgument() const;
    void SetPolar(float magnitude, float argument);

    Complex &operator = (const int&);
    Complex &operator += (const Complex&);
    Complex &operator -= (const Complex&);

private:
    float real; // wartosc rzeczywista liczby zespolonej
    float imaginary; // wartosc urojona liczby zespolonej
};

/* Przeciazenia operatorow dla dzialan na liczbach zespolonych */
Complex operator + (Complex, Complex); // Dodoawania dwoch liczb zespolonych
Complex operator - (Complex, Complex); // Odejmowanie dwoch liczb zespolonych
Complex operator * (Complex, Complex); // Mnozenie dwoch liczb zespolonych
Complex operator * (Complex, int);
Complex operator / (Complex, float); // Dzielenie liczby zespolonej przez naturalna
Complex operator / (Complex, Complex); // Dzielenie dwoch liczb zespolonych
std::ostream & operator<< (std::ostream &wyjscie, Complex); // Wypisywanie liczby zespolonej
std::istream& operator>> (std::istream& is, Complex&); // Wczytywanie liczby zespolonej
bool operator == (Complex, Complex); // Porownanie dwoch liczb zespolonych

Complex sqrt(Complex c);
float abs(Complex c);

#endif //SYSTEMOFEQUATIONS_COMPLEX_H
