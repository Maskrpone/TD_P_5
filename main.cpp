#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "header.hpp"


//METHODES
Objet::Objet() {
    id = 0;
    consoVeh = 0;
    benef = 0;
}
Objet::Objet(int i, int conso, int ben) {
    id = i;
    consoVeh = conso;
    benef = ben;
}
int Objet::Getid() {
    return id;
}
int Objet::Getconso() {
    return consoVeh;
}
int Objet::Getbenef() {
    return benef;
}
void Objet::Setid(int i) {
    id = i;
}
void Objet::Setconso(int conso) {
    consoVeh = conso;
}
void Objet::Setbenef(int ben) {
    benef = ben;
}


Vehicule::Vehicule() {
    capacity = 0;
    nbObj = 0;
}
Vehicule::Vehicule(int capa, int nb) {
    capacity = capa;
    nbObj = nb;
}
int Vehicule::Getcapa() {
    return capacity;
}
int Vehicule::Getnbobj() {
    return nbObj;
}
std::vector<Objet> Vehicule::Getobjets() {
    return objets;
}
void Vehicule::Setcapa(int capa) {
    capacity = capa;
}
void Vehicule::Setnbobj(int nb) {
    nbObj = nb;
}
void Vehicule::AddObj(Objet obj) {
    objets.push_back(obj);
}


Villes::Villes() {
    nbVilles = 0;
}
Villes::Villes(int nb) {
    nbVilles = nb;
}
int Villes::Getnbvilles() {
    return nbVilles;
}
std::vector<std::string> Villes::Getnoms() {
    return nomsVilles;
}
std::vector<std::vector<int>> Villes::Getmatrice() {
    return matrice;
}
void Villes::Setnbvilles(int nb) {
    nbVilles = nb;
}
void Villes::Setnoms(std::vector<std::string> noms) {
    nomsVilles = noms;
}
void Villes::Setmatrice(std::vector<std::vector<int>> mat) {
    matrice = mat;
}


Vehicule fichierObjets(std::string name) {

    Vehicule camion;
    Objet o;

    int lettres = 0;
    int nbligne = 1;
    std::ifstream fichier(name, std::ios::in);


    if (fichier.is_open())
    {
        std::string ligne;
        while (getline(fichier, ligne))
        {
            std::cout << ligne << std::endl;
            std::stringstream s(ligne);
            lettres += s.str().length();
            if (nbligne == 1)
            {
                std::string strcapa;
                int capa;
                int nbobj;
                std::size_t posit = ligne.find(" ");
                strcapa = ligne.substr(0, posit);
                capa = std::stoi(strcapa);
                std::stringstream ss;
                ss << ligne.substr(posit);
                ss >> nbobj;

                camion.Setcapa(capa);
                camion.Setnbobj(nbobj);
            }
            else if (nbligne > 1)
            {
                int taille;
                int benef;
                std::size_t posit = ligne.find(" ");
                std::stringstream ss;
                ss << ligne.substr(posit);
                ss >> taille >> benef;

                o.Setid(nbligne-1);
                o.Setconso(taille);
                o.Setbenef(benef);
                camion.AddObj(o);
            }
            nbligne++;
        }
        fichier.close();
        return camion;
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier Objets";
    }
}


Villes fichierVilles(std::string name) {

    Villes zone;
    std::vector<std::string> noms;
    std::vector<std::vector<int>> mat;
    std::vector<int> creation;

    int lettres = 0;
    int nbligne = 1;
    int nbvilles;
    int nb = 0;
    std::ifstream fichier(name, std::ios::in);

    if (fichier.is_open())
    {
        std::string ligne;
        while (getline(fichier, ligne))
        {
            //std::cout << ligne << std::endl;
            std::stringstream s(ligne);
            lettres += s.str().length();
            if (nbligne == 1)
            {
                nbvilles = std::stoi(ligne);
                zone.Setnbvilles(nbvilles);
            }
            else if (nbligne > 1 && nbligne <= nbvilles + 1)
            {
                noms.push_back(ligne);
            }
            else if (nbligne > nbvilles + 1)
            {
                mat.push_back(creation);
                if (nbligne == nbvilles + 2)
                {
                    zone.Setnoms(noms);
                }


                size_t posit = ligne.find(" ");
                std::stringstream ss;

                std::string nom = ligne.substr(0, posit);
                nb = std::stoi(ligne);
                mat.at(nbligne - nbvilles - 2).push_back(nb);

                ss << ligne.substr(posit);
                for (int i = nbvilles; i > 1; i--)
                {
                    ss >> nb;
                    mat.at(nbligne - nbvilles - 2).push_back(nb);
                }
                if (nbligne == nbvilles * 2 + 1)
                {
                    zone.Setmatrice(mat);
                }
            }
            nbligne++;
        }
        fichier.close();
        return zone;
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier Villes";
    }
}

int main(int, char **)
{
    std::string name = "../4villes.txt";
    // lectureFichiers(name);

    
    return 0;
}
