
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
	//symbol* n = new symbol(s);
	// add node / symbol to tail
    symbol *tail = find_tail(stab);
	tail->next = s;
	s->prev = tail;

}

void insert_symbol(symbol_tab *stab, const int id, symbol* s)
{
    // add node
    // node *dst_node = find_node(stab, s->id);
    // dst_node->prev->next = dst_node;
    // dst_node->next = src_node;
}

void remove_symbol(symbol_tab *stab, const char *id)
{
    symbol *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur->next;
        if (strcmp((char *)s->id, id))
        {
            symbol *next_next = cur->next->next;
			free(s);
            cur->next = next_next;
        }
    }
}

void dump_symbols(symbol_tab *stab)
{
    symbol *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur != 0)
    {
        symbol *next = cur->next;
        printf("%s, %s, %s, %s", cur->id, cur->type_modifiers, cur->type, cur->pval);
        cur = next;
    }
}

void clear_symbols(symbol_tab *stab)
{
    symbol *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur != 0)
    {
        symbol *next = cur->next;
		free(cur);
        cur = next;
    }
}

symbol *find_symbol_by_addr(symbol_tab *stab, symbol *sym)
{
    symbol *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur;
        if (s == sym)
            return s;
        cur = cur->next;
    }
    return 0;
}

symbol *find_symbol_by_id(symbol_tab *stab, const char *id)
{
    symbol *cur = get_stable()->head;
    if (stab != 0)
        cur = stab->head;
    while (cur->next != 0)
    {
        symbol *s = cur;
        if (strcmp((char *)s->id, id))
            return s;
        cur = cur->next;
    }
    return 0;
}

symbol *find_tail(symbol_tab *stab)
{
    symbol *cur = get_stable()->head;
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
    symbol *cur = stab->head;
    while (cur)
    {
        cur = cur->next;
        k++;
    }
    return k;
}
