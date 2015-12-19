#include <stdio.h>
#include "SuffixTrie.h"

int main()
{
    int i;
    TrieNode* node;
    Trie* trie;
    trie=createTrie();
    insert(trie,"gttatagctgatcgcggcgtagcgg");
    printf("%d\n",isSubstring(trie,"ggt"));
    printf("%d\n",isSubstring(trie,"agg"));
    printf("%d\n",isSubstring(trie,"tga"));
    printf("\n");
    printf("%d\n",numberOfOccurrence(trie,"tga"));
    printf("%d\n",numberOfOccurrence(trie,"cg"));
    printf("\n");
    printf("%s\n",longestRepeated(trie));
}
