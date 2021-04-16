static __inline__ char* fileRead_NOPE(char* file){
     FILE* fp;
     long fileSize;
     char* fileContents;

     fp = fopen ( file , "rb" );
     if(!fp){
          perror(file);
          exit(1);}

     /* this block writes the size of the file in fileSize */
     fseek( fp , 0L , SEEK_END);
     fileSize = ftell( fp );
     rewind( fp );

     /* allocate memory for entire content */
     fileContents = malloc(fileSize+1);
     if(!fileContents){
          fclose(fp);
          fputs("memory alloc fails",stderr);
          exit(1);}

     /* copy the file into the buffer */
     if(fread(fileContents, fileSize, 1, fp) != 1){
          fclose(fp);
          free(fileContents);
          fputs("entire read fails",stderr);
          exit(1);}
          
     /* close the file */
     fclose(fp);
     return fileContents;}
     
static __inline__ void fileReset(char* fileName){
     FILE* out = fopen(fileName, "w");
     fwrite("" , sizeof(char) , strlen("") , out );
     fclose(out);}
     
static __inline__ void fileAppend(char* fileName, char* string){
     FILE* out = fopen(fileName, "a"); /* using "a" to APPEND */
     if(fwrite(string , sizeof(char) , strlen(string) , out ) != strlen(string)){
               printf("==file write error\n");
               exit(EXIT_FAILURE);}
     fclose(out);}
     
static __inline__ void fileOverwrite(char* fileName, char* string){
     FILE* out = fopen(fileName, "w"); /* using "w" to WRITE (overwrites the current file, if it exists, creates a new one if it doesn't) */
     if(fwrite(string , sizeof(char) , strlen(string) , out ) != strlen(string)){
               printf("==file write error\n");
               exit(EXIT_FAILURE);}
     fclose(out);}
     
static __inline__ void fileAppendFile(char* source, char* dest){
     FILE* in = fopen(source, "r");
     char *line = NULL;
	size_t len = 0; /* needs to be just zero */
	size_t read;
     
     /* using getdelim with '\n' delimiter instead of getline */
     /*while ((read = getdelim(&line, &len, '\n', in)) != -1) {*/
     while ((read = getline(&line, &len, in)) != -1) {
          fileAppend(dest, line);}
          
    	free(line);
    	fclose(in);}