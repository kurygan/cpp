#include <iostream>
#include "Fixed.hpp"

// Une petite macro pour tester les booléens proprement
#define BOOL_STR(b) (b ? "True" : "False")

int main( void ) {

    std::cout << "\033[1;34m=== PARTIE 1 : MAIN DU SUJET (OBLIGATOIRE) ===\033[0m" << std::endl;
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;

        std::cout << b << std::endl;

        std::cout << Fixed::max( a, b ) << std::endl;
    }

    std::cout << std::endl << "\033[1;34m=== PARTIE 2 : TESTS PERSO (COACH 42) ===\033[0m" << std::endl;
    
    Fixed x(10);
    Fixed y(20);
    Fixed z(10);

    // --- Comparaisons ---
    std::cout << "\033[1;33m--- Tests de Comparaison ---\033[0m" << std::endl;
    std::cout << "x (" << x << ") > y (" << y << ") : " << BOOL_STR(x > y) << std::endl;
    std::cout << "x (" << x << ") < y (" << y << ") : " << BOOL_STR(x < y) << std::endl;
    std::cout << "x (" << x << ") >= z (" << z << ") : " << BOOL_STR(x >= z) << std::endl;
    std::cout << "x (" << x << ") <= y (" << y << ") : " << BOOL_STR(x <= y) << std::endl;
    std::cout << "x (" << x << ") == z (" << z << ") : " << BOOL_STR(x == z) << std::endl;
    std::cout << "x (" << x << ") != y (" << y << ") : " << BOOL_STR(x != y) << std::endl;

    // --- Arithmétique ---
    std::cout << std::endl << "\033[1;33m--- Tests Arithmétiques ---\033[0m" << std::endl;
    Fixed res;
    
    res = y + x;
    std::cout << "Addition (20 + 10) : " << res << " (Attendu: 30)" << std::endl;
    
    res = y - x;
    std::cout << "Soustraction (20 - 10) : " << res << " (Attendu: 10)" << std::endl;
    
    res = x * y;
    std::cout << "Multiplication (10 * 20) : " << res << " (Attendu: 200)" << std::endl;
    
    res = y / x;
    std::cout << "Division (20 / 10) : " << res << " (Attendu: 2)" << std::endl;

    // Test multiplication decimales
    Fixed f1(2.5f);
    Fixed f2(2.0f);
    std::cout << "Mult Float (2.5 * 2.0) : " << (f1 * f2) << " (Attendu: 5)" << std::endl;

    // --- Incrémentation / Décrémentation (les oubliés du sujet) ---
    std::cout << std::endl << "\033[1;33m--- Tests Décrémentation ---\033[0m" << std::endl;
    Fixed d(42.42f);
    std::cout << "Base : " << d << std::endl;
    std::cout << "Pre-dec (--d) : " << --d << " (Modifie et retourne)" << std::endl;
    std::cout << "Post-dec (d--) : " << d-- << " (Retourne copie puis modifie)" << std::endl;
    std::cout << "Final : " << d << std::endl;

    // --- Min / Max ---
    std::cout << std::endl << "\033[1;33m--- Tests Min/Max ---\033[0m" << std::endl;
    std::cout << "Min(10, 20) : " << Fixed::min(x, y) << std::endl;
    std::cout << "Max(10, 20) : " << Fixed::max(x, y) << std::endl;

    return 0;
}