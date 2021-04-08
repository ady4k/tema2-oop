#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/// CLion 2021.1
/// C++11
/// Repo GitHub:
/// https://github.com/ady4k/tema2-oop

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
    Locuinta(const Locuinta &other);
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
    void setValues(const string &numeClient_, int suprafataUtila_, float discount_);
    virtual float CalculChirie(int chirieSuprafata, bool areDiscount) = 0;
    virtual void citeste(istream &in) = 0;
    virtual void afiseaza(ostream &out) = 0;
    virtual bool tip() = 0;

    // supraincarcare
    friend istream& operator>>(istream &in, Locuinta& locuinta);
    friend ostream& operator<<(ostream &out, Locuinta& locuinta);
    Locuinta& operator=(const Locuinta& other);
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

Locuinta::Locuinta(const Locuinta &other) {
    this->setNumeClient(other.getNumeClient());
    this->setSuprafataUtila(other.getSuprafataUtila());
    this->setDiscount(other.getDiscount());
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
    this->setNumeClient(numeClient_);
    this->setSuprafataUtila(suprafataUtila_);
    this->setDiscount(discount_);
}

// supraincarcare
istream &operator>>(istream &in, Locuinta &locuinta) {
    locuinta.citeste(in);
    return in;
}

ostream &operator<<(ostream &out, Locuinta &locuinta) {
    locuinta.afiseaza(out);
    return out;
}

Locuinta &Locuinta::operator=(const Locuinta &other) {
    this->setValues(other.getNumeClient(), other.getSuprafataUtila(), other.getDiscount());
    return *this;
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
    void afiseaza(ostream &out) override;
    void citeste(istream &in) override;
    bool tip() override;

    friend istream& operator>>(istream &in, Apartament& apartament);
    friend ostream& operator<<(ostream &out, Apartament& apartament);
    Apartament& operator=(const Apartament& other);
};

// constructori & destructor
Apartament::Apartament() {
    numeClient = "";
    suprafataUtila = NULL;
    discount = 0.0;
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
    this->setNumeClient(numeClient_);
    this->setSuprafataUtila(suprafataUtila_);
    this->setDiscount(discount_);
    this->setEtaj(etaj_);
}

// metode
float Apartament::CalculChirie(int chirieSuprafata, bool areDiscount) {
    return chirieSuprafata * suprafataUtila * (1 - areDiscount * discount / 100.0);
}

void Apartament::afiseaza(ostream &out) {
    out << "Etaj:" << this->etaj << "\n";
}

void Apartament::citeste(istream &in) {
    cout << "Etaj:";
    in >> this->etaj;
}

bool Apartament::tip() {
    return false;
}

// supraincarcare
istream &operator>>(istream &in, Apartament& apartament) {
    in >> static_cast<Locuinta&>(apartament);
    apartament.citeste(in);
    return in;
}

ostream &operator<<(ostream &out, Apartament& apartament) {
    out << static_cast<Locuinta&>(apartament);
    apartament.afiseaza(out);
    return out;
}

Apartament &Apartament::operator=(const Apartament &other) {
    Locuinta::operator=(other);
    this->setEtaj(other.getEtaj());
    return *this;
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
    void afiseaza(ostream &out) override;
    void citeste(istream &in) override;
    bool tip() override;

    friend istream& operator>>(istream &in, Casa& casa);
    friend ostream& operator<<(ostream &out, Casa& casa);
    Casa& operator=(const Casa& other);
};

// constructori & destructor
Casa::Casa() {
    numeClient = "";
    suprafataUtila = NULL;
    discount = 0.0;
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
    this->setNumeClient(numeClient_);
    this->setSuprafataUtila(suprafataUtila_);
    this->setDiscount(discount_);
    this->setSuprafataCurte(suprafataCurte_);
}

