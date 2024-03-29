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
#include <stb/stb_image.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <unistd.h>
#include <stdbool.h>

const char *VERSION = "0.1.0";
bool singular = false;
bool rFlag = false;

int getBcf(int width, int height) {
  unsigned int bcf;
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

bool compare_float(float a, float b) {
  return fabs(a-b) < 0.001;
}

int readFile(char *file, bool rFlag, unsigned int req, char* url) {
  char *displayfile;
  int result;
  unsigned int width, height, channels, factor;
  result = stbi_info(file, (int*) &width, (int*) &height, (int*) &channels);

  if (access(file, F_OK) != 0) {
    if (req == 0) {
      printf("FAIL\nuirc: request failed (%s), trying local fs instead\n", url);
      return 4;
    } else {
      fprintf(stderr, "uirc: %s: No such file or directory\n", file);
      exit(6);
    }
  } else {
    if (access(file, R_OK) != 0) {
      fprintf(stderr, "uirc: %s: Permission denied\n", file);
      exit(3);
    } 
    if (result != 1) {
      fprintf(stderr, "uirc: %s: Not an image or unsupported image type\n", file);
      exit(10);
    }
  }

  if (req == 0)
    printf("ok\n");

  factor = getBcf(width, height);
  double wuneven = ((float) height) / ((float) width);
  double huneven = ((float) width) / ((float) height);

  if (req == 0) {
    char *token, *next = "";

    token = strtok(url, "/");

    while (1) {
      if (next == NULL) {
        file = token;
        break;
      }
      token = next;
      next = strtok(NULL, "/");
    }
  }

  if (singular)
    displayfile = "";
  else {
    displayfile = (char*) malloc(CHAR_MAX);
    strcpy(displayfile, file);
    strcat(displayfile, " > ");
  }

  // see if uneven values equal normal aspect ratios
  // aspect ratios obtained from https://en.wikipedia.org/wiki/Aspect_ratio_(image)
  bool bestFit = false;

  if (width < height) {
    if (compare_float(wuneven, 1.77777777)) {
      // 9:16
      printf("%s9:16", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.33333333)) {
      // 3:4
      printf("%s3:4", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 0.46153846)) {
      // 6:13
      printf("%s6:13", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.25)) {
      // 4:5
      printf("%s4:5", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.5)) {
      // 2:3
      printf("%s2:3", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.6)) {
      // 10:16
      printf("%s10:16", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 2.37037037)) {
      // 27:64
      printf("%s27:64", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 3.55555555)) {
      // 9:32
      printf("%s9:32", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.66666666)) {
      // 3:5
      printf("%s3:5", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.6180)) {
      // golden ratio
      printf("%s1:1.6180 (GOLDEN RATIO!!!!)", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.85)) {
      // 1:1.85
      printf("%s1:1.85", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 2.33333333)) {
      // 9:21
      printf("%s9:21", displayfile);
      bestFit = true;
    } else if (compare_float(wuneven, 1.55555555)) {
      // 9:14
      printf("%s9:14", displayfile);
      bestFit = true;
    }
  } else {
    if (compare_float(huneven, 1.77777777)) {
      // 16:9
      printf("%s16:9", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.33333333)) {
      // 4:3
      printf("%s4:3", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 0.46153846)) {
      // 13:6
      printf("%s13:6", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.25)) {
      // 5:4
      printf("%s5:4", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.5)) {
      // 3:2
      printf("%s3:2", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.6)) {
      // 16:10
      printf("%s16:10", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 2.37037037)) {
      // 64:27
      printf("%s64:27", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 3.55555555)) {
      // 32:9
      printf("%s32:9", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.66666666)) {
      // 5:3
      printf("%s5:3", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.6180)) {
      // golden ratio
      printf("%s1.6180:1 (GOLDEN RATIO!!!!)", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.85)) {
      // 1.85:1
      printf("%s1.85:1", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 2.33333333)) {
      // 21:9
      printf("%s21:9", displayfile);
      bestFit = true;
    } else if (compare_float(huneven, 1.55555555)) {
      // 14:9
      printf("%s14:9", displayfile);
      bestFit = true;
    }
  }

  if (!bestFit) {
    if (factor == 1) {
      if (width < height) {
        printf("%s1:%.2f (uneven)", displayfile, wuneven);
      } else {
        printf("%s%.2f:1 (uneven)", displayfile, huneven);
      }
    } else {
      printf("%s%d:%d", displayfile, width / factor, height / factor);
    }
  }

  if (rFlag)
    printf(" [%dx%d]\n", width, height);
  else
    printf("\n");

  if (strcmp(displayfile, ""))
    free(displayfile);

  return 0;
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
  char outfilename[15] = "/tmp/uirc.tmp";
  curl = curl_easy_init();
  long returnCode = 0;

  if (curl) {
    fp = fopen(outfilename,"wb");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, returnCode);
    curl_easy_cleanup(curl);
    fclose(fp);
  }

  return 0;
}
// end of stack overflow snippet

