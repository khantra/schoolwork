#include <stdio.h>

int main()
{
	char  input[4];
	int inputCorrect=0;
	//float  result=0;
	printf("Enter '1' if you are Converting from Inches to Centimeters or \n '0' if  if you are Converting from Centimeters to Inches: \n");
	gets(input);

	while (inputCorrect == 0) {
		if (atoi(input) != 1 && atoi(input) != 0) {
			printf("Enter '1' if you are Converting from Inches to Centimeters or \n '0' if  if you are Converting from Centimeterss to Inche: \n");
			gets(input);
		}
		else {
			inputCorrect = 1;
		}
	}
	
	if (atoi(input)==1) {
		printf("Enter the Number of inches: ");
		gets(input);

		printf("\n You entered inches %i \n", atoi(input));
		//puts(input);
		//result = atoi(input) *2.54;
		printf("which is %.2f centimeters", atoi(input) *2.54);
	}
	else if(atoi(input) ==0){
		printf("Enter the Number of centimeters: ");
		gets(input);

		printf("\n You entered centimeters %i \n", atoi(input));
		//puts(input);
		//result = atoi(input) /2.54;
		printf("which is %.2f Inches", atoi(input) / 2.54);
	}
	
	return(0);

}