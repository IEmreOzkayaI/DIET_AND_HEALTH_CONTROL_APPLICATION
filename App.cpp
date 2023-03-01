// Program  calculates the daily calories, macros
// (protein, carbohydrate, fat) and values that a person 
// needs to maintain their weight, as well as the current
// lean body mass and fat percentage of the person.

// The main purpose of this program is to observe one's 
// own body and lead a healthy life.

// You can see whether you need to gain or lose weight
// by checking your fat rate from the table.
#include <stdio.h >                                     	// Name & Surname : Emre Özkaya
#include <stdlib.h >                                    	// Number : B1905.010057
#include <math.h >                                      	// Section : 1
#include <string.h>

//Receiving and saving information from the user
struct information
{
	int gender;
	float age;
	float height;
	float weight;
	float neck;
	float waist;
	float hip;
};

struct information inf = { 0 };
struct information *keeper = &inf;

float age, height, weight, neck, waist, hip, calorie;
int activity, selection;

char answer = 'y';
char slctn[4];
char yes[] = "yes";
char yes2[] = "YES";
char no[] = "no";
char no2[] = "NO";

void menu();
void reset();
int  gender();
void bodyFatTable();
void errorMessage();
void finalMessage();
int  activityLevel();
void calorieForMacro();
void bodyFatCalculator();
void programRequirements();
void macroCalculatorMenu();
void bodyFatRequirements();
void calorieRequirements();
void leanBodyMassForMacro();
int  macroSportControlling();
void calorieCalculatorMenu();
void calorieCalculator(int activity, float bmr);
void macroCalculator(float calorie, float weight, float pro, int fat);


int main()
{
	menu();
	return 0;
}

void programRequirements(){
	
	system("cls");
	printf("\t\t\t\t\t = Requirements For Using The Program =\n");
	printf("\t\t\t\t     ----------------------------------------------\n");
	printf("\t\t   -If you are a MAN, you should know your age, height, weight, neck and waist measurements-\n");
	printf("\t\t  -------------------------------------------------------------------------------------------\n");
	printf("\t       -If you are a WOMAN, you should know your age, height, weight, neck, waist and hip measurements-\n"),
	printf("\t     ----------------------------------------------------------------------------------------------------\n\n");
	printf("  ---------------------------------------\n");
	
}

void errorMessage(){
	system("cls");
	printf("\n!! ERROR !! Invalid Value !!\n");
	exit(EXIT_SUCCESS);
}

void finalMessage(){
	system("cls");
	printf("\nThank You For Using Me\n");
	printf("\nThis program was made by Emre Ozkaya...");
	printf("\n\t\t\t Number : B1905.010057");
	printf("\n\t\t\t Section : 1");
	exit(EXIT_SUCCESS);
}

int macroSportControlling(){
	printf("  --------------------------------------------\n");
	printf("- Do You Do Sports ?\n");
	printf("- Yes : 1\n");
	printf("- No  : 2\n");
	printf("  ------------------------\n");
 	printf("  Your Answer (1 | 2) : ");
	scanf("%d",&selection); 
	return selection;
}

int gender()
{
	printf("- Male   : 1\n");
	printf("- Female : 2\n");
	printf("  ----------------");
	printf("\n  Your Gender  : ");
	scanf("%d", &selection);
	keeper->gender = selection;

	return selection;
}

void calorieRequirements()
{
	printf("  ---------------------------------------\n");
	printf("  Please Enter Your Age 	   : ");
	scanf("%f", &age);
	keeper->age = age;

	printf("  Please Enter Your Height (cm)    : ");
	scanf("%f", &height);
	keeper->height = height;

	printf("  Please Enter Your Weight (kg)    : ");
	scanf("%f", &weight);
	keeper->weight = weight;
}

void bodyFatRequirements()
{
	printf("  ---------------------------------------\n");

	printf("  Please Enter Your Age 	    : ");
	scanf("%f", &age);
	keeper->age = age;

	printf("  Please Enter Your Height (cm)     : ");
	scanf("%f", &height);
	keeper->height = height;

	printf("  Please Enter Your Weight (kg)     : ");
	scanf("%f", &weight);
	keeper->weight = weight;

	printf("  Please Enter Your Neck   (cm)     : ");
	scanf("%f", &neck);
	keeper->neck = neck;

	printf("  Please Enter Your Waist  (cm)     : ");
	scanf("%f", &waist);
	keeper->waist = waist;
}

