/*
*******************************************************************************************************
                                        Task_4_description
*******************************************************************************************************
Consider the following C program and answer the following questions:
1. Describe what the compute_array() function in the code does?
2. Is the program memory safe? If not, how could the program be made memory safe while retaining its
original functionality?
*******************************************************************************************************
*/

/*
Description of the compute_array() function:

The compute_array() function takes a combined string as input, which consists of three parts: string_1, separator, and string_2.
It computes an array of integers where each element represents the length of the longest prefix of string_2 that matches a suffix of the substring starting at the corresponding index in string_combined.
The function iterates over the characters of string_combined, starting from index 1.
For each index i, it initializes array_1[i] to 0 and then incrementally checks if the substring starting at index i in string_combined matches its corresponding prefix. It does this by comparing characters between string_combined[array_1[i]] and string_combined[i + array_1[i]]. It increments array_1[i] as long as the characters match and the index is within bounds.
Finally, it returns the computed array array_1.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_array(char* string_combined) 
{
    int n = strlen(string_combined);
    int* array_1 = (int*)malloc(sizeof(int)*n);
    array_1[0] = 0;
    for (int i = 1; i < n; i++) 
    {
        array_1[i] = 0;
       
        while(((i + array_1[i]) < n) && (string_combined[array_1[i]] == string_combined[i + array_1[i]])) 
        {
            (array_1[i])++;
        }
    }
    return array_1;
}


int main()
{
    char* string_1 = "abc";
    char* separator = "$";
    char* string_2 = "abcacbabcabddbabcaxabc";
   
    char string_combined[200];
    strcpy(string_combined, string_1);
    strcat(string_combined, separator);
    strcat(string_combined, string_2);
    int* array_1 = compute_array(string_combined);
    int n = strlen(string_combined);
    int m = strlen(string_1);
   
    for (int i = 0; i < n; i++) 
    {
        if (array_1[i] == m) 
        {
            printf("%d ", i - m - 1);
        }
    }
    free(array_1);
    return 0;
}