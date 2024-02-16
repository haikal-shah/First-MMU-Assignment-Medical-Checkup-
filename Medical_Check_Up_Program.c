//header
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to keep user(s)'s data
struct data{
char blood_type[4], blood_result[100], age_result[50], BMI_result[100], name[80], special_health_condition[100];
float height, weight, BMI;
int age;
};

//global counter to update struct data
int counter;

//function prototype
void file_write(struct data person[], int);
void compare_blood(struct data person[], int);
void group_age(struct data person[], int);
void bmi(struct data person[], int);
void special_health(struct data person[], int);

//void main; write or update the data (text)
void main(){
	
	//the data storage limit
	struct data user[100];

	file_write(user,counter); //w+ the file
	
	//displayed when the program ends
	printf("\n\n::::::::::::::::::::::::::  || THANK YOU FOR USING THE PROGRAM ||  ::::::::::::::::::::::::::");
}

//void file_rewrite; if the user wants to rewrite the data (file w+)
void file_write(struct data person[],int counter){
	
	int i; //counter for looping
	
	FILE *fp; //file pointers
	fp = fopen("Health Record.txt","w+"); //opens the file to rewrite
	
	printf("=============================================================================================");
	printf("\n                                  MEDICAL CHECKUP REPORT");
	printf("\n=============================================================================================");
	printf("\n::::::::::::::::::::::::::::::::::::::  || WELCOME ||  ::::::::::::::::::::::::::::::::::::::");
	
	printf("\n\nHow many user(s) data to store?: "); //asking the user to input numbers of users
	scanf("%d", &counter);
	
	for(i=0; i<counter; i++){
	fflush(stdin);
	printf("\n\nEnter name: "); //keeping the user(s) name
    scanf("%[^\n]s", person[counter].name);
		
	fflush(stdin);
	printf("Enter age : "); //keeping the user(s) age
	scanf("%d", &person[counter].age);
	group_age(person,counter);
		
	fflush(stdin);	
	printf("Enter height [CM]: "); //keeping the user(s) height
	scanf("%f", &person[counter].height);
	
	fflush(stdin);
	printf("Enter weight [KG]: "); //keeping the user(s) weight
	scanf("%f", &person[counter].weight);
	bmi(person,counter);	

	fflush(stdin);
	printf("Enter blood type [AB+] [AB-] [A+] [A-] [B+] [B-] [O+] [O-]: "); //keeping the user(s) bloodtype
	scanf("%s",person[counter].blood_type);
	compare_blood(person,counter);
		
	special_health(person,counter); //keeping the user(s) health condition
	
	printf("\n\n=============================================================================================");
	printf("\n                                  RESULT");
	printf("\n=============================================================================================");
			
	//display the calculated data
	printf("\n\n%s",person[counter].name); //outputing the user(s) name
	printf("\n%s",person[counter].age_result); //outputing the user(s) age
	printf("\nYour BMI Index is: %.2f",person[counter].BMI); //outputing the user(s) bmi index
	printf("\n%s",person[counter].BMI_result); //outputing the user(s) bmi scale
	printf("\n%s",person[counter].blood_result); //outputing the user(s) blood compatibility
	printf("\nSpecial health condition: %s", person[counter].special_health_condition); //outputing the user(s) health condition
		
	//writing the datas into the file
	fprintf(fp,"\n\nName: %s", person[counter].name); //keeping the user(s) name
	fprintf(fp,"\nAge: %d \n%s", person[counter].age, person[counter].age_result); //keeping the user(s) age and age group
	fprintf(fp,"\nHeight: %.2f CM \nWeight: %.2f KG", person[counter].height, person[counter].weight); //keeping the user(s) height and weight
	fprintf(fp,"\nYour BMI index: %.2f \n%s", person[counter].BMI, person[counter].BMI_result); //keeping the user(s) bmi index and class
	fprintf(fp,"\nYour blood type: %s \n%s", person[counter].blood_type, person[counter].blood_result); //keeping the user(s) blood type and compatibility
	fprintf(fp,"\nAny special health condition?: %s", person[counter].special_health_condition); //keeping the user(s) special health condition
	}
	fclose(fp);	
}

