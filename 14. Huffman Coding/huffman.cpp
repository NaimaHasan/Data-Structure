#include <bits/stdc++.h>
using namespace std;

map<char, string> codes;

struct MinHeapNode {
    char data;

    int freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void generateCodes(struct MinHeapNode* root, string str) {
    if (!root)
        return;

    if (root->data != 0)
        codes.insert(pair<char, string>(root->data, str));

    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

MinHeapNode* HuffmanCodes(map<char, int> freq)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (auto itr : freq)
        minHeap.push(new MinHeapNode(itr.first, itr.second));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();


        top = new MinHeapNode(0, left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    generateCodes(minHeap.top(), "");

    return minHeap.top();
}

string decodeHuffman(string encodedString, struct MinHeapNode * root){
    string output;
    MinHeapNode * cur = root;

    for(int i = 0; i < encodedString.length(); i++) {
        if(encodedString[i] == '0'){
            cur = cur->left;
        }
        else if(encodedString[i] == '1'){
            cur = cur->right;
        }
        if(cur->left == NULL && cur->right == NULL){
            output += cur->data;
            cur = root;
        }
    }

    return output;
}

int main()
{
    char input[10005];
    map<char, int> freq;
    string output;

    scanf("%s", input);

    for(int i = 0; input[i]; i++){
        freq[input[i]]++;
    }

    MinHeapNode * codeTreeRoot = HuffmanCodes(freq);

    for(int i = 0; input[i]; i++){
        auto itr = codes.find(input[i]);
        if( itr != codes.end() )
            output += itr->second;
    }

    cout << decodeHuffman(output, codeTreeRoot) << endl;

    return 0;
}