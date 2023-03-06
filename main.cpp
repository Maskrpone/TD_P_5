#include "header.hpp"

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
