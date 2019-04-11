#include "magickminify.h"
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
    printf("mj!\n");

    magickminify_init();

    FILE* fp;
    fp = fopen("reef.jpg", "r");
    if (fp == NULL) {
        perror("unable to open reef.jpg");
        exit(-1);
    }

    struct stat fs;
    int fso = fstat(fileno(fp), &fs);

    printf("file sz: %ld\n", fs.st_size);

    ssize_t src_len = fs.st_size;
    char src_data[fs.st_size];

    fread(src_data, src_len, 1, fp);
    fclose(fp);

    ssize_t rsz_len = 0;
    void* rsz_data = magickminify(src_data, src_len, &rsz_len);

    printf("resized file sz: %ld\n", rsz_len);

    FILE * fpo = fopen("smallreef.jpg", "w");
    fwrite(rsz_data, rsz_len, 1, fpo);

    if (rsz_data != NULL) {
        free(rsz_data);
    }

    magickminify_cleanup();

    return 0;
}
