#define ALLOCSIZE 10000 /* size of available space  */

static char allocbuf[ALLOCSIZE]; /* storgage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits  */
    allocp += n;
    return allocp - n;
  } else { /* not enough room  */
    return 0;
  }
}

void afree(char *p) { /* free storage pointed to by p */
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;
  }
}
