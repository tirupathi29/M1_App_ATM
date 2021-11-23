/**
 * @file feature.h
 * @author Saba Begum ()
 * @brief ATM function prototypes
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#ifndef FEATURE_H
#define FEATURE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
  node structure for implementing a queue to store transaction history
*/
typedef struct node {
    char statement[50];
    struct node* link;
} node;



/*
  ATM function prototypes
*/
void pinGeneration(void);
int checkPin(void);
void showBalance(int *);
void depositMoney(node **, int *);
void withdrawMoney(node **, int *);
void saveHistory(node **, char *);
void removeHistory(node **);
void showHistory(node **);



int main(void) {
    int choice1, choice2;
    int pinValid = 0, balance = 0;

    node *head = NULL;
  
  
  
#endif

/**
 * @brief end of function declaration
 * 
 */
