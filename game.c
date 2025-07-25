#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>


char point[9] = {'1','2','3','4','5','6','7','8','9'};
void display(){
   
system("cls");
 printf("\n\t\t*********TIC-TAC-TOE***********\n");
 printf("\n\n\t\tEnter Box number to put 'x' or '0' ");
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
int ai();

int main(int argc, char const *argv[])
{
    char player1[20],player2[20] , new;
    int choice=0,opt;
    display();
    printf("\n 1.Play with Freind\n2.Play with A.I\n Choose the option '1' Or '2'");
    scanf("%d",&opt);
    if (opt==1)
    {
          system("cls");
       printf("Enter player 1 name (x):\t");
  scanf("%s",&player1);
       printf("Enter player 2 name  (0):\t");
   scanf("%s",&player2);
    label:
     system("cls");
        printf("Choose who'll play first:\n '1' for %s and '2' for %s: \t ",player1,player2);
      scanf("%d",&choice);
    }else{
       printf("Enter player 1 name (x):\t");
     scanf("%s",&player1);

     strcpy(player2, "Ai");

      choice =1;
      printf("\n%s will play first\n",player1);

    }
    
    
      
      
   
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
                getchar();
          exit(0);
      }
    
    }
    else if(win==0){ // 0 wins
      if (strcmp(player2,"Ai")==0)
      {
           printf("\n %s Won the match and  you lost %s\n",player2,player1);
      }else{
              printf("\n Congrats! %s Won the match",player2);

      }
      

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
        getchar();
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
             getchar();
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
          
          
          if (strcmp(player2,"Ai")==0)
          {
          
           
            box= ai();

            printf("\nAi played %d\n",box);
            Sleep(1500);

          }
          else{
            printf("\n%s's trun : ",player2);
              scanf("%d",&box);
            
          }
           
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
             
      
      win = logic();
      if (win==-1 && draw==9){
     
       return -1;
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

/*

  there are 3 different loops for Ai ;

  1st is to go through each box and check whthter Ai is winning Or not by playing that move

  2nd to check whether the opponent winning or not by gogin through each box ; if opponent winning block 

  3rd to aquire the all vaild corner boxes to get better edge in the game

  4th if any of the conditon not taking place in the favour of ai then play any valid move 


  Ai will in each box put the 'x' or '0' to check whther its winning or its opponent and then undoing the box by putting point[i]=temp ; temp which contian the boxc number 

  by simple swapng;


*/
int ai(){
 char temp ;
        // Play best possible winning move
  for ( int i = 0; i <9; i++)
  {
    if (point[i]!='x' && point[i]!='0') // check valid move
    {   
    
        temp = point[i];
        point[i]='0';
        if (logic()==0)   // check whether it the logic return 0 or not
        { 
          point[i]=temp;
          
          return i + 1;
        }
         point[i]=temp;
    
  }
  
}
 // Block the opponent 
for (int  i = 0; i < 9; i++)
{
   if (point[i]!='x' && point[i]!='0') {
      temp = point[i];
        point[i]='x';
        if(logic()==1) // check whether it the logic return 1 or not to block the player 
        { 
          point[i]=temp; // undo board
                return i + 1;
        } 

        point[i]=temp;

   }
      
        
       
     // 
     
    
}
  

// check for center 

 if (  point[4]!='x' && point[4]!='0' )
       {
            return 5;
        }

// check for corner box 
int corner[]={0,2,6,8};
 for (int i = 0; i <4; i++)
 {
    int index = corner[i]; 
    if ( point[index]!='x' && point[index]!='0'){
          return index +1;
    }
 }

 // check for side boxes
 int side[]={1,3,5,7};
 for (int i = 0; i <4; i++)
 {
    int index = side[i]; 
    if ( point[index]!='x' && point[index]!='0'){
          return index +1;
    }
 }

 return 1;



}