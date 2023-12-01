#ifndef JOUR01_H
#define JOUR01_H

#include "../coeur/butano.h"

class Jour01 {
public:
    Jour01();

    static void calculer_calibration_partie_01();
    static void calculer_calibration_partie_02();

private:
    static int calculer_valeur_calibration_partie_01(const bn::string_view& sv);
    static int calculer_valeur_calibration_partie_02(const bn::string_view& sv);
};

#endif // JOUR01_H
