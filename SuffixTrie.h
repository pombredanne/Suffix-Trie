#include <stdbool.h>

struct TrieNode
{
    bool end;
    struct TrieNode* parent;
    struct TrieNode* children[26];
};

typedef struct TrieNode TrieNode;

TrieNode* createNode();

struct Trie
{
    TrieNode* root;
};

typedef struct Trie Trie;

Trie* createTrie();
void insert(Trie* trie, char* s);
int letterToInt(char c);
TrieNode* insertChar(TrieNode* node, int i, bool end);
bool isSubstring(Trie* trie, char* s);
int numberOfOccurrence(Trie* trie, char* s);
char* longestRepeated(Trie* trie);
char* nodeToString(TrieNode* node);
