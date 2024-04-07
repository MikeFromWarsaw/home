///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 3 ze strony 180.
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
    cout << napis << ": ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}
void sort_bubble(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool nastapila_zamiana_liczb = false;
        for (int j = 0; j < (n - i); j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                nastapila_zamiana_liczb = true;
            }

        }
        if (nastapila_zamiana_liczb == false)
        {
            cout << "W pętli wewnętrznej nie nastąpiła zamiana liczb, więc kończymy sortowanie na i = "
                 << i << "." << endl;
            // Nie ma potrzeby kontynuowania kolejnych operacji
            // sortowania bąbelkowego, gdyż w tej iteracji nie było
            // żadnej zmiany, co oznacza, że liczby już są posortowane.

            // Return powoduje, że w tym miejscu funkcja kończy swoje
            // działanie. Ta funkcja nie zwraca żadnej wartości (patrz
            // definicja tej funkcji ze słowem 'void'), więc słowem 'return'
            // stawiamy tylko średnik.
            return;
        }
    }
}

int main()
{
    int a[] = { 1, 1, 7, 3, 5 };
    int n = 5;

    wyswietl_tablice(a, 5, "Liczby przed sortowaniem");
    sort_bubble(a, n);
    wyswietl_tablice(a, 5, "Liczby po sortowaniu");

    return 0;
}
