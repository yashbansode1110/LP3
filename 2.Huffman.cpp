
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;

    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Min Heap Comparator
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : ";

        if (code == "")
            cout << "0";
        else
            cout << code;

        cout << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input";
        return 0;
    }

    char ch[n];
    int freq[n];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
        cin >> ch[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    // Create Min Heap
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters
    for (int i = 0; i < n; i++)
        pq.push(new Node(ch[i], freq[i]));

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }
    
    // Print Huffman Codes
    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");

    return 0;
}
