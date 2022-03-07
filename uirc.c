#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "stb_image.h"

const char *VERSION = "0.1.0";

int handleArg(arg) char *arg; {
  int value; 
  char flag, *longFlag, first, firstTwo[3];
  char *help, *license;

  help =  "Copyright 2022 Bryson Steck\n"
          "";

  flag = '-';
  longFlag = "--";
  first = arg[0];

  firstTwo[0] = arg[0];
  firstTwo[1] = arg[1];
  firstTwo[2] = '\0';

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
    switch (firstTwo[1]) {
      case 'h':
        printf("an unneccessary image ratio calculator (uirc) v%s\n", VERSION);
        printf("%s\n", help);
        break;
      case 'l':
        printf("license\n");
        break;
      default:
        printf("uirc: invalid argument \"%s\"\n", arg);
        return 1;
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


