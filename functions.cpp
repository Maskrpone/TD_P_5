#include "header.hpp"

void lectureFichiers(std::string& name)
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



Objet::Objet()
{
    this->id = 2;
    this->consoVeh = 10;
    this->benef = 4;
}

int const Objet::getBenef()
{
    return benef;
}

int const Objet::getConsoVeh()
{
    return this->consoVeh;
}

float const Objet::getRatio()
{
    int cons = this->getConsoVeh();
    int benef = this->getBenef();

    return static_cast<float>(benef) / static_cast<float>(cons);
}

std::vector<Objet> const Vehicule::getObj()
{
    return this->objets;
}

void Vehicule::bestBenef() {
    std::vector<Objet> bestRatio;
    std::vector<Objet> copieListe = this->getObj();

    int bestID = 0;
    int secID = 0;
    int ID = 0;
    bool stock = false;

    while (ID != this->nbObj - 1 && stock == true)
    {   
        for (int i = 0; i < nbObj; i++)
        {
            if(copieListe.at(i).getRatio() > copieListe.at(bestID).getRatio()){
                secID = bestID;
                bestID = i;
            }
        }
        
        ID++;
    }

}