#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Define the CHAR structure
struct CHAR
{
    char symbol;
    int frequency;
};

// Define a structure for a node in the Huffman tree
struct Node
{
    CHAR character;
    Node *left;
    Node *right;
};

// Custom comparison for the priority queue
struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->character.frequency > b->character.frequency;
    }
};

// Function to build the Huffman tree
Node *buildHuffmanTree(vector<CHAR> &characters)
{
    priority_queue<Node *, vector<Node *>, CompareNodes> minHeap;

    // Create leaf nodes for each character and add them to the minHeap
    for (const CHAR &c : characters)
    {
        Node *newNode = new Node();
        newNode->character = c;
        newNode->left = nullptr;
        newNode->right = nullptr;
        minHeap.push(newNode);
    }

    while (minHeap.size() > 1)
    {
        // Extract the two nodes with the lowest frequencies
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with the sum of frequencies
        Node *internalNode = new Node();
        internalNode->character.symbol = '$'; // Special symbol for internal nodes
        internalNode->character.frequency = left->character.frequency + right->character.frequency;
        internalNode->left = left;
        internalNode->right = right;

        // Add the new internal node back to the minHeap
        minHeap.push(internalNode);
    }

    // The remaining node in the minHeap is the root of the Huffman tree
    return minHeap.top();
}

// In-order traversal of the Huffman tree and print characters
void inOrderTraversal(Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        if (root->character.symbol != '$')
        {
            cout << root->character.symbol << " ";
        }
        inOrderTraversal(root->right);
    }
}

int main()
{
    int n;
    cout << "Enter the number of distinct characters: ";
    cin >> n;

    vector<CHAR> characters(n);

    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i].symbol;
    }

    cout << "Enter their frequencies: ";
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i].frequency;
    }

    // Build the Huffman tree
    Node *root = buildHuffmanTree(characters);

    cout << "In-order traversal of the tree (Huffman): ";
    inOrderTraversal(root);

    return 0;
}