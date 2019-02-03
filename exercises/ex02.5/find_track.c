/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    // TODO: fill this in
    int i;
    int status;
    regex_t re;
    
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
    	puts("Invalid regex pattern");
	exit(1);
    }

    for (i=0; i <NUM_TRACKS; i++) {
	char *track_string = tracks[i];
    	status = regexec(&re, track_string, (size_t) 0, NULL, 0);
	regfree(&re);
	if (status == 1) {
	    printf("%s\n", track_string);
	} else if (status != 0) {
	    puts("sad");
	}
    }
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
