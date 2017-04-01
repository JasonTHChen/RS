#include "record.h"
#include <ctype.h>

/*
 * Name:   Jason Chen
 * Date:   March 20, 2017
 */

/* returns 1 and creates one record if ID, name, and score are valid; otherwise returns 0 */
int create_record(record *prec, const char data[]) {
	char id[LINESIZE];
	char last[LINESIZE];
	char first[LINESIZE];
	char number[LINESIZE];
	int score = 0;
	
	if (sscanf(data, "%s %s %s %s", id, first, last, number) != 4) {
			fprintf(stderr, "# Miss data [ID] [firstname] [lastname] [score]\n");
		return 0;
	}
	
	if (!check_student_id(id)) {
			fprintf(stderr, "# Invalid ID: %s\n", id);
		return 0;
	}
	
	if(!check_name(first) || !check_name(last)) {
			fprintf(stderr, "# Invalid name: %s %s\n", first, last);
		return 0;
	}
	
	if (!check_score(number, &score)) {
			fprintf(stderr, "# Invalid score: %s\n", number);
		return 0;
	}
	
	str_tolower(first);
	str_tolower(last);
	
	/* create a record */
	strcpy(prec->id, id);
	strcpy(prec->name.first, first);
	strcpy(prec->name.last, last);
	prec->score = score;
	return 1;
}

/* prints out a record in this format (ID : last, first : score) */
void print_record(const record *prec) {
	printf("%s : %s, %s : %d\n", prec->id, prec->name.last, prec->name.first, prec->score);
}

/* returns 1 if the id has lowercase 'a' at the first character and follow by 8 numbers; otherwise returns 0 */
int check_student_id(const char student_id[]) {
	size_t i;
	if((strlen(student_id) + 1) != IDSIZE) {
		#ifdef DEBUG
			fprintf(stderr, "# ID length invalid\n");
		#endif
		return 0;
	}
	if(student_id[0] != 'a') {
		#ifdef DEBUG
			fprintf(stderr, "# first letter is not an 'a'\n");
		#endif
		return 0;
	}
	for(i = 1; student_id[i] != '\0'; i++) {
		if(student_id[i] < 48 || student_id[i] > 57) {
			return 0;
		}
	}
	return 1;
}

/* returns 1 if the name has fewer than 20 characters; otherwise return 0 */
int check_name(const char name[]) {
	size_t name_length = strlen(name) + 1;
	if(name_length >= NAMESIZE) {
		#ifdef DEBUG
			fprintf(stderr, "# length of name is invaid\n");
		#endif
		return 0;
	}
	return 1;
}

/* returns 1 if score is between 0 and 100; otherwise retruns 0 */
int check_score(const char number[], int *score) {
	size_t i;
	for (i = 0; number[i] != '\0'; i++) {
		if (!isdigit(number[i])) {
			#ifdef DEBUG
				fprintf(stderr, "# non-digit input\n");
			#endif
			return 0;
		}
	}
	
	if(sscanf(number, "%d", score) != 1) {
		return 0;
	}
	
	if (*score < 0 || *score > 100) {
		return 0;
	}
	return 1;
}

/* changes all characters to lowercase */
void str_tolower(char s[]) {
	size_t i;
	for(i = 0; s[i] != '\0'; i++) {
		s[i] = tolower(s[i]); 
	}
}