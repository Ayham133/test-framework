/**
 * @file: suite.h
 *
 * Date: 14/08/2026
 */

#include "../include/test.h"

typedef struct Suite Suite;

/**
 * @brief       initiate suite
 *
 * Allocate memory for the suite struct.
 *
 * @param name      the name of the suite
 *
 * @return      return the pointer for the new suite
 *
 * @Note: this function will return NULL if the allocation failed,
 * or if the string name is NULL or '\0'.
 */
Suite *suite_init(const char *name);

/**
 * @brief       get the name of the requeseted suite.
 *
 * @param suite         pointer to the requeseted suite
 *
 * @return              return the name of the requeseted suite.
 * @Note: this function will return NULL if the suite is Null,
 */
char *suite_get_name(Suite *suite);


typedef struct SuiteGroup SuiteGroup;

/**
 * @brief       check if this suite_group is full or not.
 *
 * @return [bool]   return true if this suite group is full, false otherwise.
 *
 * @Note: this function will return false if this suite_group is Null, or 
 * any other errors.
 */
bool suite_group_is_full(SuiteGroup *suite_group);

/**
 * @brief       check if this suite_group is empty or not.
 *
 * @return [bool]   return true if this suite group is empty, false otherwise.
 *
 * @Note: this function will return false if this suite_group is Null, or 
 * any other errors.
 */
bool suite_group_is_empty(SuiteGroup *suite_group);

/**
 * @brief       get the requeseted suite from this suite_group list
 *
 * After authenticating the index and this suite_group list, return the
 * suite at the requeseted index
 *
 * @param suite_group       this suite_group requeseted
 * @param index             the index requeseted
 * @param out_value         the place where the requeseted suite will be stored
 *
 * @return [bool]           return true if there were no errors, false otherwise.
 *
 * @Note: this function will return false, if this suite_group is null or empyt,
 * and this function will returh false if the index is out of bound, and if the
 * out_value is null
 */
bool suite_group_get(SuiteGroup *suite_group, unsigned index, Suite *out_value);

/**
 * @brief       get the size of the requeseted group
 *
 * @param group     the requeseted group
 * @return          return the size of the requeseted group.
 *
 * @Note: this function will return zero if the group is NULL,
 * or empty.
 */
unsigned suite_group_size(SuiteGroup *group);
