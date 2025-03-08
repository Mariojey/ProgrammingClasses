/*

Napisz program w języku C, który implementuje szyfrowanie XOR dla plików. Szyfrowanie to polega na zastosowaniu operacji logicznej XOR na każdym najcie danych przy użyciu podanego klucza
Proces deszyfrowania odbywa się w ten sam sposób - ponowne wykonanie operacji XOR na zaszyfrowanych danych z tym samym kluczem przywraca oryginalną treść pliku.

Program powinien być uruchamiany z trzema argumentami podanymi w linii poleceń.
Pierwszy argument określa nazwę pliku wejściowego, drugi argument to nazwa pliku wyjściowego, natomiast trzeci argument to pojedynczy znak ASCII pełniący rolę klucza szyfrowania.

W programie należy zadbać o poprawną obsługę błędów, takich jak brak dostępu do pliku lub jego nieistnienie.

Dane odczytywane / zapisywane do plików i  wszelkie inne komunikaty, powinny być wyświetlone na konsoli.



 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  if(argc < 4){
    printf("Niepoprawne wywołanie");
    return 1;
  }

  FILE * file = fopen(argv[1],"r");
  FILE * destiny = fopen(argv[2],"w");

  if(file == NULL){
    printf("Plik nie istnieje");
    return 1;
  }

  printf("Szyfrowanie / deszyfrowanie plik: ");
  printf("%s", argv[1]);
  printf(" -> ");
  printf("%s", argv[2]);
  printf("z kluczem '%s'", argv[3]);

  char input_content;

  while((input_content = fgetc(file)) != EOF){
    printf("%c",input_content);
    printf(" -> ");
    char encoded = input_content ^ argv[3][0];
    printf("%c",encoded);
    putc(encoded, destiny);
  }

  fclose(file);
  fclose(destiny);
  return 0;

}