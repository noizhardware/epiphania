/*#define  _GNU_SOURCE*/
#define _POSIX_C_SOURCE 200809L /* for getline() and getdelim() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include "html.h"*/

#include "helpers.h" /* temporary */
#include "baoutil.h"
#include "baofiles.h"

#include "baotime.h"


/* C90 compliant <3 */

/***
code documentation block
***/

/*
images!

script blocks (js)

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

*/

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

int main (){
/* var defs */
     /*char* head10 = "";*/
     char* fileName = "testhtml.html";
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
     epiFile epiFiles[100]; /* max files */
     unsigned int tagIndex = 0;
/* var defs END */

     startTimer();

     theme = "dark";
     pageTitle = "test";

     fileReset(fileName);
     fileAppendFile("render/head10.html", fileName);
     fileAppendString(fileName, theme);
     fileAppendFile("render/head20.html", fileName);
     fileAppendString(fileName, pageTitle);
     fileAppendFile("render/head30.html", fileName);
     /*fileAppendFile("render/head30-topimage.html", fileName);*/
     fileAppendFile("render/lxmenu_test.html", fileName);
     fileAppendFile("render/head40.html", fileName);
     /*fileAppendFile("render/head40-topimage.html", fileName);*/

     fileAppendString(fileName, "<h1>PORCODIO</h1>\n"); /* MAIN */

     /* full test (MAIN)*/
          /*toHtml = appendString(toHtml, htmlParagraph(terminateStringOnChar(epiSource, '\n', true, false), true), true);*/ /* takes first line */

          /* TODO: creare dei #define per sti blocchetti (da mettere direttamente in helpers.h >> baofiles.h)*/
          html = htmlHeader("Header ONE", 1);
               fileAppendString(fileName, html);
               free(html);
          html = htmlHeader("Header TWO", 2);
               fileAppendString(fileName, html);
               free(html);
          html = htmlHeader("Header THREE", 3);
               fileAppendString(fileName, html);
               free(html);
          html = htmlHeader("Header FOUR", 4);
               fileAppendString(fileName, html);
               free(html);
          html = htmlHeader("Header FIVE", 5);
               fileAppendString(fileName, html);
               free(html);
          html = htmlHeader("Header SIX", 6);
               fileAppendString(fileName, html);
               free(html);

          html = htmlParagraph("plain paragraph");
               fileAppendString(fileName, html);
               free(html);

          html2 = htmlBold("bold text");
          html = htmlParagraph(html2);
               fileAppendString(fileName, html);
               free(html);
               free(html2);
          html2 = htmlItalic("italic text");
          html = htmlParagraph(html2);
               fileAppendString(fileName, html);
               free(html);
               free(html2);
          html3 = htmlItalic("italic and bold text");
          html2 = htmlBold(html3);
          html = htmlParagraph(html2);
               fileAppendString(fileName, html);
               free(html);
               free(html2);
               free(html3);

          html = htmlParagraph("line break below:");
               fileAppendString(fileName, html);
               free(html);
               html = htmlBr();
                    fileAppendString(fileName, html);
                    free(html);
          html = htmlParagraph("horizontal ruler below:");
               fileAppendString(fileName, html);
               free(html);
               html = htmlHr();
                    fileAppendString(fileName, html);
                    free(html);

          html2 = htmlLinkLoc("localsample", "This is a local link");
          html = htmlParagraph(html2);
               fileAppendString(fileName, html);
               free(html);
               free(html2);
          html2 = htmlLinkExt("http://www.example.com", "This is an external link");
          html = htmlParagraph(html2);
               fileAppendString(fileName, html);
               free(html);
               free(html2);

          html2 = htmlCenter("centered text");
          html = htmlParagraph(html2);
               fileAppendString(fileName, html);
               free(html);
               free(html2);

          html = htmlList(list, ARRAYELEMS(list));
               fileAppendString(fileName, html);
               free(html);

     fileAppendFile("render/foot10.html", fileName);

     /* file reading */
     /*lines = fileToLines("database/matrixmixers.md", MAX_LINE_SIZE, MAX_LINES_IN_FILE);*/
     epiName = "matrixmixers";
     lines = getArray(epiName);

     /* delete all comments */
     while(lines[i][0]!=EOF){
          line = terminateStringOnString(lines[i], COMMENT_GLYPH, true);
          sprintf(lines[i], "%s", line);
          printf("%s\n", lines[i]);
          free(line);
          i++;}

          epiFiles[0].name = epiName;
          printf("==filename: %s\n", epiFiles[0].name);

          i=0;
      while(lines[i][0]!=EOF){
          if(startsWith(lines[i], "title ")){
            line = removeSubstr(lines[i], "title ");
            epiFiles[0].title = line;
            printf("==title: %s\n", epiFiles[0].title);
            free(line);}
          else if(startsWith(lines[i], "parent ")){
            line = removeSubstr(lines[i], "parent ");
            epiFiles[0].parent = line;
            printf("==parent: %s\n", epiFiles[0].parent);
            free(line);}
          else if(startsWith(lines[i], "type ")){
            line = removeSubstr(lines[i], "type ");
            if(strEqual(line, "normal")){
              epiFiles[0].type = NORMAL;}
            else if(strEqual(line, "index")){
              epiFiles[0].type = INDEX;}
            else if(strEqual(line, "leaf")){
              epiFiles[0].type = LEAF;}
            printf("==type: %d\n", epiFiles[0].type);
            free(line);}
          else if(startsWith(lines[i], "theme ")){
            line = removeSubstr(lines[i], "theme ");
            if(strEqual(line, "light")){
              epiFiles[0].type = LIGHT;}
            else if(strEqual(line, "dark")){
              epiFiles[0].type = DARK;}
            else if(strEqual(line, "black")){
              epiFiles[0].type = BLACK;}
            printf("==theme: %d\n", epiFiles[0].type);
            free(line);}
          else if(startsWith(lines[i], "desc ")){
            line = removeSubstr(lines[i], "desc ");
            epiFiles[0].description = line;
            printf("==description: %s\n", epiFiles[0].description);
            free(line);}
          else if(startsWith(lines[i], "status ")){
            line = removeSubstr(lines[i], "status ");
            if(strEqual(line, "active")){
              epiFiles[0].status = ACTIVE;}
            else if(strEqual(line, "upcoming")){
              epiFiles[0].status = UPCOMING;}
            else if(strEqual(line, "unlisted")){
              epiFiles[0].status = UNLISTED;}
            else if(strEqual(line, "hide")){
              epiFiles[0].status = HIDE;}
            printf("==status: %d\n", epiFiles[0].status);
            free(line);}
          else if(startsWith(lines[i], TAG_GLYPH)){
            line = removeSubstr(lines[i], TAG_GLYPH);
            epiFiles[0].tags[tagIndex] = line;
            printf("==tag: %s\n", epiFiles[0].tags[tagIndex]);
            tagIndex++;
            free(line);}
           i++;}


     freeStringTable(lines);

     stopTimer();
     printf("finished in: %ld.%ldsec\n", elapsed().tv_sec, elapsed().tv_usec);

return 0;}
