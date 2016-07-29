# c Code example


```c
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[])
{
      FILE *inputdeck;
      int count;
      char args_error_flag = 0;

      if (argc > 1) {
            for (count = 1; count < argc; count+=2) {
                  if(!strcmp(argv[count],"-inp")) {
                        printf("-inp : %s \n", argv[count+1]);
                        inputdeck = fopen(argv[count+1]);
                  } else {
                        printf("Invalid command option: %s\n", argv[count] );
                        args_error_flag = 1;
                  };
            }
            if(args_error_flag == 1) {
                  printf("Check your comand option\n");
                  exit(1);
            }
      } else {
            printf("Invalid arguments number.\n");
      }


      fclose(inputdeck);
      return 0;
}
```


