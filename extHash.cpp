#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

// Bucket definition
struct Bucket {
    int localDepth;                 // how many bits this bucket is using
    vector<int> values;             // store keys
    Bucket(int depth) : localDepth(depth) {}
};

class ExtendibleHash {
    int globalDepth;
    int bucketSize;
    vector<Bucket*> directory;

public:
    ExtendibleHash(int initDepth, int bSize) {
        globalDepth = initDepth;
        bucketSize = bSize;
        int size = 1 << globalDepth;   // 2^globalDepth
        for (int i = 0; i < size; i++) {
            directory.push_back(new Bucket(globalDepth));
        }
    }

    // Convert number to binary string with fixed bits
    string toBinary(int num, int bits) {
        return bitset<16>(num).to_string().substr(16 - bits); 
    }

    // Hash function: take lower 'globalDepth' bits
    int hash(int key) {
        return key & ((1 << globalDepth) - 1);
    }

    void insert(int key) {
        int index = hash(key);
        Bucket* bucket = directory[index];

        // If bucket not full
        if ((int)bucket->values.size() < bucketSize) {
            bucket->values.push_back(key);
        } else {
            cout << "Bucket full! Splitting...\n";
            splitBucket(index);
            insert(key); // retry insert
        }
    }

    void splitBucket(int index) {
        Bucket* oldBucket = directory[index];
        int oldLocalDepth = oldBucket->localDepth;

        // If local depth equals global depth -> double directory
        if (oldLocalDepth == globalDepth) {
            globalDepth++;
            int newSize = 1 << globalDepth;
            directory.resize(newSize);
            for (int i = 0; i < newSize; i++) {
                directory[i] = directory[i % (1 << oldLocalDepth)];
            }
            cout << "Expanded directory to depth " << globalDepth << endl;
        }

        // Create new bucket
        Bucket* newBucket = new Bucket(oldLocalDepth + 1);
        oldBucket->localDepth++;

        // Redistribute keys
        vector<int> temp = oldBucket->values;
        oldBucket->values.clear();
        int prefixBit = 1 << (oldBucket->localDepth - 1);
        for (int key : temp) {
            int newIndex = hash(key);
            if (newIndex & prefixBit) {
                directory[newIndex] = newBucket;
                newBucket->values.push_back(key);
            } else {
                directory[newIndex] = oldBucket;
                oldBucket->values.push_back(key);
            }
        }
    }

    // 🔹 Search function
    bool search(int key) {
        int index = hash(key);
        Bucket* bucket = directory[index];
        for (int val : bucket->values) {
            if (val == key) {
                cout << "Key " << key << " found in bucket with localDepth=" 
                     << bucket->localDepth << endl;
                return true;
            }
        }
        cout << "Key " << key << " not found." << endl;
        return false;
    }

    // 🔹 Delete function
    void remove(int key) {
        int index = hash(key);
        Bucket* bucket = directory[index];
        for (auto it = bucket->values.begin(); it != bucket->values.end(); ++it) {
            if (*it == key) {
                bucket->values.erase(it);
                cout << "Key " << key << " deleted." << endl;
                return;
            }
        }
        cout << "Key " << key << " not found (cannot delete)." << endl;
    }

    void display() {
        cout << "\n--- Directory (Global Depth = " << globalDepth << ") ---\n";
        int size = 1 << globalDepth;
        for (int i = 0; i < size; i++) {
            cout << "Dir[" << toBinary(i, globalDepth) << "] : ";
            for (int val : directory[i]->values)
                cout << val << " ";
            cout << "(localDepth=" << directory[i]->localDepth << ")\n";
        }
    }
};

int main() {
    ExtendibleHash ht(1, 3);  // Start with globalDepth=1, bucket size=3

    vector<int> keys = {16, 4, 6, 22, 24, 10, 31, 7, 9, 20};

    for (int key : keys) {
        cout << "\nInserting " << key << " (binary=" << bitset<8>(key) << ")";
        ht.insert(key);
        ht.display();
    }

    // 🔹 Test search
    ht.search(22);
    ht.search(15);

    // 🔹 Test delete
    ht.remove(22);
    ht.remove(15);

    ht.display();

    return 0;
}

