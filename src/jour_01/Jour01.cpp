#include "../jour_01/Jour01.h"
#include "../jour_01/input_jour_01.h"
#include <cctype>

Jour01::Jour01() {
}

void Jour01::calculer_calibration_partie_01() {
    int res = 0;

    for(const bn::string_view& sv : jour_01::input){
        res += calculer_valeur_calibration_partie_01(sv);
    }


    BN_LOG("Total calibration partie 01 : ", res);

}

void Jour01::calculer_calibration_partie_02() {
    int res = 0;

    constexpr const bn::array<bn::string_view, 7> exemple = {
        "two1nine",
        "eightwothree",
        "abcone2threexyz",
        "xtwone3four",
        "4nineeightseven2",
        "zoneight234",
       "7pqrstsixteen"
    };

    for(const bn::string_view& sv : jour_01::input){
        res += calculer_valeur_calibration_partie_02(sv);
    }

    BN_LOG("Total calibration partie 02 : ", res);

}




int Jour01::calculer_valeur_calibration_partie_01(const bn::string_view&sv) {
    // Premier chiffre
    char chiffre_debut;
    auto it = std::find_if(sv.begin(), sv.end(), [](char c) {
        //return c >= 48 || c <= 57;
        return std::isdigit(c);
    });

    if (it != sv.end()) {
        //BN_LOG("Premier caractère trouvé: ", *it);
        chiffre_debut = *it;
    }


    // Dernier chiffre
    char chiffre_fin;
    auto rit = std::find_if(sv.rbegin(), sv.rend(), [](char c) {
        return std::isdigit(c);
    });

    if (rit != sv.rend()) {
        //BN_LOG("Dernier caractère trouvé: ", *rit);
        chiffre_fin = *rit;
    }

    int chiffre = (chiffre_debut - '0') * 10 + (chiffre_fin - '0');

    return chiffre;
}

int Jour01::calculer_valeur_calibration_partie_02(const bn::string_view& sv) {
    static constexpr const bn::array<bn::string_view, 9> chiffres_lettres = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    static constexpr const bn::array<int, 9> chiffres = {1, 2, 3, 4, 5, 6, 7, 8, 9};


    bn::vector<int, 2> liste;

    int i = 0;
    for(const char& c : sv){
        if(std::isdigit(c)){
            BN_LOG(c);
            if(liste.full()){
                liste.pop_back();
            }
            liste.push_back(c - '0');
        }
        else{
            auto x = sv.substr(i);
            for(int j = 0 ; j < chiffres_lettres.size() ; j++){
                if(x.starts_with(chiffres_lettres[j])){
                    BN_LOG(chiffres_lettres[j]);
                    if(liste.full()){
                        liste.pop_back();
                    }
                    liste.push_back(chiffres[j]);

                    break;
                }
            }
        }
        i++;
    }

    int chiffre = 0;

    if(liste.size() == 1){
        chiffre = (liste[0] * 10) + liste[0];
    }
    else{
        chiffre = (liste[0] * 10) + liste[1];
    }

    BN_LOG("res: ", chiffre);
    BN_LOG("-----------------");


    return chiffre;

}
