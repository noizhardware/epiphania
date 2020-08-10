/* files */
static __inline__ void fileReset(char* fileName);
static __inline__ void fileOverwrite(char* fileName, char* string);
static __inline__ void fileAppendString(char* fileName, char* string);
static __inline__ void fileAppendFile(char* source, char* dest);
static __inline__ char* fileToString(char* file);

static __inline__ void fileReset(char* fileName){
     FILE* out = fopen(fileName, "w");
     fwrite("" , sizeof(char) , strlen("") , out );
     fclose(out);}

static __inline__ void fileOverwrite(char* fileName, char* string){
     FILE* out = fopen(fileName, "w"); /* using "w" to WRITE (overwrites the current file, if it exists, creates a new one if it doesn't) */
     if(fwrite(string , sizeof(char) , strlen(string) , out ) != strlen(string)){
               printf("==: file write error\n");
               exit(EXIT_FAILURE);}
     fclose(out);}

static __inline__ void fileAppendString(char* fileName, char* string){
     FILE* out = fopen(fileName, "a"); /* using "a" to APPEND */
     if(fwrite(string , sizeof(char) , strlen(string) , out ) != strlen(string)){
               printf("==: file write error\n");
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

/* files END */

/* HTML */
#include "baostring.h"
/*#include "baoutil.h"*/ /* for ARRAYELEMS */
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
/* HTML END */
