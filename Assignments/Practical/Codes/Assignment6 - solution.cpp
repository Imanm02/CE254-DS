#include<bits/stdc++.h>
#include <iostream>

using namespace std;

const long long mostExample = 3e5 + 5;
const long long mostTough = 1e9 + 7;
const long long mostHard = (long long) 1<<31;

long long input1;
long long input2;
long long father[mostExample];
long long hold[mostExample];
long long fatherOfNode[mostExample];
long long temp1;

long long point;

vector <long long> output;

long long parent(long long temp) {
    if(father[temp] < 0) {
            return temp;
    }
    if(father[temp] >= 0) {
            return parent(father[temp]);
    }

}
long long XOR(long long temp) {
    if(father[temp] < 0) {
            return fatherOfNode[temp];
    }
    long long out = fatherOfNode[temp] ^ XOR(father[temp]);
    return out;
}

void join(long long int1, long long int2, long long int3) {
    long long V = int1, U = int2;
    int1 = parent(int1), int2 = parent(int2);
    if(int1 == int2) {
        long long temp1 = XOR(V) ^ int3, temp2 = XOR(U);
        if(temp1 != temp2) {
            point = 1;
        }
        if(temp1 == temp2) {
            point = 0;
        }
        return;
    }
    temp1--;
    if(father[int1] > father[int2]){
            swap(int1, int2);
    }
    long long int4 = XOR(V);
    long long int5 = XOR(U);
    fatherOfNode[int2] = int4 ^ int5 ^ int3;
    father[int1] = father[int1] + father[int2];
    father[int2] = int1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    hold[0] = 1;
    cin >> input1;
    cin >> input2;
    hold[1] = 1 % mostTough * mostHard % mostTough;
    for(long long i = 2; i < mostExample; i++) {
        hold[i] = hold[i - 1] % mostTough * mostHard % mostTough;
    }
    temp1 = input1;
    memset(father, -1, sizeof(father));
    for(long long i = 1; i <= input2; i++) {
        long long temporory1, temporory2, temporory3;
        cin >> temporory1;
        cin >> temporory2;
        cin >> temporory3;
        join(temporory1, temporory2, temporory3);
        if(point == 1) {
            output.push_back(0);
        }
        else {
            output.push_back(hold[temp1]);
        }
    }
    for(long long i = 0; i < input2; i++){
        cout<<output[i]<<'\n';
    }

    return 0;
}
