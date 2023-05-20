#include <iostream>
#include <cstring>
#include <string>
#include <exception>
#include <vector>

using namespace std;
class Animal{  //declararea obiectelor
protected:
   string tip;
   string locatie;
   string nume;
public:
     Animal( string type="mamifer", string location="rinocer", string name="NE"):tip(type), locatie(location), nume(name){} //constructor
    Animal(const Animal& other){ //constructor de copiere
        tip=other.tip;
        locatie=other.locatie;
        nume=other.nume;
    }
    virtual ~Animal()=default; //destructor
    Animal& operator=(const Animal& other){ //operatorul = de copiere
        if(this!=&other){
            tip=other.tip;
            locatie=other.locatie;
            nume=other.nume;
        }
        return *this;
    }
    string get_tip() const;   //declaram antetele functiilor
    string get_locatie() const;
    string get_nume() const;
    void set_tip(const string& new_tip);
    void set_locatie(const string& new_locatie);
    void set_nume(const string& new_nume);
    friend ostream& operator<<(ostream& out, const Animal& animal);
};
string Animal::get_tip() const {
    return tip;
}
string Animal::get_locatie() const {
    return locatie;
}
string Animal::get_nume() const {
    return nume;
}
void Animal::set_tip(const string& new_tip){
    tip=new_tip;
}
void Animal::set_locatie(const string& new_locatie){
    locatie=new_locatie;
}
void Animal::set_nume(const string& new_nume){
    nume=new_nume;
}
ostream& operator<<(ostream& out, const Animal& animal){ //operatorul de afisare
    out<<"Tipul animalului: "<<animal.tip<<endl;
    out<<"Locatia in gradina: "<<animal.locatie<<endl;
    out<<"Specia animalului: "<<animal.nume<<endl;
    return out;
}

class Bilet{
    int pret;
    string tip_bilet;
    static int numaratoare;
public:
    Bilet(int price=100, string type_bilet="adult"):pret(price), tip_bilet(type_bilet){
        ++numaratoare;
    }
    Bilet(const Bilet& other){
        pret=other.pret;
        tip_bilet=other.tip_bilet;
    }
    ~Bilet()=default;
    Bilet& operator=(const Bilet& other){
        if(this!=&other) {
            pret=other.pret;
            tip_bilet = other.tip_bilet;
        }
        return *this;
    }
    static void afisareNumaratoare(){  //Metodele statice
        cout<<"Numaratoare: "<<numaratoare<<endl;
    }
    static void resetareNumaratoare(){
        numaratoare=0;
    }
    int get_pret() const;
    string get_tip_bilet() const;
    static int get_numaratoare() ;
    void set_pret( int new_pret);
    void set_tip_bilet(string new_tip_bilet);
    friend ostream& operator<<(ostream& out, const Bilet& bilet);
};
int Bilet::numaratoare=0;
int Bilet::get_pret() const{
        return pret;
    }
string Bilet::get_tip_bilet() const {
    return tip_bilet;
}
int Bilet::get_numaratoare() {
    return numaratoare;
}
void Bilet::set_pret(int new_pret) {
    if (new_pret<0) {
        throw out_of_range("Pretul biletului nu poate fi negativ!");
    }
    pret=new_pret;
}
void Bilet::set_tip_bilet(string new_tip_bilet) {
    tip_bilet=new_tip_bilet;
}

ostream& operator<<(ostream& out, const Bilet& bilet){
    out<<"Pretul biletului: "<<bilet.pret<<" de lei"<<endl;
    out<<"Tipul biletului: "<<bilet.tip_bilet<<endl;
    return out;
}

class Cost{
    int hrana_animale;
    int salariu_angajat;
    int chirie;
    int intretinere;
    vector<Cost> costuri;
    int luna_curenta;
public:
    Cost(int food_animal=1000, int salary_employee=2000, int rent=3000, int maintenance=1700):hrana_animale(food_animal), salariu_angajat(salary_employee), chirie(rent), intretinere(maintenance){
        ++luna_curenta;
    }

    Cost(const Cost& other){
        hrana_animale=other.hrana_animale;
        salariu_angajat=other.salariu_angajat;
        chirie=other.chirie;
        intretinere=other.intretinere;
    }

