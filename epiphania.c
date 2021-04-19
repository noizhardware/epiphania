/*** TODO

this program writes to testhtml.html now

     - see: https://github.com/hundredrabbits/100r.co/blob/master/src/main.c (fputs and fprintf)
     - elimina leading and trailing spaces (possono rimanere dalla rimozione dei comments)
     - get rid of all malloc/calloc
     - images!
     - script blocks (js)
     - "linked from" : list of pages that link to the present page, at the end of the present page

<head>
  <meta charset="utf-8">
  <!-- Basic -->
  <meta name="author" content="underscorediscovery">
  <meta name='description' content='game/design/develop.'/>
  <meta name='keywords' content='Ruby, underscorediscovery, _discovery, luxe, luxe engine, Oscean, Merveilles' />
  <meta name="thumbnail" content="https://underscorediscovery.ca/media/diary/1.jpg" />
  <link rel="shortcut icon" href="media/icon/favico.png" />
  <!-- Twitter -->
  <meta name="twitter:card" content="summary">
  <meta name="twitter:site" content="@___discovery">
  <meta name="twitter:title" content="game/design/develop">
  <meta name="twitter:description" content="access endpoint: _discovery">
  <meta name="twitter:creator" content="@___discovery">
  <meta name="twitter:image" content="https://underscorediscovery.ca/media/diary/1.jpg">

* google analytics block (dentro head)
    <!-- Google verify ownership tag -->
    <meta name="google-site-verification" content="ORFFuZKTOlNuCp1VtRDqofVDm6lV4M9hDI86duO1Elo" />

    <!-- Global site tag (gtag.js) - Google Analytics -->
    <script async src="https://www.googletagmanager.com/gtag/js?id=UA-132920421-1"></script>
    <script>
      window.dataLayer = window.dataLayer || [];
      function gtag(){dataLayer.push(arguments);}
      gtag('js', new Date());

      gtag('config', 'UA-132920421-1');
    </script>

* sitemap generator: checka ogni file i link locali che ha, e li lista come suoi children, ricorsivamente

* https://www.foo.software/lighthouse

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

#define EPIPHANIA_VERSION "2021d19-1710"

/*** DEFINES */
     /*#define  _GNU_SOURCE*/
     #define _POSIX_C_SOURCE 200809L /* for getline() and getdelim() */
/* DEFINES end. */

/*** INCLUDES */
     #include <stdio.h>
     #include <stdlib.h>
     #include <string.h>
     #include <locale.h>
     /*#include "html.h"*/

     #include "helpers.h" /* cacca: temporary */
     #include "baoutil.h"
     #include "baofiles.h"

     #include "baotime.h"
/* INCLUDES end. */

/*** TYPEDEFS */
/* TYPEDEFS end. */

/*** GLOBALS */
/* GLOBALS end. */

/*** FUNCTION DECLARATIONS */
/* FUNCTION DECLARATIONS end. */

