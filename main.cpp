#include <iostream>
#include <cstring>
using namespace std;
class Animal{
   char* tip;
   char* locatie;
   char* nume;
public:
    Animal(){
       tip=new char[8];
       strcpy(tip, "mamifer");
       locatie=new char[3];
       strcpy(locatie, "N");
       nume=new char[8];
       strcpy(nume, "maimuta");
    }
    Animal(const char* type, const char* location, const char* name ){
        tip=new char[strlen(type)+1];
        strcpy(tip, type);
        locatie=new char[strlen(location)+1];
        strcpy(locatie, location);
        nume=new char[strlen(name)+1];
        strcpy(nume, name);
    }
    Animal(const Animal& other){
        delete[] tip;
        tip=new char[strlen(other.tip)];
        strncpy(tip, other.tip, strlen(other.tip));
        tip[strlen(other.tip)]='\0';
        delete[] locatie;
        locatie=new char[strlen(other.locatie)];
        strncpy(locatie, other.locatie, strlen(other.locatie));
        locatie[strlen(other.locatie)]='\0';
        delete[] nume;
        nume=new char[strlen(other.nume)];
        strncpy(nume, other.nume, strlen(other.nume));
        nume[strlen(other.nume)]='\0';
    }
    ~Animal(){
        if(tip!=nullptr)delete[] tip;
        if(locatie!=nullptr)delete[] locatie;
        if(nume!=nullptr)delete[] nume;
    }
    Animal(Animal&& other)noexcept{
        tip=other.tip;
        locatie=other.locatie;
        nume=other.nume;
        other.tip=nullptr;
        other.locatie=nullptr;
        other.nume=nullptr;
    }
    Animal& operator=(Animal&& other){
        if(this!=&other){
            if(tip!=nullptr)delete[] tip;
            if(locatie!=nullptr)delete[] locatie;
            if(nume!=nullptr)delete[] nume;
            tip=other.tip;
            locatie=other.locatie;
            nume=other.nume;
            other.tip=nullptr;
            other.locatie=nullptr;
            other.nume=nullptr;
        }
        return *this;
    }
    Animal& operator=(const Animal& other){
        if(this!=&other){
            delete[] tip;
            delete[] locatie;
            delete[] nume;
            tip=new char[strlen(other.tip)];
            strncpy(tip, other.tip, strlen(other.tip));
            tip[strlen(other.tip)]='\0';
            locatie=new char[strlen(other.locatie)];
            strncpy(locatie, other.locatie, strlen(other.locatie));
            locatie[strlen(other.locatie)]='\0';
            nume=new char[strlen(other.nume)];
            strncpy(nume, other.nume, strlen(other.nume));
            nume[strlen(other.nume)]='\0';
        }
        return *this;
    }
    const char* get_tip() const;
    const char* get_locatie() const;
    const char* get_nume() const;
    void set_tip(const char* new_tip);
    void set_locatie(const char* new_locatie);
    void set_nume(const char* new_nume);
    friend ostream& operator<<(ostream& out, const Animal& animal);
};
const char* Animal::get_tip() const {
    return tip;
}
const char* Animal::get_locatie() const {
    return locatie;
}
const char* Animal::get_nume() const {
    return nume;
}
void Animal::set_tip(const char* new_tip){
    if(tip!= nullptr)delete[] tip;
    tip=new char[strlen(new_tip)+1];
    strcpy(tip, new_tip);
}
void Animal::set_locatie(const char* new_locatie){
    if(locatie!= nullptr)delete[] locatie;
    locatie=new char[strlen(new_locatie)+1];
    strcpy(locatie, new_locatie);
}
void Animal::set_nume(const char* new_nume){
    if(nume!= nullptr)delete[] nume;
    nume=new char[strlen(new_nume)+1];
    strcpy(nume, new_nume);
}
ostream& operator<<(ostream& out, const Animal& animal){
    out<<"Tipul animalului: "<<animal.tip<<endl;
    out<<"Locatia in gradina: "<<animal.locatie<<endl;
    out<<"Specia animalului: "<<animal.nume<<endl;
    return out;
}

class Bilet{
    int pret;
    char* tip_bilet;
public:
    Bilet(){
        pret=100;
        tip_bilet=new char[20];
        strcpy(tip_bilet, "adult");
    }
    Bilet(int price, const char* type_bilet){
        pret=price;
        tip_bilet=new char[strlen(type_bilet)+1];
        strcpy(tip_bilet, type_bilet);
    }
    Bilet(const Bilet& other){
        pret=other.pret;
        delete[] tip_bilet;
        tip_bilet=new char[strlen(other.tip_bilet)];
        strncpy(tip_bilet, other.tip_bilet, strlen(other.tip_bilet));
        tip_bilet[strlen(other.tip_bilet)]='\0';
    }
    ~Bilet(){
        if(tip_bilet!= nullptr)delete[] tip_bilet;
    }
    Bilet& operator=(const Bilet& other){
        if(this!=&other) {
            delete[] tip_bilet;
            pret=other.pret;
            tip_bilet = new char[strlen(other.tip_bilet)];
            strncpy(tip_bilet, other.tip_bilet, strlen(other.tip_bilet));
            tip_bilet[strlen(other.tip_bilet)] = '\0';
        }
        return *this;
    }
    int get_pret() const;
    const char* get_tip_bilet() const;
    void set_pret( int new_pret);
    void set_tip_bilet(const char* new_tip_bilet);
    friend ostream& operator<<(ostream& out, const Bilet& bilet);

};
int Bilet::get_pret() const{
        return pret;
    }
