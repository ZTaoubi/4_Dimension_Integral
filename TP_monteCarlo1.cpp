// Ce projet fait partie de mon travail académique dans le cadre du cours dirigé par mon professeur, Monsieur Krim.
// L'objectif est d'estimer une intégrale en quatre dimensions en utilisant la méthode de Monte Carlo en C++.
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Fonction à intégrer
double F(double x, double y, double z, double w) {
    return std::exp(x + y + z + w);
}

int main() {
    double sum = 0., x, y, z, w;
    double a, b, c, d, e, f, g, h;
    int N;

    // Demander les bornes d'intégration pour chaque dimension
    std::cout << "Entrez la valeur de la 1ere integrale : borne inferieure\n";
    std::cin >> a;
    std::cout << "Entrez la valeur de la 1ere integrale : borne superieure\n";
    std::cin >> b;
    std::cout << "Entrez la valeur de la 2eme integrale : borne inferieure\n";
    std::cin >> c;
    std::cout << "Entrez la valeur de la 2eme integrale : borne superieure\n";
    std::cin >> d;
    std::cout << "Entrez la valeur de la 3eme integrale : borne inferieure\n";
    std::cin >> e;
    std::cout << "Entrez la valeur de la 3eme integrale : borne superieure\n";
    std::cin >> f;
    std::cout << "Entrez la valeur de la 4eme integrale : borne inferieure\n";
    std::cin >> g;
    std::cout << "Entrez la valeur de la 4eme integrale : borne superieure\n";
    std::cin >> h;
    
    // Demander le nombre de répétitions pour l'estimation
    std::cout << "Entrez le nombre de repetitions\n";
    std::cin >> N;

    // Initialiser le générateur de nombres aléatoires
    std::srand(std::time(0));

    // Boucle Monte Carlo pour générer des points aléatoires et évaluer l'intégrale
    for (int i = 0; i < N; i++) {
        x = a + (b - a) * static_cast<double>(std::rand()) / RAND_MAX;
        y = c + (d - c) * static_cast<double>(std::rand()) / RAND_MAX;
        z = e + (f - e) * static_cast<double>(std::rand()) / RAND_MAX;
        w = g + (h - g) * static_cast<double>(std::rand()) / RAND_MAX;
        sum += F(x, y, z, w);
    }

    // Calcul de l'intégrale en multipliant par le volume de l'espace intégré
    double I = (b - a) * (d - c) * (f - e) * (h - g) * sum / N;
    std::cout << "Intégrale approximée: " << I << "\n";

    return 0;
}