/*** MAIN */
int main (){
/**** var defs */
     /*char* head10 = "";*/
     char fileOut[EPI_MAX_FILENAME_LEN] = "site/testhtml.html";
     char* theme;
     char* pageTitle;
     char* html;
     char* html2;
     char* html3;
          char* list[] = {
               "list item one",
               "list item two",
               "list item three",};
     char** lines;
     char* line;
     int i = 0;
     char* epiName;
     epiFile epiFiles[MAX_FILES];
     unsigned int tagIndex = 0;
/**** var defs END */

     setlocale(LC_NUMERIC, ""); /* to get comma thousand separators for large numbers */

     startTimer();
     
     /**** HTML writing test */
          theme = "dark";
          pageTitle = "test";

          fileReset(fileOut);
          fileAppendFile("render/head10.html", fileOut);
          fileAppendString(fileOut, theme);
          fileAppendFile("render/head20.html", fileOut);
          fileAppendString(fileOut, pageTitle);
          fileAppendFile("render/head30.html", fileOut);
          /*fileAppendFile("render/head30-topimage.html", fileOut);*/
          fileAppendFile("render/lxmenu_test.html", fileOut);
          fileAppendFile("render/head40.html", fileOut);
          /*fileAppendFile("render/head40-topimage.html", fileOut);*/

          fileAppendString(fileOut, "<h1>PORCODIO</h1>\n"); /* MAIN */
          
          /* TODO: move this macro in its lib, and move "html" there as well, as a global var */
          #define HTML_HEADER(string, headerNum, file) html = htmlHeader(string, headerNum);fileAppendString(file, html);free(html);
               HTML_HEADER ("Header ONE", 1, fileOut);
               HTML_HEADER ("Header TWO", 2, fileOut);
               HTML_HEADER ("Header THREE", 3, fileOut);
               HTML_HEADER ("Header FOUR", 4, fileOut);
               HTML_HEADER ("Header FIVE", 5, fileOut);
               HTML_HEADER ("Header SIX", 6, fileOut);
               /* TODO: write macros for all the other html things */

          #define HTML_PARAGRAPH(string, file) html = htmlParagraph(string);fileAppendString(fileOut, html);free(html);
               HTML_PARAGRAPH("plain paragraph", fileOut);

               html2 = htmlBold("bold text");
               html = htmlParagraph(html2);
                    fileAppendString(fileOut, html);
                    free(html);
                    free(html2);
               html2 = htmlItalic("italic text");
               html = htmlParagraph(html2);
                    fileAppendString(fileOut, html);
                    free(html);
                    free(html2);
               html3 = htmlItalic("italic and bold text");
               html2 = htmlBold(html3);
               html = htmlParagraph(html2);
                    fileAppendString(fileOut, html);
                    free(html);
                    free(html2);
                    free(html3);

               HTML_PARAGRAPH("line break below:", fileOut);
               #define HTML_LINEBREAK(file) html = htmlBr();fileAppendString(file, html);free(html);
                    HTML_LINEBREAK(fileOut);
               HTML_PARAGRAPH("horizontal ruler below:", fileOut);
               #define HTML_HRULER(file) html = htmlHr();fileAppendString(file, html);free(html);
                    HTML_HRULER(fileOut);
               
               html2 = htmlLinkLoc("localsample", "This is a local link");
               html = htmlParagraph(html2);
                    fileAppendString(fileOut, html);
                    free(html);
                    free(html2);
               html2 = htmlLinkExt("http://www.example.com", "This is an external link");
               html = htmlParagraph(html2);
                    fileAppendString(fileOut, html);
                    free(html);
                    free(html2);

               html2 = htmlCenter("centered text");
               html = htmlParagraph(html2);
                    fileAppendString(fileOut, html);
                    free(html);
                    free(html2);

               html = htmlList(list, ARRAYELEMS(list));
                    fileAppendString(fileOut, html);
                    free(html);

          fileAppendFile("render/foot10.html", fileOut);
     /**** HTML writing test END. */

     /**** file reading */
     /*lines = fileToLines("database/matrixmixers.md", MAX_LINE_SIZE, MAX_LINES_IN_FILE);*/
     epiName = "test";
     lines = getArray(epiName);

     printf("\n");
     /* delete all comments */
     while(lines[i][0]!=EOF){
          if(!strEqual(lines[i], "---")){
               line = terminateStringOnString(lines[i], COMMENT_GLYPH, true); /* TODO: copiare eliminazione commenti da mass.h, li è fatta meglio */
               sprintf(lines[i], "%s", line);
               free(line);
          }
          printf(">>%s\n", lines[i]);
          i++;
     }
     printf("\n");
     /* delete all comments END. */

     /* setup output file */
     epiFiles[0].name = epiName;
     printf("==filename: %s >> ", epiFiles[0].name);
     sprintf(fileOut, "site/%s.html", epiName);
     printf("%s\n", fileOut);
     fileReset(fileOut);

     i=0; /* now getting metadata from the file */
     while(lines[i][0]!=EOF){
          if(startsWith(lines[i], "title ")){
               epiFiles[0].title = trim(lines[i]+6);
               printf("==title: |%s|\n", epiFiles[0].title);}
          else if(startsWith(lines[i], "parent ")){
               epiFiles[0].parent = trim(lines[i]+7);
               printf("==parent: |%s|\n", epiFiles[0].parent);}
          else if(startsWith(lines[i], "type ")){
               if(strEqual(trim(lines[i]+5), "normal")){
                    epiFiles[0].type = NORMAL;}
               else if(strEqual(trim(lines[i]+5), "index")){
                    epiFiles[0].type = INDEX;}
               else if(strEqual(trim(lines[i]+5), "leaf")){
                    epiFiles[0].type = LEAF;}
               else{
                    epiFiles[0].type = NOTYPE;}
               printf("==type: %d\n", epiFiles[0].type);}
          else if(startsWith(lines[i], "theme ")){
               sprintf(epiFiles[0].theme, "%s", lines[i]+6);
               /*if(strEqual(trim(lines[i]+6), "light")){
                    epiFiles[0].theme = LIGHT;}
               else if(strEqual(trim(lines[i]+6), "dark")){
                    epiFiles[0].theme = DARK;}
               else if(strEqual(trim(lines[i]+6), "black")){
                    epiFiles[0].theme = BLACK;}
               else{
                    epiFiles[0].theme = NOTHEME;}*/
               printf("==theme: %s\n", epiFiles[0].theme);
          }
          else if(startsWith(lines[i], "desc ")){
               epiFiles[0].description = trim(lines[i]+5);
               printf("==description: |%s|\n", epiFiles[0].description);}
          else if(startsWith(lines[i], "status ")){
               if(strEqual(trim(lines[i]+7), "active")){
                    epiFiles[0].status = ACTIVE;}
               else if(strEqual(trim(lines[i]+7), "upcoming")){
                    epiFiles[0].status = UPCOMING;}
               else if(strEqual(trim(lines[i]+7), "unlisted")){
                    epiFiles[0].status = UNLISTED;}
               else if(strEqual(trim(lines[i]+7), "hide")){
                    epiFiles[0].status = HIDE;}
               else{
                    epiFiles[0].status = NOSTATUS;}
               printf("==status: %d\n", epiFiles[0].status);
               if(epiFiles[0].status==ACTIVE || epiFiles[0].status==UNLISTED){
                    fileAppendFile("render/head10.html", fileOut);
                    fileAppendString(fileOut, epiFiles[0].theme);/* css theme */
                    fileAppendFile("render/head20.html", fileOut);
                    fileAppendString(fileOut, epiName);/* page title */
                    fileAppendFile("render/head30.html", fileOut);
                    /*fileAppendFile("render/head30-topimage.html", fileOut);*/
                    fileAppendFile("render/lxmenu_test.html", fileOut);
                    fileAppendFile("render/head40.html", fileOut);
                    /*fileAppendFile("render/head40-topimage.html", fileOut);*/
               }
          }
          else if(startsWith(lines[i], "imgg ")){
               epiFiles[0].image = trim(lines[i]+5);
               printf("==image: |%s|\n", epiFiles[0].image);}
          else if(startsWith(lines[i], TAG_GLYPH)){
               epiFiles[0].tags[tagIndex] = trim(lines[i]+strlen(TAG_GLYPH));
               printf("==tag %d: |%s|\n", tagIndex, epiFiles[0].tags[tagIndex]);
               tagIndex++;}
          else{ /* it's page contents */
               
               printf(">>CONTENTS>>%s\n", trim(lines[i]));
               
               
               if(startsWith(lines[i], "# ")){
                    HTML_HEADER (lines[i]+2, 1, fileOut);
               }
               else if(startsWith(lines[i], "## ")){
                    HTML_HEADER (lines[i]+3, 2, fileOut);
               }
               else if(startsWith(lines[i], "### ")){
                    HTML_HEADER (lines[i]+4, 3, fileOut);
               }
               else if(startsWith(lines[i], "#### ")){
                    HTML_HEADER (lines[i]+5, 4, fileOut);
               }
               else if(startsWith(lines[i], "##### ")){
                    HTML_HEADER (lines[i]+6, 5, fileOut);
               }
               else if(startsWith(lines[i], "###### ")){
                    HTML_HEADER (lines[i]+7, 6, fileOut);
               }
               else if(strEqual(lines[i], "---")){
                    HTML_HRULER(fileOut);
               }
               else if(strEqual(lines[i], "br")){
                    HTML_LINEBREAK(fileOut);
               }
               else{
                    /*HTML_PARAGRAPH(lines[i], fileOut);*/
                    epiDoLine(lines[i], fileOut);
               }
               
          }
          
          i++;
     }
     freeStringTable(lines);
          
     /* the file has ended, let's write the footer */
     fileAppendFile("render/foot10.html", fileOut);
     
     
     /*printf("finished in: %'.0f nsec\n", getTimerNs());*/
     printf("==>finished in: %.2f ms\n", getTimerMs());

return 0;}
/* MAIN end. */

/*** FUNCTION DEFINITIONS */
/* FUNCTION DEFINITIONS end. */
