#include <stdio.h>
#include <stdlib.h>

char cesar(char ch, int shift){
  if (ch >= 'a' && ch <= 'z'){
    ch = 'a' + (ch - 'a' + shift) % 26;
  }
  else if(ch >= 'A' && ch <= 'Z'){
    ch = 'A' + (ch - 'A' + shift) % 26;
  }
  return ch;
}

int main(int argc, const char * argv[]){

  if(argc < 3){
    printf("Usage: ./main path shift/n");
    return 1;
  }

 const char * path = argv[1];
 const int shift = atoi(argv[2]);

 FILE * file_input = fopen(path, "r");

 if(file_input == NULL){
   	perror("Error opening file");
 	return 1;
 }

 FILE * file_output = fopen("output.txt","w");

 if(file_output == NULL){
   perror("Error opening file");
   return 1;
 }

 char buffer;
 while((buffer = fgetc(file_input)) != EOF){
   printf("%c", buffer);
 }

 rewind(file_input);

 while((buffer = getc(file_input)) != EOF){
  char decoded = cesar(buffer, shift);
  printf("%c", decoded);
  putc(decoded, file_output);
 }

 fclose(file_input);
 fclose(file_output);

  return 0;
}