    ~Cost()=default;
    Cost& operator=(const Cost& other){
        if(this!=&other) {
            hrana_animale = other.hrana_animale;
            salariu_angajat = other.salariu_angajat;
            chirie = other.chirie;
            intretinere = other.intretinere;
        }
        return *this;
    }
    void adauga_cost(const Cost& cost) {
        costuri.push_back(cost);
    }
    vector<Cost> get_costuri();
    int get_hrana_animale() const;
    int get_salariu_angajat() const;
    int get_chirie() const;
    int get_intretinere() const;
    void set_hrana_animale(int new_hrana_animale);
    void set_salariu_angajat(int new_salariu_angajat);
    void set_chirie(int new_chirie);
    void set_intretinere(int new_intretinere);
    void set_luna_curenta(int new_luna_curenta);
    friend ostream& operator<<(ostream& out, const Cost& cost);
};
vector<Cost> Cost::get_costuri(){
    return costuri;
}
int Cost::get_hrana_animale() const{
    return hrana_animale;
}
int Cost::get_salariu_angajat() const{
    return salariu_angajat;
}
int Cost::get_chirie() const{
    return chirie;
}
int Cost::get_intretinere() const{
    return intretinere;
}
void Cost::set_hrana_animale(int new_hrana_animale) {
    hrana_animale=new_hrana_animale;
}
void Cost::set_salariu_angajat(int new_salariu_angajat) {
    salariu_angajat=new_salariu_angajat;
}
void Cost::set_chirie(int new_chirie) {
    chirie=new_chirie;
}
void Cost::set_intretinere(int new_intretinere) {
    intretinere=new_intretinere;
}
void Cost::set_luna_curenta(int new_luna_curenta) {
    luna_curenta=new_luna_curenta;
}
ostream& operator<<(ostream& out, const Cost& cost){
    if (cost.luna_curenta==1){
        out<<"Luna "<<cost.luna_curenta<<":"<<endl;
    }
    out<<"Pretul hranei animalelor: "<<cost.hrana_animale<<" de lei"<<endl;
    out<<"Salariul angajatului: "<<cost.salariu_angajat<<" de lei"<<endl;
    out<<"Pretul chiriei: "<<cost.chirie<<" de lei"<<endl;
    out<<"Pretul intretinerii: "<<cost.intretinere<<" de lei"<<endl;
    return out;
}

class Angajat{
protected:
    string nume_angajat;
    int varsta_angajat;
    string sex_angajat;
    int vechime_angajat;
public:
    Angajat(string name_employee="Gicuta", int age_employee=37, string sex_employee="M", int vechime_employee=9):nume_angajat(name_employee), varsta_angajat(age_employee), sex_angajat(sex_employee),vechime_angajat(vechime_employee){}
    Angajat(const Angajat& other){
        nume_angajat=other.nume_angajat;
        varsta_angajat=other.varsta_angajat;
        sex_angajat=other.sex_angajat;
        vechime_angajat=other.vechime_angajat;
    }
    virtual ~Angajat()=default;
    Angajat& operator=(const Angajat& other){
        if(this!=&other){
            nume_angajat=other.nume_angajat;
            varsta_angajat=other.varsta_angajat;
            sex_angajat=other.sex_angajat;
            vechime_angajat=other.vechime_angajat;
        }
        return *this;
    }
    string get_nume_angajat() const;
    int get_varsta_angajat() const;
    string get_sex_angajat() const;
    int get_vechime_angajat() const;
    void set_nume_angajat(const string& new_nume_angajat);
    void set_varsta_angajat(int new_varsta_angajat);
    void set_sex_angajat(const string& new_sex_angajat);
    void set_vechime_angajat(int new_vechime_angajat);
    friend ostream& operator<<(ostream& out, const Angajat& angajat);
};
string Angajat::get_nume_angajat() const {
    return nume_angajat;
}
int Angajat::get_varsta_angajat() const {
    return varsta_angajat;
}
string Angajat::get_sex_angajat() const {
    return sex_angajat;
}
int Angajat::get_vechime_angajat() const {
    return vechime_angajat;
}
void Angajat::set_nume_angajat(const string &new_nume_angajat) {
    nume_angajat=new_nume_angajat;
}
void Angajat::set_varsta_angajat(int new_varsta_angajat) {
    varsta_angajat=new_varsta_angajat;
}
void Angajat::set_sex_angajat(const string &new_sex_angajat) {
    sex_angajat=new_sex_angajat;
}
void Angajat::set_vechime_angajat(int new_vechime_angajat) {
    vechime_angajat=new_vechime_angajat;
}
ostream& operator<<(ostream& out, const Angajat& angajat){ //operatorul de afisare
    out<<"Numele angajatului: "<<angajat.nume_angajat<<endl;
    out<<"Varsta angajatului: "<<angajat.varsta_angajat<<endl;
    out<<"Sexul angajatului: "<<angajat.sex_angajat<<endl;
    out<<"Vechimea angajatului: "<<angajat.vechime_angajat<<endl;
    return out;
}

