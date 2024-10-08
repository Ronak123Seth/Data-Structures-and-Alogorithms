/*
Spell Checker using custom dictionary
*/

#include <iostream>
#include <vector>
#include <string>

#define underlineOn "\033[4m"
#define underlineOff "\033[0m"

using namespace std;

// Trie Node Structure
struct TrieNode {
    bool terminating = false;
    TrieNode* children[26] = {nullptr};
};

// Trie Class Definition
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insertWord(const string& word) {
        TrieNode* currNode = root;
        for (char c : word) {
            if (currNode->children[c - 'a'] == nullptr) {
                currNode->children[c - 'a'] = new TrieNode();
            }
            currNode = currNode->children[c - 'a'];
        }
        currNode->terminating = true;
    }

    bool searchWord(const string& word) {
        TrieNode* currNode = root;
        for (char c : word) {
            if (currNode->children[c - 'a'] != nullptr) {
                currNode = currNode->children[c - 'a'];
            } else {
                return false;
            }
        }
        return currNode->terminating;
    }
};

int main() {
    Trie oTrie;

    vector<string> words = { "cat", "car", "cart", "ball", "bat", "bats", "hell" };
    for (const string& word : words)
        oTrie.insertWord(word);

    string s = "";
    char c;
    while ((c = getchar())) {
        if (c == '\n') { // break on enter
            oTrie.searchWord(s) ? cout << s : cout << underlineOn << s << underlineOff;
            cout << c;
            s = "";  // Reset the string for the next line
        } else if (c == ' ') {
            oTrie.searchWord(s) ? cout << s : cout << underlineOn << s << underlineOff;
            cout << c;
            s = "";  // Reset the string for the next word
        } else {
            s += c;  // Add character to the current word
        }
    }

    cout << endl << endl;
    return 0;
}
