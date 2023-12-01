#include "../coeur/butano.h"

#include "../jour_01/Jour01.h"

int main() {
    bn::core::init();

    Jour01 jour_01;
    jour_01.calculer_calibration_partie_01();
    jour_01.calculer_calibration_partie_02();

    while(true) {
        bn::core::update();
    }
}
