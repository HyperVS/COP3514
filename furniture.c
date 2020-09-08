#include<stdio.h>
#include<stdlib.h>
int main()
{

        // Declarations
        int months, option;

        //Displaying the menu
        printf("Please select from the following menu:\n");
        printf("1. Sofa\n2. Loveseat\n3. 4 Post Bed\n4. Dresser\n5. Kitchen Table\n");
        printf("Please enter your furniture selection: ");
        
        // Getting user input on option selected
        scanf("%d",&option);

        // Validating the option selected
        if(option<1 || option>5)

        {
                printf("Invalid Selection.\n");
                exit(1);
        }
        
        // Getting user input on months rented
        printf("Enter months rented: ");
        scanf("%d",&months);

        // Validating months rented
        if(months<1){
                printf("Invalid number of Months.\n");
                exit(1);
        }

        // Calculating amount to pay
        int amount = 0;

        switch(option)
        {
            case 1:
                if(months >= 12){
                        amount = 100 * months / 12;
                        months = months % 12; 
                }
                else{
                        //for first month
                        amount = 20 ;
                        months--;
                }
                //for remaining months
                amount += 12 * months;
                break;
            
            case 2:
                if(months >= 12){
                        amount = 80 * months / 12;
                        months = months % 12; 
                }
                else{
                        amount = 15 ;
                        months--;
                }
                amount += 10 * months;
                break;

            case 3:
                if(months >= 12){
                        amount = 105 * months / 12;
                        months = months % 12; 
                }
                else{
                        amount = 25 ;
                        months--;
                }
                amount += 8 * months;
                break;
            
            case 4:
                if(months >= 12){
                        amount = 50 * months / 12;
                        months = months % 12; 
                }
                else{
                        amount = 10 ;
                        months--;
                }
                amount += 5 * months;
                break;

            case 5:
                if(months >= 12){
                        amount = 120 * months / 12;
                        months = months % 12; 
                }
                else{
                        amount = 25 ;
                        months--;
                }
                amount += 10 *months;
                break;
        }

        printf("Amount due ($) : %d\n",amount);
}