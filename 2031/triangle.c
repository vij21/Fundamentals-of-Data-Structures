#include<stdio.h>

int main(){

	int noR;
	//promt the user to enter the number of rows 
    printf("Enter the number of rows in the triangle: ");
	scanf("%d",&noR);
	
	int row, colSpace, colStar;
	for(row=1;row<=noR;row++){
	
	//printing spaces between the stars 
	for(colStar=row;colStar<noR;colStar++){
	printf(" ");
	
		}
	for(colStar=1;colStar<=(2*row-1);colStar++){
	
        
            /*
             * Print star for last row (i==rows),
             * first column(j==1) and for
             * last column (j==(2*i-1)).
             */ 
             
             //prints the stars for first last and last row 
            if(row==noR || colStar==1 || colStar==(2*row-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
	}
	        printf("\n");



}
return 0;
}