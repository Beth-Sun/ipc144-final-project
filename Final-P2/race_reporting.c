#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "race_reporting.h"

#define WORST_RESULT 500.

#define BEST_RESULT 0.

void calculateAgeGroup(const int age, char* age_group) {
	if (age >= 35) {
		strcpy(age_group, "Senior");
	}
	else if (age >= 21) {
		strcpy(age_group, "Adult");
	}
	else  {
		strcpy(age_group, "Junior");
	}
}

void formatTime(const double time, char* formatted_time) {
	if (time > 0) {
		int hour = time;
		int min = (time - hour) * 60;
		sprintf(formatted_time, "%d:%02d", hour, min);
	}
	else {
		strcpy(formatted_time, "N/A");
	}
}

int findInCategory(struct RiderInfo* riders, const size, char category, struct RiderInfo** result) {
	int size_r = 0, i;
	for (i = 0; i < size; i++) {
		if (riders[i].raceLength == category) {
			result[size_r++] = &riders[i];
		}
	}
	return size_r;
}


void shiftToRight(double* arr, int size, int position) {
	int i;
	for (i = size - 1; i > position; i--) {
		arr[i] = arr[i - 1];
	}
}

void shiftToRightR(struct RiderInfo** arr, int size, int position) {
	int i;
	for (i = size - 1; i > position; i--) {
		arr[i] = arr[i - 1];
	}
}

void findTop3(struct RiderInfo* riders, const size, char category, struct RiderInfo** result) {
	double top_3[3] = { WORST_RESULT, WORST_RESULT, WORST_RESULT };
	int i, j;
	for (i = 0; i < size; i++) {
		if (riders[i].withdrawn || riders[i].raceLength != category) {
			continue;
		}
		double time = riders[i].finishTime - riders[i].startTime;
		for (j = 0; j < 3; j++) {
			if (time <= top_3[j]) {
				shiftToRight(top_3, 3, j);
				top_3[j] = time;
				shiftToRightR(result, 3, j);
				result[j] = &riders[i];
				break;
			}
		}
	}
}

void findLast3(struct RiderInfo* riders, const size, char category, struct RiderInfo** result) {
	double top_3[3] = { BEST_RESULT, BEST_RESULT, BEST_RESULT };
	int i, j;
	for (i = 0; i < size; i++) {
		if (riders[i].withdrawn || riders[i].raceLength != category) {
			continue;
		}
		double time = riders[i].finishTime - riders[i].startTime;
		for (j = 0; j < 3; j++) {
			if (time >= top_3[j]) {
				shiftToRight(top_3, 3, j);
				top_3[j] = time;
				shiftToRightR(result, 3, j);
				result[j] = &riders[i];
				break;
			}
		}
	}
}

// helper function for findWinners(), get result array index from raceLength
int raceLengthIndex(char race_length) {
	int index = 0;
	if (race_length == 'M') {
		index = 1;
	}
	else if (race_length == 'L') {
		index = 2;
	}
	return index;
}

void findWinners(const struct RiderInfo* riders, const size, struct RiderInfo* result) {
	strcpy(result[raceLengthIndex('S')].name, "");
	strcpy(result[raceLengthIndex('M')].name, "");
	strcpy(result[raceLengthIndex('L')].name, "");
	
	result[raceLengthIndex('S')].raceLength = 'S';
	result[raceLengthIndex('M')].raceLength = 'M';
	result[raceLengthIndex('L')].raceLength = 'L';

	result[raceLengthIndex('S')].startTime = WORST_RESULT;
	result[raceLengthIndex('S')].finishTime = BEST_RESULT;

	result[raceLengthIndex('M')].startTime = WORST_RESULT;
	result[raceLengthIndex('M')].finishTime = BEST_RESULT;

	result[raceLengthIndex('L')].startTime = WORST_RESULT;
	result[raceLengthIndex('L')].finishTime = BEST_RESULT;

	int i;
	for (i = 0; i < size; i++) {
		if (riders->withdrawn) {
			continue;
		}
		int rl_index = raceLengthIndex(riders->raceLength);
		double time = riders[i].finishTime - riders[i].startTime;
		double best_time = result[rl_index].finishTime - result[rl_index].startTime;
		if (time > best_time) {
			result[rl_index] = riders[i];
		}
	}
}