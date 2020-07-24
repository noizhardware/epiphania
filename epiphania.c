/*#define  _GNU_SOURCE*/
#define _POSIX_C_SOURCE 200809L /* for getline() and getdelim() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

     
/*
head10
dark / light (theme)
head20
page title
head30
lxmenu
head40
main (page)
foot10
*/

#define DARK "dark"
#define LIGHT "light"
#define BLACK "black"

int main (){
     /*char* head10 = "";*/
     char* fileName = "testhtml.html";
     
     char* theme;
     char* pageTitle;
     
     theme = DARK;
     pageTitle = "test";

     fileReset(fileName);
     fileAppendFile("render/head10.html", fileName);
     fileAppend(fileName, theme);
     fileAppendFile("render/head20.html", fileName);
     fileAppend(fileName, pageTitle);
     fileAppendFile("render/head30.html", fileName);
     fileAppendFile("render/lxmenu_test.html", fileName);
     fileAppendFile("render/head40.html", fileName);
     
     fileAppend(fileName, "<h1>PORCODIO</h1>\n"); /* MAIN */
     
     fileAppendFile("render/foot10.html", fileName);
     

return 0;}
