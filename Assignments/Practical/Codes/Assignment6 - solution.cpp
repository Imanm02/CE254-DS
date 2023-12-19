#include <bits/stdc++.h>
using namespace std;

const long long MAX_NODES = 3e5 + 5;
const long long MOD = 1e9 + 7;
const long long BASE = (long long)1 << 31;

long long numNodes, numQueries;
long long parentNodes[MAX_NODES], xorValue[MAX_NODES], parentNode[MAX_NODES];
long long queryCounter;

vector<long long> results;

long long findParent(long long node) {
    if (parentNodes[node] < 0) {
        return node;
    }
    return findParent(parentNodes[node]);
}

long long computeXOR(long long node) {
    if (parentNodes[node] < 0) {
        return parentNode[node];
    }
    return parentNode[node] ^ computeXOR(parentNodes[node]);
}

void unionSets(long long node1, long long node2, long long value) {
    node1 = findParent(node1);
    node2 = findParent(node2);

    if (node1 == node2) {
        long long xor1 = computeXOR(node1) ^ value;
        long long xor2 = computeXOR(node2);
        queryCounter = (xor1 != xor2) ? 1 : 0;
        return;
    }

    if (parentNodes[node1] > parentNodes[node2]) {
        swap(node1, node2);
    }

    long long xor1 = computeXOR(node1);
    long long xor2 = computeXOR(node2);
    parentNode[node2] = xor1 ^ xor2 ^ value;
    parentNodes[node1] += parentNodes[node2];
    parentNodes[node2] = node1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> numNodes >> numQueries;
    memset(parentNodes, -1, sizeof(parentNodes));
    for (long long i = 0; i < numQueries; i++) {
        long long node1, node2, value;
        cin >> node1 >> node2 >> value;
        unionSets(node1, node2, value);
        results.push_back(queryCounter ? 0 : BASE);
    }
    for (auto result : results) {
        cout << result << '\n';
    }
    return 0;
}