#include "ATM.h"


/*
  This function will search for the PIN entered by the user
  in the file where the PIN numbers are stored
  If PIN is found return 1
  Otherwise, return 0
*/
int checkPin(void) {
    FILE *fp;
    // buffer to read PIN and store from file
    char pin[8];
    // buffer to read PIN and store from user
    char keyPin[8];
    int pinValid = 0;

    printf("\n\nEnter the PIN: \n");
    scanf("%s", keyPin);

    fp = fopen("pin.txt", "r");
    if (NULL == fp) {
        printf("\nFile cannot be opened\n");
        exit(EXIT_FAILURE);
    }

    /*
      Search for the PIN entered by user in file pin.txt
    */
    while (fgets(pin, sizeof(pin), fp) != NULL) {
        if (strstr(pin, keyPin)) {
            pinValid = 1;
        }
    }
    fclose(fp);

    return pinValid;
}

/*
  This function will generate a 4-digit random number that
  is considered as PIN
*/
void pinGeneration(void) {
    FILE *fp;

    /*
	  Generate a random 4 digit number
	*/
    srand(time(NULL));
    int generatedPin = 1000+rand()%9000;

    printf("\nPIN generated successfully\n");
    printf("\nYour generated PIN: %d\n", generatedPin);
    printf("\nRe-run the program and use ATM with this PIN\n\n");

    fp = fopen("pin.txt", "a");
    if (NULL == fp) {
        printf("\nCannot open file!");
        exit(EXIT_FAILURE);
    }

    /*
      Write PIN to the file
    */
    fprintf(fp, "%d\n", generatedPin);
    fclose(fp);
}

/*
  This function will display the current balance amount
*/
void showBalance(int *balance) {
    printf("\nYour current balance is Rs.%d\n", *balance);
}

/*
  This function will add the money deposited to the balance
*/
void depositMoney(node **head, int *balance) {
    int depositAmount;
    /*
      buffer to store
    */
    char depositStmt[50];

    printf("\nEnter amount to deposit: ");
    scanf("%d", &depositAmount);

    if (depositAmount > 0) {
        *balance += depositAmount;
        printf("\nRs.%d deposited\n", depositAmount);

		/*
		  saving formatted string in depositStmt character array
		*/
        snprintf(depositStmt, sizeof(depositStmt), "Rs.%d deposited\n", depositAmount);
        saveHistory(head, depositStmt);
    } else {
        printf("\nInvalid amount entered\n.");
    }
}

/*
  This function will deduct the money withdrawn from the balance
*/
void withdrawMoney(node **head, int *balance) {
    int withdrawAmount;
    char withdrawStmt[50];

    printf("\nEnter amount to withdraw: ");
    scanf("%d", &withdrawAmount);

    if (withdrawAmount > 0) {
        if (withdrawAmount > *balance) {
            printf("\nCannot withdraw. Balance Rs.%d\n", *balance);
        } else {
            *balance -= withdrawAmount;
            printf("\nRs.%d withdrawn\n", withdrawAmount);

            /*
			  saving formatted string in withdrawStmt character array
			*/
            snprintf(withdrawStmt, sizeof(withdrawStmt), "Rs.%d withdrawn\n", withdrawAmount);
            saveHistory(head, withdrawStmt);
        }
    } else {
        printf("\nInvalid amount entered\n.");
    }
}

/*
  This function will save a transaction statement
*/
void saveHistory(node **head, char *str) {
    static int count = 0;
    node *temp;
    temp = (node *)malloc(sizeof(node));

    strcpy(temp->statement, str);
    temp->link = NULL;

    if (NULL == *head) {
        *head = temp;
        count++;
    } else {
        if (10 == count) {
            removeHistory(head);
            count--;
        }
        node *p;
        p = *head;
        while (NULL != p->link) {
            p = p->link;
        }
        p->link = temp;
        count++;
    }
}

/*
  This function is used to remove the oldest transaction when
  10 transactions are made
*/
void removeHistory(node **head) {
    node *temp;
    temp = *head;
    *head = (*head)->link;
    temp->link = NULL;
    free(temp);
}

/*
  This function will display the transaction history
*/
void showHistory(node **head) {
    node *temp;
    temp = *head;

    if (NULL == temp) {
        printf("\nNo transaction history...\n");
    } else {
        printf("\nTransaction History\n-------------------\n\n");
        while (NULL != temp) {
            printf("%s\n", temp->statement);
            temp = temp->link;
        }
    }
}

