#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Definire clase
// ******************************************************************************* //
class Locuinta {
private:
    string numeClient;
    int suprafataUtila;
    float discount;
public:
    // constructori & destructor
    Locuinta() {
        numeClient = '\0';
        suprafataUtila = NULL;
        discount = 0.0;
    }

    Locuinta(const string &numeClient, int suprafataUtila, float discount) : numeClient(numeClient),
                                                                             suprafataUtila(suprafataUtila),
                                                                             discount(discount) {

    }

    ~Locuinta() { }

    // getteri
    const string &getNumeClient() const {
        return numeClient;
    }

    int getSuprafataUtila() const {
        return suprafataUtila;
    }

    float getDiscount() const {
        return discount;
    }

    // setteri
    void setNumeClient(const string &numeClient_) {
        this->numeClient = numeClient_;
    }

    void setSuprafataUtila(int suprafataUtila_) {
        this->suprafataUtila = suprafataUtila_;
    }

    void setDiscount(float discount_) {
        this->discount = discount_;
    }

    // metode
    virtual float CalculChirie(float chirie, bool areDiscount) {

        return 0;
    }
};

// ******************************************************************************* //
class Apartament : public Locuinta{
private:
    int etaj;
public:
    // constructori & destructor
    Apartament() {
        etaj = NULL;
    }

    Apartament(const string &numeClient, int suprafataUtila, float discount, int etaj) : Locuinta(numeClient,
                                                                                                  suprafataUtila,
                                                                                                  discount),
                                                                                         etaj(etaj) {

    }

    ~Apartament() { }

    // getteri
    int getEtaj() const {
        return etaj;
    }

    // setteri
    void setEtaj(int etaj_) {
        this->etaj = etaj_;
    }

    // metode
    float CalculChirie(float chirie, bool areDiscount) override {

        return 0;
    }
};

// ******************************************************************************* //
class Casa : public Locuinta{
private:
    int suprafataCurte;
public:
    // constructori & destructor
    Casa() {
        suprafataCurte = NULL;
    }

    Casa(const string &numeClient, int suprafataUtila, float discount, int suprafataCurte) : Locuinta(numeClient,
                                                                                                      suprafataUtila,
                                                                                                      discount),
                                                                                             suprafataCurte(
                                                                                                     suprafataCurte) {

    }

    ~Casa() { }

    // getteri
    int getSuprafataCurte() const {
        return suprafataCurte;
    }

    // setteri
    void setSuprafataCurte(int suprafataCurte_) {
        this->suprafataCurte = suprafataCurte_;
    }

    // metode
    float CalculChirie(float chirie, bool areDiscount) override {

        return 0;
    }
};

// ******************************************************************************* //
class AgentieImobiliara {
private:
    Locuinta *locuinta;
public:
    // constructori
    AgentieImobiliara() {

    }
    ~AgentieImobiliara() {
        delete locuinta;
    }

    // getteri
    Locuinta *getLocuinta() const {
        return locuinta;
    }

    // setteri
    void setLocuinta(Locuinta *locuinta_) {
        this->locuinta = locuinta_;
    }

    // metode
};

// supraincarcare



// baza
// ******************************************************************************* //
int main() {


    return 0;
}
