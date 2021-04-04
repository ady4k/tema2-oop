#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Definire clase
// ******************************************************************************* //
class Locuinta {
protected:
    string numeClient;
    int suprafataUtila;
    float discount;
public:
    // constructori & destructor
    Locuinta();
    Locuinta(const string &numeClient_, int suprafataUtila_, float discount_);
    ~Locuinta();

    // getteri
    const string &getNumeClient() const;
    int getSuprafataUtila() const;
    float getDiscount() const;

    // setteri
    void setNumeClient(const string &numeClient_);
    void setSuprafataUtila(int suprafataUtila_);
    void setDiscount(float discount_);

    // metode
    virtual void setValues(const string &numeClient_, int suprafataUtila_, float discount_);
    virtual float CalculChirie(int chirieSuprafata, bool areDiscount);
};

// constructori & destructor
Locuinta::Locuinta() {
    numeClient = '\0';
    suprafataUtila = NULL;
    discount = 0.0;
}

Locuinta::Locuinta(const string &numeClient_, int suprafataUtila_, float discount_) : numeClient(numeClient_),
                                                                                      suprafataUtila(suprafataUtila_),
                                                                                      discount(discount_) {
    numeClient = numeClient_;
    suprafataUtila = suprafataUtila_;
    discount = discount_;
}

Locuinta::~Locuinta() = default;

// getteri
const string &Locuinta::getNumeClient() const {
    return numeClient;
}

int Locuinta::getSuprafataUtila() const {
    return suprafataUtila;
}

float Locuinta::getDiscount() const {
    return discount;
}

// setteri
void Locuinta::setNumeClient(const string &numeClient_) {
    this->numeClient = numeClient_;
}

void Locuinta::setSuprafataUtila(int suprafataUtila_) {
    this->suprafataUtila = suprafataUtila_;
}

void Locuinta::setDiscount(float discount_) {
    this->discount = discount_;
}

void Locuinta::setValues(const string &numeClient_, int suprafataUtila_, float discount_) {
    this->numeClient = numeClient_;
    this->suprafataUtila = suprafataUtila_;
    this->discount = discount_;
}

// metode
float Locuinta::CalculChirie(int chirieSuprafata, bool areDiscount) {
    return 0;
}


// ******************************************************************************* //
class Apartament : public Locuinta{
private:
    int etaj;
public:
    // constructori & destructor
    Apartament();
    Apartament(const string &numeClient_, int suprafataUtila_, float discount_, int etaj_);
    ~Apartament();

    // getteri
    int getEtaj() const;

    // setteri
    void setEtaj(int etaj_);
    void setValues(const string &numeClient_, int suprafataUtila_, float discount_, int etaj_);

    // metode
    float CalculChirie(int chirieSuprafata, bool areDiscount) override;
};

// constructori & destructor
Apartament::Apartament() {
    etaj = NULL;
}

Apartament::Apartament(const string &numeClient_, int suprafataUtila_, float discount_, int etaj_) : Locuinta(numeClient_,
                                                                                                              suprafataUtila_,
                                                                                                              discount_),
                                                                                                      etaj(etaj_) {
    numeClient = numeClient_;
    suprafataUtila = suprafataUtila_;
    discount = discount_;
    etaj = etaj_;
}

Apartament::~Apartament() = default;

// getteri
int Apartament::getEtaj() const {
    return etaj;
}

// setteri
void Apartament::setEtaj(int etaj_) {
    this->etaj = etaj_;
}

void Apartament::setValues(const string &numeClient_, int suprafataUtila_, float discount_, int etaj_) {
    this->numeClient = numeClient_;
    this->suprafataUtila = suprafataUtila_;
    this->discount = discount_;
    this->etaj = etaj_;
}

// metode
float Apartament::CalculChirie(int chirieSuprafata, bool areDiscount) {
    return chirieSuprafata * suprafataUtila * (1 - areDiscount * discount / 100.0);
}