int activityLevel()
{
	printf("  ---------------------------------------");
	printf("\n  1 : BMR          : Basal Metabolic Rate\n");
	printf("  2 : Sedentary    : Little or No Exercise\n");
	printf("  3 : Light        : Exercise 1-3 times/week\n");
	printf("  4 : Moderate     : Exercise 4-5 times/week\n");
	printf("  5 : Active       : Exercise 5-6 times/week\n");
	printf("  6 : Very Active  : Exercise 6-7 times/week\n");
	printf("  7 : Extra Active : Physical Job and Exercise 6-7 times/week\n");
	printf("  -----------------------------------------------------------");
	printf("\n  Please Select Your Activity Level : ");
	scanf("%d", &activity);
	printf("  -------------------------------------");
	return activity;
}

//Reset the information received from the user.
void reset()
{
	keeper->gender = 0;
	keeper->age = 0;
	keeper->height = 0;
	keeper->weight = 0;
	keeper->neck = 0;
	keeper->waist = 0;
	keeper->hip = 0;
	system("cls");
	menu();
}

void bodyFatTable()
{
	system("cls");
	printf("\t\t\t\t\t\t === Body Fat Table ===\n");
	printf(" == FOR MALE ==\n");
	printf(" -----------------------------------------------------------------------\n\n");
	printf("   BodyFat \t\tSituation  \t\t  To Do \n");
	printf(" ===========\t\t========= \t\t==========\n");
	printf("  %%5 or Less\t\t  Risky  \t\t Gain Fat \n");
	printf("  %%6 to %%13\t\t  Athletes  \t\t Gain Muscle \n");
	printf("  %%14 to %%17\t\t  Fitness  \t\t Gain Muscle and Burn Fat \n");
	printf("  %%18 to %%25\t\t  Average  \t\t Burn Fat \n");
	printf("  %%25 or more\t\t  Obese  \t\t Burn Fat Immediately \n\n");
	printf(" -----------------------------------------------------------------------\n");
	printf(" == FOR FEMALE ==\n");
	printf(" -----------------------------------------------------------------------\n\n");
	printf("   BodyFat \t\tSituation  \t\t  To Do \n");
	printf(" ===========\t\t========= \t\t==========\n");
	printf("  %%13 or Less\t\t  Risky  \t\t Gain Fat \n");
	printf("  %%14 to %%20\t\t  Athletes  \t\t Gain Muscle \n");
	printf("  %%21 to %%24\t\t  Fitness  \t\t Gain Muscle and Burn Fat \n");
	printf("  %%25 to %%31\t\t  Average  \t\t Burn Fat \n");
	printf("  %%31 or more\t\t  Obese  \t\t Burn Fat Immediately \n\n");
	printf(" -----------------------------------------------------------------------\n");
}

void calorieCalculator(int activity, float bmr)
{
	switch (activity)
	{
		case 1:
			printf(" %.f kcal.\n", bmr);
			break;
		case 2:
			printf(" %.f kcal.\n", bmr *12 / 10);
			break;
		case 3:
			printf(" %.f kcal.\n", bmr *1375 / 1000);
			break;
		case 4:
			printf(" %.f kcal.\n", bmr *14648 / 10000);
			break;
		case 5:
			printf(" %.f kcal.\n", bmr *16 / 10);
			break;
		case 6:
			printf(" %.f kcal.\n", bmr *1725 / 1000);
			break;
		case 7:
			printf(" %.f kcal.\n", bmr *19 / 10);
			break;
		default:
			errorMessage();
			break;
	}
}

