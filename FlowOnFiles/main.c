#include <stdio.h>

int main(){

  FILE * file;

  file = fopen("my_file.txt", "w");

  if(file == NULL){
    printf("File not found\n");
    return 1;
  }

  //If you want write data to file you ought to use fprintf or fputs (for strings) or fputc (for chars)
  char buffer_hw[12] = "Hello World";
  fprintf(file, "%s", buffer_hw);

  char buffer_hf[12] = "Hello Filee";
  fputs(buffer_hf, file);
  fputc('\n', file);
//
//  feof(plik) – sprawdza, czy osiągnięto koniec pliku
//
//ferror(plik) – sprawdza, czy wystąpił błąd
//
//rewind(plik) – cofa wskaźnik pliku na początek
//
//fseek(plik, offset, origin) – przesuwa wskaźnik pliku
//
//ftell(plik) – zwraca bieżącą pozycję wskaźnika

  return 0;
}
