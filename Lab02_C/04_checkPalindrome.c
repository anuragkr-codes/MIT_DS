#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool checkPalindrome(char *str, int s, int e){
	//base case
	if(str[s] != str[e])
			return false;
	if(s >= e)
			return true;

	checkPalindrome(str, s+1, e-1);
}

int main(){
	char str[100];
	printf("Enter the string to check palindrome : ");
	gets(str);
	int lenght = strlen(str);

	bool isPalindrome = checkPalindrome(str, 0, lenght-1);
	if(isPalindrome)
		printf("Enter string is a Palindrome! \n");
	else
		printf("Enter string is NOT a Palindrome! \n");

return 0;
}