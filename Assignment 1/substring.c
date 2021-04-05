#include <stdio.h>
#include <stdlib.h>

int get_length(char* string){
    // Function to get the length of a string;
    // Traverses the char array until a \0 is found
    int size = 0;
    for (int i = 0; i < 499;i++){
        if (string[i] == '\0'){
            break;
        }
        size++;
    }
    return size;
}

int match(char main_string[500], char sub_string[500], int i, int sub_len){
    // function to match if a sub string of length sub_len starts at index i of main_string
    for (int counter = i; counter < i+sub_len; counter++){
        if (main_string[counter] != sub_string[counter-i]){
            return 0;
        }
    }
    return 1;
}

int main() {

    printf("Enter the main string: ");
    char main_string[500];
    scanf("%[^\n]s", &main_string);
    getchar();

    printf("Enter the sub string: ");
    char sub_string[500];
    scanf("%[^\n]s", &sub_string);

    int main_length = get_length(main_string);
    int sub_length = get_length(sub_string);


    if (sub_length > main_length){
        // Edge case handling
        printf("Error! sub-string cannot be longer than the main string!");
        return 0;
    } else{
        // traverses the main char array and checks if the current character matches
        // with the first character of the sub_string
        for (int i = 0; i < main_length-sub_length+1; i++){
            if (main_string[i] == sub_string[0]){
                if (match(main_string, sub_string,i, sub_length)) {
                    // checks if substring exists, starting at position i
                    printf("Starts at %d and ends at %d",i, i+sub_length-1);
                    break;
                }
            }
        }
    }

    return 0;
}
