#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>

void reformat_string(char *src, char *dst) {
    for (; *src; ++src)
        if (!ispunct((unsigned char) *src))
            *dst++ = tolower((unsigned char) *src);
    *dst = 0;
}

void print_kv(char* key, guint* value) {
    g_print("%s : %d  \n",key,*value);
}

int main(int argc, char** argv) {
    FILE *f = fopen(argv[1], "r");
    char xr[1024];
    GHashTable *ht = g_hash_table_new(g_str_hash, g_str_equal);
    while(fscanf(f," %1023s",xr) == 1)
    {
	char* x;
	x = malloc(sizeof(xr));
	reformat_string(xr, x);
	guint *v;
	v = (guint*) g_hash_table_lookup(ht, x);
        if (v == NULL)
        {
	    guint *ox = g_malloc(sizeof(guint));
	    *ox = 1;
	    g_hash_table_insert(ht, g_strdup(x), ox);
        } else
        {
	    (*v)++;
            g_hash_table_replace(ht, g_strdup(x), v);
        }
    }
    fclose(f);
    g_hash_table_foreach(ht, (GHFunc)print_kv, NULL);
}