void macroCalculator(float calorie, float weight, float pro, int fat)
{
	macroSportControlling();
	switch(selection){
		case 1 :
			printf("  ---------------------------------------");
			printf("\n  Your Protein Requirement       : %.f  gr \n", weight *pro);
			printf("  Your Fat Requirement	         : %.f  gr \n", weight *fat);
			printf("  Your Carbonhydrate Requirement : %.f gr \n", (calorie - ((weight *pro) *4) - ((weight *fat) *9)) / 4);
			printf("  ---------------------------------------\n");
			break;
			
		case 2 :
			printf("  ---------------------------------------");
			printf("\n  Your Protein Requirement       : %.f  gr \n", weight *1);
			printf("  Your Fat Requirement	         : %.f  gr \n", weight *1);
			printf("  Your Carbonhydrate Requirement : %.f gr \n", (calorie - ((weight *1) *4) - ((weight *1) *9)) / 4);
			printf("  ---------------------------------------\n");
			break;
		default:
			errorMessage();
			break;		
	}
}

//This function is for body fat percentage calculating.
void bodyFatCalculator()
{
	float bodyFatPercent , bodyFatMass , leanBodyMass ;
	printf("\t\t\t\t\t\t=== BODY FAT CALCULATOR ===");
	printf("\n \t\t\t\t\t     === PLEASE SELECT YOUR GENDER === \n");
	printf("\t\t\t\t\t -----------------------------------------\n\n");

	if (keeper->gender == 1 || keeper->gender == 2)
	{
		selection = keeper->gender;
	}
	else
	{
		gender();
	}

	if (selection == 1)
	{
		system("cls");
		printf("\t\t\t\t\t\t=== Body Fat Calculator ===\n");
		printf("\t\t\t\t\t    -----------------------------------\n\n");

		printf("  == FOR MALE == \n");
		if (keeper->neck != 0 && keeper->waist != 0)
		{
			age = keeper->age;
			height = keeper->height;
			weight = keeper->weight;
			neck = keeper->neck;
			waist = keeper->waist;

		}
		else if (keeper->age && keeper->neck == 0)
		{
			printf("  ---------------------------------------\n");

			printf("  Please Enter Your Neck  (cm)  : ");
			scanf("%f", &neck);
			keeper->neck = neck;

			printf("  Please Enter Your Waist (cm)	: ");
			scanf("%f", &waist);
			keeper->waist = waist;

		}
		else
		{
			bodyFatRequirements();

		}

		printf("  ---------------------------------------");
		bodyFatPercent = ((495) / ((1.0324 - 0.19077* log10(waist - neck)) + (0.15456* log10(height)))) - 450;
		printf("\n  Body Fat Percentage    : %%%.2f\n", bodyFatPercent);

		bodyFatMass = (weight *bodyFatPercent) / 100;
		printf("  Body Fat Mass          : %.2f kg\n", bodyFatMass);

		leanBodyMass = (weight - bodyFatMass);
		printf("  Lean Body Mass         : %.2f kg\n", leanBodyMass);
		printf("  ---------------------------------------");

		if (bodyFatPercent <= 5 && bodyFatPercent >= 0)
		{
			printf("\n  Suggestion: You have to gain some fat \n  because you're in a risky situation.\n");
		}
		else if (bodyFatPercent > 5 && bodyFatPercent <= 13)
		{
			printf("\n  Suggestion: Your fat percentage is at \n  an athletic level so if you want, you \n  can gain muscle.\n");
		}
		else if (bodyFatPercent > 13 && bodyFatPercent <= 17)
		{
			printf("\n  Suggestion: Your fat percentage is at \n  an fitness level so if you want, you \n  can gain muscle and burn fat.\n");
		}
		else if (bodyFatPercent > 17 && bodyFatPercent <= 25)
		{
			printf("\n  Suggestion: Your fat percentage is at \n  an average level so if you want, you \n  can gain muscle and burn fat.\n");
		}
		else if (bodyFatPercent > 25)
		{
			printf("\n  Suggestion: You have to burn fat \n  because you're in a obese situation.\n");
		}
		else
		{
			errorMessage();
		}

		printf("  ---------------------------------------\n");
	}
	else if (selection == 2)
	{
		system("cls");
		printf("\t\t\t\t\t\t=== Body Fat Calculator ===\n");
		printf("\t\t\t\t\t    -----------------------------------\n\n");

		printf("  == FOR FEMALE == \n");

		if (keeper->neck != 0 && keeper->waist != 0 && keeper->hip != 0)
		{
			age = keeper->age;
			height = keeper->height;
			weight = keeper->weight;
			neck = keeper->neck;
			waist = keeper->waist;
			hip = keeper->hip;

		}
		else if (keeper->age && keeper->neck == 0)
		{
			printf("  ---------------------------------------\n");
			printf("  Please Enter Your Neck  (cm)    : ");
			scanf("%f", &neck);
			keeper->neck = neck;

			printf("  Please Enter Your Waist (cm)    : ");
			scanf("%f", &waist);
			keeper->waist = waist;

			printf("  Please Enter Your Hip   (cm)    : ");
			scanf("%f", &hip);
			keeper->hip = hip;
		}
		else
		{
			bodyFatRequirements();

			printf("  Please Enter Your Hip    (cm)     : ");
			scanf("%f", &hip);
			keeper->hip = hip;
		}

		printf("  ---------------------------------------");
		bodyFatPercent = ((495) / ((1.29579 - 0.35004* log10(waist + hip - neck)) + (0.22100* log10(height)))) - 450;
		printf("\n  Body Fat Percentage    : %%%.2f\n", bodyFatPercent);

		bodyFatMass = (weight *bodyFatPercent) / 100;
		printf("  Body Fat Mass          : %.2f kg\n", bodyFatMass);

		leanBodyMass = (weight - bodyFatMass);
		printf("  Lean Body Mass         : %.2f kg\n", leanBodyMass);
		printf("  ---------------------------------------");

		if (bodyFatPercent < 14 && bodyFatPercent >= 0)
		{
			printf("\n  Suggestion: You have to gain some fat \n  because you're in a risky situation.\n");
		}
		else if (bodyFatPercent >= 14 && bodyFatPercent < 21)
		{
			printf("\n  Suggestion: Your fat percentage is at \n  an athletic level so if you want, you \n  can gain muscle.\n");
		}
		else if (bodyFatPercent >= 21 && bodyFatPercent < 25)
		{
			printf("\n  Suggestion: Your fat percentage is at \n  an fitness level so if you want, you \n  can gain muscle and burn fat.\n");
		}
		else if (bodyFatPercent >= 25 && bodyFatPercent < 31)
		{
			printf("\n  Suggestion: Your fat percentage is at \n  an fitness level so if you want, you \n  can gain muscle and burn fat.\n");
		}
		else if (bodyFatPercent > 31)
		{
			printf("\n  Suggestion: You have to burn fat \n  because you're in a obese situation.\n");
		}
		else
		{
			errorMessage();
		}

		printf("  ---------------------------------------\n");

	}
	else
	{
		errorMessage();
	}
}

