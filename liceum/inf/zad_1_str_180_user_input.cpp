///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 1 ze strony 180. Werjsa z wprowadzaniem danych przez użytkownika.
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


int main()
{
    int a[20];
    int n = 0;
    cout << "Podaj liczbę elementów tablicy (maks. 20): ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "Podaj wartość " << (i + 1) << " elementu: ";
        cin >> a[i];
    }
    cout << "Wrowadziłeś następujące wartości: ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }

    cout << endl << "Sortuję..." << endl;

    // Użyjmy sortowania bąbelkowego.
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            // Ten warunek decyduje, czy elementy/wartości zamienią się
            // miejscami. W zadaniu jest wymaganie, że liczby mamy posortować
            // niemalejąco po najmniejszej cyfrze jedności. Możemy to zrobić
            // dzieląc każdą z liczb w tym warunku przez 10 i porównując resztę
            // z dzielenia.
            // Przykład:
            // Jeśli a[j] równałby się 14 a a[j + 1] równałby się 9, to
            // to mielibyśmy (14 % 10) > (9 % 10) a po wyliczeniu 4 > 9, czyli
            // nierówność byłaby fałszywa i liczby nie zostałby zamienione.
            if ((a[j] % 10) > (a[j + 1] % 10))
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

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
