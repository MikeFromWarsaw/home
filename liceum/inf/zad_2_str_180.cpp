///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 2 ze strony 180.
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

// Oryginalny algorytm sortowania przez wybierania wyznaczający pierwszy element
// tablicy.
void sort_wybieranie(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        int tmp = a[i];
        a[i] = a[m];
        a[m] = tmp;
    }
}

// Zadanie wymaga, aby algorytm wyznaczał wpierw ostatni element, przedostatni,
// itd., czyli zczynał sortowanie od końca tablicy.
void sort_wybieranie_od_konca(int a[], int n)
{
    // Tutaj zmieniliśmy kierunek przechodzenia po elementach. Zaczynamy od
    // i = (n-1) czyli od ostatniego elementu
    // i kończymy na i = 1, czyli drugim elemencie liczą od początku (w tablicy
    // temu elementowi odpowiada index = 1, czyli a[1]).
    for (int i = n - 1; i >= 1; i--)
    {
        int m = i;
        // Tutaj podobnie. Odwróciliśmy kierunek przechodzenia i zaczynamy od
        // indeksu j = (i - 1), czyli elementu a[i - 1] a kończymy na pierwszym
        // w tabeli, czyli j = 0, czyli elemencie a[0].
        for (int j = i - 1; j >= 0; j--)
        {
            // Tutaj znowu podobnie. Ze względu, że zmienna j nie wzrasta a
            // maleje, więc musieliśmy zmienić operację porównania z < na >.
            // Najlepszym sposobem zrozumienia tych zmian jest wykonanie
            // tego programu w trybie debug tak, żeby móc śledzić przebieg
            // wykonwyania programu i wartości zmiennych i, j, m.
            if (a[j] > a[m])
            {
                m = j;
            }
        }
        int tmp = a[i];
        a[i] = a[m];
        a[m] = tmp;
    }
}

int main()
{
    int a[] = { 19, 1, 7, 39, 5 };
    int n = 5;

    sort_wybieranie_od_konca(a, n);

    cout << "Posortowane liczby niemalejąco: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;

    return 0;
}
