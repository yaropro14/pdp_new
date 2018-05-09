#include "all.h"


int main(int argc, char **argv) {

    if (strcmp(argv[1], "-t") == 0) //режим трассировки включен
        t = 1;
    if (strcmp(argv[1], "-q") == 0) //режим трассировки выключен
        t = 0;

//    //printf("---start testmem---\n");
//    testmem();
//    printf("---end testmem---\n");

    FILE* f = fopen(argv[2], "r");
    load_file(f);
    fclose(f);

    f = fopen(argv[3], "w");
    f_mem_dump(01000, 0100, f);
    fclose(f);

    w_write(out, 0200);
    //word test = w_read(0177564);
    //printf("%06o", test);

    printf("--------------------RUNNING--------------------\n");

    run(01000);
    return 0;
}