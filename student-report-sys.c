#include <stdio.h>
#include<string.h>

int main() {

    char exit = '\0';

    do {

        int tries = 0;
        int arr[3];
        int total = 0;
        float average = 0;
        char grade[50] = "";
        char *subs[3] = {"MATH", "PHYSICS", "CHEMISTRY"};
        char id[50] = "Abdullah";
        char pass[50] = "Abdullah1234";
        char id_input[50] = "\0";
        char pass_input[50] = "\0";

        do {

            printf("Student Report Card System.\n");

            printf("\nEnter your Id: ");
            fgets(id_input, sizeof(id_input), stdin);
            id_input[strcspn(id_input, "\n")] = '\0';

            printf("Enter your password: ");
            fgets(pass_input, sizeof(pass_input), stdin);
            pass_input[strcspn(pass_input, "\n")] = '\0';

            if (strcmp(id, id_input) != 0 || strcmp(pass, pass_input) != 0) {

                tries++;
            }

            if ((strcmp(id, id_input) != 0 || strcmp(pass, pass_input) != 0) && tries != 3) {

                printf("\nInvalid password or id, please try again.\n");
            }

            if (tries == 3) {

                printf("\nInvalid password or id.\n");
            }

        }while ((strcmp(id, id_input) != 0 || strcmp(pass, pass_input) != 0) && tries != 3);

        if (tries == 3) {

            printf("\nYour account has been locked for suspecious activities.\n");
            return 1;
        }

        else {

            printf("\nAccess Granted.\n");
        }

        printf("Welcome %s.\n", id);

        printf("\nEnter your marks for the following subjects.\n");

        for (int i = 0; i < 3; i++) {

            do {

                printf("\n%s: ", subs[i]);
                scanf("%d", &arr[i]);

                if (arr[i] < 0 || arr[i] > 100) {

                    printf("\nInvalid marks. Marks must be between (1-100)\n");
                }
            }while (arr[i] < 0 || arr[i] > 100);
            
        }

        for (int i = 0; i < 3; i++) {

            total += arr[i];
        }

        average = total / 3.0;

        if (average >= 80) {

            strcpy(grade, "A+");
        }

        else if (average >= 70) {

            strcpy(grade, "A");
        }

        else if (average >= 60) {

            strcpy(grade, "B");
        }

        else if (average >= 50) {

            strcpy(grade, "C");
        }

        else if (average >= 40) {

            strcpy(grade, "D");
        }

        else {

            strcpy(grade, "F");
        }

        printf("\n<RESULTS>\n");

        printf("\nTOTAL MARKS: %d\n", total);
        printf("AVERAGE MARKS: %.2f\n", average);
        printf("GRADE: %s\n", grade);

        printf("\nSUBJECTS PASS/FAILED.\n");

        if (arr[0] >= 33) {

            printf("\nMATH: PASSED.\n");
        }

        else {

            printf("\nMATH: FAILED.\n");
        }

        if (arr[1] >= 33) {

            printf("PHYSICS: PASSED.\n");
        }

        else {

            printf("PHYSICS: FAILED.\n");
        }

        if (arr[2] >= 33) {

            printf("CHEMISTRY: PASSED.\n");
        }

        else {

            printf("CHEMISTRY: FAILED.\n");
        }

        printf("\nDO YOU WANT TO CONTINUE OR EXIT (Y/N): ");
        scanf(" %c", &exit);
        getchar();

    } while (exit != 'N');

    return 0;

}