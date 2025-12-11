#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> outputFiles = {
        "C:\\Users\\User\\Desktop\\folder\\Jakub_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Adam_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Karol_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Mikołaj_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Hubert_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Dawid_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Artur_gift.txt",
        "C:\\Users\\User\\Desktop\\folder\\Julka_gift.txt"
    };

    std::unordered_map<std::string, int> nameCount;

    for (const auto& filename : outputFiles) {
        std::ifstream fin(filename, std::ios::binary);
        if (!fin) {
            std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
            continue;
        }

        std::string name;
        std::getline(fin, name);
        fin.close();

        // Usuwamy spacje na końcu
        name.erase(name.find_last_not_of(' ') + 1);

        nameCount[name]++;
    }

    bool allUnique = true;
    for (const auto& pair : nameCount) {
        if (pair.second != 1) {
            std::cout << "Imię \"" << pair.first << "\" pojawia się " << pair.second << " razy!" << std::endl;
            allUnique = false;
        }
    }

    if (allUnique) {
        std::cout << "Sprawdzenie zakończone. Wszystkie imiona są unikalne." << std::endl;
    }
    else {
        std::cout << "Uwaga! Niektóre imiona powtarzają się." << std::endl;
    }

    return 0;
}