// ******************************************************************************* //
class Casa : public Locuinta{
private:
    int suprafataCurte;
public:
    // constructori & destructor
    Casa();
    Casa(const string &numeClient_, int suprafataUtila_, float discount_, int suprafataCurte_);
    ~Casa();

    // getteri
    int getSuprafataCurte() const;

    // setteri
    void setSuprafataCurte(int suprafataCurte_);
    void setValues(const string &numeClient_, int suprafataUtila_, float discount_, int suprafataCurte_);

    // metode
    float CalculChirie(int chirieSuprafata, bool areDiscount) override;
};

// constructori & destructor
Casa::Casa() {
    suprafataCurte = NULL;
}

Casa::Casa(const string &numeClient_, int suprafataUtila_, float discount_, int suprafataCurte_) : Locuinta(numeClient_,
                                                                                                            suprafataUtila_,
                                                                                                            discount_),
                                                                                                    suprafataCurte(
                                                                                                            suprafataCurte_) {
    numeClient = numeClient_;
    suprafataUtila = suprafataUtila_;
    discount = discount_;
    suprafataCurte = suprafataCurte_;
}

Casa::~Casa() = default;

// getteri
int Casa::getSuprafataCurte() const {
    return suprafataCurte;
}

// setteri
void Casa::setSuprafataCurte(int suprafataCurte_) {
    this->suprafataCurte = suprafataCurte_;
}

void Casa::setValues(const string &numeClient_, int suprafataUtila_, float discount_, int suprafataCurte_) {
    this->numeClient = numeClient_;
    this->suprafataUtila = suprafataUtila_;
    this->discount = discount_;
    this->suprafataCurte = suprafataCurte_;
}

// metode
float Casa::CalculChirie(int chirieSuprafata, bool areDiscount) {
    return chirieSuprafata * (suprafataUtila + 0.2 * suprafataCurte) * (1 - areDiscount * discount / 100.0);
}

// ******************************************************************************* //
class AgentieImobiliara {
private:
    static int dimensiune;
    static int nrLocuinte;
    Locuinta *locuinta;
public:
    // constructori & destructor
    AgentieImobiliara();
    AgentieImobiliara(int dimensiune_);
    AgentieImobiliara(const AgentieImobiliara &other);
    ~AgentieImobiliara();

    // getteri
    Locuinta *getLocuinta() const;
    static int getDimensiune();
    static int getNrLocuinte();

    // setteri
    void setLocuinta(Locuinta *locuinta_);
    static void setDimensiune(int dimensiune_);
    static void setNrLocuinte(int nrLocuinte_);

    // metode
    void initializare(int nrLocuinte_);
    void extindere();
    void micsorare();
    void stergereLocuinta(int nrLocuinta);
    void adaugaLocuinta(const string &numeClient_, int suprafataUtila_, float discount_);

};

// constructori
AgentieImobiliara::AgentieImobiliara() {
    dimensiune = NULL;
    nrLocuinte = NULL;
    locuinta = new Locuinta[0];
}

AgentieImobiliara::AgentieImobiliara(int dimensiune_) {
    dimensiune = dimensiune_;
    nrLocuinte = 0;
    locuinta = new Locuinta[dimensiune_];
}

AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara &other) {
    nrLocuinte = other.nrLocuinte;
    if (dimensiune < 1) {
        locuinta = NULL;
    } else {
        locuinta = new Locuinta[dimensiune];
        for (int i = 0; i < dimensiune; i++) {
            locuinta[i] = other.locuinta[i];
        }
    }
}

AgentieImobiliara::~AgentieImobiliara() {
    delete [] locuinta;
}

// getteri
Locuinta *AgentieImobiliara::getLocuinta() const {
    return locuinta;
}

int AgentieImobiliara::getDimensiune() {
    return dimensiune;
}

int AgentieImobiliara::getNrLocuinte() {
    return nrLocuinte;
}

