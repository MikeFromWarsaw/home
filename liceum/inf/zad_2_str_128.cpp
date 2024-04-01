///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 2 ze strony 128.
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

// Poniżej jest przedstawiona część tablicy ze znakami (US-ASCII) i
// odpowiadającymi im wartościami liczbowymi. Znak widoczny w tekście w
// rzeczywistości jest liczbą zapisaną na jednym bajcie (1 bajt to 8 bitów) w
// pliku lub w pamięci komputera.
// Należy zauważyć, że litery A-Z oraz a-z ułożone są w kolejności alfabetycznej,
// stąd ich położenie można np. wyznaczyć względem 'A' dla liter A-Z i 'a' dla
// a-z. 'B' jest położna względem 'A' o 1 pozycję, 'C' o 2 pozycje itd. Ta
// obserwacja jest ważna, żeby zrozumieć implementację alogrytmu Cezara
// przedstawioną w książce.
//
// Znaki US-ASCII i odopowiadjące im ich kody (wartości liczbowe).
// ...
//  32 => ' ',  33 => '!',  34 => '"',  35 => '#',  36 => '$',  37 => '%',
//  38 => '&',  39 => ''',  40 => '(',  41 => ')',  42 => '*',  43 => '+',
//  44 => ',',  45 => '-',  46 => '.',  47 => '/',  48 => '0',  49 => '1',
//  50 => '2',  51 => '3',  52 => '4',  53 => '5',  54 => '6',  55 => '7',
//  56 => '8',  57 => '9',  58 => ':',  59 => ';',  60 => '<',  61 => '=',
//  62 => '>',  63 => '?',  64 => '@',  65 => 'A',  66 => 'B',  67 => 'C',
//  68 => 'D',  69 => 'E',  70 => 'F',  71 => 'G',  72 => 'H',  73 => 'I',
//  74 => 'J',  75 => 'K',  76 => 'L',  77 => 'M',  78 => 'N',  79 => 'O',
//  80 => 'P',  81 => 'Q',  82 => 'R',  83 => 'S',  84 => 'T',  85 => 'U',
//  86 => 'V',  87 => 'W',  88 => 'X',  89 => 'Y',  90 => 'Z',  91 => '[',
//  92 => '\',  93 => ']',  94 => '^',  95 => '_',  96 => '`',  97 => 'a',
//  98 => 'b',  99 => 'c', 100 => 'd', 101 => 'e', 102 => 'f', 103 => 'g',
// 104 => 'h', 105 => 'i', 106 => 'j', 107 => 'k', 108 => 'l', 109 => 'm',
// 110 => 'n', 111 => 'o', 112 => 'p', 113 => 'q', 114 => 'r', 115 => 's',
// 116 => 't', 117 => 'u', 118 => 'v', 119 => 'w', 120 => 'x', 121 => 'y',
// 122 => 'z', 123 => '{', 124 => '|', 125 => '}', 126 => '~',
// ...
// Z pewnych względów pozostałe znaki nie zostały tutaj przedstawione
// (np. polskie), gdyż nie jest to przedmiotem zadania oraz dodatkowo mogłoby
// komplikować zadanie.

// Zerknijmy na litery A-Z i ich pozycje w tabeli ASCII. Jak widać, ich
// reprezentacje liczbowe są zależne od położenia liter w alfabecie.
//
// 65 => 'A',
// 66 => 'B',
// 67 => 'C',
// 68 => 'D',
// 69 => 'E',
// 70 => 'F',
// 71 => 'G',
// 72 => 'H',
// 73 => 'I',
// 74 => 'J',
// 75 => 'K',
// 76 => 'L',
// 77 => 'M',
// 78 => 'N',
// 79 => 'O',
// 80 => 'P',
// 81 => 'Q',
// 82 => 'R',
// 83 => 'S',
// 84 => 'T',
// 85 => 'U',
// 86 => 'V',
// 87 => 'W',
// 88 => 'X',
// 89 => 'Y',
// 90 => 'Z',

// Przechodząc do szyfru Cezara mamy:
//
// Jeśli klucz = 0, to:
// 'A' po zaszyfrowaniu jest 'A'
// 'B' po zaszyfrowaniu jest 'B'
// 'C' po zaszyfrowaniu jest 'C'
// ...
// 'Y' po zaszyfrowaniu jest 'Y'
// 'Z' po zaszyfrowaniu jest 'Z'

// Jeśli klucz = 1, to:
// 'A' po zaszyfrowaniu jest 'B'
// 'B' po zaszyfrowaniu jest 'C'
// 'C' po zaszyfrowaniu jest 'D'
// ...
// 'Y' po zaszyfrowaniu jest 'Z'
// 'Z' po zaszyfrowaniu jest 'A'

// Jeśli klucz = 2, to:
// 'A' po zaszyfrowaniu jest 'C'
// 'B' po zaszyfrowaniu jest 'D'
// 'C' po zaszyfrowaniu jest 'E'
// ...
// 'Y' po zaszyfrowaniu jest 'A'
// 'Z' po zaszyfrowaniu jest 'B'

