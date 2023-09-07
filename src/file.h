#ifndef _FILE_H
#define _FILE_H

#define is_open(x,f,p)  if (x == NULL) { \
			UNPROTECT(p); \
			error("Unable to open file %s.\n", f); \
			return(R_NilValue); \
			}

/* memory allocation macro */
#define str_alloc(x,x_len,len) if(len > x_len) { \
                        	if(x) \
                                	R_chk_free(x); \
	                        x = (char *) R_chk_calloc(len, sizeof(char)); \
	                        x_len = len; \
                		} 

#define STRLEN 256

struct _spectrum {
	int *mz;   /* mass or m/z */
	int *in;   /* intensity */
	int len;   /* number of points */
	int alloc; /* allocated memory */
};

typedef struct _spectrum spectrum_t;

struct _spectra {
	int n_scans;  /* number of scans */
	int p_count;  /* point count */
	int alloc;    /* size of allocated memory */
	double *ri;
	double *rt;
	struct _spectrum *sp;
};

typedef struct _spectra spectra_t;

/* Function prototypes */
int checksig(unsigned char *);

void swapb(void *, int);
void swapp(void *, int, int);

spectra_t * read_dat(FILE *, int);
void write_dat(FILE *, spectra_t *, int);
void write_peaks_dat(char **, double *, double *, int *, int *, int *, int *);

spectra_t * read_txt(FILE *, int, int, int);
int read_spectrum(char *, int *, int *);
void write_txt(FILE *, spectra_t *, char *);
void write_peaks_text(char **, double *, double *, int *, int *, int *, char **);

spectra_t pktosp(double *, double *, int *, int *, int);

void text_to_dat(char **, char **, int *, int *);
void dat_to_text(char **, char **, int *, char **);

#endif
