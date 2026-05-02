#include "def.h"

/* all_lower - true if a string is all lower-case */

int all_lower (char *str)
{
	while (*str) {
		if (!isascii ((unsigned char) * str) || !islower ((unsigned char) * str))
			return 0;
		++str;
	}

	return 1;
}


/* all_upper - true if a string is all upper-case */

int all_upper (char *str)
{
	while (*str) {
		if (!isascii ((unsigned char) * str) || !isupper ((unsigned char) * str))
			return 0;
		++str;
	}

	return 1;
}


/* intcmp - compares two integers for use by qsort. */

int intcmp (const void *a, const void *b)
{
  return *(const int *) a - *(const int *) b;
}


/* check_char - checks a character to make sure it's within the range
 *		we're expecting.  If not, generates fatal error message
 *		and exits.
 */

void check_char (int c)
{
	if (c >= CSIZE)
		lerr (_("bad character '%s' detected in check_char()"),
			readable_form (c));

	if (c >= ctrl.csize)
		lerr (_
			("scanner requires -8 flag to use the character %s"),
			readable_form (c));
}



/* clower - replace upper-case letter to lower-case */

unsigned char clower (int c)
{
	return (unsigned char) ((isascii (c) && isupper (c)) ? tolower (c) : c);
}
