#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <sstream>

bool sortByVardas(const Studentas &a, const Studentas &b)
{
    return a.vardas < b.vardas;
}

bool sortByPavarde(const Studentas &a, const Studentas &b)
{
    return a.pavarde < b.pavarde;
}

bool sortByVidurkis(const Studentas &a, const Studentas &b)
{
    double vidurkisA = 0.4 * vidurkis(a.nd_rezultatai) + 0.6 * a.egzaminas;
    double vidurkisB = 0.4 * vidurkis(b.nd_rezultatai) + 0.6 * b.egzaminas;
    return vidurkisA < vidurkisB;
}

bool sortByMediana(const Studentas &a, const Studentas &b)
{
    double medianaA = 0.4 * mediana(a.nd_rezultatai) + 0.6 * a.egzaminas;
    double medianaB = 0.4 * mediana(b.nd_rezultatai) + 0.6 * b.egzaminas;
    return medianaA < medianaB;
}

void spausdintiGalutiniusBalus(const std::vector<Studentas> &studentai, const std::string &isvedimoFailoVardas, int rusiavimoTipas)
{
    std::ostream *out;
    std::ofstream fileOut;

    if (!isvedimoFailoVardas.empty())
    {
        fileOut.open(isvedimoFailoVardas);
        out = &fileOut;
    }
    else
    {
        out = &std::cout;
    }

    std::vector<Studentas> surusiuotiStudentai = studentai;

    switch (rusiavimoTipas)
    {
    case 1:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVardas);
        break;
    case 2:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByPavarde);
        break;
    case 3:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVidurkis);
        break;
    case 4:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByMediana);
        break;
    }

    *out << std::fixed << std::setprecision(2);
    *out << "Studentų galutiniai balai:\n";
    *out << "----------------------------------------------------------------\n";
    *out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    *out << "----------------------------------------------------------------\n";

    for (const Studentas &studentas : surusiuotiStudentai)
    {
        double galutinisVidurkis = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        double galutineMediana = 0.4 * mediana(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        *out << std::left << std::setw(15) << studentas.vardas << std::setw(15) << studentas.pavarde << std::setw(20) << galutinisVidurkis << std::setw(20) << galutineMediana << "\n";
    }
    *out << "----------------------------------------------------------------\n";

    if (!isvedimoFailoVardas.empty())
    {
        fileOut.close();
    }
}

void manualInput(std::vector<Studentas> &studentai)
{
    char testi = 't';
    while (testi == 't' || testi == 'T')
    {
        Studentas naujasStudentas;
        std::string temp;

        std::cout << "Įveskite studento vardą: ";
        std::cin >> naujasStudentas.vardas;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> naujasStudentas.pavarde;

        std::cout << "Įveskite namų darbų pažymius (0 norint baigti): ";
        int pazymys;
        while (true)
        {
            std::cin >> pazymys;
            if (std::cin.fail() || pazymys < 0 || pazymys > 10)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neteisingai įvestas pažymys. Turi būti sveikasis skaičius nuo 0 iki 10." << std::endl;
                continue;
            }
            if (pazymys == 0)
            {
                break;
            }
            naujasStudentas.nd_rezultatai.push_back(pazymys);
        }

        std::cout << "Įveskite egzamino rezultatą: ";
        while (true)
        {
            std::cin >> naujasStudentas.egzaminas;
            if (std::cin.fail() || naujasStudentas.egzaminas < 0 || naujasStudentas.egzaminas > 10)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neteisingai įvestas egzamino rezultatas. Turi būti sveikasis skaičius nuo 0 iki 10." << std::endl;
                continue;
            }
            break;
        }

        studentai.push_back(naujasStudentas);

        std::cout << "Ar norite įvesti dar vieną studentą? (t/n): ";
        std::cin >> testi;
    }
}

void generateGradesOnly(std::vector<Studentas> &studentai)
{
    for (Studentas &studentas : studentai)
    {
        generateRandomGrades(studentas);
    }
}

void readFileDataFromFile(std::vector<Studentas> &studentai, const std::string &failoVardas)
{
    std::ifstream failas(failoVardas);
    if (!failas.is_open())
    {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoVardas);
    }

    Studentas studentas;
    std::string eilute;

    while (getline(failas, eilute))
    {
        std::istringstream eilutesSrautas(eilute);
        eilutesSrautas >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        studentas.nd_rezultatai.clear();
        while (eilutesSrautas >> pazymys && pazymys != -1) {
            studentas.nd_rezultatai.push_back(pazymys);
        }

        studentas.egzaminas = pazymys;
        studentai.push_back(studentas);
    }

    failas.close();
}

void generateStudentFiles(const std::vector<int> &sizes)
{
    for (int size : sizes)
    {
        std::string fileName = "studentai" + std::to_string(size) + ".txt";
        std::ofstream outFile(fileName);

        for (int i = 1; i <= size; i++)
        {
            outFile << "Vardas" << i << " Pavarde" << i;
            int ndCount = rand() % 10 + 1; // Generuoti nuo 1 iki 10 namų darbų pažymių
            for (int j = 0; j < ndCount; j++)
            {
                outFile << " " << (rand() % 10 + 1); // Generuoti pažymius nuo 1 iki 10
            }
            outFile << " " << (rand() % 10 + 1); // Egzamino pažymys
            outFile << std::endl;
        }

        outFile.close();
    }
}

void rusiuotiStudentus(const std::vector<Studentas>& studentai) {
    std::vector<Studentas> kietiakiai, vargsiukai;

    for (const auto& studentas : studentai) {
        double galutinisBalas = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        if (galutinisBalas < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakiai.push_back(studentas);
        }
    }

    std::ofstream kietiakiaiFailas("kietiakiai.txt");
    std::ofstream vargsiukaiFailas("vargsiukai.txt");

    for (const auto& studentas : kietiakiai) {
        kietiakiaiFailas << studentas.vardas << " " << studentas.pavarde << " " << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) << std::endl;
    }

    for (const auto& studentas : vargsiukai) {
        vargsiukaiFailas << studentas.vardas << " " << studentas.pavarde << " " << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) << std::endl;
    }

    kietiakiaiFailas.close();
    vargsiukaiFailas.close();

    std::cout << "Studentai išsaugoti į failus: kietiakiai.txt ir vargsiukai.txt." << std::endl;
}