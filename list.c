#include <stdio.h>
#include "list.h"
#include "dbg.h"

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }
    
    free(list->last);
    free(list);
}

void List_clear(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }
}

void List_clear_destroy(List *list)
{
    List_clear(list);
    List_destroy(list);
}

void List_push(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);
    
    node->value = value;
    check(node->value != NULL, "INVALID: value cannot be NULL");
    
    if(list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    
    list->count++;
    
error:
    return;
}

void *List_pop(List *list)
{
    ListNode *node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);
    
    node->value = value;
    check(node->value != NULL, "INVALID: value cannot be NULL");
    
    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }
    
    list->count++;
    
error:
    return;
}

void *List_shift(List *list)
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node)
{
    void *result = NULL;
    
    check(list->first && list->last, "List is empty");
    check(node, "node cannot be NULL");
    
    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        check(list->first != NULL, "INVALID: list->first cannot be NULL");
        list->first->prev = NULL;
    } else if(node == list->last) {
        list->last = node->prev;
        check(list->last != NULL, "INVALID: list->last cannot be NULL");
        list->last->next = NULL;
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }
    
    list->count--;
    result = node->value;
    free(node);
    
error:
    return result;
}

void List_print(List *list)
{
    ListNode *now = list->first;
    check(list->first && list->last, "List is empty");
    check(now != NULL, "node cannot be NULL");
    
    printf("[");
    
    int i = 0;
    
    for(i = 0; i < list->count; i++) {
        void *value = now->value;
        check(value != NULL, "INVALID: value cannot be NULL");
        
        printf("%s", value);
        if (i != list->count-1)
            printf(",");
        
        now = now->next;
    }
    
    printf("]\n");
    
error:
    return;
}

int main(int argc, char* argv[])
{
    List *list = List_create();
    char *a, *b, *c, *d, *e;
    a = "0";
    b = "1";
    c = "2";
    d = "3";
    e = "4";
    
    List_push(list, a);
    List_push(list, b);
    List_push(list, c);
    List_push(list, d);
    List_push(list, e);
    
    List_pop(list);
    List_shift(list);
    List_unshift(list, e);
    List_push(list, a);
    
    List_remove(list, list->last->prev);
    
    List_print(list); // [4,1,2,0]
    
    return 0;
}
