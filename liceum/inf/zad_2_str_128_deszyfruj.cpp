///////////////////////////////////////////////////////////////////////////////
/// Program deszyfruje wiadomosci zaszyfrowane w zadaniu nr 2 ze strony 128.
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

// Funkcja odszyfrowuje wiadomość zaszyfrowaną szyfrem Cezara.
// Klucz powinien być liczbą całkowitą od 0 do 25, bo każda inna wartość,
// ujemna, czy dodatania, większa od 26 lub mniejsza, i tak finalnie jest
// zamieniana na wartość od 0 do 25, gdzie 0 oznacza faktycznie brak szyfrowania.
string odszyfruj_AZ(string zaszyfrowana, int klucz)
{
    // Odszyfrowana wiadomość.
    string odszyfrowana;

    for (int i = 0; i < zaszyfrowana.size(); i++)
    {
        char znak = zaszyfrowana[i];

        if (znak >= 'A' && znak <= 'Z')
        {
            // Pozycja zaszyfrowanej litery względem litery 'A'.
            int poz_po_zaszyf = znak - 'A';
            // Przy szyfrowaniu kluczem wybieraliśmy literę oddaloną od
            // od litery do zaszyfrowania o liczbę pozycji równą zmiennej klucz
            // licząc w prawą stronę. W tym przypadku odszyfrowujemy, stąd
            // szukamy litery oddalonej od litery zaszyfrowanej na lewo od niej,
            // stąd odejmujemy wartość klucza.
            int poz_przed_zaszyf = (poz_po_zaszyf - klucz) % 26;
            // Pozycja odszyfrowanej litery wychodzi nam ujemna, to musimy
            // przesunąć ją dodatkowo o długść alfabetu.
            if (poz_przed_zaszyf < 0)
            {
                poz_przed_zaszyf += 26;
            }
            // Wyżej przedstawione operacje można również zapisać w taki sposób
            // int poz_przed_zaszyf = (poz_po_zaszyf - klucz + 26) % 26;
            // Ta wersja jest krótsza, ale może być mniej jasna dla początkujących.

            // Wyznacz literę oddaloną od litery 'A' o 'poz_przed_zaszyf' miejsc.
            // Korzystamy z funkcji char(...) która pozwala nam zamienić
            // liczbę na znak.
            char odszyfrowany_znak = char('A' + poz_przed_zaszyf);
            odszyfrowana += odszyfrowany_znak;
        }
        else
        {
            odszyfrowana += znak;
        }
    }

    return odszyfrowana;
}
int main()
{
    cout << "Podaj zaszyfrowaną wiadomość:" << endl;
    string zaszyfrowana_wiadomosc;
    // Pobierz wiadomość, która może zawierać spacje.
    getline(cin, zaszyfrowana_wiadomosc);

    for (int klucz = 0; klucz < 26; klucz++)
    {
        cout << "Odszyfrowuję dla klucza " << klucz << endl;
        string odszyfrowana = odszyfruj_AZ(zaszyfrowana_wiadomosc, klucz);
        cout << odszyfrowana << endl;
    }

    return 0;
}
