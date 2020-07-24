#include <stdio.h>
#include "baofiles.h"
#include "baostring.h"
/*#include "html.h"*/

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

#define DARK "dark"
#define LIGHT "light"
#define BLACK "black"

int main (){
/* var defs */
     /*char* epiFileName;*/
     /*char* epiSource;*/
     
     char* toHtml = "";
     /*char* list[] = {
          "list item one",
          "list item two",
          "list item three",};*/
     char* theme;
     char* pagetitle;
     /*char* lxmenu = "";*/
     char* head10 = "";
     char* head20 = "";
     char* head30;
     char* head40;
     char* foot10;
     char* lxmenutest;
     char* test;
/* var defs END */
     
     /*epiFileName = "database/matrixmixers.md";
     epiSource = fileRead(epiFileName);*/
     
     /* split lines? '\n' */
     /* deleteComments */
     /* title */
     /* parent */
     /* theme */
     /* type */
     /* desc */
     /* status */
     /* tags */
     
     theme = DARK; /* here theme is decided */
     pagetitle = "test"; /* page title */
     
/******************************************************************************************/

     /*toHtml = appendString(toHtml, epiSource, true);*/
     /*printf("%s\n", toHtml);*/
     
     /*head10 = fileRead("render/head10.html");
          toHtml = appendString(toHtml, head10);
          free(head10);*/
          
          /*test = appendChar("porcodio", 'S');
          free(test);*/
          
          
     toHtml = appendString(toHtml, theme);
     head20 = fileRead("render/head20.html");
     
          /*************************************
          e bho, quando uso appendString una seconda volta, mi fa errore
          *************************************/
          /*toHtml = appendString(toHtml, head20);*/
          
          free(head20);
     /*toHtml = appendString(toHtml, pagetitle);
     head30 = fileRead("render/head30.html");
          toHtml = appendString(toHtml, head30);
          free(head30);*/
     
     /*toHtml = appendString(toHtml, fileRead("render/head30-topimage.html"), true);*/
     
     /*lxmenutest = fileRead("render/lxmenu_test.html");
          toHtml = appendString(toHtml, lxmenutest);
          free(lxmenutest);
     head40 = fileRead("render/head40.html");
          toHtml = appendString(toHtml, head40);
          free(head40);*/
     
     /*toHtml = appendString(toHtml, fileRead("render/head40-topimage.html"), true);*/

/* full test (main)*/
     /*toHtml = appendString(toHtml, htmlParagraph(terminateStringOnChar(epiSource, '\n', true, false), true), true);*/ /* takes first line */
     
     /*printf("%s", htmlHeader("Header ONE", 1, false));*/ /* htmlHeader must NOT free, as the string literal hasn't been malloc'ed!! */
     /*toHtml = appendString(toHtml, htmlHeader("Header ONE", 1, false), true);*/ /* htmlHeader must NOT free, as the string literal hasn't been malloc'ed!! */
     /*printf("%s", htmlHeader("Header TWO", 2, false));
     toHtml = appendString(toHtml, htmlHeader("Header TWO", 2, false), true);
     printf("%s", htmlHeader("Header THREE", 3, false));
     toHtml = appendString(toHtml, htmlHeader("Header THREE", 3, false), true);
     printf("%s", htmlHeader("Header FOUR", 4, false));
     toHtml = appendString(toHtml, htmlHeader("Header FOUR", 4, false), true);
     printf("%s", htmlHeader("Header FIVE", 5, false));
     toHtml = appendString(toHtml, htmlHeader("Header FIVE", 5, false), true);
     printf("%s", htmlHeader("Header SIX", 6, false));
     toHtml = appendString(toHtml, htmlHeader("Header SIX", 6, false), true);

     printf("%s", htmlParagraph("plain paragraph", false));
     toHtml = appendString(toHtml, htmlParagraph("plain paragraph", false), true);
     
     printf("%s", htmlParagraph(htmlBold("bold text", false), true));
     toHtml = appendString(toHtml, htmlParagraph(htmlBold("bold text", false), true), true);
     
     printf("%s", htmlParagraph(htmlItalic("italic text", false), true));
     toHtml = appendString(toHtml, htmlParagraph(htmlItalic("italic text", false), true), true);
     
     printf("%s", htmlParagraph(htmlItalic(htmlBold("italic and bold text", false), true), true));
     toHtml = appendString(toHtml, htmlParagraph(htmlItalic(htmlBold("italic and bold text", false), true), true), true);
     
     printf("%s", htmlParagraph("line break below", false));
     toHtml = appendString(toHtml, htmlParagraph("line break below", false), true);
     printf("%s", htmlBr());
     toHtml = appendString(toHtml, htmlBr(), true);
     
     printf("%s", htmlParagraph(htmlLinkLoc("localsample", "This is a local link", false), true));
     toHtml = appendString(toHtml, htmlParagraph(htmlLinkLoc("localsample", "This is a local link", false), true), true);
     
     printf("%s", htmlParagraph(htmlLinkExt("http://www.example.com", "This is an external link", false), true));
     toHtml = appendString(toHtml, htmlParagraph(htmlLinkExt("http://www.example.com", "This is an external link", false), true), true);
     
     printf("%s", htmlParagraph("horizontal rule below", false));
     toHtml = appendString(toHtml, htmlParagraph("horizontal rule below", false), true);
     printf("%s", htmlHr());
     toHtml = appendString(toHtml, htmlHr(), true);
     
     printf("%s", htmlParagraph(htmlCenter("centered text", false), true));
     toHtml = appendString(toHtml, htmlParagraph(htmlCenter("centered text", false), true), true);
     

     printf("list has %d elements\n", ARRAYELEMS(list));
     printf("%s", htmlList(list, false));
     toHtml = appendString(toHtml, htmlList(list, false), true);*/
/* test end */
     
     /*foot10 = fileRead("render/foot10.html");
          toHtml = appendString(toHtml, foot10);
          free(foot10);*/

     
     if(fileWrite("testhtml.html", toHtml)){
          printf("filewrite SUCCESS!!!\n");}
     else{
          printf("filewrite FAIL!!!\n");}
          
     /*free(epiSource);*/
     free(toHtml);
     
return 0;}
