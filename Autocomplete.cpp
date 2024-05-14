#include "Autocomplete.h"

class Autocomplete::TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(const std::string& word) {
    insertWord(root, word);
}

void Autocomplete::insertWord(TrieNode* node, const std::string& word) {
    for (char ch : word) {
        int index = ch - 'a';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* node = root;

    for (char ch : partialWord) {
        int index = ch - 'a';
        if (!node->children[index]) {
            return suggestions; 
        }
        node = node->children[index];
    }

    getSuggestionsHelper(node, partialWord, suggestions);
    return suggestions;
}

void Autocomplete::getSuggestionsHelper(TrieNode* node, std::string currentPrefix, std::vector<std::string>& suggestions) {
    if (node == nullptr) {
        return;
    }

    if (node->isEndOfWord) {
        suggestions.push_back(currentPrefix);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char ch = 'a' + i;
            getSuggestionsHelper(node->children[i], currentPrefix + ch, suggestions);
        }
    }
}
