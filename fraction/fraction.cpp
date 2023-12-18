#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
};

// ���������� ��������� ������ ��� ������ �����
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.getNumerator() << "/" << fraction.getDenominator();
    return os;
}

int main() 
{
    setlocale(LC_ALL, "");
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction quot = f1 / f2;

    std::cout << "�����: " << sum << std::endl;
    std::cout << "��������: " << diff << std::endl;
    std::cout << "������������: " << prod << std::endl;
    std::cout << "�������: " << quot << std::endl;

    return 0;
}