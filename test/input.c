#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <tools/debug.h>
#include <tools/l.h>
#include <string.h>
/* Needed only tor prototypes */
/* " *I
/*------------------------------------------------------------------------
* INPUT.C:
The input system used by LeX-generated lex~cal analyzers.
*------------------------------------------------------------------------
* System-dependent defines.
*I
# #ifdef MSDOS
define COPY(d,s,a) memmove(d,s,a)
# #else
#endif
define COPY(d,s,a) memcpy(d,s,a)
#define STDIN
0
/* standard input */
/*----------------------------------------------------------------------*/
#define MAXLOOK
#define MAXLEX
16
1024
/* Maximum amount of lookahead */
/* Maximum lexeme sizes.
*/
#define BUFSIZE
(MAXLEX * 3) + (2 * MAXLOOK)
)
/* Change the 3 only */
#define DANGER
End buf -
MAXLOOK
/* Flush buffer when Next
*/
/* passes this address
*/
#define END
(&Start_buf[BUFSIZE])
/* Just past last char in but */
#define NO MORE_CHARS()
( Eof_read && Next >=End buf
typedef unsigned char
uchar;
PRIVATE
PRIVATE
PRIVATE
PRIVATE
PRIVATE
PRIVATE
PRIVATE
PRIVATE
uchar
uchar
uchar
uchar
uchar
uchar
int
int
Start_buf[BUFSIZE]; /* Input buffer
PRIVATE
int
PRIVA'l'E
int
PRIVATE
int
PRIVATE
int
*End buf
*Next
*sMark
*eMark
*pMark
pLineno
pLength
Inp_file
Lineno
Mline
END;
END;
END;
END;
NULL;
0;
0;
1 1 STDIN;
Termchar = 0;
/*
/*
/*
/*
Just past last character
Next input character
Start of current lexeme
End of current lexeme
/* Start of previous lexeme
/* Line # of previous lexeme
/* Length of previous lexeme
/* Input tile handle
/* Current line number
/* Line # when mark_end() called
/* Holds the character that was
*I
*I
*I
*I
*I
*I
*I
*I
*I
*/
*I
*I

l*----------------------------------------------------------------------*1
PRIVATE void print_col_map( fp )
FILE
*fp;
{
static char *text[] =
{
"The Yy_cmap [] and Yy_rmap arrays are used as follows:",
"" I
" next state= Yydtran[ Yy_rmap[current_ state] l [ Yy_cmap[input_char] ]·"
-
I
I
"" I
"Character positions in the Yy_cmap array are:",
II
I
A@
AA
AB
Ac
AD
AE
AF
AG
AH
AI
AJ
AK
AL
AM
AN
"'0",
Ap
AQ
AR
As
AT
Au
Av
Aw
Ax
Ay
Az
A [
A\\
A l
A " I
\"
#
$
%
&
(
)
*
+
/",
0
1
2
3
4
5
6
7
8
9
<
>
?II
•
I
@
A
B
c
D
E
F
G
H
I
J
K
L
M
N
0",
p
Q
R
s
T
u
v
w
X
y
z
[
\\
l
II
I
a
b
c
d
e
f
g
h
i
j
k
1
m
n
o",
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
p
q
r
s
t
u
v
w
X
y
z
{
I
DEL",
NULL
} ;
comment(fp, text);
fprintf(fp, "%s %s
Yy_cmap[%d] =\n{\n
pmap
(fp, Col_map, MAX CHARS);
PRIVATE void print_row_map( fp, nrows )
FILE
*fp;
int
nrows;
{
fprintf(fp, "%s %s
Yy_rmap[%d] =\n{\n
pmap
(fp, Row_map, nrows );
PRIVATE void pmap( fp, p, n )
FILE
int
int
*fp;
*p;
n;
/* Print a one-dimensional array.
*I
int j;
for( j = 0; j < (n- 1); j++ )
{
fprintf(fp, "%3d," , *p++ );
if( (j % NCOLS)
fprintf(fp, "\n NCOLS-1 )
");
fprintf( fp, "%3d\n};\n\n", *p );
