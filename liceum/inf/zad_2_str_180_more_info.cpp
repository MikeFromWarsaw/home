///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 2 ze strony 180. Werjsa wyświetlające informację w konsoli
/// na temat przebiegu zmian w tablicy podczas sortowania.
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

void wyswietl_tablice(int a[], int n, int margines, string napis)
{
    // std::string(margines, ' ') to jest wcięcie, żeby nasz napis był
    // przesunięty w prawo dla lepszej prezentacji tego, co się dzieje
    // w pętlach.
    cout << std::string(margines, ' ') << napis << ": ";
    // Wyświetl aktualną zawartość tablicy
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// Zadanie wymaga, aby algorytm wyznaczał wpierw ostatni element, przedostatni,
// itd., czyli żeby sortował tablicę zaczynając od końca.
void sort_wybieranie_od_konca(int a[], int n)
{
    // Tutaj zmieniliśmy kierunek przechodzenia po elementach. Zaczynamy od
    // i = (n-1) czyli od ostatniego elementu
    // i kończymy na i = 1, czyli drugim elemencie liczą od początku (w tablicy
    // temu elementowi odpowiada index = 1, czyli a[1]).
    cout << "Pętla dla 'i' od " << (n-1)
         << " do 1" << endl;
    for (int i = n - 1; i >= 1; i--)
    {
        int m = i;
        // Tutaj podobnie. Odwróciliśmy kierunek przechodzenia i zaczynamy od
        // indeksu j = (i - 1), czyli elementu a[i - 1] a kończymy na pierwszym
        // w tabeli, czyli j = 0, czyli elemencie a[0].
        cout << "    Pętla dla 'j' od " << (i - 1) << " do 0" << endl;
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
        wyswietl_tablice(a, n, 8, "po zamianie");
    }
}

int main()
{
    int a[] = { 19, 1, 7, 39, 5 };
    int n = 5;

    wyswietl_tablice(a, n, 0, "Liczby przed sortowaniem");
    cout << endl;
    sort_wybieranie_od_konca(a, n);
    cout << endl;
    wyswietl_tablice(a, n, 0, "Posortowane liczby niemalejąco");

    return 0;
}
