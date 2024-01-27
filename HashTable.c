#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10000

typedef struct item
{
    char *key;
    int value;
} item;

item *hash_table[TABLE_SIZE];

int hash_function(char *key)
{
    int value = 0;

    for (int i = 0; i < strlen(key); i++)
    {
        value += key[i];
    }
    return value % TABLE_SIZE;
}

int indexer(int i, char *key)
{
    int index = hash_function(key);
    while (hash_table[index] != NULL && hash_table[index]->key != NULL && strcmp(key, hash_table[index]->key) != 0)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    return index;
}
void insert(char *key, int value)
{

    int index = indexer(index, key);
    if (hash_table[index] == NULL || hash_table[index]->key == NULL)
    {
        hash_table[index] = (item *)malloc(sizeof(item));
        hash_table[index]->key = strdup(key);
    }
    hash_table[index]->value = value;
}

int find(char *key)
{
    int index = indexer(index, key);
    if (hash_table[index] == NULL || hash_table[index]->key == NULL)
        return -1;
    else
        return hash_table[index]->value;
}

void delete(char *key)
{
    int index = indexer(index, key);
    if (hash_table[index] == NULL || hash_table[index]->key == NULL)
    {
        printf("Key not found\n");
    }
    else
    {
        free(hash_table[index]->key);
        hash_table[index]->key = NULL;
        hash_table[index]->value = -1;
        printf("%s deleted.\n", key);
    }
}

int main()
{
    insert("apple", 1);
    insert("banana", 2);
    insert("orange", 3);
    printf("%d\n", find("banana"));
    printf("%d\n", find("orange"));
    printf("%d\n", find("nothing"));
    printf("%d\n", find("apple"));
    delete ("apple");
    delete ("apple");

    return 0;
}