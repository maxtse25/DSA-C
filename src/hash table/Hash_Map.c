#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct HashMap {
    HashNode* buckets[TABLE_SIZE];
} HashMap;

// Hash function to calculate the hash index
unsigned int hash(char* key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);
    
    // Convert the string to an integer
    while (i < key_len) {
        value = value * 37 + key[i];
        i++;
    }
    // This modulo operation ensure the hash value is within the bounds of hash table array
    return value % TABLE_SIZE;
}

// Initialize a hash map
HashMap* createHashMap() {
    HashMap* map = malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

// Insert key-value pair into hash map
void insert(HashMap* map, char* key, int value) {
    unsigned int bucketIndex = hash(key);
    HashNode* new_node = malloc(sizeof(HashNode));
}