//void compare_blood; get user(s) blood type and gives compatible blood type
void compare_blood(struct data person[],int counter){
	
	int i; //counter for looping
	
	//giving the user(s) blood compatibility 
	for(i=0; i<counter; i++){
		if(strcmp(person[counter].blood_type,"ab+")==0 || strcmp(person[counter].blood_type,"AB+")==0){ //ab+ blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- O+ B- B+ A- A+ AB- AB+ \nYou can donate blood to: AB+");
		}
		else if(strcmp(person[counter].blood_type,"ab-")==0 || strcmp(person[counter].blood_type,"AB-")==0){ //ab- blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- B- A- AB- \nYou can donate blood to: AB+ AB-");
		}
		else if(strcmp(person[counter].blood_type,"a+")==0 || strcmp(person[counter].blood_type,"A+")==0){ //a+ blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- O+ A- A+ \nYou can donate blood to: AB+ A+");
		}
		else if(strcmp(person[counter].blood_type,"a-")==0 || strcmp(person[counter].blood_type,"A-")==0){ //a- blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- A- \nYou can donate blood to: AB+ AB- A+ A-");
		}
		else if(strcmp(person[counter].blood_type,"b+")==0 || strcmp(person[counter].blood_type,"B+")==0){ //b+ blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- O+ B- B+ \nYou can donate blood to: AB+ B+");
		}
		else if(strcmp(person[counter].blood_type,"b-")==0 || strcmp(person[counter].blood_type,"B-")==0){ //b- blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- B- \nYou can donate blood to: AB+ AB- B+ B-");
		}
		else if(strcmp(person[counter].blood_type,"o+")==0 || strcmp(person[counter].blood_type,"O+")==0){ //o+ blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- O+ \nYou can donate blood to: AB+ A+ B+ O+");
		}
		else if(strcmp(person[counter].blood_type,"o-")==0 || strcmp(person[counter].blood_type,"O-")==0){ //o- blood
			strcpy(person[counter].blood_result, "You can recieve blood from: O- \nYou can donate blood to: O- O+ B- B+ A- A+ AB-");
		}
		else{ //if the user insert non existent blood type
			strcpy(person[counter].blood_result, "Invalid blood type");
		}
	}
}

//void group_age; get the users age and classify their age group
void group_age(struct data person[],int counter){
	
	int i;//counter for looping
	
	//classify user(s) age group
	for(i=0; i<counter; i++){

			switch(person[counter].age){
    			case 0 ... 3: //0 - 3 years old
        			strcpy(person[counter].age_result, "Your age group is: Infant");
        			break;
    			case 4 ... 12: //4 - 12 years old
        			strcpy(person[counter].age_result, "Your age group is: Children");
        		break;
    		case 13 ... 17: //13 - 17 years old
        		strcpy(person[counter].age_result, "Your age group is: Teen");
        		break;
    		case 18 ... 30: //18 - 30 years old
        		strcpy(person[counter].age_result, "Your age group is: Young Adult");
        		break;
    		case 31 ... 59: //31 - 59 years old
        		strcpy(person[counter].age_result, "Your age group is: Middle-aged Adult");
        		break;
    		case 60 ... 200: //60 - 200 years old
        		strcpy(person[counter].age_result, "Your age group is: Old Adult");
    		default: //200+ or the user insert non int value
    			strcpy(person[counter].age_result, "Invalid Age Group");
    			break;
		}
	}
}

//void bmi(struct data person[],int counter); get users' height and weight to give their bmi result and category
void bmi(struct data person[],int counter){

	int i;//for loops
	
	for(i=0; i<counter; i++){   
		
		//variables for calculations
		float bmi;
		float meter;
		
		//calculations
		meter = person[counter].height / 100; //meter = height(cm) / 100
    	bmi = person[counter].weight / (meter * meter); //bmi = weight(kg) = / (meter * meter)
		person[counter].BMI = bmi; //storing the bmi
  
    	if(bmi < 18.5){ //bmi less than 18.5
			strcpy(person[counter].BMI_result, "Your BMI category is: Underweight");
    	}  
    	else if(bmi >= 18.5 && bmi <= 24.9){ //bmi 18.5 - 24.9
			strcpy(person[counter].BMI_result, "Your BMI category is: Normal");
    	}  
    	else if(bmi >= 25.0 && bmi <= 29.9){ //bmi 25.0 - 29.9
    		strcpy(person[counter].BMI_result, "Your BMI category is: Overweight");
    	}  
    	else if(bmi > 30){ //bmi more than 30
    		strcpy(person[counter].BMI_result, "Your BMI category is: Obese");
    	}  
    	else{ //if the user puts in invalid data
			strcpy(person[counter].BMI_result, "Invalid BMI Scale");
    	} 
	}
}

//void special_health(struct data person[],int counter) asking the user(s) if they have any special health condition
void special_health(struct data person[],int counter)
{
	char condition;// y/n
	
	printf("Do you have any special health condition [Y/N]: "); ///asking the user(s) if they have any health condition (y/n) respond
	scanf(" %c", &condition);
	
	if(condition == 'Y'||condition =='y'){ //if yes (y/Y)
		fflush(stdin);
		printf("Insert special health condition: ");
		scanf("%[^\n]s", person[counter].special_health_condition);
	}
	else{ //if no (anything other than y/Y)
		printf("No special health condition");
		strcpy(person[counter].special_health_condition, "No special health condition");
	}
}