int handleArg(char *arg, int argc) {
  unsigned int complete;
  char flag, first, firstTwo[3], firstFour[5];
  const char *help;

  help =  "USAGE: uirc [OPTIONS] IMAGE1 [IMAGE2] [...]\n\n"

          "OPTIONS:\n"
          "informational:\n"
          "  -h, --help   \t: Display this message\n"
          "  -l, --license\t: Display the license disclaimer for uirc (BSD 2-Clause)\n"
          "  -v, --version\t: Display the version of uirc\n\n"

          "functional:\n"
          "  -r, --res    \t: Display the resolution of the image (in addition to the ratio)\n\n"

          "HELP:\n"
          "For more information on how to use uirc, open the man page uirc(1).\n";

  first = arg[0];

  firstFour[0] = arg[0];
  firstFour[1] = arg[1];
  firstFour[2] = arg[2];
  firstFour[3] = arg[3];
  firstFour[4] = '\0';

  firstTwo[0] = arg[0];
  firstTwo[1] = arg[1];
  firstTwo[2] = '\0';

  if (strcmp("--", firstTwo) == 0 || '-' == first) {
    if (strcmp("--help", arg) == 0 || strcmp("-h", arg) == 0) {
      printf("an unneccessary image ratio calculator (uirc) v%s\n\n", VERSION);
      printf("Copyright 2022 Bryson Steck\nFree and Open Source under the BSD 2-Clause License\n\n");  
      printf("%s\n", help);
      exit(1);
    } else if (strcmp("--license", arg) == 0 || strcmp("-l", arg) == 0) {
      printf("uirc is Free and Open Source Software under the BSD 2-Clause License.\n");
      printf("Please read the license regarding copying and distributing uirc.\n");
      printf("https://github.com/brysonsteck/uirc/blob/master/LICENSE\n");
      exit(1);
    } else if (strcmp("--res", arg) == 0 || strcmp("-r", arg) == 0) {
      if (rFlag) {
        fprintf(stderr, "uirc: -r / --res flag is used way too many times\n");
        exit(9);
      }
      rFlag = true;
      if (argc == 3)
        singular = true;
      return 0;
    } else if (strcmp("--version", arg) == 0 || strcmp("-v", arg) == 0) {
      printf("uirc v%s", VERSION);
      exit(1);
    } else {
      fprintf(stderr, "uirc: invalid argument \"%s\"\nType \"uirc --help\" for help with arguments.\n", arg);
      exit(5);
    }
  }

  if (argc == 2)
    singular = true;

  if (strcmp("http", firstFour) == 0) {
    printf("downloading \"%s\"...", arg);
    fflush(stdout);
    download(arg);
    complete = readFile("/tmp/uirc.tmp", rFlag, 0, arg);
    if (complete != 0) 
      readFile(arg, rFlag, 1, "");
    else
      remove("/tmp/uirc.tmp");
  } else {
    // if no more flags, run ratio calculations
    return readFile(arg, rFlag, 1, "");
  }

  return 0;
}

int main(int argc, char *argv[]) {
  char *i, *a;
  unsigned int runs, code, arg_code;

  if (argc <= 1) {
    printf("uirc: at least one argument is required\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    a = argv[i];
    arg_code = handleArg(a, argc);
    if (arg_code > code)
      code = arg_code;
    runs++;
  }

  if (runs < 2 && rFlag) {
    printf("uirc: at least one file/url is required\n");
    return 1;
  }

  return 0;
}

