# Gradina Zoologica ~ Proiect POO
## Descriere Proiect:
In acest proiect, am realizat o aplicatie care gestioneaza o baza de date a unei gradini zoologice, folosind tehnici fundamentale ale programarii pe obiecte.

Acest proiect contine 4 clase: Animal, Spectacol, Bilet si Cost.

### Am folosit si compunere, astfel Spectacol are un vector cu obiecte de tip Animal (reprezentand o lista cu animalele care participa la un spectacol).

### Clasa "Animal":
- Setarea/obtinerea tipului animalului
- Setarea/obtinerea locatiei animalului
- Setarea/obtinerea numelui animalului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre animal
- Suprascrierea operatorului de mutare pentru ca un obiect să poata prelua caracteristicile de la un alt obiect, dezalocand memoria pentru cel din urma

### Clasa "Bilet":
- Setarea/obtinerea pretului biletului
- Setarea/obtinerea tipului biletului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre bilet

### Clasa "Spectacol":
- Setarea/obtinerea numarului maxim de spectatori ai spectacolului
- Setarea/obtinerea orei de incepere a spectacolului
- Setarea/obtinerea numarului de animale ale spectacolului
- Suprascrierea operatorului de afisare pentru afisarea informatiilor despre spectacol

### Clasa "Cost":
- Setarea/obtinerea costului hranei animalelor
- Setarea/obtinerea costului salariilor angajatiilor
- Setarea/obtinerea costului chiriei
- Setarea/obtinerea costului intretinerii
- Suprascrierea operatorului de afisare informatiilor despre cost

### Functiile de business:
- Calculul profitului gradinii zoologice
- Calculul numarului de angajati si salariul total pe care acestia il primesc

Bineinteles ca putem crea obiecte noi cu ajutorul constructorului, dar si sa le copiem, folosind constructorul de copiere si operatorul de atribuire. Memoria alocata pentru atributele de tip siruri de caractere poate fi gestionata cu ajutorul constructorilor si a destructorilor.
