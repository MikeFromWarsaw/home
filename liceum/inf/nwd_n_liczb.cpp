///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 2 ze strony 115.
///
/// Kod zawiera polskie znaki zapisane jako UTF-8. Jeśli w Twoim edytorze lub
/// linii poleceń nie wyświetlają się prawidłowo, to możesz się ich pozbyć.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

/// Funkcja oblicza NWD dwóch liczb.
/// Uwagi:
/// Algorytm nie używa reszty z dzielenia (%) w celu przyspieszenia obliczeń
/// oraz nie jest zoptymalizowany. Wszystko po to, aby algorytm był czytelny
/// dla osób niezbyt obeznanych z tematem, gdyż to zadanie tylko wykorzystuje
/// algorytn NWD i wymaga dodatkowej pracy.
/// Należy podkreslić, że funkcja nwd różniew nie sprawdza poprawności
/// wprowadzonych danych, gdyż możliwe jest przekazanie a i b <= 0. Jest to
/// spowodowane potrzebą skupienia się na samym algorytmie, co zresztą czynione
/// jest także w książce, z której pochodzi to zadanie.
int nwd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return b;
}

int main()
{
    // Zakładamy, że pozwalamy policzyć NWD dla maksymalnie 20 liczb, stąd
    // tablica z liczbami zawiera 20 elementów typu integer (całkowitego).
    int liczby[20];
    // Liczba oczekiwanych liczb.
    int n = 0;

    cout << "Dla ilu liczb chcesz policzyć NWD? Wprowadź wartość od 1 do 20: ";
    cin >> n;
    cout << endl;

    // Poproś o wartości n liczb. Pamiętaj, że w tym kodzie poprawność
    // wprowadzanych liczb nie jest weryfikowana w celu przejrzystości kodu,
    // który ma pokazać działanie algorytmu.
    for (int i = 0; i < n; ++i)
    {
        cout << "Wprowadź liczbę nr " << (i + 1) << ":";
        cin >> liczby[i];
        cout << endl;
    }

    // Teraz w tablicy liczby mamy n liczb. Teoria mówi tak, że mając n liczb
    // możemy policzyć NWD dla nich wszystkich w następujący sposób:
    //
    // wynik = NWD(liczba_1, liczba_2)
    // wynik = NWD(wynik, liczba_3)
    // wynik = NWD(wynik, liczba_4)
    // ...
    // wynik = NWD(wynik, liczba_N)

    // Policzmy 2 pierwsze liczby.
    int last_nwd = nwd(liczby[0], liczby[1]);
    // Wyświetlamy pierwsze obliczenie.
    cout << "NWD(" << liczby[0] << ", " << liczby[1] << ") to " << last_nwd << endl;

    // Kolejne obliczenia, gdzie argumentami NWD są kolejne liczby oraz ostatni
    // wynik NWD.
    for (int i = 2; i < n; ++i)
    {
        cout << "NWD(" << last_nwd << ", " << liczby[i] << ") to ";
        last_nwd = nwd(last_nwd, liczby[i]);
        cout << last_nwd << endl;
    }

    cout << "Wynik NWD(";
    for (int i = 0; i < n; ++i)
    {
        cout << liczby[i];
        if (i < (n - 1))
        {
            cout << ",";
        }
    }
    cout << ") to " << last_nwd << endl;

    return 0;
}
