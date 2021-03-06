#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <utils/Log.h>

#define INFO(...) \
    do { \
        printf(__VA_ARGS__); \
        printf("\n"); \
        ALOGD(__VA_ARGS__); \
    } while(0)


inline void assert_fail(const char *file, int line, const char *func, const char *expr) {
    INFO("assertion failed at file %s, line %d, function %s:",
            file, line, func);
    INFO("%s", expr);
    abort();
}

#define ASSERT(e) \
    do { \
        if (!(e)) \
            assert_fail(__FILE__, __LINE__, __func__, #e); \
    } while(0)

// Where to print the parcel contents: aout, alog, aerr. alog doesn't seem to work.
#define PLOG aout

#endif // COMMON_H
