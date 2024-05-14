#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>

class PrefixMatcher {
public:
    PrefixMatcher();
    void insert(const std::string& address, int routerNumber);
    int selectRouter(const std::string& networkAddress);

private:
    class TrieNode;
    TrieNode* root;
};

#endif 
