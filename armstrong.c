#include<stdio.h>
#include<math.h>
 
/*
* count number of digits of given number 'num'
*/
int countDigits(int num)
{
    int digitCnt = 0;
    // Number is positive
    // take backup of 'num', we can also directly use 'num'
    int temp = num;
    // Iterate over each digit using division operator.
    while(temp > 0) {
        // increment the number of digits count (digitCnt)
        digitCnt++;
        // remove the last element using division operator.
        temp = temp / 10;
    }
 
    return digitCnt;
}
 
int main()
{
    int n,temp,rem,arm;
    arm = 0;
    printf("Enter a positive number : ");
    scanf("%d",&n);
 
    // check if the 'n' is negative. Display the error message.
    if(n <= 0)
    {
        printf("Error: Please enter positive number\n");
        return 0;
    }
 
    // Take backup of number 'n'
    temp = n;
 
    // count number of digits in Number
    // Use - https://sillycodes.com/program-to-count-number-of-digits-in-c/
    int nDigits = countDigits(n);
 
    // Go through the each digit and calculate the power(digit, nDigit)
    // add the powers to 'arm' variable. which will be holding sum of all powers
    while(temp>0)
    {
        // get the last digit of number or current digit using modulus
        rem = temp %10;
 
        // calculate the power of 'rem' with 'nDigits'
        // Use - https://sillycodes.com/program-to-find-power-of-number-in-c/
        arm = arm + pow(rem, nDigits);
        
        // Remove the last digit by dividing the 'temp' by '10'
        temp = temp/10;
    }
    // After all iterations, The 'arm' variable contains the sum of power of each digit.
    // if 'arm' is equal to the input number 'n', Then the 'n' is Armstrong number.
    if(arm == n)
        printf("Number %d is an Armstrong Number \n", n);
    else
        printf("Number %d Not an Armstrong Number\n", n);
    return 0;
}