//This function is calorie menu for calculating.
void calorieCalculatorMenu()
{
	float calculatorFormulaBMR , bmr;
	printf("\t\t\t\t\t\t=== CALORIE CALCULATOR ===\n");
	printf("\t\t\t\t\t     === PLEASE SELECT YOUR GENDER === \n");
	printf("\t\t\t\t\t -----------------------------------------\n\n");

	if (keeper->gender == 1 || keeper->gender == 2)
	{
		selection = keeper->gender;
	}
	else
	{
		gender();
	}

	if (selection == 1)
	{
		system("cls");
		printf("\t\t\t\t\t\t=== CALORIE CALCULATOR ===\n");
		printf("\t\t\t\t\t    ----------------------------------\n\n");

		printf("\n  == FOR MALE == \n");

		if (keeper->age != 0 && keeper->height != 0 && keeper->weight != 0)
		{
			age = keeper->age;
			height = keeper->height;
			weight = keeper->weight;

		}
		else
		{
			calorieRequirements();
		}

		calculatorFormulaBMR = ((10 *weight + 6.25 *height) - (5 *age) + 5);
		bmr = calculatorFormulaBMR;

		activityLevel();
		printf("\n  Calorie Requirement For Maintain Weight :");
		calorieCalculator(activity, bmr);
		printf("  ----------------------------------------------------\n");

	}
	else if (selection == 2)
	{
		system("cls");
		printf("\t\t\t\t\t\t=== CALORIE CALCULATOR ===\n");
		printf("\t\t\t\t\t    ----------------------------------\n\n");

		printf("\n  == FOR FEMALE == \n");

		if (keeper->age != 0 && keeper->height != 0 && keeper->weight != 0)
		{
			age = keeper->age;
			height = keeper->height;
			weight = keeper->weight;

		}
		else
		{
			calorieRequirements();
		}

		calculatorFormulaBMR = (10 *weight + 6.25 *height - 5 *age - 161);
		bmr = calculatorFormulaBMR;

		activityLevel();
		printf("\n  Calorie Requirement For Maintain Weight :");
		calorieCalculator(activity, bmr);
		printf("  ----------------------------------------------------\n");
	}
	else
	{
		errorMessage();
	}
}

