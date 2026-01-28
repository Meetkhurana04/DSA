#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);


int main() {
    // Example input
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    int n1 = 3, n2 = 3;

    struct ListNode *list1 = NULL, *list2 = NULL, *tail = NULL;

    // create list1
    for (int i = 0; i < n1; i++) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = arr1[i];
        newNode->next = NULL;

        if (list1 == NULL) {
            list1 = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // create list2
    tail = NULL;
    for (int i = 0; i < n2; i++) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = arr2[i];
        newNode->next = NULL;

        if (list2 == NULL) {
            list2 = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // call your function
    struct ListNode *result = mergeTwoLists(list1, list2);

    // print merged list
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }

    return 0;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *ptr = list1;
    struct ListNode *cpt = list2;

    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *start = head;

    /* first node */
    if (ptr->val > cpt->val) {
        head->val = cpt->val;
        cpt = cpt->next;
    } else {
        head->val = ptr->val;
        ptr = ptr->next;
    }

    /* merge while both lists have elements */
    while (ptr != NULL && cpt != NULL) {
        head->next = malloc(sizeof(struct ListNode));
        head = head->next;

        if (ptr->val > cpt->val) {
            head->val = cpt->val;
            cpt = cpt->next;
        } else {
            head->val = ptr->val;
            ptr = ptr->next;
        }
    }

    /* remaining elements of list1 */
    while (ptr != NULL) {
        head->next = malloc(sizeof(struct ListNode));
        head = head->next;

        head->val = ptr->val;
        ptr = ptr->next;
    }

    /* remaining elements of list2 */
    while (cpt != NULL) {
        head->next = malloc(sizeof(struct ListNode));
        head = head->next;

        head->val = cpt->val;
        cpt = cpt->next;
    }

    head->next = NULL;
    return start;
}
