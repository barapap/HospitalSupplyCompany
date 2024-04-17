#include <stdio.h>
#include <math.h> 

	int num,ml,drop,hours;
	float ans=0;
	char terminate;
	float rate,kg;
	
	
			int get_problem() {	
			
					printf("Enter the number of the problem you wish to solve.\n");
					printf("\tGIVEN A MEDICAL ORDER IN \t\tCALCULATE RATE IN\n");
					printf("______________________________________________________________________\n");
					printf("|(1)|\tM1/hr & tubing drop factor\t\t|drop/min\n");
					printf("|(2)|\t1L for n hr\t\t\t\t|ml/hr\n");
					printf("|(3)|\tmg/kg/hr & concentration in mg/ml\t|ml/hr\n");
					printf("|(4)|\tunits/hr & concentration in units/ml\t|ml/hr\n");
					printf("|(5)|\tQUIT\t\t\t\t\t|ml/hr\n");
					
					printf("\nProblems >> ");
					scanf("%d",&num);
					return num;		
					}
				
				
			int fig_drop_min (float ml, float drop)	{		//change to rounded value for prob 1
			
					ans = (ml*drop) / 60;
					return (int)(ans+0.5f);			
					}
				
							
			int get_rate_drop_factor ()	{					//function for prob 1
			
					printf("Enter the rate in ml/hr >> ");
					scanf("%d",&ml); 
					printf("Enter tubing's drop factor (drops/ml) >> ");
					scanf("%d",&drop);		
					return fig_drop_min (ml, drop);		
					}
					
					
			int by_weight (float rate, float kg, int ml) {	//change to round value for prob 3
			
				return(round(ans = rate*kg*ml));
				}
			
					
			int get_kg_rate_conc ()	{						//function prob 3
			
				printf("Enter rate in mg/kg/hr >> ");
				scanf("%f",&rate); 
				printf("Enter patient weight in kg >> ");
				scanf("%f",&kg);
				printf("Enter concentration in m/ml >> ");
				scanf("%d",&ml);
				by_weight (rate,kg,ml);		
				return ans;	
				}
			
			
			int by_units (int ml, int drop)	{				// change to round value for prob 4
			
				ans = ml/drop;
				return (int)(ans+0.5f);
				}			
			
			
			int get_units_conc () {							//function prob 4
			
				printf("Enter rate in units/hr >> ");
				scanf("%d",&ml); 
				printf("Enter concentration in units/ml >> ");
				scanf("%d",&drop);
				by_units (ml,drop);
				return ans;
				}
			
						
			int fig_ml_hr (int hours) {						//change to round value for prob 2	
		
				ans = 1000/hours;		//1000 alrdy in ml
				return (int)(ans+0.5f);
				}
			

/*======================================================================================================*/ 

	
int main ()
{
	int finalans;
	printf("INTRAVENOUS RATE ASSISTANT\n");
	while(1)
	{
		switch(get_problem())
		{
			case 1: 
				finalans = get_rate_drop_factor();
				printf("The drop rate per minutes is %d",finalans);
				break;
				
			case 2:
				printf("Enter number of hours >> ");
				scanf("%d",&hours); 
				finalans = fig_ml_hr (hours);								//to make round value
				printf("The rate in millilitres per hours is %d",finalans);
				break; 
				
			case 3:
				finalans = get_kg_rate_conc();
				printf("The rate in millilitres per hours is %d",finalans);
				break;
				
			case 4:
				finalans = get_units_conc();
				printf("The rate in millilitres per hours is %d",finalans);
				break;
				
			case 5:
				return 0;
				break;
				
			default:
				printf("\n""""""""Sorry you have entered an invalid problem index.\n");
				printf("Please try again, enter 5 to exit.""""""""");
		} 
		printf("\n\n\n");
		fflush(stdin);
	
	}
		
	return 0;
}
