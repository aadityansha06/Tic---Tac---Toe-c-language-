#include<stdio.h>
#include<stdlib.h>
char point[9] = {'1','2','3','4','5','6','7','8','9'};
void display(){
   
system("cls");
printf("\n\n");
   printf("\n \t\t%c\t|\t%c\t|\t%c",point[0],point[1],point[2]);
   printf("\n\t\t------------------------------------");
   
   printf("\n \t\t%c\t|\t%c\t|\t%c\n",point[3],point[4],point[5]);
    printf("\t\t------------------------------------\n");
   
   printf(" \t\t%c\t|\t%c\t|\t%c",point[6],point[7],point[8]);
    printf("\n\t\t------------------------------------\n\n\n");
};


int move(int choice,char player1[20],char player2[20]);

int logic();

int main(int argc, char const *argv[])
{
    char player1[20],player2[20] , new;
    int choice=0;
     system("cls");
    printf("Enter player 1 name (x):\t");
    gets(player1);
       printf("Enter player 2 name  (0):\t");
    gets(player2);
   label:
    system("cls");
      
      
      printf("Choose who'll play first:\n '1' for %s and '2' for %s: \t ",player1,player2);
      scanf("%d",&choice);
       printf("\nEnter the box number to put 'x' or '0' \t\n ");
  int win = move(choice,player1,player2);
    if (win==1)
    {
      printf("\n Congrats! %s Won the match",player1);
      printf("\nDo you want to play agin 'y' Or 'n'  ");
      scanf(" %c",&new); // put a \n before %c i also don't know why maybe due to memory takes \n as input or something 
      if (new=='y'|| new == 'Y')
      {
        for (int i = 0; i < 9; i++)
        {
            point[i]= i+'1';
        }
        
          system("cls");
          goto label;
      }
      else{
                printf("\nSee you later %s and %s\n",player1,player2);
          exit(0);
      }
    
    }
    else if(win==0){ // 0 wins
      printf("\n Congrats! %s Won the match",player2);
    printf("\nDo you want to play agin 'y' Or 'n'  ");
      scanf(" %c",&new);
      if (new=='y'|| new == 'Y')
      {
          for (int i = 0; i < 9; i++)
        {
            point[i]= i+'1';
        }
        
          system("cls");
          goto label;
      }else{
        printf("\nSee you later %s and %s\n",player1,player2);
          exit(0);
      }

  }
  
  else{ /// Draw 
         printf("\n Match draw!!");
       printf("\nDo you want to play agin 'y' Or 'n'  ");
      scanf(" %c",&new);
      if (new=='y'|| new == 'Y')
      {
          for (int i = 0; i < 9; i++)
        {
            point[i]= i+'1';
        }
        
          system("cls");
          goto label;
      }
      else{
        printf("\nSee you later %s and %s\n",player1,player2);
          exit(0);
      }

    }
   
    return 0;
}


int move(int choice,char player1[20],char player2[20]){
    int win=-1;

    int  box;
  display();
    int draw=0;
  while (win != 1 && win !=0 )
    {
            
                
         
           if(choice==1){
           
             printf("\n%s's trun : ",player1);
            scanf("%d",&box);
            if (point[box-1]=='x' || point[box-1]=='0' || box>9 || box<1)
            {
              printf("Invalid move :");
              continue;

            
            }
            else{
                   point[box-1] ='x';
                   draw++;
                  choice=0;
                 display();
            }
          


      }else{
          
          printf("\n%s's trun : ",player2);
           scanf("%d",&box);
           if(point[box-1]=='x' || point[box-1]=='0' || box>9 || box<1)
            {
              printf("Invalid move :");
              continue;

              
            }
            else{
                   point[box-1] ='0';
                     draw++;
                   choice=1;
                 display();
            }
            
      }
       
      if (win==-1 && draw==9){
     
       return -1;
    }
    else{
       win = logic();

    }
      

        
    }
    
    

    if (win==1)
    {
      return 1;
    }
    else if(win==0){
       return 0;

    }

    
    
    

};


int logic(){
  
  if (point[0] =='x' && point[4]=='x' && point[8]=='x' || point[2] =='x' && point[4]=='x' && point[6]=='x' 

  || point[0] =='x' && point[1]=='x' && point[2]=='x' || point[3] =='x' && point[4]=='x' && point[5]=='x' 
||point[6] =='x' && point[7]=='x' && point[8]=='x' || point[0] =='x' && point[3]=='x' && point[6]=='x' 
|| point[1] =='x' && point[4]=='x' && point[7]=='x'||point[2] =='x' && point[5]=='x' && point[8]=='x')
  {
    return 1;
  }
  else if (point[0] =='0' && point[4]=='0' && point[8]=='0' || point[2] =='0' && point[4]=='0' && point[6]=='0' 

  || point[0] =='0' && point[1]=='0' && point[2]=='0' || point[3] =='0' && point[4]=='0' && point[5]=='0' 
||point[6] =='0' && point[7]=='0' && point[8]=='0' || point[0] =='0' && point[3]=='0' && point[6]=='0' 
|| point[1] =='0' && point[4]=='0' && point[7]=='0'||point[2] =='0' && point[5]=='0' && point[8]=='0')
  {
    return 0;
  }
  else{
     return -1;
  }
  

  
 
  

};
