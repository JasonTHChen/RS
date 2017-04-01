#include "record_list.h"

/*
 * Name:   Jason Chen
 * Date:   March 20, 2017
 */

/*************************************************************************************
 * rs program accepts sorting arugment. If there is no specific sort arugment, the   *
 * records will be sorted by ID. Then, the program reads records from standard input *
 * and stores them in a dynamic array. After finish reading, the program sorts the   *
 * array and prints back the records in some sort order.                             *
 *************************************************************************************/
 
int get_option(const char[]);
void sorting_option(const int, const record_list *);

/* takes 1 argument which tells the program how the data is wanted to be sorted
   or no arugment which sorts the data by default(sorted by id) */
int main(int argc, char *argv[]) {
	int option = 0;
	record_list list;
	list.nalloc = 0;
	list.nused = 0;
	
	#ifdef DEBUG
		fprintf(stderr, "# Initial memory allocation\n");
	#endif
	
	if (argc > 2) {
		fprintf(stderr, "usage: %s or %s [sort_option] \n", argv[0], argv[0]);
		return 1;
	}
	
	if (argc == 2) {
		option = get_option(argv[1]);
		if (!option) {
			fprintf(stderr, "usage: %s or %s [sort_option] \n", argv[0], argv[0]);
			return 2;
		}
	}
		
	list.data = malloc(list.nalloc * sizeof(list.data));
	add_record(&list);
	sorting_option(option, &list);
	print_records(&list);
	free_memory(&list);
	
	return 0;
}

/* gets an option that is passed in arguments */
int get_option(const char arg[]) {
	if (strlen(arg) == 2) {
		if (arg[0] == 'n' && arg[1] == '+') {
			return 1;
		} else if (arg[0] == 'n' && arg[1] == '-') {
			return 2;
		} else if (arg[0] == 's' && arg[1] == '+') {
			return 3;
		} else if (arg[0] == 's' && arg[1] == '-') {
			return 4;
		}
	}
	
	if (strlen(arg) == 4) {
		if (arg[0] == 'n' && arg[1] == '+') {
			if (arg[2] == 's' && arg[3] == '-') {
				return 5;
			} else if (arg[2] == 's' && arg[3] == '+') {
				return 1;
			}
		} else if (arg[0] == 'n' && arg[1] == '-') {
			if (arg[2] == 's' && arg[3] == '+') {
				return 6;
			} else if (arg[2] == 's' && arg[3] == '-') {
				return 2;
			}
		} else if (arg[0] == 's' && arg[1] == '+') {
			if (arg[2] == 'n' && arg[3] == '-') {
				return 7;
			} else if (arg[2] == 'n' && arg[3] == '+') {
				return 3;
			}
		} else if (arg[0] == 's' && arg[1] == '-') {
			if (arg[2] == 'n' && arg[3] == '+') {
				return 8;
			} else if (arg[2] == 'n' && arg[3] == '-') {
				return 4;
			}
		}
	}
	
	return 0;
}

/* sort user's desired option */
void sorting_option(const int option, const record_list *list) {
	switch (option) {
	  case 0:
	    /* sort ID */
		qsort(list->data, list->nused, sizeof(record), sort_id);
		break;
	  case 1:
	    /* n+s+ */
		qsort(list->data, list->nused, sizeof(record), nasc_sasc);
		break;
	  case 2:
	    /* n-s- */
		qsort(list->data, list->nused, sizeof(record), ndsc_sdsc);
		break;
	  case 3:
	    /* s+n+ */
		qsort(list->data, list->nused, sizeof(record), sasc_nasc);
		break;
	  case 4:
	    /* s-n- */
		qsort(list->data, list->nused, sizeof(record), sdsc_ndsc);
		break;
	  case 5:
	    /* n+s- */
		qsort(list->data, list->nused, sizeof(record), nasc_sdsc);
		break;
	  case 6:
	    /* n-s+ */
		qsort(list->data, list->nused, sizeof(record), ndsc_sasc);
		break;
	  case 7:
	    /* s+n- */
		qsort(list->data, list->nused, sizeof(record), sasc_ndsc);
		break;
	  case 8:
	    /* s-n+ */
		qsort(list->data, list->nused, sizeof(record), sdsc_nasc);
		break;
	  default:
		/* should not be here */
		fprintf(stderr, "error option\n");

	}
}
