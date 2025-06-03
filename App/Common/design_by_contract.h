#ifndef DESIGN_BY_CONTRACT_H
#define DESIGN_BY_CONTRACT_H

#include "custom_assert.h"


/**
 * @brief Precondition condition which needs to be true before the function is called.
 * @param condition The condition to check
 */
#define PRE_CONDITION(condition)                            \
    do                                                     \
    {                                                      \
        if (!(condition))                                  \
        {                                                  \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                  \
    } while (false)

/**
 * @brief Invariant condition which needs to be true during the execution of the program.
 * @param condition The condition to check
 */
#define INVARIANT(condition)                               \
    do                                                     \
    {                                                      \
        if (!(condition))                                  \
        {                                                  \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                  \
    } while (false)

/**
 * @brief Postcondition condition which needs to be true after the function is called.
 * @param condition The condition to check
 */
#define POST_CONDITION(condition)                           \
    do                                                     \
    {                                                      \
        if (!(condition))                                  \
        {                                                  \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                  \
    } while (false)

#endif // DESIGN_BY_CONTRACT_H

