

float dodawanie_inne()
{
    float a;
    std::cin >> a;
    float b;
    std::cin >> b;
    return a + b;
}

int main()
{
    std::cout << "Wprowadz dwie liczby: ";
    float tu_bedzie_wynik = dodawanie_inne();
    std::cout << "Wynik dodawania wynosi: " << tu_bedzie_wynik << std::endl;
    return 0;
}
