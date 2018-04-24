#include "Complex.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

Complex::Complex(float real, float imaginary)
{
    this->real = real; //Przypisz pierwszy argument konstruktora do wartosci rzeczywistej liczby zespolonej
    this->imaginary = imaginary; //Przypisz drugi argument konstruktora do wartosci urojonej liczby zespolonej
}

float Complex::GetReal() const
{
    return real; // Zwroc wartosc rzeczywista liczby zespolonej
}

void Complex::SetReal(float _real)
{
    real = _real; // Przypisz podany argument do wartosci rzeczywistej liczby zespolonej
}

float Complex::GetImaginary() const
{
    return imaginary; // Zwroc wartosc urojona liczby zespolonej
}

void Complex::SetImaginary(float _imaginary)
{
    imaginary = _imaginary; //Przypisz podany argument do wartosci urojonej liczby zespolonej
}

float Complex::Modul()
{
    /* Zwroc modul liczby zespolonej wg. wzoru
     * pierwiastek(czescRzeczywista^2 + czescUrojona^2)*/
    return(
            sqrtf( // Funckja obliczajaca pierwiastek
                    (real * real) +
                    (imaginary * imaginary)
            )
    );
}

Complex Complex::Sprzezenie()
{
    Complex sprzezona(real, (-1 * imaginary));

    return sprzezona; // Zwroc sprzezenie liczby zespolonej
}

Complex &Complex::operator=(const int &real)
{
    this->real = real;
    this->imaginary = 0;

    return *this;
}

Complex operator + (Complex z1, Complex z2)
{
    Complex wynik(0,0);

    wynik.SetReal(z1.GetReal() + z2.GetReal()); // Dodaj czesci rzeczywiste
    wynik.SetImaginary(z1.GetImaginary() + z2.GetImaginary()); // Dodaj czesci urojone

    return wynik; // Zwroc wynik dodawania
}

Complex operator - (Complex z1, Complex z2)
{
    Complex wynik(0,0);

    wynik.SetReal(z1.GetReal() - z2.GetReal()); // Odejmij czesci rzeczywiste
    wynik.SetImaginary(z1.GetImaginary() - z2.GetImaginary()); // Odejmij czesci urojone

    return wynik; // Zwroc wynik odejmowania
}

Complex operator * (Complex z1, Complex z2)
{
    Complex wynik(0,0);

    /* Obliczenie czesci rzeczywistej */
    wynik.SetReal((z1.GetReal() * z2.GetReal()) - (z1.GetImaginary() * z2.GetImaginary()));
    /* Obliczenie czesci urojonej */
    wynik.SetImaginary((z1.GetReal() * z2.GetImaginary()) + (z1.GetImaginary() * z2.GetReal()));

    return wynik; // Zwroc wynik mnozenia
}

Complex operator / (Complex z1, float num)
{
    Complex wynik(0,0);

    /* Sprawdz czy nie dzielimy przez 0 */
    if(num != 0)
    {
        wynik.SetReal(z1.GetReal() / num); // Obliczenie czesci rzeczywistej
        wynik.SetImaginary(z1.GetImaginary() / num); // Obliczenie czesci urojonej

        return wynik; // Zwroc wynik dzielenia
    } else
    {
        std::cout << "Nie dziel przez zero"; // Powiadom o bledzie

        return z1; // Zwroc wartosc wyjsciowa
    }
}

Complex operator / (Complex z1, Complex z2)
{
    Complex wynik(0,0);

    /* Sprawdz czy nie dzielimy przez 0 */
    if (z2.Modul() != 0)
    {
        wynik = (z1 * z2.Sprzezenie()) / (z2.Modul() * z2.Modul()); // Obliczenie wyniku dzielenia

        return wynik; // Zwroc wynik dzielenia
    } else
    {
        std::cout << "Nie dziel przez zero"; // Powiadom o bledzie

        return z1; // Zwroc wartosc wyjsciowa
    }
}