class Contract{
protected:
    int durata;
    int salariu;
public:
    Contract(int duration=5, int salary=2700): durata(duration), salariu(salary){}
    Contract(const Contract& other){
        durata=other.durata;
        salariu=other.salariu;
    }
    virtual ~Contract()=default;
    Contract& operator=(const Contract& other){
        if(this!=&other){
            durata=other.durata;
            salariu=other.salariu;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Contract& contract);
    void set_durata(const int new_durata);

};
ostream& operator<<(ostream& out, const Contract& contract){ //operatorul de afisare
    out<<"Durata contractului: "<<contract.durata<<endl;
    out<<"Salariul: "<<contract.salariu<<" de lei"<<endl;
    return out;
}
void Contract::set_durata(int new_durata){
    durata=new_durata;
}


class Ingrijitor:public Angajat, protected Contract{  //declararea obiectelor
    string animal_preferat;
    int nr_custi;
public:
    Ingrijitor(string name_employee="Paulica", int age_employee=89, string sex_employee="M", int vechime_employee=50, int duration= 17, int salary=23400, string favorite_animal="strut", int nr_cages=35):Angajat(name_employee, age_employee, sex_employee, vechime_employee), Contract(duration, salary), animal_preferat(favorite_animal), nr_custi(nr_cages){} //constructor
    Ingrijitor(const Ingrijitor& other){ //constructor de copiere
        animal_preferat=other.animal_preferat;
        nr_custi=other.nr_custi;
        nume_angajat=other.nume_angajat;
        varsta_angajat=other.varsta_angajat;
        sex_angajat=other.sex_angajat;
        vechime_angajat=other.vechime_angajat;
        durata=other.durata;
        salariu=other.salariu;
    }
    ~Ingrijitor()=default; //destructor
    Ingrijitor& operator=(const Ingrijitor& other){ //operatorul = de copiere
        if(this!=&other){
            animal_preferat=other.animal_preferat;
            nr_custi=other.nr_custi;
            nume_angajat=other.nume_angajat;
            varsta_angajat=other.varsta_angajat;
            sex_angajat=other.sex_angajat;
            vechime_angajat=other.vechime_angajat;
            durata=other.durata;
            salariu=other.salariu;
        }
        return *this;
    }
    string get_animal_preferat() const;   //declaram antetele functiilor
    int get_nr_custi() const;
    void set_animal_preferat(const string& new_animal_preferat);
    void set_nr_custi(int new_nr_custi);
    friend ostream& operator<<(ostream& out, const Ingrijitor& ingrijitor);
    bool spor() const;
    void set_salariu(int new_salariu);

};
string Ingrijitor::get_animal_preferat() const {
    return animal_preferat;
}
int Ingrijitor::get_nr_custi() const {
    return nr_custi;
}
void Ingrijitor::set_animal_preferat(const string& new_animal_preferat){
    animal_preferat=new_animal_preferat;
}
void Ingrijitor::set_nr_custi(int new_nr_custi){
    nr_custi=new_nr_custi;
}
ostream& operator<<(ostream& out, const Ingrijitor& ingrijitor){ //operatorul de afisare
    out<<"Animalul preferat: "<<ingrijitor.animal_preferat<<endl;
    out<<"Numarul de custi: "<<ingrijitor.nr_custi<<endl;
    out<<"Numele angajatului: "<<ingrijitor.nume_angajat<<endl;
    out<<"Varsta angajatului: "<<ingrijitor.varsta_angajat<<endl;
    out<<"Sexul angajatului: "<<ingrijitor.sex_angajat<<endl;
    out<<"Vechimea angajatului: "<<ingrijitor.vechime_angajat<<endl;
    out<<"Durata contractului: "<<ingrijitor.durata<<endl;
    out<<"Salariul angajatului: "<<ingrijitor.salariu<<endl;
    return out;
}
void Ingrijitor::set_salariu(int new_salariu){
    if(spor()){
         this->salariu += 1500;
    }
    else this->salariu;
}
bool Ingrijitor::spor() const {
    return this->varsta_angajat >= 50;
}

class Casier:public Angajat{  //declararea obiectelor
    int nr_bilete_vandute;
public:
    Casier(string name_employee="Ana", int age_employee=26, string sex_employee="F", int vechime_employee=2, int nr_bilete_sold=120):Angajat(name_employee, age_employee, sex_employee, vechime_employee), nr_bilete_vandute(nr_bilete_sold){} //constructor
    Casier(const Casier& other){ //constructor de copiere
        nr_bilete_vandute=other.nr_bilete_vandute;
    }
    ~Casier()=default; //destructor
    Casier& operator=(const Casier& other){ //operatorul = de copiere
        if(this!=&other){
            nr_bilete_vandute=other.nr_bilete_vandute;
        }
        return *this;
    }
    int get_nr_bilete_vandute() const;   //declaram antetele functiilor
    void set_nr_bilete_vandute(int new_nr_bilete_vandute);
    friend ostream& operator<<(ostream& out, const Casier& casier);
};
int Casier::get_nr_bilete_vandute() const {
    return nr_bilete_vandute;
}
void Casier::set_nr_bilete_vandute(int new_nr_bilete_vandute){
    nr_bilete_vandute=new_nr_bilete_vandute;
}

ostream& operator<<(ostream& out, const Casier& casier){ //operatorul de afisare
    out<<"Numarul de bilete vandute: "<<casier.nr_bilete_vandute<<endl;
    out<<"Numele angajatului: "<<casier.nume_angajat<<endl;
    out<<"Varsta angajatului: "<<casier.varsta_angajat<<endl;
    out<<"Sexul angajatului: "<<casier.sex_angajat<<endl;
    out<<"Vechimea angajatului: "<<casier.vechime_angajat<<endl;
    return out;
}

class Primire:protected Animal{
    string tara;
    string temperatura;
public:
    Primire(string type="pasare", string location="S", string name="flamingo", string country="Maroc", string temperature="cald"):Animal(type, location, name), tara(country), temperatura(temperature){}
    Primire(const Primire& other){
        tara=other.tara;
        temperatura=other.temperatura;
        tip=other.tip;
        locatie=other.locatie;
        nume=other.nume;
    }
    ~Primire()=default;
    Primire& operator=(const Primire& other){
        if(this!=&other){
            tara=other.tara;
            temperatura=other.temperatura;
            tip=other.tip;
            locatie=other.locatie;
            nume=other.nume;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Primire& primire);
};
ostream& operator<<(ostream& out, const Primire& primire) { //operatorul de afisare
    out<<"Tara de origine: "<<primire.tara<<endl;
    out<<"Temperatura: "<<primire.temperatura<<endl;
    return out;
}

class Produs{
public:
    virtual ~Produs()=default;
    virtual bool calorii() const=0;
    virtual bool expirare() const=0;
};

class Mancare:public Produs{
    int nr_cal_produs;
    int perioada_produs;
public:
    Mancare(int nr_cal_product=190, int perioada_product=3): nr_cal_produs(nr_cal_product), perioada_produs(perioada_product){}
    Mancare(const Mancare& other){
        nr_cal_produs=other.nr_cal_produs;
        perioada_produs=other.perioada_produs;
    }
    ~Mancare()=default;
    Mancare& operator=(const Mancare& other){
        if(this!=&other){
            nr_cal_produs=other.nr_cal_produs;
            perioada_produs=other.perioada_produs;
        }
        return *this;
    }
    bool calorii() const override;
    bool expirare() const override;
    void prezentare() const;
    friend ostream& operator<<(ostream& out, const Mancare& mancare);
};
void Mancare::prezentare() const {
    if(calorii())cout<<"Nesanatos"<<endl;
    else cout<<"Sanatos"<<endl;
    if(expirare())cout<<"Expirat"<<endl;
    else cout<<"Valid"<<endl;
}
bool Mancare::calorii() const {
    if(nr_cal_produs>=300)return true;
    else return false;
}
bool Mancare::expirare() const {
    if(perioada_produs>=7)return true;
    else return false;
}
ostream& operator<<(ostream& out, const Mancare& mancare) { //operatorul de afisare
    out<<"Numar de calorii ale produsului: "<<mancare.nr_cal_produs<<endl;
    out<<"Perioada de depozitare a produsului: "<<mancare.perioada_produs<<endl;
    return out;
}

class Drum{
protected:
    int pret_material;
    int durata_constructie;
public:
    Drum(int price_material=40, int duration_construction=14):pret_material(price_material), durata_constructie(duration_construction){}
    Drum(const Drum& other){
        pret_material=other.pret_material;
        durata_constructie=other.durata_constructie;
    }
    virtual ~Drum()=default;
    Drum& operator=(const Drum& other){
        if(this!=&other){
            pret_material=other.pret_material;
            durata_constructie=other.durata_constructie;
        }
        return *this;
    }
    virtual void pret() const = 0; //sa fie diferit in clasele drivate
    virtual void timp() const = 0; //si asta
    friend ostream& operator<<(ostream& out, const Drum& drum);
};
ostream& operator<<(ostream& out, const Drum& drum) { //operatorul de afisare
    out<<"Pretul materialului: "<<drum.pret_material<<endl;
    out<<"Durata de constructie a drumului: "<<drum.durata_constructie<<endl;
    return out;
}
class Asfalt:public Drum{
public:
    Asfalt(int price_material=15, int duration_construction=56): Drum(price_material, duration_construction){}
    Asfalt(const Asfalt& other){
        pret_material=other.pret_material;
        durata_constructie=other.durata_constructie;
    }
    ~Asfalt()=default;
    Asfalt& operator=(const Asfalt& other){
        if(this!=&other){
            pret_material=other.pret_material;
            durata_constructie=other.durata_constructie;
        }
        return *this;
    }
    void pret() const override;
    void timp() const override;
    friend ostream& operator<<(ostream& out, const Asfalt& asfalt);
};
void Asfalt::pret() const{
    cout<<"Pretul pentru construirea unui drum de asfalt este: "<<pret_material<<endl;
}
void Asfalt::timp() const{
    cout<<"Durata estimata pentru construirea unui drum de asfalt este: "<< durata_constructie<<" zile."<<endl;
}
ostream& operator<<(ostream& out, const Asfalt& asfalt) { //operatorul de afisare
    out<<"Pretul drumului de asfalt: "<<asfalt.pret_material<<endl;
    out<<"Durata de constructie a drumului de asfalt: "<<asfalt.durata_constructie<<endl;
    return out;
}
class Pietris:public Drum{
public:
    Pietris(int price_material=15, int duration_construction=56): Drum(price_material, duration_construction){}
    Pietris(const Pietris& other){
        pret_material=other.pret_material;
        durata_constructie=other.durata_constructie;
    }
    ~Pietris()=default;
    Pietris& operator=(const Pietris& other){
        if(this!=&other){
            pret_material=other.pret_material;
            durata_constructie=other.durata_constructie;
        }
        return *this;
    }
    void pret() const override;
    void timp() const override;
    friend ostream& operator<<(ostream& out, const Pietris& pietris);
};
void Pietris::pret() const {
    cout<<"Pretul pentru construirea unui drum de pietris este: "<<pret_material<<endl;
}
void Pietris::timp() const {
    cout<<"Durata estimata pentru construirea unui drum de pietris este: "<< durata_constructie<<" zile."<<endl;
}
ostream& operator<<(ostream& out, const Pietris& pietris) { //operatorul de afisare
    out<<"Pretul drumului de petris: "<<pietris.pret_material<<endl;
    out<<"Durata de constructie a drumului de pietris: "<<pietris.durata_constructie<<endl;
    return out;
}

class ZooException:public exception{
private:
    string message;

public:
    ZooException(const string& msg):message(msg){}

