#include<stdio.h>

void copyString(char *str, char *str2){
	//base case
	if(*str == '\0')
			return;

	*str2 = *str;
	copyString(str+1, str2+1);
}

int main(){
	char str[100];
	printf("Enter the string : ");
	gets(str);

	char str2[100];
	copyString(str, str2);

	//output
	printf("The string is successfully copied into str2. \n");
	printf("str : ");
	puts(str);
	printf("str2 : ");
	puts(str2);                                                                                                                                                                          

return 0;
}