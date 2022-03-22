/*

uirc: an unnecessary image ratio calculator
Created by Bryson Steck (@brysonsteck on GitHub)
Free and Open Source Software under the BSD 2-Clause License

BSD 2-Clause License

Copyright (c) 2022, Bryson Steck
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stb/stb_image.h>
#include <curl/curl.h>
#include <stdbool.h>

const char *VERSION = "0.1.0";

int handleArg(arg) char *arg; {
  int value, size; 
  char flag, *longFlag, first, firstTwo[3];
  const char *help;

  help =  "usage: uirc [OPTIONS] IMAGE1 [IMAGE2] [...]\n\n"

          "OPTIONS:\n"
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

  bool rFlag;

  // determine if any arguments are flags 
  if (strcmp(longFlag, firstTwo) == 0) {
    printf("ok");
    return 0;
  } else if (flag == first) {
    for (int i = 1; i < size; i++) {
      switch (arg[i]) {
        case 'h':
          printf("an unneccessary image ratio calculator (uirc) v%s\n\n", VERSION);
          printf("Copyright 2022 Bryson Steck\n\n\n");  
          printf("%s\n", help);
          exit(1);
        case 'l':
          //readLicense();
          exit(1);
        case 'r':
          rFlag = true;
          break;
        case '\0':
          
          break;
      }
    }
  }
  // if no more flags, run ratio calculations
  return readFile(arg, rFlag);
  
}

int readFile(file, showRes) char *file; bool showRes;{
  int width, height, channels, biggestFactor;
  unsigned char *img = stbi_load(file, &width, &height, &channels, 0);
  if (img == NULL) {
    printf("uirc: could not open file %s\n", file);
    exit(3);
  }
  printf("Opened file \n");

  biggestFactor = getBiggestFactor(width, height);
  stbi_image_free(img);

  printf("Ratio of %s > %d:%d\n", file, width / biggestFactor, height / biggestFactor);
  return 0;

}

int getBiggestFactor(int width, int height) {
  int *widthFactors, *heightFactors;
  int bcf;
  for (int i = 1; i <= width; i++) {
    for (int j = 1; j <= height; j++) {
      if (width % i == 0) {
        if (height % j == 0 && i == j) {
          bcf = j;
        }
      }
    }
  }
  return bcf;
}

//void readLicense() {
//  FILE *license;
//  char ch;
//
//  license = fopen(LICENSE_DIR "LICENSE", "r");
//  if (license == NULL) {
//    printf("uirc: cannot find LICENSE in %s\n", LICENSE_DIR);
//    printf("uirc: if you changed the location of the file, recompile uirc with the correct location or move the file back\n");
//    exit(2);
//  } else {
//    printf("uirc is Free and Open Source Software under the BSD 2-Clause License. You can view it by visiting the GitHub repository for uirc:\nhttps://github.com/brysonsteck/uirc/blob/master/LICENSE\n");
//    do {
//      ch = fgetc(license);
//      printf("%c", ch);
//    } while (ch != EOF);
//  }
//  fclose(license);
//  return;
//}

int main(int argc, char *argv[]) {
  //int i;
  char *i;

  if (argc <= 1) {
    printf("uirc: at least one argument is required\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    char *a = argv[i];
    int returned = handleArg(a);
    if (returned != 0)
      return returned;
  }
}


