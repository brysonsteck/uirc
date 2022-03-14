#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stb/stb_image.h>

const char *VERSION = "0.1.0";

int handleArg(arg) char *arg; {
  int value, size; 
  char flag, *longFlag, first, firstTwo[3];
  const char *help;

  help =  "usage: uirc [-hl] [-r] IMAGE1 [IMAGE2] [...]\n\n"

          "options:\n"
          "\t-h\t> Display this message\n"
          "\t-l\t> Display the license disclaimer for uirc (BSD 2-Clause)\n\n"

          "\t-r\t> Display the resolution of the image (in addition to the ratio)\n\n"

          "help:\n"
          "If you get stuck using uirc, you can read the manpage for uirc:\n\n"

          "\t'man uirc'\n\n";

  flag = '-';
  longFlag = "--";
  first = arg[0];

  firstTwo[0] = arg[0];
  firstTwo[1] = arg[1];
  firstTwo[2] = '\0';
  size = sizeof arg;

  //if (strcmp(longFlag, firstTwo) == 0) {
    //printf("it has two dashes\n");
  //  switch (arg) {
  //    case "--okay":
  //      printf("success");
  //      break;
  //    default:
  //      printf("failure");
  //      break;
  //  }
  //  return 0;
  //} else if (flag == first) {
  //  printf("it has a dash\n");
  //  return 0;
  //}

  if (flag == first) {
    for (int i = 1; i < size; i++) {
      switch (arg[i]) {
        case 'h':
          printf("an unneccessary image ratio calculator (uirc) v%s\n\n", VERSION);
          printf("Copyright 2022 Bryson Steck\nLicensed under the BSD 2-Clause. You can read the license by running 'uirc -l'\n\n");  
          printf("%s\n", help);
          break;
        case 'l':
          printf("%s\n", license);
          break;
        case '\0':
          break;
        //default:
        //  printf("uirc: invalid argument \"%s\"\n", arg);
        //  return 1;
      }
    }
  }

  return 0;
  
}

int readFile() {
  
}

int main(argc, argv) int argc; char *argv[]; {
  //int i;
  char *i;

  if (argc <= 1) {
    printf("uirc: at least one argument is required\n");
    return 1;
  }

  char *a = argv[1];
  return handleArg(a);

}


