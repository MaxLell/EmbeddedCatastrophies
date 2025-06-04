#ifndef CUSTOM_ASSERT_H
#define CUSTOM_ASSERT_H

void assert_failed(const char *condition, const char *file, int line);

#define ASSERT(condition)                                                \
    do                                                                   \
    {                                                                    \
        if (!(condition))                                                \
        {                                                                \
            assert_failed(#condition, __FILE__, __LINE__);               \
        }                                                                \
    } while (0)

#endif // CUSTOM_ASSERT_H