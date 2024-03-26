///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 3 ze strony 115.
///
/// Kod zawiera polskie znaki zapisane jako UTF-8. Jeśli w Twoim edytorze lub
/// linii poleceń nie wyświetlają się prawidłowo, to możesz ich się pozbyć.
///
/// W kodzie zawartym w podręczniku nie sprawdza się poprawności wartości
/// argumentów funckcji, stąd i tutaj stosowanae jest to podejście.
/// Prawdopodobnie ma to na celu poprawienie przejrzystości kodu, czyli skupienie
/// uwagi ucznia na samym algorytmie a nie przetwarzaniu błędów oraz zmniejszenie
/// zawartości kodu w książce.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// Funkcja liczy NWD liczb a i b.
// Oczywiście tę implementację można zastąpić szybszą wersją wykorzystującą
// operację modulo (resztę z dzielenia).
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
    int a, b;
    cout << "Wprowadź dlugości boków prostokąta." << endl;
    cout << "Wprowadź długość boku a w postaci liczby całkowitej dodatniej:" << endl;
    cin >> a;
    cout << "Wprowadź długość boku b w postaci liczby całkowitej dodatniej:" << endl;
    cin >> b;
    cout << "Podałeś boki o długości a=" << a << ", b=" << b << endl;

    // Oba boki prostokąta (a i b) muszą być podzielne (bez reszty) przez tę
    // samą liczbę, wtedy będziemy mieli prostokąt w pewni wypełniony
    // kwadratami. Dodatkowo chcemy, aby kwadratów było jak najmniej, stąd
    // musimy poszukać jak najdłużeszego boku kwadratu. Pomoże nam w tym NWD,
    // który znajdzie największy wspólny dzielnik boków a i b.
    int bok_kwadratu = nwd(a, b);

    // Mając długość boku kwadratu musimy znaleźć liczbę kwadratów, które
    // zmieszczą się prostokącie ab, więc mnożymy przez siebie liczbę kwadratów,
    // które zmieszczą się na boku a i liczbę kwadratów, które zmieszczą się na
    // boku b otrzymują liczbę wszystkich kwadratów wypełniającyh prostoką ab.
    int liczba_kwadratow = (a / bok_kwadratu) * (b / bok_kwadratu);

    cout << "Długość boku kwadratu wynosi: " << bok_kwadratu << endl;
    cout << "Liczba kwadratow w prostakacie wynosi: " << liczba_kwadratow << endl;

    return 0;
}
