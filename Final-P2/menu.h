#ifndef MENU_H
#define MENU_H

#include "file_helper.h"

int menu(const struct RiderInfo* riders, int size);
int getMenuOption();
int getInt();
int getIntInRange(int min, int max);
char getCategory();

void displayBasic(const struct RiderInfo* riders, int size);
void displayWithdraw(const struct RiderInfo* riders, int size);
void displayCrossCategory(const struct RiderInfo* riders, int size);

void displayRiderBasic(const struct RiderInfo* rider);
void displayRiderWithdraw(const struct RiderInfo* rider);
void displayRiderCrossCategory(const struct RiderInfo* rider);

#endif