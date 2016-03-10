#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE    1000

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __ENTRY_DATA {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry_data;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
    entry_data *data;
} entry;

entry *HashTable[HASH_TABLE_SIZE];

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
unsigned int BKDRHash(char *str);

#endif
