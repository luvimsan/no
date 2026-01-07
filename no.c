#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *help = "Usage: no [STRING]... \n"
"  or:  no OPTION \n"
"Repeatedly output a line with all specified STRING(s), or 'n'. \n\n"
"  -h, --help        display this help and exit \n"
"  -v, --version     output version information and exit \n\n"
"Report bugs to: me@me.org \n"
"or available locally via: info '(coreutils) no invocation' \n";

char *version =
"no (AOU coreutils) 1.1 \n"
"Copyright (C) 2026 Free Software Creation, Inc. \n"
"This is free software: you are free to change and redistribute it. \n"
"There is NO WARRANTY, to the extent permitted by law. \n\n"
"Written by Loaay Waheed. \n";


void no_forever(int argc, char **argv) {
    while (1) {
        int cnt = argc;
        for (int i = 1; i < cnt; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }

}

void parse_flags(int argc, char **argv) {
    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        printf("%s", help);
        exit(0);
    }

    else if (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")) {
        printf("%s", version);
        exit(0);
    }

    else if (argv[1][0] == '-' && argv[1][1] == '-' ) {
        printf("no: unrecognized option '%s'\n", argv[1]);
        printf("Try 'no --help' for more information.\n");
        exit(0);
    }

    else if (argv[1][0] == '-') {
        printf("no: unrecognized option -- '%c'\n", argv[1][1]);
        printf("Try 'no --help' for more information.\n");
        exit(0);
    }

    else {
        no_forever(argc, argv);
    }

}


int main(int argc, char **argv) {
    if (argc == 1) {
            while (1) {
                printf("n\n");
            }
    }

    else if (argc == 2) {
        parse_flags(argc, argv);
    }

    else {
        parse_flags(argc, argv);
        no_forever(argc, argv);
    }

    return 0;
}
