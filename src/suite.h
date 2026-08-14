/**
 * @file: suite.h
 *
 * Date: 14/08/2026
 */

#include "../include/test.h"

typedef struct Suite Suite;

/**
 * @brife       check if this suite_group is full or not.
 *
 * @return [bool]   return true if this suite group is full, false otherwise.
 *
 * @Note: this function will return false if this suite_group is Null, or 
 * any other errors.
 */
bool suite_group_is_full(SuiteGroup *suite_group);

/**
 * @brife       check if this suite_group is empty or not.
 *
 * @return [bool]   return true if this suite group is empty, false otherwise.
 *
 * @Note: this function will return false if this suite_group is Null, or 
 * any other errors.
 */
bool suite_group_is_empty(SuiteGroup *suite_group);

/**
 * @brife       get the requeseted suite from this suite_group list
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