// Jeśli klucz = 25, to:
// 'A' po zaszyfrowaniu jest 'Z'
// 'B' po zaszyfrowaniu jest 'A'
// 'C' po zaszyfrowaniu jest 'B'
// ...
// 'Y' po zaszyfrowaniu jest 'X'
// 'Z' po zaszyfrowaniu jest 'Y'

// Jeśli klucz = 26, to:
// 'A' po zaszyfrowaniu jest 'A'
// 'B' po zaszyfrowaniu jest 'B'
// 'C' po zaszyfrowaniu jest 'C'
// ...
// 'Y' po zaszyfrowaniu jest 'Y'
// 'Z' po zaszyfrowaniu jest 'Z'

// Obserwacja:
// W szyfrze Cezara klucz jest przesunięciem pozycji litery w alfabecie. Jeśli
// klucz wnosi 0, 26, 52, itd. to 'A' odpowiada 'A', więc
// litery przez zaszyfrowaniem po zaszyfrowaniu są takie same, czyli nasz
// tekst nie będzie zaszyfrowany.
//
// Obserwacja:
// W algorytmie szyfru Cezara pojawia się rotacja alfabetu wykorzystywanego
// do szyfrowania tekstu. Poniżej pokazane jest jak każda litera zamieniana
// jest na odpowiadającą jej zaszyfrowaną postać.
//
// Klucz = 1
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    ZABCDEFGHIJKLMNOPQRSTUVWXY
//
// Klucz = 2
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    YZABCDEFGHIJKLMNOPQRSTUVWX
//
// Klucz = 3
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    XYZABCDEFGHIJKLMNOPQRSTUVW
//
// ...
//
// Klucz = 25
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    BCDEFGHIJKLMNOPQRSTUVWXYZA
//
// Klucz = 26
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    ABCDEFGHIJKLMNOPQRSTUVWXYZ
//
// Jeśli klucz będzie wartością ujemną, to dla przykładu klucz=-1 oznacza, że
// zaszyfrowaną literą A jest litera Z, bo jest na pozycji -1 względem A.
//
// Klucz = -1
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    ZABCDEFGHIJKLMNOPQRSTUVWXY
//
// Klucz = -2
// Przed: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Po:    YZABCDEFGHIJKLMNOPQRSTUVWX
//
// itd.
//
// Można zauważyć, że ujemna wartość klucza odpowiada dodatniej w następujący
// sposób:
// Przy założeniu, że klucz > -26, to klucz = klucz + 26
// Jeśli klucz może być dowolną liczbą ujemną, to musimy skorzystać z funkcji
// modulo i wtedy mamy, gdy klucz < 0, to klucz = (klucz % 26) + 26.


#define LICZBA_LITER_W_ALFABECIE 26

string zaszyfruj(string wiadomosc, int klucz)
{
    string zaszyfrowana_wiadomosc;

    // Klucz może być wartością ujemną, co oznacza, że nowa_pozycja
    // może mieć wartość ujemą (reszta z dzielenia liczby ujemnej jest
    // liczbą ujemną).
    klucz = klucz % LICZBA_LITER_W_ALFABECIE;
    // W tym miejscu klucz może mieć wartość <-25,+25>
    if (klucz < 0)
    {
        klucz += LICZBA_LITER_W_ALFABECIE;
    }
    // W tym miejscu klucz będzie wartością od 0 do 25.

    for (int i = 0; i < wiadomosc.size(); i++)
    {
        // Pobierzmy znak, który jest tekście na i-tej pozycji.
        // Dzięki temu kod będzie bardziej czytelny.
        char znak = wiadomosc[i];

        // Chcemy szyfrować tylko wielkie litery alfabetu.
        if (znak >= 'A' && znak <= 'Z')
        {
            int pozycja_znaku_wzgledem_A = znak - 'A';
            // Określamy pozycję litery w alfabecie, która będzie
            // literą reprezentującą zaszyfrowany znak zawarty w zmiennej 'znak'
            int nowa_pozycja = (pozycja_znaku_wzgledem_A + klucz) % LICZBA_LITER_W_ALFABECIE;
            zaszyfrowana_wiadomosc += char('A' + nowa_pozycja);
        }
        else
        {
            // Tego znaku nie szyfrujemy.
            zaszyfrowana_wiadomosc += znak;
        }
    }

    return zaszyfrowana_wiadomosc;
}

int main()
{
    string zaszyfrowana_wiadomosc;
    string wiadomosc;
    int klucz = 0;

    cout << "Napisz wiadomość (szyfrowane będą tylko wielkie litery):" << endl;
    // Tutaj używamy funkcji 'getline' gdyż umożliwia wczytanie tekstu
    // zawierającego spacje. W przeciwnym razie użycie tylko cin spowodowałoby,
    // że wiadomość skończyłaby się na pierwszej napotkanej spacji.
    getline(cin, wiadomosc);

    cout << "Wprowadź klucz dla szyfru Cezara, którym chcesz zaszyfrować wiadomość."
         << endl
         << "Klucz musi być dodatnią lub jemną liczbą całkowitą"
         << endl;

    cin >> klucz;

    string zaszyfrowana = zaszyfruj(wiadomosc, klucz);

    cout << "Zaszyfrowana wiadomość:" << endl;
    cout << zaszyfrowana;
    cout << endl;



    return 0;
}
