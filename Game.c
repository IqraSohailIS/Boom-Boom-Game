#include<stdio.h>
#include<conio.h>
int choice=0,grid_size=0,i,j,bomb=0,safe_zone=0,difficulty_level=0,score=0; //Variables
int unrevealed_value_1[5][5],unrevealed_value_2[6][6],unrevealed_value_3[7][7];    //int Arrays
char revealed_value_1[5][5],revealed_value_2[6][6],revealed_value_3[7][7];    //char Arrays;
char value_1[5][5],value_2[6][6],value_3[7][7];    //char Arrays
int grid_print(),play_exit(),random_value(),selecting_difficulty_level(),working(),revealed_grid_print();       //Functions
int main()
{   
    system("color E5"); 
    printf("\"WELCOME TO THE BOOM BOOM GAME\"\n\n");
    do
    {	
    score=0;
	selecting_difficulty_level();
	random_value();
	grid_print();
	working();
	}while(choice==1);
}

//DEFINING THE FUNCTION selecting_difficulty_level()
int selecting_difficulty_level()
{
	//Asking user to tell about the difficulty level
	do
	{
		
	printf("Select difficulty level:\n1 for easy\n2 for medium\n3 for hard\n\n\"MORE DIFFICULTY LEVEL MEANS A LARGER GRID AND MORE BOMBS!\"\n\nEnter your choice:");
	scanf("%d",&difficulty_level);
	
	if(difficulty_level<1 || difficulty_level>3)
	printf("Your choice is wrong!\n\n");
	
   }while(difficulty_level<1 || difficulty_level>3);
	
	system("cls");    
	
	//Assigning grid_size according to difficulty_level
    if(difficulty_level==1)
	{
		grid_size=5;
	}
	else if(difficulty_level==2)
	{
		grid_size=6;
	}
	else
	{
		grid_size=7;
	}		
}

//DEFINING THE FUNCTION random_value()
int	random_value()
{
	//Random Values for easy difficulty level
	if(grid_size==5)
	{
	for(i=0;i<grid_size;i++)
	{
		for(j=0;j<grid_size;j++)
		{
			unrevealed_value_1[i][j]=rand()%2;        //Generates random value either 0 or 1
		}
	}
	for(i=0;i<grid_size;i++)
	{
		for(j=0;j<grid_size;j++)
		{
			if(unrevealed_value_1[i][j]==1)
			{
			value_1[i][j]='1';
			safe_zone++;
		    }
			else
			{
			value_1[i][j]='*';
		    bomb++;
			}
        }
    }
}

	//Random Values for medium difficulty level
   	else if(grid_size==6)
	{
	for(i=0;i<grid_size;i++)
	{
		for(j=0;j<grid_size;j++)
		{
			unrevealed_value_2[i][j]=rand()%2;
		}
	}
	for(i=0;i<grid_size;i++)
	{
		for(j=0;j<grid_size;j++)
		{
			if(unrevealed_value_2[i][j]==1)
			{
			value_2[i][j]='1';
			safe_zone++;
		    }
			else
			{
			value_2[i][j]='*';
			bomb++;
            }
		}
    }
    }
	//Random Values for hard difficulty level
	else
	{
	for(i=0;i<grid_size;i++)
	{
		for(j=0;j<grid_size;j++)
		{
			unrevealed_value_3[i][j]=rand()%2;
		}
	}
	for(i=0;i<grid_size;i++)
	{
		for(j=0;j<grid_size;j++)
		{
			if(unrevealed_value_3[i][j]==1)
			{
			value_3[i][j]='1';
			safe_zone++;
		    }
			else
			{
			value_3[i][j]='*';
			bomb++;
		    }
        }
    }
    }
}
//DEFINING THE FUNCTION grid_print()
int grid_print()
{
//Grid for easy difficulty level
	if(grid_size==5)
	{
		printf("Difficulty Level: Easy\nGrid: 5x5\nTotal Bombs: %d\nTotal Safe Zones: %d\n\n",bomb,safe_zone);
		printf("Horizontal ==> Rows\nVertical ==> Columns\n\n\n");
		printf("\t");
    	for(i=0;i<grid_size;i++)
	    {
	    	for(j=0;j<grid_size;j++)
	    	{
			revealed_value_1[i][j]=' ';
	     	}
     	}	
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",revealed_value_1[i][j]);
            }
            printf("\n\n");
        }
    }

//Grid for medium difficulty level
    else if(grid_size==6)
	{
		printf("Difficulty Level: Medium\nGrid: 6x6\nTotal Bombs: %d\nTotal Safe Zones: %d\n\n",bomb,safe_zone);
		printf("Horizontal ==> Rows\nVertical ==> Columns\n\n\n");
		printf("\t");
	    for(i=0;i<grid_size;i++)
	    {
	    	for(j=0;j<grid_size;j++)
	    	{
			revealed_value_2[i][j]=' ';
	     	}
     	}	
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",revealed_value_2[i][j]);
            }
            printf("\n\n");
        }
    }

