///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 8 ze strony 116.
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

int nwd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }

    return a;
}

int main()
{
    int n = 0;
    int m = 0;

    cout << "Podaj liczbę bombek w pudełku z dużymi bombkami" << endl;
    cin >> n;
    cout << "Podaj liczbę bombek w pudełku z małymi bombkami" << endl;
    cin >> m;

    // Aby wykorzystać wszystkie bombki z pudełek i żeby liczba
    // małych bombek i dużych była sobie równa stosujemy NWW.
    // Przykład: dla pudełek na 4 i 6 bombek mamy NWW=12 tzn. potrzebujemy
    // 3 pudełka po 4 bombki i 2 pudełka na 6 bombek.
    // Wzór na NWW to NWW(n, m) = (n * m) / NWD(n, m)

    int nww = (n * m) / nwd(n, m);
    // Liczba pudełek z dużymi bombkami.
    int pudelka_n = nww / n;
    // Liczba pudełek z małymi bombkami.
    int pudelka_m = nww / m;

    cout << "Potrzebujemy " << pudelka_n << " pudełka z dużymi bombkami"
         << " oraz " << pudelka_m << " pudełka z małymi bombkami" << endl;
    cout << endl;
    cout << "Sprawdźmy, czy się zgadaza." << endl;
    cout << "Całkowita liczba bombek dużych to " << n << "*" << pudelka_n << "=" << nww << endl;
    cout << "Całkowita liczba bombek małych to " << m << "*" << pudelka_m << "=" << nww << endl;

    return 0;
}
