#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char **palindrome_add(char **palindrome, char input_word[], int *palindrome_count){
    int i;

    palindrome = realloc(palindrome, (*(palindrome_count)+1) * sizeof(char*) );
    palindrome[*palindrome_count] = malloc((strlen(input_word)+1)*sizeof(char));

    for(i=0; i<=strlen(input_word); i++)
        palindrome[*palindrome_count][i] = input_word[i];

    (*palindrome_count)++;

    return palindrome;
}
int main()
{
    int i,j,len_input,k,l,radius,palindrome_count=0;
    char input[501],slovo[501]={'\0'},**palindrome = NULL;

    //READ STRINGS UNTIL NO NEW STRING IS ENTERED
    while(gets(input)!=NULL){
        if(input[0]=='\0')
            return 0;



        //CREATE A MIRROR COPY OF ORIGINAL
        len_input=strlen(input);

        radius=0;
        for(i=1;i<len_input;i++){
            while(toupper(input[i-radius-1])==toupper(input[i+radius])){
                for(j=i-radius-1;j<=i+radius&&(i-radius>0&&i+radius<len_input);j++){
                    printf("%c",input[j]);
                }
                radius++;
                putchar('\n');
            }
            radius=1;
        }

        //ODD
        radius=1;
        for(i=1;i<len_input;i++){
            while(toupper(input[i-radius])==toupper(input[i+radius])){
                for(j=i-radius;j<=i+radius&&(i-radius>=0&&i+radius<=len_input);j++){
                    printf("%c",input[j]);
                }
                putchar('\n');
                radius++;

            }
            radius=1;

        }

        putchar('\n');
        //printf("%s || %s\n",mirror_input, input);





    }
}
