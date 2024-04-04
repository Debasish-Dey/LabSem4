#include <iostream>
#include <queue>
#include <unordered_map>
#include <string.h>

using namespace std;

struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->frequency > r->frequency;
    }
};

HuffmanNode* buildHuffmanTree(const unordered_map<char, unsigned>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode *left = pq.top(); pq.pop();
        HuffmanNode *right = pq.top(); pq.pop();
        HuffmanNode *parent = new HuffmanNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

void encodeHuffman(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
    }

    encodeHuffman(root->left, code + "0", huffmanCode);
    encodeHuffman(root->right, code + "1", huffmanCode);
}

void displayHuffmanCodes(const unordered_map<char, string>& huffmanCode) {
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    // getline(cin, input);

    unordered_map<char, unsigned> freqMap;
    for (char c : input) {
        freqMap[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(freqMap);

    unordered_map<char, string> huffmanCode;
    encodeHuffman(root, "", huffmanCode);

    displayHuffmanCodes(huffmanCode);

    return 0;
}
