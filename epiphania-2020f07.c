#include <stdio.h>
#include "baofiles.h"
#include "baostring.h"
#include "html.h"

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
     char* list[] = {
          "list item one",
          "list item two",
          "list item three",};
     char* theme;
     char* pagetitle;
     /*char* lxmenu = "";*/
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
           
     toHtml = appendString(toHtml, fileRead("render/head10.html"), true); /* must be false, as "toHtml" hasn't been malloc'ed yet */
     toHtml = appendString(toHtml, theme, false); /* now it SHOULD BE OK to free it as it's been malloc'ed by the previous appendString */
     toHtml = appendString(toHtml, fileRead("render/head20.html"), true); /* THIS ONE ERRORS OUT ON WIN10 if the file contains more than 9 characters */
     toHtml = appendString(toHtml, pagetitle, true);
     toHtml = appendString(toHtml, fileRead("render/head30.html"), true);
     
     /*toHtml = appendString(toHtml, fileRead("render/head30-topimage.html"), true);*/
     
     toHtml = appendString(toHtml, fileRead("render/lxmenu_test.html"), true); /* lxmenu test */
     toHtml = appendString(toHtml, fileRead("render/head40.html"), true);
     
     /*toHtml = appendString(toHtml, fileRead("render/head40-topimage.html"), true);*/

/* full test (main)*/
     /*toHtml = appendString(toHtml, htmlParagraph(terminateStringOnChar(epiSource, '\n', true, false), true), true);*/ /* takes first line */
     
     printf("%s", htmlHeader("Header ONE", 1, false)); /* htmlHeader must NOT free, as the string literal hasn't been malloc'ed!! */
     toHtml = appendString(toHtml, htmlHeader("Header ONE", 1, false), true); /* htmlHeader must NOT free, as the string literal hasn't been malloc'ed!! */
     printf("%s", htmlHeader("Header TWO", 2, false));
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
     toHtml = appendString(toHtml, htmlList(list, false), true);
/* test end */
     
     toHtml = appendString(toHtml, fileRead("render/foot10.html"), true);

     
     if(fileWrite("testhtml.html", toHtml)){
          printf("filewrite SUCCESS!!!\n");}
     else{
          printf("filewrite FAIL!!!\n");}
          
     /*free(epiSource);*/
     free(toHtml);
     
return 0;}
