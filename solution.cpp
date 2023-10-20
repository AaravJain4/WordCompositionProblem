#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
};

TrieNode* createTrieNode() {
    TrieNode* newNode = new TrieNode();
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = nullptr;
    }
    newNode->isEndOfWord = false;
    return newNode;
}

void insertWord(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool isCompoundWord(TrieNode* root, const string& word, int startIndex, int wordCount) {
    int n = word.size();
    TrieNode* node = root;

    for (int i = startIndex; i < n; i++) {
        int index = word[i] - 'a';
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
        if (node->isEndOfWord) {
            if (i == n - 1) {
                return wordCount >= 1;
            }
            if (isCompoundWord(root, word, i + 1, wordCount + 1)) {
                return true;
            }
        }
    }

    return false;
}

bool wordComparator(const string& a, const string& b) {
    return a.size() > b.size();
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    TrieNode* root = createTrieNode();
    vector<string> words;
    ifstream inputFile("Input_02.txt");
    string word;
    while (inputFile >> word) {
        words.push_back(word);
        insertWord(root, word);
    }
    sort(words.begin(), words.end(), wordComparator);

    string longestCompoundWord, secondLongestCompoundWord;

    for (const string& word : words) {
        if (isCompoundWord(root, word, 0, 0)) {
            if (word.size() > longestCompoundWord.size()) {
                secondLongestCompoundWord = longestCompoundWord;
                longestCompoundWord = word;
            } else if (word.size() > secondLongestCompoundWord.size()) {
                secondLongestCompoundWord = word;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Longest Compound Word: " << longestCompoundWord << endl;
    cout << "Second Longest Compound Word: " << secondLongestCompoundWord << endl;
    cout << "Time taken to process file Input_01.txt: " << duration.count() << " milliseconds" << endl;

    return 0;
}