// setteri
void AgentieImobiliara::setLocuinta(Locuinta *locuinta_) {
    this->locuinta = locuinta_;
}

void AgentieImobiliara::setDimensiune(int dimensiune_) {
    dimensiune = dimensiune_;
}

void AgentieImobiliara::setNrLocuinte(int nrLocuinte_) {
    nrLocuinte = nrLocuinte_;
}

// metode
void AgentieImobiliara::initializare(int nrLocuinte_) {
    for(int i = nrLocuinte_; i < dimensiune; i++) {
        locuinta[i].setValues("", NULL, 0.0);
    }
}

void AgentieImobiliara::extindere() {
    dimensiune++;
    if (dimensiune > 1) {
        Locuinta *temp = new Locuinta[dimensiune];
        for(int i = 0; i < nrLocuinte; i++) {
            temp[i] = locuinta[i];
        }
        delete [] locuinta;
        locuinta = temp;
        initializare(nrLocuinte);
    } else {
        locuinta = new Locuinta[dimensiune];
        initializare(nrLocuinte);
    }
}

void AgentieImobiliara::micsorare() {
    dimensiune--;
    Locuinta *temp = new Locuinta[dimensiune];
    for(int i = 0; i < dimensiune; i++) {
        temp[i] = locuinta[i];
    }
    delete [] locuinta;
    locuinta = temp;
}

void AgentieImobiliara::stergereLocuinta(int nrLocuinta) {
    for(int i = nrLocuinta; i < nrLocuinta - 1; i++) {
        locuinta[i] = locuinta[i + 1];
    }
    nrLocuinte--;
    micsorare();
}

void AgentieImobiliara::adaugaLocuinta(const string &numeClient_, int suprafataUtila_, float discount_) {
    if (nrLocuinte == dimensiune) {
        extindere();
        locuinta[nrLocuinte++].setValues(numeClient_, suprafataUtila_, discount_);
    } else {
        locuinta[nrLocuinte++].setValues(numeClient_, suprafataUtila_, discount_);
    }
}

// supraincarcare


// ******************************************************************************* //

// baza
bool iesire();

int main() {
    bool exit = false; // marcheaza iesirea din program
    int i;
    // meniu interactiv
    do {
        cout << "1. \n"
                "2. \n"
                "3. \n"
                "4. \n"
                "5. \n"
                "6. \n"
                "7. \n";
        cin >> i;
        switch (i) {
            case 1: {
                system("CLS");
                //
                system("pause");
                exit = iesire();
                break;
            }
            case 2: {
                system("CLS");
                //
                system("pause");
                exit = iesire();
                break;
            }
            case 3: {
                system("CLS");
                //
                system("pause");
                exit = iesire();
                break;
            }
            case 4: {
                system("CLS");
                //
                system("pause");
                exit = iesire();
                break;
            }
            case 5: {
                system("CLS");
                //
                system("pause");
                exit = iesire();
                break;
            }
            case 6: {
                system("CLS");
                //
                system("pause");
                exit = iesire();
                break;
            }
            case 7: {
                system("CLS");
                exit = true;
                break;
            }
            default: {
                system("CLS");
                cout << "Introduceti un numar de la 1 la 7!";
                break;
            }
        }
        system("CLS");
    } while(!exit);
    return 0;
}

bool iesire() {
    bool exit = false;
    cout << "\n\nDoriti sa iesiti din program? (Y/n)";
    char acord;
    bool iesit = false;
    do {
        cin >> acord;
        if (acord == 'Y' || acord == 'y') {
            system("CLS");
            exit = true;
            iesit = true;
        } else if (acord == 'N' || acord == 'n') {
            system("CLS");
            iesit = true;
        } else {
            system("cls");
            cout << "Valoare invalida!\nIntroduceti Y (da) sau n (nu).";
        }
    } while (!iesit);
    return exit;
}
