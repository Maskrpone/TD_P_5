#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Objet // objets à stocker dans le véhicule
{
    private:
        int id; // nom de l'objet
        int consoVeh; //son poid
        int benef; // son bénéfice
};

class Vehicule
{
    private:
        int capacity; //capacité du camion
        int nbObj;  //nbre d'objet au total
        std::vector<Objet> objets; //vecteur contenant les objets 
        std::vector<Objet> inTruck; //vecteur contenant les objets dans le camions
};

class Ville {
    private:
        std::string name; // nom de la ville
        std::vector<int> distance; //distance entre cette ville et les autres
};

class Villes // agit comme la liste des villes
{
    private:
        int nbVilles;
        std::vector<Ville> liste; // vecteur contenant les structures de chaques villes (structure précédente)
};

void lectureFichiers(std::string name)
{
    std::ifstream fichier(name, std::ios::in); // ouverture en mode lecture

    if (fichier) // on vérifie que le fichier s'est bien ouvert
    {
        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::cout << ligne << std::endl;
        }
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier !"; // message d'erreur
    }
}

int main(int, char **)
{
    std::string name = "../4villes.txt";
    lectureFichiers(name);
    return 0;
}
