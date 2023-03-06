#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Objet
{
private:
    int id;
    int consoVeh;
    int benef;
};

class Vehicule
{
private:
    int capacity;
    int nbObj;
    std::vector<Objet> objets;
};

class Villes
{
private:
    int nbVilles;
    std::vector<std::string> nomVilles;
};

void lectureFichiers(std::string name)
{
    std::ifstream fichier(name, std::ios::in);

    if (fichier)
    {
        std::string ligne;
        while(std::getline(fichier, ligne))
        {
                std::cout << ligne << std::endl;
        }
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier !";
        return;
    }
}

int main(int, char **)
{
    std::string name = "../4villes.txt";
    lectureFichiers(name);
    return 0;
}
