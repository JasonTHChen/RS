#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IDSIZE 10
#define NAMESIZE 20
#define LINESIZE 512

/*
 * Name:   Jason Chen
 * Date:   March 20, 2017
 */

/*************************************************************************************
 * Each record consist of an ID, a name, and a score. In addition, a name consist of *
 * a last name and a first name. This will check all valid input from user           *
 *************************************************************************************/

typedef struct {
	char last[NAMESIZE];	/* last name (1 word), e.g., "simpson" */ 
	char first[NAMESIZE]; 	/* first name (1 word), e.g., "homer" */ 
} name;

typedef struct { 
	char id[IDSIZE];      	/* ID (’a’ followed by 8 digits), e.g., "a12345678" */ 
	name name; 			 	/* name (as defined above) */
	int score; 			 	/* score (between 0 & 100 inclusive), e.g., 25 */
} record;

/* returns 1 and creates one record if ID, name, and score are valid; otherwise returns 0 */
int create_record(record *prec, const char data[]);
/* prints out a record in this format (ID : last, first : score) */
void print_record(const record *prec);
/* returns 1 if the id has lowercase 'a' at the first character and follow by 8 numbers; otherwise returns 0 */
int check_student_id(const char student_id[]);
/* returns 1 if the name has fewer than 20 characters; otherwise return 0 */
int check_name(const char name[]);
/* returns 1 if score is between 0 and 100 and only has numbers; otherwise retruns 0 */
int check_score(const char number[], int *score);
/* changes all characters to lowercase */
void str_tolower(char s[]);

#endif
