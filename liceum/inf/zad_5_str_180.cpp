///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 5 ze strony 180.
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
#include <bitset>
using namespace std;

void wyswietl_tablice(int a[], int n, string napis)
{
    cout << napis << ":" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl << endl;
}

// Funkcja zwraca sumę cyfr binarnych liczby 'liczba'. Algorytm obliczenia tej
// wartości polega na dzieleniu libczy przez 2 aż do momentu, gdy jest ona równa
// 0. Natomiast reszta z dzielenia przez 2 daje nam resztę z dzielenia, której
// wartość odpowiada cyfrze na pozycji jedności.
// Dla zainteresowanych:
// Ten algorytm można by uproscić poprzez sotosowanie logiki bitowej i przesu-
// nięcia bitów w zmiennej całkowitej, jednak ten temat może wykraczać poza
// zakres niezbędnej wiedzy a niżej przedstawione rozwiązanie daje ten sam wynik
int suma_jedynek_w_zapisie_binarnym(int liczba)
{
    int suma_cyfr = 0;

    // Powtarzaj dopóki liczba jest większa od zera.
    while (liczba > 0)
    {
        int reszta_z_dzielenia = liczba % 2;
        // Resztą z dzielenia przez 2 jest 1 lub 0, więc sumujemy jedynki,
        // co odpowiada liczbie jedynem w binarnym zapisie liczby.
        suma_cyfr += reszta_z_dzielenia;
        liczba /= 2;
    }

    return suma_cyfr;
}

// Funkcja porównuje dwie liczby 'a' i 'b' ze sobą i zwraca wartość 'true', gdy
// suma cyfr liczby w zapisie binarnym 'a' jest większa od sumy cyfr liczby 'b',
// w przeciwnym razie zwraca 'false'.
//
// Przykład:
// 32 w zapisie binarnym to 100000
// 7 w zapisie binarnym to  000111
// porownaj(32, 7) zwróci 'false', bo 1 jest mniejsze od 1 + 1 + 1.
bool porownaj(int a, int b)
{
    return suma_jedynek_w_zapisie_binarnym(a) > suma_jedynek_w_zapisie_binarnym(b);
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
    int a[] = { 31, 128, 127, 1, 2, 4, 8 };
    int n = 5;

    wyswietl_tablice(a, n, "Liczby przed sortowaniem");
    sort_babelkowe(a, n);
    wyswietl_tablice(a, n, "Posortowane liczby");

    cout << "Dodatkowo zerknijmy, jak wygląda ich binarna reprezentacja i"
         << " jak te liczby \"widziała\" funkcja porównująca:" << endl;
    // Uwaga. bitset<8>(a[i]) wyświetla liczbę w systemie dwójkowym, jednak
    // trzeba podać liczbę bitów do wyświetlenia. Przy licznie 8 nasze liczby,
    // w tablicy 'a' nie powinny przeraczać wartości 256, inaczej nie wszystkie
    // jedynki będą widoczne w poniższej wizualizacji.
    for (int i = 0; i < n; ++i)
    {
        cout << "- " << a[i] << " to binarnie " << bitset<8>(a[i]) << ", gdzie suma jedynek to " << suma_jedynek_w_zapisie_binarnym(a[i]) << endl;
    }
    cout << endl;

    return 0;
}
