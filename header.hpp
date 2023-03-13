#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>

class Objet // objets à stocker dans le véhicule
{
    private:
        int id; // nom de l'objet
        int consoVeh; //son poid
        int benef; // son bénéfice
    public:
        Objet();
        Objet(std::string&);
        const int getBenef();
        const int getConsoVeh();
        const float getRatio();   
};

class Vehicule
{
    private:
        int capacity; //capacité du camion
        int nbObj;  //nbre d'objet au total
        std::vector<Objet> objets; //vecteur contenant les objets 
        std::vector<Objet> inTruck; //vecteur contenant les objets dans le camions
    public:
        std::vector<Objet> const getObj();
        void bestBenef();
};

class Villes // agit comme la liste des villes
{
    private:
        int nbVilles;
        // std::vector<Ville> liste; // vecteur contenant les structures de chaques villes (structure précédente)
};

void lectureFichiers(std::string&);
std::vector<std::vector<int>> recupObjets(std::string&);