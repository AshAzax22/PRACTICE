#include <bits/stdc++.h>
using namespace std;

struct Node {
    int profit;
    vector<Node*> children;
    Node(int p) : profit(p) {}
};

// Declare dfs function here
void dfs(Node* node, int currentProfit, int& maxProfit) {
    if (!node) {
        return;
    }
    currentProfit += node->profit;
    maxProfit = max(maxProfit, currentProfit);
    for (int i = 0; i < node->children.size(); ++i) {
        dfs(node->children[i], currentProfit, maxProfit);
    }
}

int maxProfitPath(vector<int>& profits) {
    // Parse the input into a tree
    vector<Node*> nodes;
    for (int i = 0; i < profits.size(); ++i) {
        nodes.push_back(new Node(profits[i]));
    }
    Node* root = nodes[0];
    for (int i = 1; i < nodes.size(); ++i) {
        Node* parent = nodes[(i - 1) / 2];
        parent->children.push_back(nodes[i]);
    }

    // Perform a DFS to find the maximum profit sum
    int maxProfit = INT_MIN;
    dfs(root, 0, maxProfit);
    return maxProfit;
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> profits;
    string val;
    while (iss >> val) {
        profits.push_back(val == "null" ? 0 : stoi(val));
    }
    cout << maxProfitPath(profits) << endl;
    return 0;
}