    virtual const char* what() const noexcept{
        return message.c_str();
    }
};

class NewZooException:public exception{
private:
    string message;

public:
    NewZooException(const string& msg):message(msg){}

    virtual const char* what() const noexcept {
        return message.c_str();
    }
};
void feedAnimal(int animalId){
    if(animalId<0){
        throw ZooException("Invalid animal ID.");
    }
}
// Mostenire in diamant
// Clasa de baza Veterinar
class Veterinar{
protected:
    string nume_vet;
public:
    Veterinar(const string& name_vet):nume_vet(name_vet){}

    void consultaAnimal(const string& animal){
        cout<<"Veterinarul "<<nume_vet<<" consulta "<<animal<<endl;
    }
};

// Clasa intermediara VeterinarChirurg care mosteneste clasa de baza Veterinar
class VeterinarChirurg:virtual public Veterinar{
public:
    VeterinarChirurg(const string& name_vet):Veterinar(name_vet){}

    void efectueazaOperatie(const string& animal, const string& tipOperatie){
        cout<<"Veterinarul chirurg "<<nume_vet<<" efectueaza operatia "<<tipOperatie<<" la "<<animal<<endl;
    }
};

// Clasa intermediara VeterinarDermatolog care mosteneste clasa de baza Veterinar
class VeterinarDermatolog:virtual public Veterinar{
public:
    VeterinarDermatolog(const string& name_vet):Veterinar(name_vet){}

