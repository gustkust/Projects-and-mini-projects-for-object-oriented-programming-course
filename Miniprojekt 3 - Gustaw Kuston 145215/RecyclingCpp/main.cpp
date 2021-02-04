#include <memory>
#include "Wezel.h"


// int main() {
// for (int i = 0 ; i < 10; i++) {
//     // po wywolaniue nowego unique_ptr, zostaje wywolany destruktor ~Wezel, plus jeden raz na koncu programu
//     std::unique_ptr<Wezel>(new Wezel());
// }
// return 0;
// }

// int main () {
// for (int i = 0; i < 10; i++) {
//     // uruchomienie ze shared_ptr nic nie zmienilo
//     std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
// }
// }

// z samymi wskaznikami shared_ptr program nie zwalnia pamieci jak nalezy (wystepuja cykliczne dowiazania)
// aby rozwiazac ten problem uzylem weak_ptr w Wezel.h
int main () {
for (int i = 0 ; i < 10; i++) {
    std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
    std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();
    w1->next = w2;
    w2->next = w1;
}
}
