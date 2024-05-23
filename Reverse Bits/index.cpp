#include <iostream>
using namespace std;

uint32_t get(uint32_t n) {
    uint32_t res = 0;

    for (int i = 0; i < 32; i++) {
        int bit = (n >> i) & 1; // Extract the i-th bit
        res |= bit << (31 - i); // Set the bit in the reversed position
    }

    return res;
}

int main() {
    uint32_t n;
    cin >> n;

    cout << get(n) << endl;

    return 0;
}
