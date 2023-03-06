#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


class Objet {
private:
    int id;
    int consoVeh;
    int benef;
public:
    Objet();
    Objet(int i, int conso, int ben);
    int Getid();
    int Getconso();
    int Getbenef();
    void Setid(int i);
    void Setconso(int conso);
    void Setbenef(int ben);
};


class Vehicule {
private:
    int capacity;
    int nbObj;
    std::vector<Objet> objets;
public:
    Vehicule();
    Vehicule(int capa, int nb);
    int Getcapa();
    int Getnbobj();
    std::vector<Objet> Getobjets();
    void Setcapa(int capa);
    void Setnbobj(int nb);
    void AddObj(Objet obj);
};


class Villes {
private:
    int nbVilles;
    std::vector<std::string> nomsVilles;
    std::vector<std::vector<int>> matrice;
public:
    Villes();
    Villes(int nb);
    int Getnbvilles();
    std::vector<std::string> Getnoms();
    std::vector<std::vector<int>> Getmatrice();
    void Setnbvilles(int nb);
    void Setnoms(std::vector<std::string> noms);
    void Setmatrice(std::vector<std::vector<int>> mat);
};

