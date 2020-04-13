#include "race_reporting.h"
#include "menu.h"


int menu(const struct RiderInfo* riders, int size) {
	int option = getMenuOption();
	char category;

	if (option == 1) { // top 3
		category = getCategory();
		struct RiderInfo top_3[3];
		findTop3(riders, size, category, top_3);
		displayBasic(top_3, 3);
	}
	else if (option == 2) { // all riders in category
		category = getCategory();
		struct RiderInfo categorized[MAXRECORD];
		int size_c = findInCategory(riders, size, category, categorized);
		displayWithdraw(categorized, size_c);
	}
	else if (option == 3) { // last 3
		category = getCategory();
		struct RiderInfo last_3[3];
		findLast3(riders, size, category, last_3);
		displayBasic(last_3, 3);
	}
	else if (option == 4) { // winners
		struct RiderInfo winners[3];
		findWinners(riders, size, winners);
		displayCrossCategory(winners, 3);
	}
	
	return option;
}

int getMenuOption() {
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a category\n");
	printf("2 - Print all riders in a category\n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories\n");
	printf(":");
	return getIntInRange(0, 4);
}

int getInt() {
	char nl = '\0';
	int value = 0;
	while (!scanf("%d%c", &value, &nl) || nl != '\n') {
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
	}
	return value;
}

int getIntInRange(int min, int max) {
	int value;
	while (1) {
		value = getInt();
		if (value >= min && value <= max) {
			break;
		}
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
	}
	return value;
}

char getCategory() {
	printf("Which category (S, M, L): ");
	char nl, value = '\0';
	while ((!scanf("%c%c", &value, &nl) || nl != '\n') &&
		(value != 'S' && value != 'M' && value != 'L')) {
		clearKeyboard();
		printf("*** INVALID INPUT *** <Please enter a valid category (S, M, L)>: ");
	}
	return value;
}

void displayBasicReport(const struct RiderInfo* riders, int size) {
	int i;
	printf("\nRider                    Age Group Time\n");
	printf("---------------------------------------\n");
	for (i = 0; i < size; i++) {
		displayRiderBasic(&riders[i]);
	}
	printf("\n");
}

void displayWithdrawReport(const struct RiderInfo* riders, int size) {
	int i;
	printf("\nRider                    Age Group Time Withdrew\n");
	printf("------------------------------------------------\n");
	for (i = 0; i < size; i++) {
		displayRiderWithdraw(&riders[i]);
	}
	printf("\n");
}

void displayCrossCategoryReport(const struct RiderInfo* riders, int size) {
	int i;
	printf("\nRider                    Age Group Category Time\n");
	printf("------------------------------------------------\n");
	for (i = 0; i < size; i++) {
		displayRiderCrossCategory(&riders[i]);
	}
	printf("\n");
}

void displayRiderBasic(const struct RiderInfo* rider) {
	if (!strcmp(rider->name, "")) {
		return;
	}
	char age_group[10];
	char time[6];
	calculateAgeGroup(rider->age, age_group);
	formatTime(rider->withdrawn ? 0. : rider->finishTime - rider->startTime, time);

	printf("%25s%-9s %s",
		rider->name,
		age_group,
		time
	);
}

void displayRiderWithdraw(const struct RiderInfo* rider) {
	if (!strcmp(rider->name, "")) {
		return;
	}
	char age_group[10];
	char time[6];
	calculateAgeGroup(rider->age, age_group);
	formatTime(rider->withdrawn ? 0. : rider->finishTime - rider->startTime, time);

	printf("%25s%-9s %s %-8s",
		rider->name,
		age_group,
		time,
		rider->withdrawn ? "Yes" : "No"
	);
}

void displayRiderCrossCategory(const struct RiderInfo* rider) {
	if (!strcmp(rider->name, "")) {
		return;
	}
	char age_group[10];
	char time[6];
	char category[8];
	if (rider->raceLength == 'S') {
		strcpy(category, "50 km");
	}
	else if (rider->raceLength == 'M') {
		strcpy(category, "75 km");
	}
	else {
		strcpy(category, "100 km");
	}
	calculateAgeGroup(rider->age, age_group);
	formatTime(rider->withdrawn ? 0. : rider->finishTime - rider->startTime, time);

	printf("%25s%-9s %s %s",
		rider->name,
		age_group,
		category,
		time
	);
}
