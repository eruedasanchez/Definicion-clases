#include <iostream>

using namespace std;

using uint = unsigned int;

/* Ejercicio 1 */

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        uint alto_;
        uint ancho_;
};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho){};

uint Rectangulo::alto() {
    return alto_;
}

/* Completar definición: ancho */
uint Rectangulo::ancho() {
    return ancho_;
}

/* Completar definición: area */
float Rectangulo::area() {
    return (ancho_ * alto_) / 2;
}

/* Ejercicio 2 */

/* Clase Elipse */
class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();

    private:
    uint r_a_;
    uint r_b_;
};

Elipse::Elipse(uint a, uint b) : r_a_(a), r_b_(b) {};

uint Elipse::r_a(){
    return r_a_;
}

uint Elipse::r_b(){
    return r_b_;
}

float Elipse::area(){
    float PI = 3.14;
    return PI * r_a_ * r_b_;
}

/* Ejercicio 3 */

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    /* Completar */
    return r_.ancho();
}

float Cuadrado::area() {
    /* Completar */
    return r_.ancho() * r_.alto();
}

/* Ejercicio 4. Clase Circulo */

class Circulo {
public:
    Circulo(uint rd);
    uint radio();
    float area();

private:
    Elipse e_;
};

Circulo::Circulo(uint rd): e_(rd, rd) {}

uint Circulo::radio() {
    /* Completar */
    return e_.r_a();
}

float Circulo::area() {
    /* Completar */
    float PI = 3.14;
    return PI * e_.r_a() * e_.r_b();
}

/* Ejercicio 5 */

/* ostream Rectangulo */
ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

/* ostream Elipse */
ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

/* Ejercicio 6 */

/* ostream Cuadrado */
ostream& operator<<(ostream& os, Cuadrado cuad) {
    os << "Cuad(" << cuad.lado()  << ")";
    return os;
}

/* ostream Circulo */
ostream& operator<<(ostream& os, Circulo circ) {
    os << "Circ(" << circ.radio() << ")";
    return os;
}
