#ifndef RECORD_LIST_H
#define RECORD_LIST_H

#include "record.h"

#include <stdlib.h>

/*
 * Name:   Jason Chen
 * Date:   March 20, 2017
 */

/*************************************************************************************
 * This dynamic array starts with 0 record, goes to 1 record and then doubles in     *
 * size in each later re-allocation. This means that the number of records in the    *
 * the array goest from 0 to 1, then to 2, then to 4, then to 8, then to 16 and so   *
 * on. The array is resized whenever the user needs to add a record but all "slots"  *
 * in the dynamic array are already in user.                                         *
 *************************************************************************************/
 
typedef struct {
	record *data;			/* pointer to dynamic array of records */
	size_t nalloc;			/* number of records allocated */
	size_t nused;			/* number of records used */
} record_list;

/* prints all the records from the record_list */
void print_records(const record_list *list);
/* returns 1 if space is full; otherwise, returns 0*/
int check_space(record_list *list);
/* double the size of space if dynamic memory is full */
void realloc_space(record_list *list);
/* adds a record to the record_list */
void add_record(record_list *list);
/* releases the memory  */
void free_memory(record_list *list);

/* sorts record_list by ID */
int sort_id(const void *p, const void *q);

/* sorts name in ascending order then score in ascending order */
int nasc_sasc(const void *p, const void *q);
/* sorts name in descending order then score in descending order */
int ndsc_sdsc(const void *p, const void *q);
/* sorts score in ascending order then name in ascending order */
int sasc_nasc(const void *p, const void *q);
/* sorts score in descending order then name in descending order */
int sdsc_ndsc(const void *p, const void *q);
/* sorts name in ascending order then score in descending order */
int nasc_sdsc(const void *p, const void *q);
/* sorts name in descending order then score in ascending order */
int ndsc_sasc(const void *p, const void *q);
/* sorts score in ascending order then name in descending order */
int sasc_ndsc(const void *p, const void *q);
/* sorts score in descending order then name in ascending order */
int sdsc_nasc(const void *p, const void *q);



#endif