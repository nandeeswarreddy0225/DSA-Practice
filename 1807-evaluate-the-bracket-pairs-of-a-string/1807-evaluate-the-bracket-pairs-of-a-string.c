#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20011

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

unsigned int hashFunction(char *str) {
    unsigned int hash = 5381;

    while (*str) {
        hash = ((hash << 5) + hash) + (unsigned char)(*str);
        str++;
    }

    return hash % TABLE_SIZE;
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    Node *table[TABLE_SIZE] = {NULL};

    /* Build hash table */
    for (int i = 0; i < knowledgeSize; i++) {
        char *key = knowledge[i][0];
        char *value = knowledge[i][1];

        unsigned int index = hashFunction(key);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->next = table[index];

        table[index] = newNode;
    }

    int n = strlen(s);

    char *result = (char *)malloc((n + 1) * sizeof(char));
    int pos = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] != '(') {
            result[pos++] = s[i];
        } 
        else {
            i++;

            char key[101];
            int k = 0;

            while (s[i] != ')') {
                key[k++] = s[i++];
            }

            key[k] = '\0';

            unsigned int index = hashFunction(key);

            Node *current = table[index];
            char *value = NULL;

            while (current != NULL) {
                if (strcmp(current->key, key) == 0) {
                    value = current->value;
                    break;
                }

                current = current->next;
            }

            if (value == NULL) {
                result[pos++] = '?';
            } 
            else {
                for (int j = 0; value[j] != '\0'; j++) {
                    result[pos++] = value[j];
                }
            }
        }
    }

    result[pos] = '\0';

    /* Free hash table */
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = table[i];

        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return result;
}