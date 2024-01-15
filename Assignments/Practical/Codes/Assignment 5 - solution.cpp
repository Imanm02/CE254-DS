#include <iostream>
#include <map>

using namespace std;

map<int, int> rootLinks;

int findRoot(int amount) {
    if (rootLinks.find(amount) == rootLinks.end())
        return amount;
    else {
        int root = findRoot(rootLinks[amount]);
        rootLinks[amount] = root;
        return root;
    }
}

int main() {
    int queries;
    scanf("%d", &queries);
    int maxRoot = 0;

    for (int i = 0; i < queries; i++) {
        int amount1, amount2;
        scanf("%d %d", &amount1, &amount2);
        int root1 = findRoot(amount1);
        int root2 = findRoot(amount2);

        if (root2 == -1 && root1 == root2) {
            maxRoot = -1;
            break;
        }

        if (root2 != -1 && (root1 > root2 || root1 == -1)) {
            maxRoot = max(maxRoot, root2);
            rootLinks[root2] = root1;
        } else {
            maxRoot = max(maxRoot, root1);
            rootLinks[root1] = (root2 == -1) ? -1 : root2;
        }
    }
    printf("%d", maxRoot);

    return 0;
}