///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 4 ze strony 115.
///
/// Kod zawiera polskie znaki zapisane jako UTF-8. Jeśli w Twoim edytorze lub
/// linii poleceń nie wyświetlają się prawidłowo, to możesz ich się pozbyć.
///
/// W kodzie zawartym w podręczniku nie sprawdza się poprawności wartości
/// argumentów funkcji, stąd i tutaj stosowane jest to podejście.
/// Prawdopodobnie ma to na celu poprawienie przejrzystości kodu, czyli skupienie
/// uwagi ucznia na samym algorytmie a nie przetwarzaniu błędów oraz - być może
/// - zmniejszenie zawartości kodu w książce.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// NWD liczb a i b.
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

struct wymierna
{
    int licznik;
    int mianownik;
};

int main()
{
    wymierna w;

    cout << "Podaj licznik: ";
    cin >> w.licznik;
    cout << "Podaj mianownik (większy od zera): ";
    cin >> w.mianownik;

    int n = nwd(w.licznik, w.mianownik);

    w.licznik = w.licznik / n;
    w.mianownik = w.mianownik / n;

    // Sprawdź, czy to jest ułamek właściwy.
    cout << "Ułamek po skróceniu: ";
    cout << w.licznik << "/" << w.mianownik << endl;

    if (w.licznik < w.mianownik)
    {
        // Ułamek właściwy.
        cout << "Jest to ułamek właściwy." << endl;
    }
    else
    {
        // Ułamek niewłaściwy.
        cout << "Jest to ułamek niewłaściwy." << endl;
        // Pamiętajmy, że dzielenie licz całkowitych (typ int) zawsze i tylko
        // zwraca liczby całkowite, czyli 5 / 3 zwróci 1. Resztę z tego
        // dzielenia można uzyskać stosując operator modulo % w ten sposób
        // 5 % 3, który zwróci 2.
        int czesc_calkowita = w.licznik / w.mianownik;
        cout << "Część całkowita ułamka: " << czesc_calkowita << endl;
        // W celu wyznaczenia licznika nowego ułamka musimy znaleźć resztę z
        // dzielenia w.licznik przez w.mianownik.
        int licznik = w.licznik % w.mianownik;
        // Wyświetl liczbę mieszaną, ale gdy licznik nowego ułamka jest różny
        // od zera, bo jeśli jest równy zero, to mamy tylko część całkowitą.
        // Możesz to sprawdzić to podając licznik 15 i mianownik 5.
        if (licznik != 0)
        {
            // Wyświetlmy ułamek niewłaściwy w postaci liczby mieszanej, czyli
            // całości i ułamka właściwego.
            cout << "W postaci liczby mieszanej: "
                 << czesc_calkowita << " " << licznik << "/" << w.mianownik;
        }
    }
    return 0;
}
