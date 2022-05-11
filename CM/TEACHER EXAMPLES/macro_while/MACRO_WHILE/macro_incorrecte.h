#ifndef MACRO_INCORRECTE_H
#define MACRO_INCORRECTE_H

#define REPETER(s, n) \
    { \
        printf("(%d) =>", n);         \
        for (int i = 0; i < n; i++) \
            printf("%s", s); \
        printf("<=\n"); \
    }

#endif
