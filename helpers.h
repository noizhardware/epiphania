#ifndef _HELPERS_H_
#define _HELPERS_H_

#define HELPERS_VERSION "2021d19-1705"

/*** TODO
     - get rid of da fukkin malloc
     - nested lists might be nice
*/

/*** INCLUDES */
     #include"baostring.h" /* files - html */
     #include"baofiles.h"
/* INCLUDES end. */

#ifdef __cplusplus
     extern "C" {
#endif

/*** DEFINES */
     #define EPI_MAX_LINE_SIZE 256
     #define EPI_MAX_LINES_IN_FILE 256
     /*#define EPI_MAX_NESTED 8*/

     #define MAX_FILES 100 /* maximum number of file to be processed */

     #define COMMENT_GLYPH "--"
     #define TAG_GLYPH ",,"
     #define CONTENT_GLYPH "***"
     
     /**** EPIPHANIA ONLY */
          /*#define MAX_TAG_LENGTH 20*/
          #define EPI_MAX_FILENAME_LEN 32
          #define EPI_MAX_PARTNAME_LEN 16
          #define MAX_TAGS 20
          #define EPI_FILE_EXTENSION ".md"
     /**** EPIPHANIA ONLY end. */
     
/* DEFINES end. */

/*** TYPEDEFS */

/**** EPIPHANIA ONLY */
typedef enum{
  NOTYPE,
  NORMAL,
  INDEX,
  LEAF
} epiType;
/*typedef enum{
  NOTHEME,
  LIGHT,
  DARK,
  BLACK
} epiTheme;*/
typedef enum{
  NOSTATUS,
  ACTIVE,
  UPCOMING,
  UNLISTED,
  HIDE
} epiStatus;

typedef struct epiFile{
  char* name;
  char* title;
  char* parent;
  epiType type;
  char theme[EPI_MAX_PARTNAME_LEN];
  char* description;
  epiStatus status;
  char* image;
  char* tags[MAX_TAGS];
  /*char tags[MAX_TAGS][MAX_TAG_LENGTH];*/
} epiFile;
/**** EPIPHANIA ONLY end. */

/* TYPEDEFS end. */

/*** GLOBALS */
/* GLOBALS end. */

/*** FUNCTION DECLARATIONS */
     /****** EPIPHANIA ONLY *******/
          static __inline__ char** getArray(char* filename);
     /****** EPIPHANIA ONLY end. *******/
     
     /**** FILES */
     static __inline__ void fileReset(char* fileName);
     static __inline__ void fileOverwrite(char* fileName, char* string);
     static __inline__ void fileAppendString(char* fileName, char* string);
     static __inline__ void fileAppendChar(char* fileName, char c);
     static __inline__ void fileAppendFile(char* source, char* dest);
     static __inline__ char* fileToString(char* file);
     /**** FILES end. */
     
     /**** HTML */
     static __inline__ char* htmlHeader(char* headerText, unsigned char headerNum);
     static __inline__ char* htmlParagraph(char* paragraphText);
     static __inline__ char* htmlBold(char* boldText);
     static __inline__ char* htmlItalic(char* italicText);
     static __inline__ char* htmlCenter(char* centeredText);
     static __inline__ char* htmlBr();
     static __inline__ char* htmlHr();
     static __inline__ char* htmlLinkLoc(char* linkAddress, char* linkText);
     static __inline__ char* htmlLinkExt(char* linkAddress, char* linkText);
     static __inline__ char* htmlList(char** list, size_t size);
     /**** HTML end. */
     
/* FUNCTION DECLARATIONS end. */

/*** FUNCTION DEFINITIONS */

/**** EPIPHANIA ONLY */

static __inline__ void epiDoLine(char lineIn[EPI_MAX_LINE_SIZE], char fileOut[EPI_MAX_FILENAME_LEN]){/*kak*/
     uint8_t bold = 0;
     uint8_t italic = 0;
     uint8_t local = 0;
     uint8_t external = 0;
     uint8_t externalName = 0;
     static uint8_t list = 0;
     uint8_t listItem = 0;
     uint16_t c = 0;
     char linkBuf[EPI_MAX_LINE_SIZE];
     uint16_t linkBufIndex;
     
     fileAppendString(fileOut, "<p>");/* open paragraph */
     
     if(list && !startsWith(lineIn, "- ")){
          fileAppendString(fileOut, "</ul>\n");
          list=0;
     }
     
     if(startsWith(lineIn, "ct ")){/* open centered text */
          fileAppendString(fileOut, "<center>");
          local=1;
          c+=3;
     }
     
     while(lineIn[c]!='\0'){/* loop all chars in line */
          if(startsWith(lineIn+c, "**")){
               if(bold){/* bold was open */
                    fileAppendString(fileOut, "</b>");/* now, close it */
                    bold=0;
               }
               else{/* let's open bold */
                    fileAppendString(fileOut, "<b>");
                    bold=1;
               }
               c+=2;
          }
          else if(startsWith(lineIn+c, "_")){
               if(italic){/* italic was open */
                    fileAppendString(fileOut, "</i>");/* now, close it */
                    italic=0;
               }
               else{/* let's open italic */
                    fileAppendString(fileOut, "<i>");
                    italic=1;
               }
               c++;
          }
          else if(startsWith(lineIn+c, "[[")){
               /* let's open local address */
               fileAppendString(fileOut, "<a href=\"");
               local=1;
               c+=2;
          }
          else if(startsWith(lineIn+c, "]](") && local){
               /* let's close local address and open local text */
               fileAppendString(fileOut, ".html\" class=\"local\">");
               c+=3;
          }
          else if(startsWith(lineIn+c, ")") && local){
               /* let's close local text */
               fileAppendString(fileOut, "</a>");
               local=0;
               c++;
          }
          else if(!external && startsWith(lineIn+c, "www.")){
               /* open external link */
               fileAppendString(fileOut, "<a href=\"http://www.");
               sprintf(linkBuf, "http://www.");
               linkBufIndex=11;
               external=1;
               c+=4;
          }
          else if(!external && startsWith(lineIn+c, "https:")){
               /* open external link */
               fileAppendString(fileOut, "<a href=\"https:");
               sprintf(linkBuf, "https:");
               linkBufIndex=6;
               external=1;
               c+=6;
          }
          else if(!external && startsWith(lineIn+c, "http:")){
               /* open external link */
               fileAppendString(fileOut, "<a href=\"http:");
               sprintf(linkBuf, "http:");
               linkBufIndex=5;
               external=1;
               c+=5;
          }
          else if(external && startsWith(lineIn+c, "(")){
               /* external link name open */
               externalName=1;
               fileAppendString(fileOut, "\" target=\"_blank\" class=\"external\">");
               c++;
          }
          else if(external && externalName && startsWith(lineIn+c, ")")){
               /* external link name close, and close all external */
               fileAppendString(fileOut, "</a>");
               external=0;
               externalName=0;
               c++;
          }
          else if(external && !externalName && startsWith(lineIn+c, " ")){
               /* unnamed external link, let's close all */
               linkBuf[linkBufIndex]='\0';
               fileAppendString(fileOut, "\" target=\"_blank\" class=\"external\">");
               fileAppendString(fileOut, linkBuf);
               fileAppendString(fileOut, "</a>");
               external=0;
               externalName=0;
               c++;
          }
          else if(startsWith(lineIn+c, "- ")){
               /* let's open list if not open, and open listItem */
               if(!list){
                    fileAppendString(fileOut, "<ul>\n");
                    list=1;
               }
               fileAppendString(fileOut, "\t<li>");
               listItem=1;
               c+=2;
          }
          else{
               if(external){
                    linkBuf[linkBufIndex]=lineIn[c];
                    linkBufIndex++;
               }
               fileAppendChar(fileOut, lineIn[c]);
               c++;
          }
     }/* loop all chars in line */
     
     if(external && !externalName){/* I had a link at the end of the line, terminated by the '\0' */
          /* unnamed external link, let's close all */
          linkBuf[linkBufIndex]='\0';
          fileAppendString(fileOut, "\" target=\"_blank\" class=\"external\">");
          fileAppendString(fileOut, linkBuf);
          fileAppendString(fileOut, "</a>");
          external=0;
     }
     if(startsWith(lineIn, "ct ")){/* close centered text */
          fileAppendString(fileOut, "</center>");
     }
     if(listItem){/* the current line was a list item, let's close it */
          fileAppendString(fileOut, "</li>");
          listItem=0;
     }
     fileAppendString(fileOut, "</p>\n");/* close paragraph */
}



/* takes a filename and spits out an array of lines */
static __inline__ char** getArray(char* filename){
     char** out;
     char* fn;
     fn = calloc(1, 10);
     memcpy(fn, "database/", 9);
     fn=appendString(fn, filename);
     fn=appendString(fn, EPI_FILE_EXTENSION);
     out = fileToLines(fn, EPI_MAX_LINE_SIZE, EPI_MAX_LINES_IN_FILE);
     free(fn);
     return out;}
/**** EPIPHANIA ONLY end. */

/**** FILES */
/* empties the file */
static __inline__ void fileReset(char* fileName){
     FILE* out = fopen(fileName, "w");
     fwrite("" , sizeof(char) , strlen("") , out );
     fclose(out);}

static __inline__ void fileOverwrite(char* fileName, char* string){
     FILE* out = fopen(fileName, "w"); /* using "w" to WRITE (overwrites the current file, if it exists, creates a new one if it doesn't) */
     if(fwrite(string , sizeof(char) , strlen(string) , out ) != strlen(string)){
               printf("::== file write error\n");
               exit(EXIT_FAILURE);}
     fclose(out);}

static __inline__ void fileAppendString(char* fileName, char* string){
     FILE* out = fopen(fileName, "a"); /* using "a" to APPEND */
     if(fwrite(string , sizeof(char) , strlen(string) , out ) != strlen(string)){
               printf("::== file write error\n");
               exit(EXIT_FAILURE);}
     fclose(out);}
static __inline__ void fileAppendChar(char* fileName, char c){
     FILE* out = fopen(fileName, "a"); /* using "a" to APPEND */
     if(fputc(c, out) != c){
               printf("::== file write error\n");
               exit(EXIT_FAILURE);}
     fclose(out);}

static __inline__ void fileAppendFile(char* source, char* dest){
     FILE* in = fopen(source, "r");
     char *line = NULL;
	size_t len = 0; /* needs to be just zero */
	size_t read;

     /* using getdelim with '\n' delimiter instead of getline */
     /*while ((read = getdelim(&line, &len, '\n', in)) != -1) {*/
     while ((int)(read = getline(&line, &len, in)) != -1) {
          fileAppendString(dest, line);}

    	free(line);
    	fclose(in);}
/*
you need to free the var yourself after using it.
Usage:
char* myString;
myString = fileRead("filename.txt");
     use myString
.
.
free(myString);
*/
static __inline__ char* fileToString(char* fileName){
     FILE* fp = fopen ( fileName , "rb" );
     long fileSize;
     char* fileContents;
     /* check for file open error */
          if(!fp){
               perror(fileName);
               exit(EXIT_FAILURE);}
     /* write the size of the file in "fileSize" */
          fseek( fp , 0L , SEEK_END);
          fileSize = ftell( fp );
          rewind( fp );
     /* allocate memory for entire content */
          fileContents = malloc(fileSize+1);
          if(!fileContents){
               fclose(fp);
               fputs("memory alloc fails",stderr);
               exit(1);}
     /* copy the file into the buffer and handle errors */
          if(fread(fileContents, fileSize, 1, fp) != 1){
               fclose(fp);
               free(fileContents);
               fputs("entire read fails",stderr);
               exit(EXIT_FAILURE);}
     /* NULL-terminate the string. fileContents is not 0-terminated, and the malloc neither */
          fileContents[fileSize] = '\0';
     /* close the file and return*/
          fclose(fp);
          return fileContents;}
/**** FILES end. */

/**** HTML */
static __inline__ char* htmlHeader(char* headerText, unsigned char headerNum){ /* headernum must be [1..9] */
     char* output = malloc(3); /* length of <h + terminating 0 */
     strcpy(output, "<h");
     output = appendChar(output, digitToChar(headerNum));
     output = appendChar(output, '>');
     output = appendString(output, headerText);
     output = appendString(output, "</h");
     output = appendChar(output, digitToChar(headerNum));
     output = appendString(output, ">\n");
     return output;}

static __inline__ char* htmlParagraph(char* paragraphText){
     char* output = malloc(4); /* length of <p> + terminating 0 */
     strcpy(output, "<p>");
     output = appendString(output, paragraphText);
     output = appendString(output, "</p>\n");
     return output;}

static __inline__ char* htmlBold(char* boldText){
     char* output = malloc(4); /* length of <b> + terminating 0 */
     strcpy(output, "<b>");
     output = appendString(output, boldText);
     output = appendString(output, "</b>");
     return output;}

static __inline__ char* htmlItalic(char* italicText){
     char* output = malloc(4); /* length of <i> + terminating 0 */
     strcpy(output, "<i>");
     output = appendString(output, italicText);
     output = appendString(output, "</i>");
     return output;}

static __inline__ char* htmlCenter(char* centeredText){
     char* output = malloc(9); /* length of <center> + terminating 0 */
     strcpy(output, "<center>");
     output = appendString(output, centeredText);
     output = appendString(output, "</center>");
     return output;}

static __inline__ char* htmlBr(){ /* newline*/
     char* output = malloc(6); /* 1 terminator + 5 chars "<br>\n" */
     strcpy(output, "<br>\n");
     return output;}

static __inline__ char* htmlHr(){ /* horizontal ruler*/
     char* output; /* new internal char* */
     output = malloc(6); /* 1 terminator + 5 chars "<hr>\n" */
     strcpy(output, "<hr>\n");
     return output;}

static __inline__ char* htmlLinkLoc(char* linkAddress, char* linkText){
     char* output = malloc(10); /* length of <a href=" + terminating 0 */
     strcpy(output, "<a href=\"");
     output = appendString(output, linkAddress);
     output = appendString(output, ".html");
     output = appendString(output, "\" class=\"local\">");
     output = appendString(output, linkText);
     output = appendString(output, "</a>");
     return output;}

static __inline__ char* htmlLinkExt(char* linkAddress, char* linkText){
     char* output = malloc(10); /* length of <a href=" + terminating 0 */
     strcpy(output, "<a href=\"");
     output = appendString(output, linkAddress);
     output = appendString(output, "\" target=\"_blank\" class=\"external\">");
     output = appendString(output, linkText);
     output = appendString(output, "</a>");
     return output;}

static __inline__ char* htmlList(char** list, size_t size){
     char* output = malloc(6); /* length of <ul>\n + terminating 0 */
     unsigned int i;
     strcpy(output, "<ul>\n");

     for(i = 0; i < size; i++){
          output = appendString(output, "\t<li>");
          output = appendString(output, list[i]);
          output = appendString(output, "</li>\n");}

     output = appendString(output, "</ul>\n");

     return output;}
/**** HTML end. */

/* FUNCTION DEFINITIONS end. */

#ifdef __cplusplus
     }
#endif
#endif /* _HELPERS_H_ */
