//This function is used for macro calculating.
void calorieForMacro()
{
	system("cls");
	printf("\n- Do You Know Your Calorie Need ?\n");
	printf("  -------------------------------\n");
	printf("   If You Don't Know You Should \n      Learn With Calculator\n");
	printf("  -------------------------------");
	printf("\n  Your Answer (yes | no): ");
	scanf("%s", slctn);

	if (strcmp(yes, slctn) == 0 || strcmp(yes2, slctn) == 0)
	{
		system("cls");
		printf("\n");
	}
	else if (strcmp(no, slctn) == 0 || strcmp(no2, slctn) == 0)
	{
		system("cls");
		calorieCalculatorMenu();
		printf("\n");
	}
	else
	{
		errorMessage();
	}
}

//This function is used for macro calculating.
void leanBodyMassForMacro()
{
	system("cls");
	printf("\n- Do You Know Your Lean Body Mass ?\n");
	printf("  -------------------------------\n");
	printf("   If You Don't Know You Should \n      Learn With Calculator\n");
	printf("  -------------------------------");
	printf("\n  Your Answer (yes | no): ");
	scanf("%s", slctn);

	if (strcmp(yes, slctn) == 0 || strcmp(yes2, slctn) == 0)
	{
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t\t=== Macro Calculator ===\n");
		printf("\t\t\t\t\t    --------------------------------\n\n");

	}
	else if (strcmp(no, slctn) == 0 || strcmp(no2, slctn) == 0)
	{
		system("cls");
		bodyFatCalculator();
		printf("\t\t\t\t\t\t=== Macro Calculator ===\n");
		printf("\t\t\t\t\t    --------------------------------\n\n");

	}
	else
	{
		errorMessage();
	}
}