std::ostream & operator<< (std::ostream &wyjscie, Complex z1)
{
    /* Sprawdz czy czesc urojona jest mniejsza od 0 */
    if (z1.GetImaginary() < 0)
    {
        /* Zwroc liczbe zespolona, w ktorej czesc urojona wystepuje ze znakiem - */
        return wyjscie << "(" << z1.GetReal() << z1.GetImaginary() << "i" << ")";
    } else
    {
        /* Zwroc liczbe zespolona, w ktorej czesc urojona wystepuje ze znakiem + */
        return wyjscie << "(" << z1.GetReal() << "+" << z1.GetImaginary() << "i" << ")";
    }
}

std::istream& operator>> (std::istream &is, Complex &z1)
{
    char c; // wczytywany znak
    float tmp; // zmienna przechowujaca wartosc tymczasowa
    std::string s; //Zmienna przechowujaca wczytane wyrazenie zespolone
    std::stringstream ss; //Sting jako strumien

    is >> s; //Wczytanie wyrazenia zespolonego
    ss.str (s); //Zmienna s jako strumien

    ss >> c; // Wczytaj znak z podanego strumienia
    /* Sprawdz czy podana liczba zespolona jest wpisana w poprawnym formacie
*   Podana liczba zespolona musi zawierać znaak "(" na poczatki */
    if (c != '(')
    {
        throw "zla liczba zespolona"; // Jesli nie - poinformuj o bledzie
    }

    /* Wczytaj czesc rzeczywista z podanego strumienia */
    ss >> tmp;
    z1.SetReal(tmp);

    /* Wczytaj czesc urojona z podanego strumienia */
    ss >> tmp;
    z1.SetImaginary(tmp);

    ss >> c; // Wczytaj nastepny znak
    /* Sprawdz czy podana liczba zespolona jest wpisana w poprawnym formacie
     * Podana liczba zespolona musi zawierać znak "i" przy czesci urojonej
     * np. (4+4i)*/
    if (c != 'i')
    {
        throw "zla liczba zespolona"; // Jesli nie - poinformuj o bledzie
    }

    ss >> c; // Wczytaj nastepny znak
    /* Sprawdz czy podana liczba zespolona jest wpisana w poprawnym formacie
    * Podana liczba zespolona musi zawierać znaak ")" na końcu */
    if (c != ')')
    {
        throw "zla liczba zespolona"; // Jesli nie - poinformuj o bledzie
    }

    return is;
}

bool operator == (Complex z1, Complex z2)
{
    /* Zwroc wynik porownania dwoch liczb zespolonych */
    return (
            (z1.GetReal() == z2.GetReal()) && // Porownaj czesci rzeczywiste
            (z1.GetImaginary() == z2.GetImaginary()) // Porownaj czesci urojone
    );
}

Complex sqrt(Complex c)
{
    Complex tmp(0,0);
    int sgn;

    if(c.GetImaginary() > 0)
    {
        sgn = 1;
    } else if(c.GetImaginary() < 0)
    {
        sgn = -1;
    } else
    {
        sgn = 0;
    }

    tmp.SetReal(sqrtf((c.GetReal() + abs(c)) / 2));
    tmp.SetImaginary(sgn * sqrtf((- c.GetReal() + abs(c)) / 2));

    return tmp;
}

float abs(Complex c)
{
    return sqrtf(c.GetReal()*c.GetReal()+c.GetImaginary()*c.GetImaginary());
}

Complex operator*(Complex c, int num)
{
    Complex tmp(0,0);

    tmp.SetReal(c.GetReal() * num);
    tmp.SetImaginary(c.GetImaginary() * num);

    return tmp;
}

Complex &Complex::operator+=(const Complex& c)
{
    SetReal(GetReal() + c.GetReal());
    SetImaginary(GetImaginary() + c.GetImaginary());

    return *this;
}

Complex &Complex::operator-=(const Complex& c)
{
    SetReal(GetReal() - c.GetReal());
    SetImaginary(GetImaginary() - c.GetImaginary());

    return *this;
}

float Complex::GetArgument() const
{
    return atan2f(real, imaginary);
}

void Complex::SetPolar(float magnitude, float argument)
{
    real = magnitude * cosf(argument);
    imaginary = magnitude + sinf(argument);
}