// metode
float Casa::CalculChirie(int chirieSuprafata, bool areDiscount) {
    float chirie = suprafataUtila + 0.2 * suprafataCurte;
    float discount = 1 - (areDiscount * discount) / 100.0;

    return chirieSuprafata * chirie * discount;
}

void Casa::afiseaza(ostream &out) {
    out << "Suprafata curte:" << this->getSuprafataCurte() << "\n";
}

void Casa::citeste(istream &in) {
    cout << "Suprafata curte:";
    in >> this->suprafataCurte;
}

bool Casa::tip() {
    return true;
}

// supraincarcare
istream &operator>>(istream &in, Casa &casa) {
    in >> static_cast<Locuinta&>(casa);
    casa.citeste(in);
    return in;
}

ostream &operator<<(ostream &out, Casa &casa) {
    out << static_cast<Locuinta&>(casa);
    casa.afiseaza(out);
    return out;
}

Casa &Casa::operator=(const Casa &other) {
    Locuinta::operator=(other);
    this->setSuprafataCurte(other.getSuprafataCurte());
    return *this;
}

// ******************************************************************************* //
class AgentieImobiliara : public Casa, Apartament {
private:
    int dimensiune;
    int nrLocuinte;
    Locuinta **locuinta;

    static int numarObiecte;
    int id;
    // implementat cu stl pentru demonstratie "static"
    // vector in care sunt inserate toate instantele clasei
    static vector<AgentieImobiliara*> obiecte;
public:
    // constructori & destructor
    AgentieImobiliara();
    explicit AgentieImobiliara(int dimensiune_);
    AgentieImobiliara(const AgentieImobiliara &other);
    ~AgentieImobiliara();

    // getteri
    Locuinta *getLocuinta() const;
    int getDimensiune() const;
    int getNrLocuinte() const;
    static int nrObiecte();
    static AgentieImobiliara* getObiect(int i);
    Locuinta *getLocuinta(int nr);

    // setteri
    void setLocuinta(Locuinta *locuinta_);
    void setDimensiune(int dimensiune_);
    void setNrLocuinte(int nrLocuinte_);


    // metode
    void initializare(int nrLocuinte_);
    void extindere();
    void micsorare();
    void stergereLocuinta(int nrLocuinta);
    void adaugaLocuinta(bool tip, const string &numeClient_, int suprafataUtila_, float discount_, int valoare);
    void afisare();
    void afisareDetaliat();
    void stergere();
    static void adaugare();

    static void afisareInstante();

};

int AgentieImobiliara::numarObiecte = 0;
vector<AgentieImobiliara*> AgentieImobiliara::obiecte = vector<AgentieImobiliara*>();

// constructori
AgentieImobiliara::AgentieImobiliara() {
    dimensiune = 0;
    nrLocuinte = 0;
    locuinta = new Locuinta*[0];

    numarObiecte++;
    id = obiecte.size();
    obiecte.push_back(this);
}

AgentieImobiliara::AgentieImobiliara(int dimensiune_) {
    dimensiune = dimensiune_;
    nrLocuinte = 0;
    locuinta = new Locuinta*[dimensiune_];

    numarObiecte++;
    id = obiecte.size();
    obiecte.push_back(this);
}

AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara &other) : Casa(other), Apartament(other) {
    nrLocuinte = other.nrLocuinte;
    dimensiune = other.dimensiune;
    if (dimensiune < 1) {
        locuinta = NULL;
    } else {
        locuinta = new Locuinta*[dimensiune];
        for (int i = 0; i < dimensiune; i++) {
            locuinta[i] = other.locuinta[i];
        }
    }

    numarObiecte++;
    id = obiecte.size();
    obiecte.push_back(this);
}

AgentieImobiliara::~AgentieImobiliara() {
    numarObiecte--;
    obiecte.erase(obiecte.begin() + id);
    delete [] locuinta;
}

// getteri
Locuinta *AgentieImobiliara::getLocuinta() const {
    return *locuinta;
}

