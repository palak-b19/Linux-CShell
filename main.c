#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

int count_words(const char *file_given)
{
    // file_given = string file_name
    FILE *fptr = fopen(file_given, "r");

    if (fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    int word_count = 0;

    char word[100];
    // doesn't consider the new line charcter
    while (fscanf(fptr, "%s", word) == 1)
    {
        // printf("%s\n", word);
        word_count++;
    }

    fclose(fptr);
    return word_count;
}

int count_words_including_NewLineCharacter(const char *file_given)
{
    FILE *fptr = fopen(file_given, "r");

    if (fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    int word_count = 0;
    bool is_word = false;

    int ch;
    int prev_char = -1;
    // doesn't consider the new line charcter
    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch == ' ' || ch == '\t')
        {
            is_word = false;
        }
        else if (ch == '\n')
        {
            // Check if the last character was a space
            if (prev_char == ' ')
            {
                word_count++; // Count newline characters as words if preceded by a space
            }
            is_word = false;
        }
        else if (!is_word)
        {
            is_word = true;
            word_count++;
        }

        prev_char = ch;
    }

    fclose(fptr);
    return word_count;
}

int main()
{
    char input[100];
    while (1)
    {
        char buffer[1024];
        getcwd(buffer, 1024);
        printf("%s:~/ ", buffer);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';
        char *token = strtok(input, " ");

        if (token == NULL)
        {
            printf("Invalid command.\n");
            continue;
        }

        if (strcmp(token, "exit") == 0)
        {
            printf("Exiting Custom Shell.\n");
            break;
        }

        if (strcmp(token, "word") == 0)
        {
            token = strtok(NULL, " ");

            if (token == NULL)
            {
                printf("Missing filename.\n");
                continue;
            }

            if (strcmp(token, "-n") == 0)
            {
                token = strtok(NULL, " ");

                if (token == NULL)
                {
                    printf("Missing filename.\n");
                    continue;
                }

                int word_count = count_words(token);
                printf("Word count (excluding new line characters): %d\n", word_count);
            }
            else if (strcmp(token, "-d") == 0)
            {
                char *file1 = strtok(NULL, " ");
                char *file2 = strtok(NULL, " ");

                if (file1 == NULL || file2 == NULL)
                {
                    printf("Missing filenames.\n");
                    continue;
                }

                int word_count1 = count_words_including_NewLineCharacter(file1);
                int word_count2 = count_words_including_NewLineCharacter(file2);

                printf("Word count of file 1: %d\n", word_count1);
                printf("Word count of file 2: %d\n", word_count2);

                int diff = abs(word_count1 - word_count2);
                printf("Difference: %d\n", diff);
            }
            else
            {
                int word_count_includingNLC = count_words_including_NewLineCharacter(token);
                printf("Word count: %d\n", word_count_includingNLC);
            }
        }
        else if (strcmp(token, "dir") == 0)
        {
            int rc = fork();
            if (rc < 0)
            {
                fprintf(stderr, "fork failed\n");
                exit(1);
            }
            else if (rc == 0)
            {
                int arg_count = 1; // Start with 1 to include "dir" itself
                char *args[11];    // Adjust the size based on your needs

                args[0] = "dir"; // The first argument is "dir"

                // Start from the next token after "dir"
                token = strtok(NULL, " ");
                while (token != NULL && arg_count < 10)
                {
                    args[arg_count] = strdup(token);
                    if (args[arg_count] == NULL)
                    {
                        perror("strdup");
                        exit(1);
                    }

                    token = strtok(NULL, " ");
                    arg_count++; // Increment after storing the token
                }

                args[arg_count] = NULL; // Null-terminate the argument list

                // Print the arguments
                // printf("Arguments: ");
                // for (int i = 0; i < arg_count; i++)
                // {
                //     printf("%s ", args[i]);
                // }
                // printf("\n");

                execvp("/home/yashu/osAssignment1/Question2/dir", args);
                printf("execvp\n"); // Print an error message if execvp fails
                exit(1);
            }
            else
            {

                wait(NULL);
                int arg_count = 1; // Start with 1 to include "dir" itself
                char *args[11];    // Adjust the size based on your needs

                args[0] = "dir"; // The first argument is "dir"

                // Start from the next token after "dir"
                token = strtok(NULL, " ");
                while (token != NULL && arg_count < 10)
                {
                    args[arg_count] = strdup(token);
                    if (args[arg_count] == NULL)
                    {
                        perror("strdup");
                        exit(1);
                    }

                    token = strtok(NULL, " ");
                    arg_count++; // Increment after storing the token
                }

                args[arg_count] = NULL;
                if (strcmp(args[1], "-r") == 0)
                {
                    rmdir(args[2]);
                    chdir(args[2]);
                }
                else
                {
                    chdir(args[arg_count - 1]);
                }
            }
        }
        else if (strcmp(token, "date") == 0)
        {
            int rc = fork();
            if (rc < 0)
            {
                fprintf(stderr, "fork failed\n");
                exit(1);
            }
            else if (rc == 0)
            {
                int arg_count = 1; // Start with 1 to include "dir" itself
                char *args[11];    // Adjust the size based on your needs

                args[0] = "date"; // The first argument is "dir"

                // Start from the next token after "dir"
                token = strtok(NULL, " ");
                while (token != NULL && arg_count < 10)
                {
                    args[arg_count] = strdup(token);
                    if (args[arg_count] == NULL)
                    {
                        perror("strdup");
                        exit(1);
                    }

                    token = strtok(NULL, " ");
                    arg_count++; // Increment after storing the token
                }

                args[arg_count] = NULL; // Null-terminate the argument list

                // Print the arguments
                // printf("Arguments: ");
                // for (int i = 0; i < arg_count; i++)
                // {
                //     printf("%s ", args[i]);
                // }
                // printf("\n");
                // printf("ffff\n");
                execvp("/home/yashu/osAssignment1/Question2/date", args);
                perror("execvp"); // Print an error message if execvp fails
                exit(1);
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
