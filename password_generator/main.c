#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(){
    int length;
    do {
        printf("Enter the length of your password : ");
        scanf("%d", &length);

        if (length <= 7) {
            printf("The length must be more than 7\n");
        }
    } while (length <= 7);

    char *password = malloc(length + 1);

    char *digits = "0123456789";
    int digit_length = strlen(digits);

    char *lowers = "abcdefghijklmnopqrstuvwxyz";
    int lower_length = strlen(lowers);

    char *upper = "ABCDEFGHIJKLMNOPKRSTUVWXYZ";
    int upper_length = strlen(upper);

    char *symbols = "!@#$%^&*()_-:;'?/,.";
    int symbols_length = strlen(symbols);


    srand(time(NULL) * getpid());

    for(int i = 0; i < length; i++){
        int char_type = rand() % 4 ;

        if(char_type == 0){
            password[i] = digits[rand() % digit_length];
        }else if(char_type == 1){
            password[i] = lowers[rand() % lower_length];
        }else if(char_type == 2){
            password[i] = upper[rand() % upper_length];
        }else{
            password[i] = symbols[rand() % symbols_length];
        }

        password[length] = '\0';
    }

    printf("Password : %s\n", password);

    free(password);
    //char password [length + 1]; --> This can be used instead of the malloc;

}
