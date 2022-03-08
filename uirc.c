#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "stb_image.h"

const char *VERSION = "0.1.0";

int handleArg(arg) char *arg; {
  int value, size; 
  char flag, *longFlag, first, firstTwo[3];
  const char *help, *license;

  help =  "usage: uirc [-hl] [-r] IMAGE1 [IMAGE2] [...]\n\n"

          "options:\n"
          "\t-h\t> Display this message\n"
          "\t-l\t> Display the license disclaimer for uirc (BSD 2-Clause)\n\n"

          "\t-r\t> Display the resolution of the image (in addition to the ratio)\n\n"

          "help:\n"
          "If you get stuck using uirc, you can read the manpage for uirc:\n\n"

          "\t'man uirc'\n\n";

  license = "Two licenses are present in uirc.\n"
            "The stb_image library that is included with uirc is available in the Public Domain:\n\n"
            "This is free and unencumbered software released into the public domain.\n"
						"Anyone is free to copy, modify, publish, use, compile, sell, or distribute this\n"
						"software, either in source code form or as a compiled binary, for any purpose,\n"
						"commercial or non-commercial, and by any means.\n"
						"In jurisdictions that recognize copyright laws, the author or authors of this\n"
						"software dedicate any and all copyright interest in the software to the public\n"
						"domain. We make this dedication for the benefit of the public at large and to\n"
						"the detriment of our heirs and successors. We intend this dedication to be an\n"
						"overt act of relinquishment in perpetuity of all present and future rights to\n"
						"this software under copyright law.\n"
						"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
						"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
						"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
						"AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN\n"
						"ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION\n"
						"WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n\n"
						"The remaining files and binaries of uirc are available under the BSD 2-Clause:\n"
						"Copyright (c) 2022, Bryson Steck\n"
						"All rights reserved.\n\n"

						"Redistribution and use in source and binary forms, with or without\n"
						"modification, are permitted provided that the following conditions are met:\n\n"

						"1. Redistributions of source code must retain the above copyright notice, this\n"
						"   list of conditions and the following disclaimer.\n\n"

						"2. Redistributions in binary form must reproduce the above copyright notice,\n"
						"   this list of conditions and the following disclaimer in the documentation\n"
						"   and/or other materials provided with the distribution.\n\n"

						"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n"
						"AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n"
						"IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE\n"
						"DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE\n"
						"FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
						"DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR\n"
						"SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER\n"
						"CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,\n"
						"OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
						"OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n";

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


