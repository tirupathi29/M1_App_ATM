#include "../unity/unity.h"
#include "../inc/ATM.h" /* Name of the header file of your project */

/* These two lines are need to be set according to project name */
#include "../inc/ATM.h"

#define PROJECT_NAME    "ATM"


/*
  ATM function prototypes
*/
void test_pinGeneration(void);
void test_checkPin(void);
void test_showBalance(int *);
void test_depositMoney(node **, int *);
void test_withdrawMoney(node **, int *);
void test_saveHistory(node **, char *);
void test_removeHistory(node **);
void test_showHistory(node **);

/* Start of the application test */

// Write the code for testing.


int main()
{
    /* Initiate the Unity Test Framework (Initiation) */

    UNITY_BEGIN();

    /*Now Run the Test function*/
    /* Means write the fucntion name for testing */


  RUN_TEST(test_pinGeneration);
  RUN_TEST(test_checkPin);
  RUN_TEST(test_showBalance);
  RUN_TEST(test_depositMoney);
  RUN_TEST(test_withdrawMoney);
  RUN_TEST(test_saveHistory);
  RUN_TEST(test_removeHistory);
  RUN_TEST(test_showHistory);

 /* Close the Unity Test Framework */
  return UNITY_END();

}

/* Write all the test functions. */
/* Here we have to write all the test cases means values for the program input that program is taking proper input and giving the desired result or not! */

void test_pinGeneration(void);{
    TEST_ASSERT_EQUAL();
}
void test_checkPin(void); {
    TEST_ASSERT_EQUAL();
}


void test_showBalance(int *); {
    TEST_ASSERT_EQUAL();
}

void test_(test_depositMoney);
 {
    TEST_ASSERT_EQUAL();
}

void test_withdrawMoney(node **, int *); {
    TEST_ASSERT_EQUAL();
}

void test_saveHistory(node **, char *);
 {
    TEST_ASSERT_EQUAL();
}

void test_removeHistory(node **); {
    TEST_ASSERT_EQUAL();
}

void test_showHistory(node **); {
    TEST_ASSERT_EQUAL();
}
