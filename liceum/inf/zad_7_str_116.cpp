///////////////////////////////////////////////////////////////////////////////
/// Zadanie nr 7 ze strony 116.
///
/// Opis algorytmu z obrazkami znajdziesz w pliku o tej samej nazwie, ale z
/// roszerzeniem pdf.
///
/// W opisie kodu AxB oznacza prostokąt o bokach, którego zmienne w kodzie
/// są "a" i "b". Wielkie litery są użyte w celu poprawy widoczności.
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
    int a;
    int b;
    int liczba_wszystkich_kwadratow = 0;

    cout << "Wprowadź długość pierwszego boku prostokąta: " << endl;
    cin >> a;
    cout << "Wprowadź długość drugiego boku prostokąta: " << endl;
    cin >> b;

    // Program wyszukuje największe kwadraty BxB w prostokącie AxB a w kolejnej
    // iteracji (pętla do-while) powtarza proces dla prostokąta (częsci AxB),
    // który nie został zapełniony kwadratami. Długości boków nowego prostokąta
    // do zapełnienia to a % b i b.
    do
    {
        // Chcemy, aby a zawsze było >= b.
        if(a < b)
        {
            // a jest mniejsze od b, więc zamieniamy ich wartości ze sobą.
            int tmp = a;
            a = b;
            b = tmp;
        }
        // Wyświetl długości boków prostokąta.
        cout << "Długości boków prostokąta: a=" << a << ", b=" << b << endl;
        // Dłuższy bok prostokąta dzielimy krótszym bokiem otrzymując w ten
        // sposób liczbę największych prostokątów, które mogą się zmieścić w
        // prostokącie AxB. Oczywiście najczęściej część tego prostokąta AxB
        // nie zostanie wypełniona (jeszcze), ale zadanie przewiduje możliwość
        // wypełniania prostokąta AxB kwadratami różnej wielkości.
        int liczba_kwadratow = a / b;
        cout << "Wstawiamy " << liczba_kwadratow << " kw. o wymiarach " << b << "x" << b  << endl;
        // Zwiększamy licznik wszystkich wkadratów wstawionych do prostokąta AxB.
        liczba_wszystkich_kwadratow += liczba_kwadratow;
        // Prostokąt AxB został zapełniony kwadratami BxB, więc pora policzyć,
        // ile jeszcze zostało do wypełnienia. Nową wartość a uzyskujemy przez
        // wyliczenie reszty z dzielenia a przez b.
        a = a % b;
        // W tym momencie mamy nową parę liczb a, b wyznaczającą pozostały
        // do podzielenia prostokąt.
        // Jeśli jednak a == 0, to oznacza, że nie było reszty i że prostokąt,
        // który właśnie wypełniliśmy kwadratami BxB został w pełni wypełniony.
    }
    while (a != 0);
    // a == 0, więc już nie ma nic do dzielenia!
    cout << endl;
    cout << "Liczba wszystkich kwadratow to " << liczba_wszystkich_kwadratow << endl;

    return 0;
}
