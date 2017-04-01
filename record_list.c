#include "record_list.h"

/*
 * Name:   Jason Chen
 * Date:   March 20, 2017
 */

/* adds a record to the record_list */
void add_record(record_list *list) {
	char line[LINESIZE];
	record rec;
	int ret;
	
	while (1) {
		printf("Student record: ");
		if (!fgets(line, LINESIZE, stdin)) {
			printf("\n");
			#ifdef DEBUG
				fprintf(stderr, "# End of prompt\n");
			#endif
			break;
		}
		ret = create_record(&rec, line);
		if (ret) {
			realloc_space(list);
			list->data[list->nused] = rec;
			list->nused++;
		}
	}
}

/* double the size of space if dynamic memory is full */
void realloc_space(record_list *list) {
	if (list->nalloc == list->nused) {
		if (list->nalloc == 0) {
			list->nalloc = 1;
		} else {
			list->nalloc = 2 * list->nalloc;
		}
		
		#ifdef DEBUG
			fprintf(stderr, "# Re-allocate memory for %d record(s), %d Bytes\n", list->nalloc, list->nalloc * sizeof(record));
		#endif
		
		list->data = realloc(list->data, list->nalloc * sizeof(record));
	}
}

/* release the memory */
void free_memory(record_list *list) {
	free(list->data);
	list->data = 0;
	list->nalloc = 0;
	list->nused = 0;
	
	#ifdef DEBUG
		fprintf(stderr, "# Deallocate allocated memory\n");
	#endif
}

/* prints all the records from the record_list */
void print_records(const record_list *list) {
	size_t i;
	for (i = 0; i < list->nused; i++) {
		print_record(&list->data[i]);
	}
}

/* sorts record_list by ID */
int sort_id(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	
	return strcmp(pp->id, qq->id);
}

/* sorts record_list by name */
static int sort_name(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = strcmp(pp->name.last, qq->name.last);
	
	if (n != 0) {
		return n;
	}
	
	return strcmp(pp->name.first, qq->name.first);
}

/* sorts record_list by score */
static int sort_score(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	
	return pp->score - qq->score;
}

/* sorts name in ascending order then score in ascending order */
int nasc_sasc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_name(pp, qq);
	
	if (n != 0) {
		return n;
	}
	
	return sort_score(pp, qq);
}

/* sorts name in descending order then score in descending order */
int ndsc_sdsc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_name(qq, pp);
	
	if (n != 0) {
		return n;
	}
	
	return sort_score(qq, pp);
}

/* sorts score in ascending order then name in ascending order */
int sasc_nasc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_score(pp, qq);
	
	if (n != 0) {
		return n;
	}
	
	return sort_name(pp, qq);
	
}

/* sorts score in descending order then name in descending order */
int sdsc_ndsc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_score(qq, pp);
	
	if (n != 0) {
		return n;
	}
	
	return sort_name(qq, pp);
}

/* sorts name in ascending order then score in descending order */
int nasc_sdsc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_name(pp, qq);
	
	if (n != 0) {
		return n;
	}
	
	return sort_score(qq, pp);
}

/* sorts name in descending order then score in ascending order */
int ndsc_sasc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_name(qq, pp);
	
	if (n != 0) {
		return n;
	}
	
	return sort_score(pp, qq);
}

/* sorts score in ascending order then name in descending order */
int sasc_ndsc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_score(pp, qq);
	
	if (n != 0) {
		return n;
	}
	
	return sort_name(qq, pp);
}

/* sorts score in descending order then name in ascending order */
int sdsc_nasc(const void *p, const void *q) {
	const record *pp = p;
	const record *qq = q;
	int n = sort_score(qq, pp);
	
	if (n != 0) {
		return n;
	}
	
	return sort_name(pp, qq);
}