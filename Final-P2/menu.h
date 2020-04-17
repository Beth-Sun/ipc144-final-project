#ifndef MENU_H
#define MENU_H

#include "file_helper.h"

int menu(struct RiderInfo* riders, int size);

void printTop3(struct RiderInfo* riders, int size);
void printAll(struct RiderInfo* riders, int size);
void printLast3(struct RiderInfo* riders, int size);
void printWinners(struct RiderInfo* riders, int size);

int getMenuOption();
int getInt();
int getIntInRange(int min, int max);
char getCategory();

void displayBasicReport(const struct RiderInfo** riders, int size);
void displayWithdrawReport(const struct RiderInfo** riders, int size);
void displayWinnersReport(const struct RiderInfo* riders, int size);

void displayRiderBasic(const struct RiderInfo* rider);
void displayRiderWithdraw(const struct RiderInfo* rider);
void displayRiderWinner(const struct RiderInfo* rider);

#endif