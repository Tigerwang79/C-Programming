#ifndef MACRO_CORRECTE_H
#define MACRO_CORRECTE_H

#define REPETER(s, n) \
    do { \
        printf("(%d) =>", n);         \
        for (int i = 0; i < n; i++) \
            printf("%s", s); \
        printf("<=\n"); \
    } while(0)

#endif
