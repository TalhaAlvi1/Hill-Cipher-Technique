#include <iostream>
#include <vector>
using namespace std;

int charToNum(char c) {
    return c - 'A';
}
char numToChar(int n) {
    return 'A' + n;
}
vector<int> encryptBlock(vector<int> block, vector<vector<int>> keyMatrix, int n) {
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += keyMatrix[i][j] * block[j];
        }
        result[i] %= 26; 
    }
    return result;
}
int main() {
    int n = 2; 
    vector<vector<int>> keyMatrix = {{6, 24}, {1, 13}}; 
    string plaintext;
    cout << "Enter plaintext (uppercase only, no spaces): ";
    cin >> plaintext;

    while (plaintext.size() % n != 0) {
        plaintext += 'X'; // Padding with 'X'
    }
    cout << "Padded Plaintext: " << plaintext << endl;
    string ciphertext = "";
    for (int i = 0; i < plaintext.size(); i += n) {
        vector<int> block(n);
        for (int j = 0; j < n; j++) {
            block[j] = charToNum(plaintext[i + j]);
        }
        vector<int> encryptedBlock = encryptBlock(block, keyMatrix, n);
        for (int num : encryptedBlock) {
            ciphertext += numToChar(num);
        }
    }
    cout << "Ciphertext: " << ciphertext << endl;
    return 0;
}