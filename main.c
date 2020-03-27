#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i;
    char input[501],mirror_input[501]={'\0'};

    //READ STRINGS UNTIL NO NEW STRING IS ENTERED
    while(gets(input)!=NULL){
        if(input[0]=='\0')
            return 0;



        //CREATE A MIRROR COPY OF ORIGINAL
        for(i=0;i<strlen(input);i++){
            input[i]=toupper(input[i]);
            mirror_input[i]=toupper(input[strlen(input)-1-i]);
        }

        printf("%s || %s\n",mirror_input, input);

        for(i=0;i<=strlen(input);i++)
        mirror_input[i]='\0';




    }
}