int AgentieImobiliara::getDimensiune() const {
    return dimensiune;
}

int AgentieImobiliara::getNrLocuinte() const {
    return nrLocuinte;
}

int AgentieImobiliara::nrObiecte() {
    return numarObiecte;
}

AgentieImobiliara* AgentieImobiliara::getObiect(int i) {
    return obiecte.at(i);
}

Locuinta *AgentieImobiliara::getLocuinta(int nr) {
    return locuinta[nr];
}

// setteri
void AgentieImobiliara::setLocuinta(Locuinta *locuinta_) {
    this->locuinta = &locuinta_;
}

void AgentieImobiliara::setDimensiune(int dimensiune_) {
    dimensiune = dimensiune_;
}

void AgentieImobiliara::setNrLocuinte(int nrLocuinte_) {
    nrLocuinte = nrLocuinte_;
}

// metode
/*
void AgentieImobiliara::initializare(int nrLocuinte_) {
    for(int i = nrLocuinte_; i < dimensiune; i++) {
        locuinta[i]->setValues("", NULL, 0.0);
    }
}
*/

void AgentieImobiliara::extindere() {
    dimensiune++;
    if (dimensiune > 1) {
        Locuinta **temp = new Locuinta*[dimensiune];
        for(int i = 0; i <= nrLocuinte; i++) {
            temp[i] = locuinta[i];
        }
        delete [] locuinta;
        locuinta = temp;
        //initializare(nrLocuinte);
    } else {
        delete [] locuinta;
        locuinta = new Locuinta*[dimensiune];
        //initializare(nrLocuinte);
    }
}

void AgentieImobiliara::micsorare() {
    dimensiune--;
    Locuinta **temp = new Locuinta*[dimensiune];
    for(int i = 0; i < dimensiune; i++) {
        temp[i] = locuinta[i];
    }
    delete [] locuinta;
    locuinta = temp;
}

void AgentieImobiliara::stergereLocuinta(int nrLocuinta) {
    for(int i = nrLocuinta; i < nrLocuinte - 1; i++) {
        locuinta[i] = locuinta[i + 1];
    }
    nrLocuinte--;
    micsorare();
}

void AgentieImobiliara::adaugaLocuinta(bool tip, const string &numeClient_, int suprafataUtila_, float discount_, int valoare) {
    if (nrLocuinte == dimensiune) {
        extindere();
    }
    if (tip == 0) {
        locuinta[nrLocuinte] = new Casa;
        dynamic_cast<Casa*>(locuinta[nrLocuinte++])->setValues(numeClient_, suprafataUtila_, discount_, valoare);
    } else {
        locuinta[nrLocuinte] = new Apartament;
        dynamic_cast<Apartament*>(locuinta[nrLocuinte++])->setValues(numeClient_, suprafataUtila_, discount_, valoare);
    }
}

void AgentieImobiliara::afisare() {
    for (int i = 0; i < nrLocuinte; i++) {
        cout << "Locuinta " << i + 1 << ") " << locuinta[i] << '\n';
    }
}

void AgentieImobiliara::afisareDetaliat() {
    for (int i = 0; i < nrLocuinte; i++) {
        cout << "Locuinta " << i + 1 << ") \n";
        cout << "Nume client: " << locuinta[i]->getNumeClient() << '\n';
        cout << "Suprafata Utila: " << locuinta[i]->getSuprafataUtila() << '\n';
        cout << "Discount (%): " << locuinta[i]->getDiscount() << '\n';
        if (!locuinta[i]->tip()) {
            cout << "Etaj: " << dynamic_cast<Apartament*>(locuinta[i])->getEtaj() << "\n\n";
        } else if (locuinta[i]->tip()) {
            cout << "Suprafata Curte: " << dynamic_cast<Casa*>(locuinta[i])->getSuprafataCurte() << "\n\n";
        }
    }
}

