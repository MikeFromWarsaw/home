///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 4 ze strony 180.
///
/// Kod zawiera polskie znaki zapisane jako UTF-8. Jeśli w Twoim edytorze lub
/// linii poleceń nie wyświetlają się prawidłowo, to je usuń.
///
/// W kodzie zawartym w podręczniku nie sprawdza się poprawności wartości
/// argumentów funkcji, stąd i tutaj stosowane jest to podejście.
/// Prawdopodobnie ma to na celu poprawienie przejrzystości kodu, tzn. skupienie
/// uwagi ucznia na samym algorytmie a nie przetwarzaniu błędów oraz - być może
/// - zmniejszenie zawartości kodu w książce.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

void wyswietl_tablice(int a[], int n, string napis)
{
    cout << napis << ":" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// Funkcja zwraca sumę cyfr liczby 'liczba'. Algorytm obliczenia tej wartości
// polega na dzieleniu libczy przez 10 aż do momentu, gdy jest ona równa 0.
// Natomiast reszta z dzielenia przez 10 daje nam resztę z dzielenia, której
// wartość odpowiada cyfrze na pozycji jedności.
int suma_cyfr(int liczba)
{
    int suma_cyfr = 0;

    while (liczba > 0)
    {
        int reszta_z_dzielenia = liczba % 10;
        suma_cyfr += reszta_z_dzielenia;
        liczba /= 10;
    }

    return suma_cyfr;
}

// Funkcja porównuje dwie liczby 'a' i 'b' ze sobą i zwraca wartość 'true', gdy
// suma cyfr liczby 'a' jest większa od sumy cyfr liczby 'b', w przeciwnym razie
// zwraca 'false'.
//
// Przykład:
// porownaj(111, 9) zwróci 'false', bo 1 + 1 + 1 jest mniejsze od 9.
bool porownaj(int a, int b)
{
    return suma_cyfr(a) > suma_cyfr(b);
}

void sort_babelkowe(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (porownaj(a[j], a[j + 1]))
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }

        }
    }
}

int main()
{
    int a[] = { 19, 1, 7, 12, 5 };
    int n = 5;

    wyswietl_tablice(a, n, "Liczby przed sortowaniem");
    sort_babelkowe(a, n);
    wyswietl_tablice(a, n, "Posortowane liczby");

    cout << "Sprawdźmy, jak te liczby \"widziała\" funkcja porównująca i czy"
         << " liczby są prawidłowo posortowane." << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << suma_cyfr(a[i]) << ", ";
    }
    cout << endl;

    return 0;
}