const char* Bilet::get_tip_bilet() const {
    return tip_bilet;
}
void Bilet::set_pret(int new_pret) {
    pret=new_pret;
}
void Bilet::set_tip_bilet(const char* new_tip_bilet) {
    if (tip_bilet != nullptr)delete[] tip_bilet;
    tip_bilet = new char[strlen(new_tip_bilet) + 1];
    strcpy(tip_bilet, new_tip_bilet);
}
ostream& operator<<(ostream& out, const Bilet& bilet){
    out<<"Pretul biletului: "<<bilet.pret<<" de lei"<<endl;
    out<<"Tipul biletului: "<<bilet.tip_bilet<<endl;
    return out;
}

class Spectacol{
    Animal* lista_animale;
    int nr_max_spectatori;
    int ora;
    int nr_animale;
public:
    Spectacol(){
        nr_animale=0;
        lista_animale=nullptr;
        nr_max_spectatori=1000;
        ora=12;
    }
    Spectacol(const Animal* animal_list ,int nr_max_spectators, int hour, int nr_animals){
        nr_animale=nr_animals;
        nr_max_spectatori=nr_max_spectators;
        ora=hour;
        lista_animale=new Animal[nr_animals];
        for(int i=0;i<nr_animals;i++)
            lista_animale[i]=animal_list[i];
    }
    Spectacol(const Spectacol& other){
        nr_max_spectatori=other.nr_max_spectatori;
        ora=other.ora;
        nr_animale=other.nr_animale;
        delete[] lista_animale;
        lista_animale=new Animal[other.nr_animale];
        for(int i=0;i<other.nr_animale;i++)
            lista_animale[i]=other.lista_animale[i];

    }
    ~Spectacol(){
        if(lista_animale!=nullptr)delete[] lista_animale;
    }
    Spectacol& operator=(const Spectacol& other){
        if(this!=&other){
            delete[] lista_animale;
            nr_max_spectatori=other.nr_max_spectatori;
            ora=other.ora;
            nr_animale=other.nr_animale;
            lista_animale= new Animal[other.nr_animale];
            for(int i=0;i<other.nr_animale;i++)
               lista_animale[i]=other.lista_animale[i];
        }
        return *this;
    }
    int get_nr_animale() const;
    int get_nr_max_spectatori() const;
    int get_ora() const;
    void set_nr_animale(int new_nr_animale);
    void set_nr_max_spectatori(int new_nr_max_spectatori);
    void set_ora(int new_ora);
    void set_lista_animale(Animal* new_lista_animale, int nr_necuvincioase);
    friend ostream& operator<<(ostream& out, const Spectacol& spectacol);
};
int Spectacol::get_nr_animale() const{
    return nr_animale;
}
int Spectacol::get_nr_max_spectatori() const{
    return nr_max_spectatori;
}
int Spectacol::get_ora() const{
    return ora;
}
void Spectacol::set_nr_animale(int new_nr_animale){
    nr_animale=new_nr_animale;
}
void Spectacol::set_nr_max_spectatori(int new_nr_max_spectatori) {
    nr_max_spectatori=new_nr_max_spectatori;
}
void Spectacol::set_ora(int new_ora){
    ora=new_ora;
}
void Spectacol::set_lista_animale(Animal* new_lista_animale, int nr_necuvincioase){
    if (lista_animale != nullptr)delete[] lista_animale;
    nr_animale=nr_necuvincioase;
    if(nr_necuvincioase>0) {
        lista_animale = new Animal[nr_necuvincioase];
        for (int i = 0; i < nr_necuvincioase; i++)
            lista_animale[i] = new_lista_animale[i];
    }
}
ostream& operator<<(ostream& out, const Spectacol& spectacol) {
    out << "Numarul de animale: " << spectacol.nr_animale << endl;
    out << "Numarul maxim de spectatori: " << spectacol.nr_max_spectatori << endl;
    out << "Ora spectacolului: " << spectacol.ora << endl;
    out << "Lista de animale: " << endl;
    out<<"\n";
    int ok=0;
    for (int i = 0; i < spectacol.nr_animale; i++)
    {ok=1;
        out << "Animal " << i + 1 << ": " << endl << spectacol.lista_animale[i] << endl;}
    if(ok==0)out<<"Nu exista";
    out<<"\n";
    return out;
}
class Cost{
    int hrana_animale;
    int salariu_angajat;
    int chirie;
    int intretinere;
public:

