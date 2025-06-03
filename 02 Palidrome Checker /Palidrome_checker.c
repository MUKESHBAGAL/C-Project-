#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        // Compare characters (case insensitive)
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    char input[100];

    do {
        int choice;
        printf("1. Check Palindrome\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the leftover newline character

        switch (choice) {
            case 1: {
                printf("Enter a Input : ");
                fgets(input, sizeof(input), stdin);

                // Remove the newline character from fgets
                input[strcspn(input, "\n")] = '\0';

                // Check if the input is a palindrome
                if (isPalindrome(input)) {
                    printf("\"%s\" is a palindrome.\n\n", input);
                } else {
                    printf("\"%s\" is not a palindrome.\n\n", input);
                }
                break;
            }
            case 2:
                printf("Thank you for visiting! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