//This function is for macro menu for calculating.
//It contains "caloForMacro" and "leanBodyMassForMacro" functions.
void macroCalculatorMenu()
{
	printf("\t\t\t\t\t\t=== MACRO CALCULATOR ===\n");
	printf("\t\t\t\t\t   === PLEASE SELECT YOUR GENDER === \n");
	printf("\t\t\t\t       -----------------------------------------\n\n");

	if (keeper->gender == 1 || keeper->gender == 2)
	{
		selection = keeper->gender;
	}
	else
	{
		gender();

	}

	if (selection == 1)
	{
		calorieForMacro();
		printf("\t\t\t\t\t\t=== Macro Calculator ===\n");
		printf("\t\t\t\t\t    --------------------------------\n\n");

		printf("\n  == FOR MALE ==\n");
		printf("  --------------------------------");
		printf("\n  Please write your calorie : ");
		scanf("%f", &calorie);

		leanBodyMassForMacro();

		printf("\n  == FOR MALE ==\n");
		printf("  --------------------------------------------\n");
		printf("  Please Enter Your Lean Body Weight[kg] : ");
		scanf("%f", &weight);

		if (weight < 50)
		{
			macroCalculator(calorie, weight, 1, 1);
		}
		else if (weight >= 50 && weight < 60)
		{
			macroCalculator(calorie, weight, 1.5, 1);
		}
		else if (weight >= 60 && weight < 70)
		{
			macroCalculator(calorie, weight, 2, 1);
		}
		else if (weight >= 70 && weight < 80)
		{
			macroCalculator(calorie, weight, 2.5, 1);
		}
		else if (weight >= 80 && weight < 90)
		{
			macroCalculator(calorie, weight, 3, 1);
		}
		else if (weight >= 90 && weight < 100)
		{
			macroCalculator(calorie, weight, 3.5, 1);
		}
		else if (weight >= 100 && weight < 110)
		{
			macroCalculator(calorie, weight, 4, 1);
		}
		else if (weight >= 110 && weight < 120)
		{
			macroCalculator(calorie, weight, 4.5, 1);
		}
		else if (weight >= 120)
		{
			macroCalculator(calorie, weight, 5, 1);
		}
		else
		{
			errorMessage();
		}
	}
	else if (selection == 2)
	{
		calorieForMacro();

		printf("\t\t\t\t\t\t=== Macro Calculator ===\n");
		printf("\t\t\t\t\t    --------------------------------\n\n");

		printf("\n  == FOR FEMALE ==\n");
		printf("  --------------------------------");

		printf("\n  Please write your calorie : ");
		scanf("%f", &calorie);

		leanBodyMassForMacro();

		printf("\n  == FOR FEMALE ==\n");
		printf("  --------------------------------------------\n");
		printf("  Please Enter Your Lean Body Weight[kg] : ");
		scanf("%f", &weight);

		if (weight < 30)
		{
			macroCalculator(calorie, weight, 1, 1);
		}
		else if (weight >= 30 && weight < 40)
		{
			macroCalculator(calorie, weight, 1.5, 1);
		}
		else if (weight >= 40 && weight < 50)
		{
			macroCalculator(calorie, weight, 2, 1);
		}
		else if (weight >= 50 && weight < 60)
		{
			macroCalculator(calorie, weight, 2.5, 1);
		}
		else if (weight >= 60 && weight < 70)
		{
			macroCalculator(calorie, weight, 3, 1);
		}
		else if (weight >= 70 && weight < 80)
		{
			macroCalculator(calorie, weight, 3.5, 1);
		}
		else if (weight >= 80 && weight < 90)
		{
			macroCalculator(calorie, weight, 4, 1);
		}
		else if (weight >= 90 && weight < 100)
		{
			macroCalculator(calorie, weight, 4.5, 1);
		}
		else if (weight >= 100)
		{
			macroCalculator(calorie, weight, 5, 1);
		}
		else
		{
			errorMessage();
		}
	}
	else
	{
		errorMessage();
	}
}

// This function is for menu area.
void menu()
{
	printf("\n\t\t\t\t  === WELCOME TO DIET AND HEALTH CONTROL APPLICATION === \n");

	while (answer == 'y' || answer == 'Y')
	{
		repeat: printf("\t\t\t\t\t == PLEASE SELECT THE ACTION YOU WANT ==\n");
		printf("\t\t\t\t    ------------------------------------------------\n\n");
		printf("- Body Fat Calculator : 1 \n");
		printf("- Calorie Calculator  : 2 \n");
		printf("- Macro Calculator    : 3 \n");
		printf("- Body Fat Table      : 4 \n");
		printf("- Information Reset   : 5 \n");
		printf("- Requirements        : 6 \n");
		printf("- Exit                : 7 \n");
		printf("  -------------------------");

		printf("\n  Your Selection      : ");
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				system("cls");
				bodyFatCalculator();
				break;
			case 2:
				system("cls");
				calorieCalculatorMenu();
				break;
			case 3:
				system("cls");
				macroCalculatorMenu();
				break;
			case 4:
				bodyFatTable();
				break;
			case 5:
				reset();
				break;
			case 6:
				programRequirements();
				break;
			case 7 : 
				finalMessage();
				break;
			default:
				errorMessage();
				break;
		}

		printf("  Do You Want to Do Another Calculating ?\n");
		printf("  Yes --> Y\n  No  --> N");
		printf("\n  ---------------------------------------");
		printf("\n  Your Answer    : ");
		scanf(" %c", &answer);
		if (answer == 'N' || answer == 'n')
		{
			finalMessage();
		}
		else if (answer == 'y' || answer == 'Y')
		{
			answer = 'y';
		}
		else
		{
			errorMessage();
		}

		system("cls");
	}
}

