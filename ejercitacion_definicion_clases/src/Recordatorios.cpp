#include <iostream>
#include <string>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

/* Ejercicio 7 */

/* Clase Fecha */
class Fecha {
  public:
    /* Completar declaraciones funciones */
    Fecha(int mes, int dia);
    int mes();
    int dia();
    bool operator==(Fecha o); // Para ejercicio 9
    void incrementar_dia(); // Para ejercicio 10


  private:
    /* Completar miembros internos */
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia){};

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

/* Ejercicio 8 */

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" <<  f.mes();
    return os;
}

/* Ejercicio 9 */

bool Fecha::operator==(Fecha o) {
    /* Completar iguadad (ej 9) */
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();

    return igual_dia && igual_mes;
}

/* Ejercicio 10 */

void Fecha::incrementar_dia(){
    if(dias_en_mes(mes_) == dia_){
        /* Caso del ultimo dia del mes */
        dia_ = 1;
        mes_++;
    } else {
        /* Cualquier otro caso */
        dia_++;
    }
}

/* Ejercicio 11 */

/* Clase Horario */
class Horario {
public:
    /* Completar declaraciones funciones */
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);
    bool operator<(Horario h);

private:
    /* Completar miembros internos */
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min){};

uint Horario::hora() {
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool igual_min = this->min() == o.min();

    return igual_hora && igual_min;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" <<  h.min();
    return os;
}

/* Ejercicio 12 */

bool Horario::operator<(Horario h) {
    if(this->hora() == h.hora()){
        return this->min() < h.min();
    } else {
        return this->hora() < h.hora() ;
    }
}

/* Ejercicio 13 */

/* Clase Recordatorio */
class Recordatorio {
public:
    /* Completar declaraciones funciones */
    Recordatorio(Fecha f, Horario h, string mensaje);
    Fecha fecha();
    Horario hora();
    string mensaje();

    bool operator==(Horario o);
    bool operator<(Horario h);


private:
    /* Completar miembros internos */
    Fecha fecha_;
    Horario hora_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string mensaje): fecha_(f), hora_(h), mensaje_(mensaje) {};

Fecha Recordatorio::fecha(){
    return fecha_;
}

Horario Recordatorio::hora(){
    return hora_;
}

string Recordatorio::mensaje(){
    return mensaje_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " " << "@" << " " <<  r.fecha() << " " <<  r.hora();
    return os;
}

/* Ejercicio 14 */

/* Clase Agenda */
class Agenda {
public:
    /* Completar declaraciones funciones */
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();

    int encontrarMinHorario(vector<Recordatorio> &vrec, int desde, int hasta);
    void intercambiar(vector<Recordatorio> &lrec, int indice, int minimo);
    void ordenarPorHora(vector<Recordatorio> &lrec);
    vector<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    /* Completar miembros internos */
    vector<Recordatorio> agenda_;
    Fecha fecha_actual_;
};

Agenda::Agenda(Fecha fecha_inicial) : fecha_actual_(fecha_inicial), agenda_() {};

void Agenda::agregar_recordatorio(Recordatorio rec){
    agenda_.push_back(rec);
}

void Agenda::incrementar_dia() {
    fecha_actual_.incrementar_dia();

}

int Agenda::encontrarMinHorario(vector<Recordatorio> &vrec, int desde, int hasta){
    int min = desde;
    for(int i = desde+1; i < hasta; i++){
        if(vrec[i].hora() < vrec[min].hora()){
            min = i;
        }
    }
    return min;
}

void Agenda::intercambiar(vector<Recordatorio> &lrec, int indice, int minimo){
    Recordatorio tmp = lrec[indice];
    lrec[indice] = lrec[minimo];
    lrec[minimo] = tmp;
}

void Agenda::ordenarPorHora(vector<Recordatorio> &lrec){
    for(int i = 0; i < lrec.size(); i++){
        int minHorario = encontrarMinHorario(lrec, i, lrec.size());
        intercambiar(lrec, i, minHorario);
    }

}

vector<Recordatorio> Agenda::recordatorios_de_hoy(){
    vector<Recordatorio> recordatoriosHoy;

    /* Se recorre toda la agenda, se compara la fecha actual con la de los recordatorios y cuando coincidad, se agregan a la lista */
    for(Recordatorio r: agenda_){
        if(fecha_actual_ == r.fecha()){
            recordatoriosHoy.push_back(r);
        }
    }
    ordenarPorHora(recordatoriosHoy);
    return recordatoriosHoy;
}

Fecha Agenda::hoy(){
    return fecha_actual_;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    vector<Recordatorio> recordatoriosDiaActualOrdenados = a.recordatorios_de_hoy();
    for(Recordatorio rec: recordatoriosDiaActualOrdenados){
        os << rec << endl;
    }
    return os;
}



