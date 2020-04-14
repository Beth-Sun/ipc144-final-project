/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)
   2)
   3)

   +--------------------------------------------------------+
   |                FILE: race_reporting.h                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef RACE_REPORTING_H
#define RACE_REPORTING_H

#include "file_helper.h"

void calculateAgeGroup(const int age, char* age_group);
void formatTime(const double time, char* formatted_time);

int findInCategory(struct RiderInfo* riders, const size, char category, struct RiderInfo** result);
void findTop3(struct RiderInfo* riders, const size, char category, struct RiderInfo** result);
void findLast3(struct RiderInfo* riders, const size, char category, struct RiderInfo** result);
void findWinners(const struct RiderInfo* riders, const size, struct RiderInfo* result);

#endif