    void efectueazaTratament(const string& animal, const string& tipTratament){
        cout<<"Veterinarul dermatolog "<<nume_vet<<" efectueaza tratamentul "<<tipTratament<<" la "<<animal<<endl;
    }
};

// Clasa derivata care mosteneste clasele intermediare VeterinarChirurg si VeterinarDermatolog
class VeterinarSpecializat:public VeterinarChirurg, public VeterinarDermatolog{
private:
    int nivel_vet;
public:
     VeterinarSpecializat(const string& name_vet="Alexandru", int nivel_Vet= 2):Veterinar(name_vet), VeterinarChirurg(name_vet), VeterinarDermatolog(name_vet), nivel_vet(nivel_Vet){}
     int get_nivel_vet() const;
};
int VeterinarSpecializat::get_nivel_vet() const {
    return nivel_vet;
}

int main() {
    Animal animal1;
    cout<<animal1<<endl;
    Animal animal2;
    animal2.set_tip("pasare");
    animal2.set_locatie("SE");
    animal2.set_nume("flamingo");
    cout<<animal2<<endl;
    Animal animal3("reptila", "V", "soparla");
    cout<<animal3<<endl;
    cout<<"Tip cu get: "<<animal3.get_tip()<<endl;
    cout<<"Locatie cu get: "<<animal3.get_locatie()<<endl;
    cout<<"Nume cu get: "<<animal3.get_nume()<<endl;
    cout<<"\n";
    Primire primire1;
    cout<<primire1<<endl;
    Primire primire2("mamifer", "V", "urs panda", "China", "temperat");
    cout<<primire2<<endl;
    cout<<"\n";
    Bilet bilet1;
    cout<<bilet1<<endl;
    Bilet bilet2;
    int pret;
    cout<<"Introduceti pretul biletului: ";
    cin>>pret;
    try {
        bilet2.set_pret(pret);
        cout<<"Pretul biletului a fost setat cu succes!\n";
    } catch(const out_of_range& e){
        cout<<"Exceptie prinsa: "<< e.what()<<'\n';
    }
    bilet2.set_tip_bilet("student");
    cout<<bilet2<<endl;
    Bilet bilet3(20, "copil");
    cout<<bilet3<<endl;
    cout<<"Pret cu get: "<<bilet3.get_pret()<<" de lei"<<endl;
    cout<<"Tip bilet cu get: "<<bilet3.get_tip_bilet()<<endl;
    cout<<"Numar bilete cu get: "<<bilet3.get_numaratoare()<<endl;
    Bilet::afisareNumaratoare();
    Bilet::resetareNumaratoare();
    cout<<"\n";
    Cost cost1;
    cout<<cost1<<endl;
    Cost cost2;
    cost2.set_hrana_animale(2000);
    cost2.set_salariu_angajat(5000);
    cost2.set_chirie(2800);
    cost2.set_intretinere(3460);
    cout<<cost2<<endl;
    Cost cost3(3900, 4600, 5760, 1200);
    cout<<cost3<<endl;
    cout<<"Hrana animale cu get: "<<cost3.get_hrana_animale()<<" de lei"<<endl;
    cout<<"Salariu angajat cu get: "<<cost3.get_salariu_angajat()<<" de lei"<<endl;
    cout<<"Chirie cu get: "<<cost3.get_chirie()<<" de lei"<<endl;
    cout<<"Intretinere cu get: "<<cost3.get_intretinere()<<" de lei"<<endl;
    cout<<"\n";
    Cost cost4;
    cost4.set_luna_curenta(1);
    cost4.adauga_cost(Cost(1500, 2500, 3500, 2000));
    cost4.adauga_cost(Cost(1200, 2200, 3100, 1800));
    cost4.adauga_cost(Cost(1300, 2400, 3300, 1900));
    const vector<Cost>& costuri=cost4.get_costuri();
    for (size_t i=0; i<costuri.size(); i++){
        cout<<"Luna "<<i+1<<":"<<endl;
        cout<<costuri[i]<<endl;
    }
    cout<<"\n";
    Angajat angajat1;
    cout<<angajat1<<endl;
    cout<<"\n";
    Angajat angajat2;
    angajat2.set_nume_angajat("Nicolae");
    angajat2.set_varsta_angajat(42);
    angajat2.set_sex_angajat("M");
    angajat2.set_vechime_angajat(9);
    cout<<angajat2<<endl;
    Contract contract1;
    cout<<"\n";
    cout<<contract1<<endl;
    Contract contract2;
    contract2.set_durata(7);
    Ingrijitor ingrijitor1;
    cout<<ingrijitor1<<endl;
    cout<<"\n";
    Ingrijitor ingrijitor2;
    ingrijitor2.set_animal_preferat("elefant");
    ingrijitor2.set_nr_custi(20);
    ingrijitor2.set_nume_angajat("Aurica");
    ingrijitor2.set_varsta_angajat(35);
    ingrijitor2.set_sex_angajat("F");
    ingrijitor2.set_vechime_angajat(2);
    ingrijitor2.set_salariu(4000);
    cout<<ingrijitor2<<endl;
    cout<<"\n";
    Ingrijitor ingrijitor3;
    if (ingrijitor3.spor()){
        cout<<"Ingrijitorul este eligibil pentru un spor salarial."<<endl;
    } else {
        cout << "Ingrijitorul nu este eligibil pentru un spor salarial." << endl;
    }
    ingrijitor3.set_salariu(4000);
    cout<<"Salariul Ingrijitorului actualizat:"<<endl;
    cout<<ingrijitor3<<"de lei"<<endl;
    cout<<"\n";
    Casier casier1;
    cout<<casier1;
    cout<<"\n";
    Mancare mancare1;
    cout<<mancare1;
    cout<<"\n";
    mancare1.prezentare();
    cout<<mancare1;
    cout<<"\n";
    Mancare mancare2; //instantele de upcasting
    Produs& produsRef=mancare2;
    produsRef.calorii();
    produsRef.expirare();
    Drum* drum1; //polimorfism la executie
    Drum* drum2;
    Asfalt asfalt1;
    Pietris pietris1;
    drum1=&asfalt1;
    drum2=&pietris1;
    drum1->pret();
    drum1->timp();
    drum2->pret();
    drum2->timp();
    cout<<"\n";
    // Efectuăm downcasting la clasa Ingrijitor folosind dynamic_cast
    Angajat* angajat=new Ingrijitor("Paulica", 89, "M", 50, 17, 23400, "strut", 35);
    Ingrijitor* ingrijitor=dynamic_cast<Ingrijitor*>(angajat);
    if (ingrijitor){
        cout<<"Angajatul este un Ingrijitor.\n";
        cout<<"Animalul preferat: "<<ingrijitor->get_animal_preferat()<<endl;
        cout<<"Numarul de custi: "<<ingrijitor->get_nr_custi()<<endl;
    }
    else{
        cout<<"Angajatul nu este un Ingrijitor.\n";
    }
    delete angajat;
    cout<<"\n";
    try{
        feedAnimal(-1);
    }catch(const ZooException& ex){
        cout<<"ZooException caught: "<<ex.what()<<endl;
        throw NewZooException("Error while feeding animal.");
    }catch(const NewZooException& ex){
        cout<<"NewZooException caught: "<<ex.what()<<endl;
    }
    VeterinarSpecializat specialist("Alexandru");
    specialist.consultaAnimal("cangur");
    specialist.efectueazaOperatie("maimuta", "sterilizare");
    specialist.efectueazaTratament("cerb", "dermatita");
    VeterinarSpecializat vet1;
    cout<<"Nivelul veterinarului: "<<vet1.get_nivel_vet()<<endl;
//    int hrana_animale=3000, salariu_angajati=12000, chirie=4200, intretinere=3500;
//    int rezultat= cheltuialaTotala(hrana_animale, salariu_angajati, chirie, intretinere);
//    cout<<"Cheltuiala totala: "<<rezultat<<" de lei"<<endl;
}
