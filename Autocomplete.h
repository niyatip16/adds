#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

class Autocomplete {
public:
    Autocomplete();
    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord);

private:
    class TrieNode;
    TrieNode* root;
    void insertWord(TrieNode* node, const std::string& word);
    void getSuggestionsHelper(TrieNode* node, std::string currentPrefix, std::vector<std::string>& suggestions);
};

#endif 
