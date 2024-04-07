///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 6 ze strony 180.
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

// Funkcja zwraca 'true' gdy b jest nieparzysta
bool porownaj(int a, int b)
{
    // Reszta z dzielenia przez 2 mówi nam, czy liczba jest parzysta, czy nie.
    // (a % 2) równa się 1, gdy a jest nieparzysta
    // (a % 2) równa się 0, gdy a jest nieparzysta
    // (b % 2) równa się 1, gdy b jest nieparzysta
    // (b % 2) równa się 0, gdy b jest nieparzysta

    // Jeśli zamienisz operator porównania z '<=' na '>=', to liczby będą
    // posortowane odwrotnie - wpierw pojawią się parzyste a następnie
    // nieparzyste.
    return (a % 2) <= (b % 2);
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
    int a[] = { 18, 1, 7, 12, 5 };
    int n = 5;

    wyswietl_tablice(a, n, "Liczby przed sortowaniem");
    sort_babelkowe(a, n);
    wyswietl_tablice(a, n, "Posortowane liczby");

    return 0;
}
