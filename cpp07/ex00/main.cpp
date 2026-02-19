#include <iostream>
#include <string>
#include "template.h" // Remplace par le nom de ton header

// --- Petite classe de test façon "Moulitest" ---
// Cette classe sert à vérifier que tes templates marchent avec des objets complexes,
// à condition que ces objets aient bien surchargé les opérateurs de comparaison !
class Awesome {
public:
    Awesome(int n) : _n(n) {}
    
    // On surcharge les opérateurs pour que ::min et ::max puissent comparer deux 'Awesome'
    bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
    bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
    
    int get_n() const { return _n; }

private:
    int _n;
};

// Surcharge de l'opérateur << pour pouvoir afficher un objet Awesome avec std::cout
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
// ----------------------------------------------

int main(void) {
    std::cout << "--- TESTS BASIQUES (Sujet 42) ---" << std::endl;
    int a = 2;
    int b = 3;
    
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "\n--- TESTS CLASSE COMPLEXE (Awesome) ---" << std::endl;
    Awesome aw1(21);
    Awesome aw2(42);

    std::cout << "Avant swap: aw1 = " << aw1 << ", aw2 = " << aw2 << std::endl;
    ::swap(aw1, aw2);
    std::cout << "Apres swap: aw1 = " << aw1 << ", aw2 = " << aw2 << std::endl;
    std::cout << "Max entre aw1 et aw2: " << ::max(aw1, aw2) << std::endl;
    std::cout << "Min entre aw1 et aw2: " << ::min(aw1, aw2) << std::endl;

    return 0;
}