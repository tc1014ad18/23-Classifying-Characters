#include <stdio.h>
#include <memory.h>
#include <ctype.h>

int main() {
    char string[1000];
    int numbers = 0;
    int punctuations = 0;
    int vowels = 0;
    int consonants = 0;
    int spaces = 0;
    int special = 0;

    printf("Hullo, mate-y!\nGive me a sentence and I'll tell you how many characters are in there,\n");
    printf("classified by their type.\n");
    printf("Your string (it should not pass of 1000 chars): ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < strlen(string); i++) {
        if (isspace(string[i])) {
            spaces++;
        } else {
            if (ispunct(string[i])) {
                punctuations++;
            } else {
                if (isdigit(string[i])) {
                    numbers++;
                } else {
                    if (isalpha(string[i])) {
                        switch((char)toupper(string[i])) {
                            case 'A':
                            case 'E':
                            case 'I':
                            case 'O':
                            case 'U':
                                vowels++;
                                break;
                            default:
                                consonants++;
                        }
                    } else {
                        special++;
                    }
                }
            }
        }
    }

    printf("Your sentence has:\n");
    printf(" * %d vowels\n", vowels);
    printf(" * %d consonants\n", consonants);
    printf(" * %d numbers\n", numbers);
    printf(" * %d punctuation characters\n", punctuations);
    printf(" * %d spaces\n", spaces);
    printf(" * %d special characters\n", special);

    printf("\nSee you around, mate!\n");

    return 0;
}