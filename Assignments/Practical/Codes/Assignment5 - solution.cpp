#include <iostream>
#include <map>

using namespace std;
map<int, int> RisheHa;

int RishehYab(int amount);

int main() {
    int input;
    scanf("%d", &input);
    int output = 0;
    int amount1, amount2;
    int risheh1, risheh2;

    for (int i = 0; i < input; i++) {
        scanf("%d", &amount1);
        risheh1 = RishehYab(amount1);
        scanf("%d", &amount2);
        risheh2 = RishehYab(amount2);
        if (risheh2 == -1 && risheh1 == risheh2) {
            output = -1;
            break;
        }
        if (risheh2!= -1 && (risheh1 > risheh2 || risheh1 == -1)) {
            if (output < risheh2) output = risheh2;
            RisheHa[risheh2] = risheh1;
        }
        else if (risheh2 == -1) {
            if (output < risheh1) output = risheh1;
            RisheHa[risheh1] = risheh2;
        }
        else if (risheh2 <= risheh1) {
            if (output < risheh1){
            output = risheh1;
            RisheHa[risheh1] = -1;
            }
        }
        else if (risheh2 > risheh1) {
            if (output < risheh1) output = risheh1;
            RisheHa[risheh1] = risheh2;
        }
    }
    printf("%d", output);

    return 0;
}

int RishehYab(int amount) {
    if (RisheHa.find(amount) == RisheHa.end())
        return amount;
    else if (RisheHa.find(amount) != RisheHa.end()) {
        int risheh = RishehYab(RisheHa[amount]);
        RisheHa[amount] = risheh;
        return risheh;
    }
}
