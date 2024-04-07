///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 1 ze strony 180. Wersja dla zaawansowanych z przekazywaniem
/// funkcji porównującej 2 liczby.
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

// Porównuje a z b. Jeśli a > b, to zwraca true, w przeciwnym razie false.
// Zauważ, że jeśli chciałbyś posortować w inny sposób, to wystarczy zmieć
// warunek w tej funkcji lub po prostu stwórz drugą funkcje z innym warunkiem.
bool porownaj_jednosci_niemalejaco(int a, int b)
{
    return (a % 10) > (b % 10);
}

// Sortuje liczby całkowite za pomocą algorytmu sortowania bąbelkowego.
// Ostanim argumentem funkcji jest porownaj, to zmienna, która będzie wskazywała
// funkcję porównującą w algorytmie.
// Gdyby Twoj kompilator nie akceptowałby deklaracji tej funkcji, to możesz
// ją zamienić na
// void sortuj_babelkowo(int a[], int n, bool (*porownaj)(int, int))
void sortuj_babelkowo(int a[], int n, bool porownaj(int, int))
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
    int a[] = { 19, 4, 33, 111, 0, 20 };
    int n = 6;

    cout << "Liczby przed sortowaniem: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }

    cout << endl << "Sortuję..." << endl;

    // Użyjmy sortowania bąbelkowego.
    sortuj_babelkowo(a, 6, porownaj_jednosci_niemalejaco);

    cout << "Posortowane liczby niemalejąco po najmniejszej liczbie jedności: "
         << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;

    cout << "Jak algorytm \"widział\" te liczby, gdy je porównywał?: "
         << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << (a[i] % 10) << ", ";
    }
    cout << endl;

    return 0;
}
