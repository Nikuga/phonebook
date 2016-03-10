#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

entry *findName(char lastname[], entry *pHead)
{
    unsigned int hash_value = BKDRHash(lastname);
    entry *pHead_hash = HashTable[hash_value];
    while (pHead_hash != NULL) {
        if (strcasecmp(lastname, pHead_hash->lastName) == 0)
            return pHead_hash;
        pHead_hash = pHead_hash->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    unsigned int hash_value = BKDRHash(lastName);
    entry *tmp = (entry *) malloc(sizeof(entry));
    strcpy(tmp->lastName, lastName);
    if(HashTable[hash_value]==NULL) {
        HashTable[hash_value] = tmp;
        HashTable[hash_value]->pNext = NULL;
    } else {
        tmp->pNext = HashTable[hash_value];
        HashTable[hash_value] = tmp;
    }

    return e;
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 31, hash = 0;
    while (*str) {
        hash = hash*seed + (*str++);
    }
    return (hash % HASH_TABLE_SIZE);
}