void AgentieImobiliara::stergere() {
    delete this;
}

void AgentieImobiliara::afisareInstante() {
    for (AgentieImobiliara* i : obiecte) {
        cout << i << ' ';
    }
}

void AgentieImobiliara::adaugare() {
    new AgentieImobiliara;
}



// ******************************************************************************* //
// baza
bool iesire();

int main() {
    bool exit = false; // marcheaza iesirea din program
    int caz;
    // meniu interactiv

    AgentieImobiliara obiect;
    // teste pentru debugging
    /*
    obiect.extindere();
    obiect.adaugaLocuinta(1, "1", 11, 69, 1);
    obiect.adaugaLocuinta(0, "1", 5, 53, 1);
    obiect.adaugaLocuinta(1, "1", 12, 78, 1);
    cout << obiect.getLocuinta(0)->getDiscount();
    cout << '\n';
    cout << obiect.getLocuinta(1)->getDiscount();
    cout << '\n';
    cout << obiect.getLocuinta(2)->getDiscount();
    cout << '\n';
    */

    do {
        cout << "1. Adauga o noua agentie imobiliara\n"
                "2. Sterge o agentie imobiliara\n"
                "3. Afiseaza agentiile imobiliare\n"
                "4. Adauga o locuinta noua intr-o agentie imobiliara\n"
                "5. Sterge o locuinta dintr-o agentie imobiliara\n"
                "6. Afiseaza locuintele dintr-o agentie imobiliara\n"
                "7. Calculeaza chiria pentru o locuinta\n"
                "8. Iesire\n";
        cin >> caz;
        switch (caz) {
            case 1: {
                system("CLS");
                cout << "Aveti " << obiect.nrObiecte() << " agentii in prezent.\nDoriti sa adaugati inca una? (Y/n)";
                char acord;
                cin >> acord;
                if (acord == 'Y' || acord == 'y') {
                    obiect.adaugare();
                    cout << "Ati adaugat o noua agentie.\n";
                } else if (acord == 'N' || acord == 'n') {
                    cout << "Nu s-a modificat nimic.\n";
                } else {
                    cout << "Valoare introdusa invalida!\nScrieri doar Y pentru da sau N pentru nu.";
                }
                system("pause");
                //exit = iesire();
                break;
            }
            case 2: {
                system("CLS");
                if (obiect.nrObiecte() == 1) {
                    cout << "Nu poti sterge ultima agentie ramasa!\n";
                } else {
                    system("CLS");
                    cout << "Introduceti numarul agentiei pe care vreti sa o stergeti.\n";
                    for (int i = 0; i < obiect.nrObiecte(); i++) {
                        cout << "Agentia nr. " << i + 1 << '\n';
                        obiect.getObiect(i)->afisare();
                        cout << '\n';
                    }
                    int numar;
                    cin >> numar;
                    obiect.getObiect(numar - 1)->stergere();
                }
                system("pause");
                //exit = iesire();
                break;
            }
            case 3: {
                system("CLS");
                cout << "Agentii imobiliare:\n\n";
                for (int i = 0; i < obiect.nrObiecte(); i++) {
                    cout << "Agentia nr. " << i + 1 << '\n';
                    obiect.getObiect(i)->afisare();
                    cout << '\n';
                }
                system("pause");
                //exit = iesire();
                break;
            }
            case 4: {
                system("CLS");
                cout << "Alegeti agentia imobiliara: \n\n";
                for (int i = 0; i < obiect.nrObiecte(); i++) {
                    cout << "Agentia nr. " << i + 1 << '\n';
                    obiect.getObiect(i)->afisare();
                    cout << '\n';
                }
                int agentie;
                cin >> agentie;
                system("CLS");
                cout << "Alegeti tipul de locuinta:\n"
                        "1)Casa\n"
                        "2)Apartament\n";
                int numar;
                cin >> numar;
                cout << "Introduceti numele clientului: ";
                string numeClient_;
                cin >> numeClient_;
                cout << "Introduceti suprafata utila a locuintei: ";
                int suprafataUtila_;
                cin >> suprafataUtila_;
                cout << "Introduceti discount-ul: ";
                float discount_;
                cin >> discount_;
                if (numar == 1) {
                    cout << "Introduceti suprafata curtii: ";
                    int suprafataCurte_;
                    cin >> suprafataCurte_;
                    obiect.getObiect(agentie - 1)->adaugaLocuinta(numar - 1, numeClient_, suprafataUtila_, discount_, suprafataCurte_);
                    cout << "Locuinta a fost adaugata!\n";
                } else {
                    cout << "Introduceti etajul apartamentului: ";
                    int etaj_;
                    cin >> etaj_;
                    obiect.getObiect(agentie - 1)->adaugaLocuinta(numar - 1, numeClient_, suprafataUtila_, discount_, etaj_);
                    cout << "Locuinta a fost adaugata!\n";
                }
                system("pause");
                //exit = iesire();
                break;
            }
            case 5: {
                system("CLS");
                cout << "Alegeti agentia imobiliara: \n\n";
                for (int i = 0; i < obiect.nrObiecte(); i++) {
                    cout << "Agentia nr. " << i + 1 << '\n';
                    obiect.getObiect(i)->afisare();
                    cout << '\n';
                }
                int agentie;
                cin >> agentie;
                system("CLS");
                cout << "Alege o locuinta:\n";
                obiect.getObiect(agentie - 1)->afisare();
                int locuinta;
                cin >> locuinta;
                obiect.getObiect(agentie - 1)->stergereLocuinta(locuinta - 1);
                cout << "Locuinta a fost stearsa!";
                system("pause");
                //exit = iesire();
                break;
            }
            case 6: {
                system("CLS");
                cout << "Alegeti agentia imobiliara: \n\n";
                for (int i = 0; i < obiect.nrObiecte(); i++) {
                    cout << "Agentia nr. " << i + 1 << '\n';
                    obiect.getObiect(i)->afisare();
                    cout << '\n';
                }
                int agentie;
                cin >> agentie;
                system("CLS");
                obiect.getObiect(agentie - 1)->afisareDetaliat();
                system("pause");
                //exit = iesire();
                break;
            }
            case 7: {
                system("CLS");
                cout << "Alegeti agentia imobiliara: \n\n";
                for (int i = 0; i < obiect.nrObiecte(); i++) {
                    cout << "Agentia nr. " << i + 1 << '\n';
                    obiect.getObiect(i)->afisare();
                    cout << '\n';
                }
                int agentie;
                cin >> agentie;
                system("CLS");
                cout << "Alege o locuinta:\n";
                obiect.getObiect(agentie - 1)->afisare();
                int locuinta;
                cin >> locuinta;
                system("CLS");
                cout << "Aplicati discount-ul pentru chiria acestei locuinta?\nIntroduceti (da) sau (nu).\n";
                string introdus;
                bool areDiscount_;
                cin >> introdus;
                if (introdus == "da" || introdus == "Da" || introdus == "dA" || introdus == "DA") {
                    areDiscount_ = true;
                } else if (introdus == "nu" || introdus == "nU" || introdus == "Nu" || introdus == "NU") {
                    areDiscount_ = false;
                } else {
                    cout << "Valoare introdusa incorecta! Discountul nu a fost aplicat.";
                    areDiscount_ = false;
                }
                int chirieSuprafata_;
                cout << "Introduceti chiria pe suprafata.\n";
                cin >> chirieSuprafata_;
                cout << obiect.getObiect(agentie - 1)->getLocuinta(locuinta - 1)->CalculChirie(chirieSuprafata_, areDiscount_) << '\n';
                system("pause");
                //exit = iesire();
                break;
            }
            case 8: {
                system("CLS");
                //
                system("pause");
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
