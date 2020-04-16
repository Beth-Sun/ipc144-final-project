/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)
   2)
   3)

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"

#define DATAFILE "data.txt"

int main(void)
{
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
    
    FILE* data_file = NULL;
    struct RiderInfo rider_info[MAXRECORD];
    int size = 0;

    data_file = fopen(DATAFILE, "r");
    if (data_file == NULL) {
        printf("Failed to open file %s", DATAFILE);
        return 1;
    }

    int finished = 0;
    while (!finished) {
        finished = readFileRecord(data_file, &rider_info[size]);
        if (!finished) size++;
    }

    fclose(data_file);

	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report
    while (menu(rider_info, size));
    printf("\nKeep on Riding!\n");

	return 0;
}