//Grid for Hard difficulty level   
    else
	{
		printf("Difficulty Level: Hard\nGrid: 7x7\nTotal Bombs: %d\nTotal Safe Zones: %d\n\n",bomb,safe_zone);
		printf("Horizontal ==> Rows\nVertical ==> Columns\n\n\n");
		printf("\t");
	    for(i=0;i<grid_size;i++)
	    {
	    	for(j=0;j<grid_size;j++)
	    	{
			revealed_value_3[i][j]=' ';
	     	}
     	}	
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",revealed_value_3[i][j]);
            }
            printf("\n\n");
        }
    }
}
////DEFINING THE FUNCTION working()
int working()
{
	if(grid_size==5)
	{
    do
	{
	printf("Enter Column Number to place a flag: ");
	scanf("%d",&j);
	printf("Enter Row Number to place a flag: ");
	scanf("%d",&i);
	if(i>5 || j>5 || i<1 || j<1)
	printf("You entered wrong row or column number!\n");
	}while(i>5 || j>5);
	
	if(unrevealed_value_1[i-1][j-1]==1)
    {
    	if( revealed_value_1[i-1][j-1]!='1')
    	{
        revealed_value_1[i-1][j-1]='1';
        score+=5;
        }
        revealed_grid_print();
	}
    else
	{	
	    printf("\n\n\t");
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",value_1[i][j]);
            }
            printf("\n\n");
        }	
	    printf("\nYour Score is %d ",score);
		printf("\n\"BOOM BOOM\"\nGAME OVER");
	    play_exit();    	
	} 
    }
    else if(grid_size==6)
	{
    do
	{
	printf("Enter Column Number to place a flag: ");
	scanf("%d",&j);
	printf("Enter Row Number to place a flag: ");
	scanf("%d",&i);
	if(i>6 || j>6 || i<1 || j<1)
	printf("You entered wrong row or column number!\n");
	}while(i>6 || j>6);
	
	if(unrevealed_value_2[i-1][j-1]==1)
    {
        if(revealed_value_2[i-1][j-1]!='1')
        {
		score+=6;
		revealed_value_2[i-1][j-1]='1';
	    }
     	revealed_grid_print();
	}
    else
	{
		printf("\n\n\t");
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",value_2[i][j]);
            }
            printf("\n\n");
        }
		printf("\nYour Score is %d ",score);
		printf("\n\"BOOM BOOM\"\nGAME OVER");
	    play_exit();    	
	} 
    }
    else
	{
    do
	{
	printf("Enter Column Number to place a flag: ");
	scanf("%d",&j);
	printf("Enter Row Number to place a flag: ");
	scanf("%d",&i);
	if(i>7 || j>7 || i<1 || j<1)
	printf("You entered wrong row or column number!\n");
	}while(i>7 || j>7);
	
	if(unrevealed_value_3[i-1][j-1]==1)
    {
    	if(revealed_value_3[i-1][j-1]!='1')
    	{
    	score+=7;
        revealed_value_3[i-1][j-1]='1';
        }
     	revealed_grid_print();
	}
    else
	{
		printf("\n\n\t");
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",value_3[i][j]);
            }
            printf("\n\n");
        }
		printf("\nYour Score is %d ",score);
		printf("\n\"BOOM BOOM\"\nGAME OVER");
	    play_exit();    	
	} 
    }
}
//DEFINING THE FUNCTION revealed_grid_print()
int revealed_grid_print()
{
	if(grid_size==5)
	{
	printf("\n\n\t");
	for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",revealed_value_1[i][j]);
            }
            printf("\n\n");
        }
        if(score==safe_zone*5)
        {
        	printf("\t");
            for(j=0;j<grid_size;j++)
            {
         	printf("\t| %d |",j+1);
           	}
        	printf("\n\n");
    
        	for(i=0;i<grid_size;i++)
        	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",value_1[i][j]);
            }
            printf("\n\n");
            }
            printf("You found all safe zones\nYOU WIN");
        	play_exit();
		}
    }
    else if(grid_size==6)
	{
	printf("\n\n\t");
	for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",revealed_value_2[i][j]);
            }
            printf("\n\n");
        }
        if(score==safe_zone*6)
        {
       
        printf("\t");
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",value_2[i][j]);
            }
            printf("\n\n");
        }
         printf("You found all safe zones\nYOU WON");
		play_exit();
		}
    }
	else
	{
	printf("\n\n\t");
	for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",revealed_value_3[i][j]);
            }
            printf("\n\n");
        }
        if(score==safe_zone*7)
        {
       	printf("\t");
        for(j=0;j<grid_size;j++)
        {
    	printf("\t| %d |",j+1);
     	}
    	printf("\n\n");
    
    	for(i=0;i<grid_size;i++)
    	{
	    	printf("\t| %d |\t",i+1);
		    for(j=0;j<grid_size;j++)
		    {
			printf("| %c |\t",value_3[i][j]);
            }
            printf("\n\n");
        }
        	printf("You found all safe zones\n YOU WIN");
        	play_exit();
		}
    }   
    working();
}
//DEFINING THE FUNCTION play_exit()
int play_exit()
{
	bomb=0;
    safe_zone=0;
    do
    {
		
   	//Asking user whether he wants to play again or exit
   	printf("\n\n\nPress 1 to play again\nPress 0 to exit\n\nEnter your choice: ");
   	scanf("%d",&choice);
   	printf("\n");
   	if(choice<0 || choice>1)
   	printf("Your choice is wrong!");
	else if(choice==0)
	printf("\'GOOD BYE\'\n\n");
	if(choice==0)
	return 0;
	else if(choice==1)
	main();
	//selecting_difficulty_level();
    }while(choice>1 || choice<0);
		
}

