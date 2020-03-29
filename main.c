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

void *find_odd(int len_input, char input[], int *longest, char **palindrome, int *palindrome_count){
    int radius,i,j,counter;
    char slovo[501]={'\0'};

    radius=1;
    for(i=1;i<len_input;i++){
        while(toupper(input[i-radius])==toupper(input[i+radius])){
            counter=0;
            for(j=i-radius;j<=i+radius&&(i-radius>=0&&i+radius<=len_input);j++){
                slovo[counter++]=input[j];
            }
            if(counter>*longest){
                *longest=counter;
            }
            slovo[counter]='\0';
            if(strlen(slovo)>2)
                palindrome = palindrome_add(palindrome, slovo, palindrome_count);

            radius++;
        }
        radius=1;
    }
    return palindrome;
}
void *find_even(int len_input, char input[], int *longest, char **palindrome, int *palindrome_count){
    int i,j,counter,radius=0;
    char slovo[501]={'\0'};

        for(i=1;i<len_input;i++){
            while(toupper(input[i-radius-1])==toupper(input[i+radius])){
                counter=0;
                for(j=i-radius-1;j<=i+radius&&(i-radius>0&&i+radius<len_input);j++){
                    slovo[counter++]=input[j];
                }
                if(counter>*longest){
                    *longest=counter;
                }
                slovo[counter]='\0';
                if(strlen(slovo)>2)
                    palindrome = palindrome_add(palindrome, slovo, palindrome_count);

                radius++;
            }
            radius=0;

        }
    return palindrome;
}

void reset(int *palindrome_count,char **palindrome, int *longest){
    int i;
    for(i=0;i<*palindrome_count;i++)
            free(palindrome[i]);
        *longest=0;
        *palindrome_count=0;
}

void print_longest(int *longest, int *palindrome_count, char **palindrome){
    int i;
    if(*longest){
        printf("%d: ",*longest);
    }
    else{
        printf("No palindromes in this sentence.");
    }
    for(i=0;i<*palindrome_count;i++){
        if(strlen(palindrome[i])==*longest)
            printf("%s ",palindrome[i]);
    }
    printf("\n\n");
}

int main()
{
    int len_input, palindrome_count=0, longest=0;
    char input[501], **palindrome = NULL;

    //READ STRINGS UNTIL NO NEW STRING IS ENTERED
    while(gets(input)!=NULL){
        if(input[0]=='\0')
            return 0;

        len_input=strlen(input);

        palindrome = find_even(len_input, input, &longest, palindrome, &palindrome_count);
        palindrome = find_odd(len_input, input, &longest, palindrome, &palindrome_count);

        print_longest(&longest,&palindrome_count,palindrome);
        reset(&palindrome_count,palindrome,&longest);
    }
    reset(&palindrome_count,palindrome,&longest);
}
