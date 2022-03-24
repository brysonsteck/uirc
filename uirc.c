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
#include <curl/easy.h>
#include <stdbool.h>

const char *VERSION = "0.1.0";

int handleArg(char *arg) {
  int value, size; 
  char flag, *longFlag, *http, first, firstTwo[3], firstFour[5];
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
  http = "http";
  first = arg[0];

  firstFour[0] = arg[0];
  firstFour[1] = arg[1];
  firstFour[2] = arg[2];
  firstFour[3] = arg[3];
  firstFour[4] = '\0';

  firstTwo[0] = arg[0];
  firstTwo[1] = arg[1];
  firstTwo[2] = '\0';
  size = sizeof arg;

  int rFlag;

  // determine if any arguments are flags 
  if (strcmp(longFlag, firstTwo) == 0) {
    printf("ok");
    return 0;
  } else if (flag == first) {
    for (int i = 1; i < size; i++) {
      switch (arg[i]) {
        case 'h':
          printf("an unneccessary image ratio calculator (uirc) v%s\n\n", VERSION);
          printf("Copyright 2022 Bryson Steck\nFree and Open Source under the BSD 2-Clause License\n\n");  
          printf("%s\n", help);
          exit(1);
        case 'l':
          printf("uirc is Free and Open Source Software under the BSD 2-Clause License.\n");
          printf("Please read the license regarding copying and distributing uirc.\n");
          printf("https://github.com/brysonsteck/uirc/blob/master/LICENSE\n");
          exit(1);
        case 'r':
          rFlag = true;
          break;
        case '\0':
          break;
      }
    }
  }
  if (strcmp(http, firstFour) == 0) {
    download(arg);
    int complete = readFile("/tmp/uirc.tmp", rFlag, 0, arg);
    if (complete != 0) {
      complete = readFile(arg, rFlag, 1);
      if (complete != 0) {
        exit(4);
      }
    }
    remove("/tmp/uirc.tmp");
  } else {
    // if no more flags, run ratio calculations
    return readFile(arg, rFlag, 1);
  }
  
}

int readFile(char *file, int rFlag, int req, char* url) {
  int width, height, channels, factor;
  unsigned char *img = stbi_load(file, &width, &height, &channels, 0);
  if (img == NULL) {
    if (req == 0) {
      printf("uirc: request failed (%s), trying local fs instead\n", url);
      return 4;
    } else {
      printf("uirc: could not open file %s\n", file);
      return 3;
    }
  }

  factor = getBcf(width, height);
  stbi_image_free(img);
  double wuneven = ((float) height) / ((float) width);
  double huneven = ((float) width) / ((float) height);

  if (factor == 1) {
    if (width < height) {
      printf("%s > 1:%.2f (uneven)\n", file, wuneven);
    } else {
      printf("%s > %.2f:1 (uneven)\n", file, huneven);
    }
  } else {
    printf("%s > %d:%d\n", file, width / factor, height / factor);   
  }
  return 0;
}

int getBcf(int width, int height) {
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

// thanks :) https://stackoverflow.com/questions/19404616/c-program-for-downloading-files-with-curl
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int download(char *url) {
  CURL *curl;
  FILE *fp;
  CURLcode res;
  char outfilename[FILENAME_MAX] = "/tmp/uirc.tmp";
  curl = curl_easy_init();
  if (curl) {
    fp = fopen(outfilename,"wb");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(fp);
  }
  return 0;
}
// end of stack overflow

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

  return 0;
}


