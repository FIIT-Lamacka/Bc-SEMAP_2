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
    int i,j,len_input,k,l,radius,palindrome_count=0,counter=0,longest=0;
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
                counter=0;
                for(j=i-radius-1;j<=i+radius&&(i-radius>0&&i+radius<len_input);j++){
                    slovo[counter++]=input[j];
                }
                if(counter>longest){
                    longest=counter;
                }
                slovo[counter]='\0';
                if(strlen(slovo)>2)
                    palindrome = palindrome_add(palindrome, slovo, &palindrome_count);

                radius++;
            }
            radius=0;

        }

        //ODD
        radius=1;
        for(i=1;i<len_input;i++){
            while(toupper(input[i-radius])==toupper(input[i+radius])){
                counter=0;
                for(j=i-radius;j<=i+radius&&(i-radius>=0&&i+radius<=len_input);j++){
                    slovo[counter++]=input[j];
                    //printf("%c",input[j]);
                }
                if(counter>longest){
                    longest=counter;
                }
                slovo[counter]='\0';
                if(strlen(slovo)>2)
                    palindrome = palindrome_add(palindrome, slovo, &palindrome_count);

                radius++;

            }
            radius=1;

        }
        if(longest){
            printf("%d: ",longest);
        }
        else{
            printf("No palindromes in this sentence.");
        }
        for(i=0;i<palindrome_count;i++){
            if(strlen(palindrome[i])==longest)
                printf("%s ",palindrome[i]);
        }
        printf("\n\n");


        for(i=0;i<palindrome_count;i++)
            free(palindrome[i]);
        longest=0;
        palindrome_count=0;







    }
    for(i=0;i<palindrome_count;i++){
            free(palindrome[i]);
        }
}
