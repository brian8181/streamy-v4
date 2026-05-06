#ifndef __DEF_H__
#define __DEF_H__

/* True if a string is all lower case. */
extern int all_lower(char *);

/* True if a string is all upper case. */
extern int all_upper(char *);

/* Compare two integers for use by qsort. */
extern int intcmp(const void *, const void *);

/* Check a character to make sure it's in the expected range. */
extern void check_char(int c);

/* Replace upper-case letter to lower-case. */
extern unsigned char clower(int);

/* strdup() that fails fatally on allocation failures. */
extern char *xstrdup(const char *);

/* Compare two characters for use by qsort with '\0' sorting last. */
extern int cclcmp(const void *, const void *);

#endif // __DEF_H__
