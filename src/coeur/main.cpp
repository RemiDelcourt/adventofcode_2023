#include "../coeur/butano.h"

int main() {
    bn::core::init();

    while(true) {
        bn::core::update();
    }
}