    Cost() {
        hrana_animale = 10000;
        salariu_angajat = 2000;
        chirie = 3000;
        intretinere = 1700;
    }

    Cost(int animal_food, int salary, int rent, int maintenance){
        hrana_animale=animal_food;
        salariu_angajat=salary;
        chirie=rent;
        intretinere=maintenance;
    }

    Cost(const Cost& other){
        hrana_animale=other.hrana_animale;
        salariu_angajat=other.salariu_angajat;
        chirie=other.chirie;
        intretinere=other.intretinere;
    }

    ~Cost()=default;
    Cost& operator=(const Cost& other){
        hrana_animale=other.hrana_animale;
        salariu_angajat=other.salariu_angajat;
        chirie=other.chirie;
        intretinere=other.intretinere;
    }

    int get_hrana_animale() const;
    int get_salariu_angajat() const;
    int get_chirie() const;
    int get_intretinere() const;
    void set_hrana_animale(int new_hrana_animale);
    void set_salariu_angajat(int new_salariu_angajat);
    void set_chirie(int new_chirie);
    void set_intretinere(int new_intretinere);
    friend ostream& operator<<(ostream& out, const Cost& cost);

};
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
ostream& operator<<(ostream& out, const Cost& cost){
    out<<"Pretul hranei animalelor: "<<cost.hrana_animale<<" de lei"<<endl;
    out<<"Salariul angajatului: "<<cost.salariu_angajat<<" de lei"<<endl;
    out<<"Pretul chiriei: "<<cost.chirie<<" de lei"<<endl;
    out<<"Pretul intretinerii: "<<cost.intretinere<<" de lei"<<endl;
    return out;
}
int profitul_gradinii_zoo(const char* tip_bilet, int nr_max_spectatori, int hrana_animale, int salariu_angajat, int chirie, int intretinere){
    int profit;
    if(tip_bilet=="adult")profit=100*nr_max_spectatori-(hrana_animale+salariu_angajat+chirie+intretinere);
    if(tip_bilet=="student")profit=50*nr_max_spectatori-(hrana_animale+salariu_angajat+chirie+intretinere);
    else if(tip_bilet=="copil")profit=20*nr_max_spectatori-(hrana_animale+salariu_angajat+chirie+intretinere);
    return profit;
}
int plata_angajati(int angajat_casa_bilete, int nr_animale){
    int plata=0;
    int x;
    int y;
    x=nr_animale*3;
    plata=angajat_casa_bilete*900+x*1800;
    y=angajat_casa_bilete+x;
    cout<<endl;
    cout<<"Numarul de angajati: "<<y<<endl;
    cout<<"Salariul total al angajatiilor: ";
    return plata;

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
    Animal animal4=std::move(animal1);
    cout<<animal4<<endl;
    cout<<"\n";
    Bilet bilet1;
    cout<<bilet1<<endl;
    Bilet bilet2;
    bilet2.set_pret(50);
    bilet2.set_tip_bilet("student");
    cout<<bilet2<<endl;
    Bilet bilet3(20, "copil");
    cout<<bilet3<<endl;
    cout<<"Pret cu get: "<<bilet3.get_pret()<<" de lei"<<endl;
    cout<<"Tip bilet cu get: "<<bilet3.get_tip_bilet()<<endl;
    cout<<"\n";
    Spectacol spectacol1;
    cout<<spectacol1<<endl;
    Spectacol spectacol2;
    spectacol2.set_nr_animale(3);
    spectacol2.set_nr_max_spectatori(100);
    spectacol2.set_ora(16);
    Animal listuta_animalute[3];
    listuta_animalute[0]=Animal("pasare", "SV", "rata");
    listuta_animalute[1]=Animal("mamifer", "NV", "cal");
    listuta_animalute[2]=Animal("mamifer", "E", "vaca");
    spectacol2.set_lista_animale(listuta_animalute, 3);
    cout<<spectacol2<<endl;
    Animal animal_list[3];
    animal_list[0] = Animal("mamifer", "N", "leu");
    animal_list[1] = Animal("mamifer", "SE", "tigru");
    animal_list[2] = Animal("reptila", "V", "broasca testoasa");
    Spectacol spectacol3(animal_list, 500, 14, 3);
    cout<<spectacol3<<endl;
    cout<<"Nr animale cu get: "<<spectacol3.get_nr_animale()<<endl;
    cout<<"Nr max spectatori cu get: "<<spectacol3.get_nr_max_spectatori()<<endl;
    cout<<"Ora cu get: "<<spectacol3.get_ora()<<endl;
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
    cout<<"Profitul gradinii zoo: "<<profitul_gradinii_zoo("adult", 200, 1000, 900, 1700, 600)<<" de lei"<<endl;
    cout<<"\n";
    cout<<plata_angajati(2, 4)<<" de lei"<<endl;
}
