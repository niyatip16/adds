#include "PrefixMatcher.h"

class PrefixMatcher::TrieNode {
public:
    TrieNode* children[2];  
    int routerNumber;

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        routerNumber = -1;  
    }
};

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

void PrefixMatcher::insert(const std::string& address, int routerNumber) {
    TrieNode* node = root;
    for (char bit : address) {
        int index = bit - '0';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(const std::string& networkAddress) {
    TrieNode* node = root;
    int selectedRouter = -1; 

    for (char bit : networkAddress) {
        int index = bit - '0';
        if (!node->children[index]) {
            break; 
        }
        node = node->children[index];
        if (node->routerNumber != -1) {
            selectedRouter = node->routerNumber;
        }
    }

    return selectedRouter;
}
