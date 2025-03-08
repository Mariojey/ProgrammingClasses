/*

Napisz program w języku C, który szyfruje tekst znajdujący się w pliku
wykorzystując szyfr Cezara. Program powinien być uruchamiany z linii poleceń
i przyjmować dwa argumenty: nazwę pliku wejściowego
oraz liczbę określającą wielkość przesunięcia w szyfrowaniu.
Po uruchomieniu program powinien otworzyć podany plik i wczytać jego zawartość.
Następnie powinien wyświetlić oryginalny tekst na ekranie.
Po wczytaniu tekstu program powinien zaszyfrować go szyfrem Cezara.
Wynik działania programu powinien zostać wyświetlony na ekranie w formacie:

Tekst: "<tekst z pliku>" po zaszyfrowaniu:
<tekst z pliku po zaszyfrowaniu>

Ostatecznie program powinien zapisać zaszyfrowany tekst do nowego pliku o nazwie:
zaszyfrowane.txt.

 */

#include <stdio.h>
#include <stdlib.h>

char cesar(char ch, int shift){
  if (ch >= 'a' && ch <= 'z'){
    ch = 'a' + (ch - 'a' + shift) % 26;
  }
  else if (ch >= 'A' && ch <= 'Z'){
    ch = 'A' + (ch - 'A' + shift) % 26;
  }
  return ch;
}

int main(int argc, char * argv[]){

  if(argc < 3){
    printf("Poprawne wywołanie programu to: ./cezar sciezka przesuniecie");
    return 1;
  }

  const char * file_input = argv[1];
  const int givenShift = atoi(argv[2]);

  FILE * file = fopen(file_input, "r");

  if(file == NULL){
    perror("Nie mozna otworzyc pliku");
    return 1;
  }

  FILE * destiny = fopen("zaszyfrowane.txt", "w");
  if(destiny == NULL){
    perror("Nie mozna otworzyc pliku");
    return 1;
  }

  char input_content;
  printf("Tekst: \"");
  while ((input_content = getc(file)) != EOF){
    printf("%c", input_content);
  }
  printf("\" po zaszyfrowaniu: ");

  rewind(file);

  while ((input_content = getc(file)) != EOF){
    char decoded = cesar(input_content, givenShift);
    printf("%c", decoded);
    putc(decoded, destiny);
  }

  fclose(file);
  fclose(destiny);

  return 0;
}