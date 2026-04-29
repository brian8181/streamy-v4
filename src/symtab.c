
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symtab.h"

// root sym_table

symbol_tab *get_stable()
{
    static symbol_tab *tab = 0;

    if (tab != 0)
        return tab;

//    symbol *streamy_init_object =
//         new_symbol("$streamy", "static", "object", 0);

//     tab = (symbol_tab *)malloc(sizeof(symbol_tab));
//     tab->head = (node *)malloc(sizeof(node));
//     tab->head->sym = streamy_init_object;
//     tab->head->next = 0;

    return tab;
}

void free_node(symbol_tab *stab, node *n)
{
    free(n->sym);
    n->sym = 0;
    free(n);
    n = 0;
}

node* new_node()
{
	node* n = (node*)malloc(sizeof(node));
	return n;
}

void init_symbol(symbol **s, const char *id, const char *type_modifiers, const char *type, const char *val)
{
    *s = (symbol*)malloc(sizeof(symbol));
    (*s)->id = (char *)malloc(strlen(id) + 1);
    strcpy((*s)->id, id);
    (*s)->type = (char *)malloc(strlen(type) + 1);
    strcpy((*s)->type_modifiers, type_modifiers);
    (*s)->type_modifiers = (char *)malloc(strlen(type_modifiers) + 1);
    strcpy((*s)->type, type);
    (*s)->pval = (char *)malloc(strlen(val) + 1);
    strcpy((*s)->type, type);
}

void init_sub_table(symbol_tab *parent)
{
    symbol_tab *symtab = (symbol_tab *)malloc(sizeof(symbol_tab));
    symtab->head = 0;
    // bkp todo!
    // symtab->parent = parent->head;
}

void add_symbol(symbol_tab* stab, symbol* s)
{
	node* n = new_node();
	n->sym = s;
	 // add node / symbol to tail
    node *tail = find_tail(stab);
	tail->next = n;
	n->prev = n;

}

void insert_symbol(symbol_tab *stab, symbol* s)
{
    // add node
    // node *dst_node = find_node(stab, s->id);
    // dst_node->prev->next = dst_node;
    // dst_node->next = src_node;
}

void remove_symbol(symbol_tab *stab, const char *id)
{
    node *cur = get_stable()->head;

    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur->next->sym;
        if (strcmp((char *)s->pval, id))
        {
            node *next_next = cur->next->next;
            free_node(stab, cur->next);
            cur->next = next_next;
        }
    }
}

void dump_symbols(symbol_tab *stab)
{
    node *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur != 0)
    {
        node *next = cur->next;
        printf("%s, %s, %s, %s", cur->sym->id, cur->sym->type_modifiers, cur->sym->type, cur->sym->pval);
        cur = next;
    }
}

void clear_symbols(symbol_tab *stab)
{
    node *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur != 0)
    {
        node *next = cur->next;
        free_node(stab, cur);
        cur = next;
    }
}

symbol *find_symbol_by_addr(symbol_tab *stab, symbol *sym)
{
    node *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur->sym;
        if (s == sym)
            return s;
        cur = cur->next;
    }
    return 0;
}

symbol *find_symbol_by_id(symbol_tab *stab, const char *id)
{
    node *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur->sym;
        if (strcmp((char *)s->pval, id))
            return s;
        cur = cur->next;
    }
    return 0;
}

symbol *find_symbol(symbol_tab *stab, symbol* s)
{
    find_symbol_by_id(stab, s->id);
}

node *find_node(symbol_tab *stab, const char *id)
{
    node *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur->sym;
        if (strcmp((char *)s->pval, id))
            return cur;
        cur = cur->next;
    }
    return 0;
}

node *find_tail(symbol_tab *stab)
{
    node *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        cur = cur->next;
    }
    return cur;
}

int size(symbol_tab *stab)
{
    int k = 0;
    node *cur = stab->head;
    while (cur)
    {
        cur = cur->next;
        k++;
    }
    return k;
}
