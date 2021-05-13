#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void boundary();
void position();
void input();
void process();
int width=29,height=29,gameover=0;
int x,y,fruitX,fruitY,score,flag;
int main()
{
	int m,n,a=0;
	position();
	while(!gameover)
	{
	   boundary();
	   input();
	   process(); 
    }
    printf("\nscore= %d",score);
    getch();
	return 0;
}

void boundary()
{
	int i,j;
	system("cls");
	for(i=0;i<width;i++)
	{
		for(j=0;j<height;j++)
		{
			if(i==0||i==height-1||j==0||j==width-1)
			{
				printf("+");
			}
			else
			{
				if(i==x && j==y)
				    printf("O");
				else if(i==fruitX && j==fruitY)
				    printf("*");
				else
			    	printf(" ");
			}
		}
		printf("\n");
	}
}

/*void position()
{
	gameover=0;
	x=width/2;
	y=height/2;
label1:
	fruitX=rand()%20;
	if(fruitX==0)
	   goto label1;
label2:
	fruitY=rand()%20;
	if(fruitY==0)
	    goto label2;
	
	score=0;
}*/

void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'w':
				flag=1;
				break;
			case 'a':
				flag=2;
				break;
			case 's':
				flag=3;
				break;
			case 'd':
				flag=4;
				break;
			case 'x':
				gameover=1;
				break;
		}
	}
}

void process()
{
	switch(flag)
	{
		case 1:
			x--;
			break;
	    case 2:
	    	--y;
	    	break;
	    case 3:
	    	++x;
	    	break;
	    case 4: 
	        y++;
	        break;
	    default:
	    	break;
	}
	if(x<=0||x>=width||y<=0||y>=height)
	{
		gameover=1;
	}
	if(x==fruitX && y==fruitY)
	{
label3:
	fruitX=rand()%20;
	if(fruitX==0)
	   goto label3;
label4:
	fruitY=rand()%20;
	if(fruitY==0)
	    goto label4;  
	score=score+5;
	}
}



