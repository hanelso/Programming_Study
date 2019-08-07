/**
 * @file	like.c
 * @brief	main source file.
 * @author	hanelso	
 * @date	2019.08.06
 *
 * likeU project source file
 */	
#include<stdio.h>

/**
 * @brief	getname function
 * @return	input name
 */
char* getname()
{
    char name[128];

    printf("Input name : ");
    scanf("%s", name);

    return name;
}

/**
 * @brief	main function
 * @return	0 = OK, 1 = error
 */
int main()
{
    char* str;

    str = getname();
    printf("I like you.\n");
    printf("%s\n", str);

    return 0;
}
