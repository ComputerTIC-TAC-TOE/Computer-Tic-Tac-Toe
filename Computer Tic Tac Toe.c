#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
char s[3][3];
int x,y;
void Display()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%2c ",s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void User(char user)
{
    int j;
    printf("Enter your position now. : ");
    scanf("%d",&x);
    while(*(s[0]+x-1)!='_')
    {
        printf("This position is already in use.\nPlease enter another position. : ");
        scanf("%d",&x);
        j=0;
        continue;
    }
    *(s[0]+x-1) = user;
}
void Comp(char comp,char user)
{
    int j,k=0;
    printf("Wait the computer is making its move.\n");
    Sleep(1000);
    for(j=0;j<3;j++)
    {

        if(s[j][0]==user && s[j][1]==user && s[j][2]!=comp && s[j][2]!=user && k==0)
        {
            s[j][2] = comp;
            k=1;
            break;
        }
        else if(s[j][0]==user && s[j][2]==user && s[j][1]!=comp && s[j][1]!=user && k==0)
        {
            s[j][1] = comp;
            k=1;
            break;
        }
        else if(s[j][1]==user && s[j][2]==user && s[j][0]!=comp && s[j][0]!=user && k==0)
        {
            s[j][0] = comp;
            k=1;
            break;
        }
        else if(s[0][j]==user && s[1][j]==user && s[2][j]!=comp && s[2][j]!=user && k==0)
        {
             s[2][j] = comp;
             k=1;
             break;
        }
        else if(s[0][j]==user && s[2][j]==user && s[1][j]!=comp && s[1][j]!=user && k==0)
        {
             s[1][j] = comp;
             k=1;
             break;
        }
        else if(s[1][j]==user && s[2][j]==user && s[0][j]!=comp && s[0][j]!=user && k==0)
        {
             s[0][j] = comp;
             k=1;
             break;
        }
    }
    for(j=0;j<3;j++)
    {
        if(s[0][j]==comp && s[1][j]==comp && s[2][j]!=comp && s[2][j]!=user && k==0)
        {
            s[2][j]=comp;
            k=1;
            break;
        }
        else if(s[0][j]==comp && s[2][j]==comp && s[1][j]!=comp && s[1][j]!=user && k==0)
        {
            s[1][j]=comp;
            k=1;
            break;
        }
        else if(s[1][j]==comp && s[2][j]==comp && s[0][j]!=user && s[0][j]!=user && k==0)
         {
             s[0][j]=comp;
             k=1;
             break;
         }
        else if(s[j][0]==comp && s[j][1]==comp && s[j][2]!=user && s[j][2]!=comp && k==0)
          {
             s[j][2]=comp;
             k=1;
             break;
          }
        else if(s[j][0]==comp && s[j][2]==comp && s[j][1]!=comp && s[j][1]!=user && k==0)
          {
             s[j][1]=comp;
             k=1;
             break;
          }
        else if(s[j][1]==comp && s[j][2]==comp && s[j][0]!=comp && s[j][0]!=user && k==0)
           {
             s[j][0]=comp;
             k=1;
             break;
           }
    }
    if(s[0][0]==comp && s[1][1]==comp && s[2][2]=='_' && k==0)
     {
         s[2][2]=comp;
         k=1;
     }
    else if(s[0][0]==comp && s[2][2]==comp && s[1][1]=='_' && k==0)
      {
         s[1][1]=comp;
         k=1;
      }
    else if(s[2][2]==comp && s[1][1]==comp && s[0][0]=='_' && k==0)
        {
            s[0][0]=comp;
            k=1;
        }
    else if(s[0][3]==comp && s[1][1]==comp && s[2][0]=='_' && k==0)
       {
         s[2][0]=comp;
         k=1;
       }
    else if(s[0][0]==comp && s[2][0]==comp && s[1][1]=='_' && k==0)
       {
            s[1][1]=comp;
            k==1;
       }
    else if(s[2][0]==comp && s[1][1]==comp && s[0][2]=='_' && k==0)
       {
         s[0][2]=comp;
         k=1;
       }
    if(s[0][0]==user && s[1][1]==user && s[2][2]=='_' && k==0)
     {
         s[2][2]=comp;
         k=1;
     }
    else if(s[0][0]==user && s[2][2]==user && s[1][1]=='_' && k==0)
      {
         s[1][1]=comp;
         k=1;
      }
    else if(s[2][2]==user && s[1][1]==user && s[0][0]=='_' && k==0)
        {
            s[0][0]=comp;
            k=1;
        }
    else if(s[0][3]==user && s[1][1]==user && s[2][0]=='_' && k==0)
       {
         s[2][0]=comp;
         k=1;
       }
    else if(s[0][0]==user && s[2][0]==user && s[1][1]=='_' && k==0)
       {
            s[1][1]=comp;
            k==1;
       }
    else if(s[2][0]==user && s[1][1]==user && s[0][2]=='_' && k==0)
       {
         s[0][2]=comp;
         k=1;
       }
    if(k==0)
    {
        srand(time(0));
        y = (rand()%(8-1+1))+1;
        while(*(s[0]+y-1)!='_')
        {
            srand(time(0));
            y = (rand()%(8-1+1))+1;
        }
        *(s[0]+y-1)=comp;
    }
}
int winner (char X,char Y)
{
    int i;
    if((s[0][0]==X && s[0][1]==X && s[0][2]==X) || (s[1][0]==X && s[1][1]==X && s[1][2]==X) || (s[2][0]==X && s[2][1]==X && s[2][2]==X) || (s[0][0]==X && s[1][0]==X && s[2][0]==X) || (s[0][1]==X && s[1][1]==X && s[2][1]==X)||(s[0][2]==X &&s[1][2]==X && s[2][2]==X))
        return 2;
    else if((s[0][0]==Y && s[0][1]==Y && s[0][2]==Y) || (s[1][0]==Y && s[1][1]==Y && s[1][2]==Y) || (s[2][0]==Y && s[2][1]==Y && s[2][2]==Y) || (s[0][0]==Y && s[1][0]==Y && s[2][0]==Y) || (s[0][1]==Y && s[1][1]==Y && s[2][1]==Y)||(s[0][2]==Y && s[1][2]==Y && s[2][2]==Y))
        return 1;
    else if((s[0][0]==X && s[1][1]==X && s[2][2]==X)||(s[0][2]==X && s[1][1]==X && s[2][0]==X))
        return 2;
    else if((s[0][0]==Y && s[1][1]==Y && s[2][2]==Y)||(s[0][2]==Y && s[1][1]==Y && s[2][0]==Y))
        return 1;
    else{
        int i,j=0;
        for(i=0;i<9;i++)
        {
            if(*(s[0]+i)=='_')
                j++;
        }
        if(9-j==9)
            return 3;
        else
            return 0;
    }
}
void winnerList(int l,char *me,char *you){
    static int i=0;
    int j,k,m;
    char name[100][3][100];
    strcpy(name[i][0],me);
    strcpy(name[i][1],you);
    i++;
    printf("LEADERBOARD ------------------------||||||||||||||||||||||||||||||\n\n");
    printf("Player 1                      Player 2                      Winner\n\n");
    for(j=0;j<i;j++)
    {
        for(k=0;k<3;k++)
        {
            if(k==2 && j==i-1)
            {
                if(l==1)
                {
                    strcpy(name[j][2],name[j][1]);
                    printf("%s",name[j][1]);
                }
                else if(l==2)
                {
                    strcpy(name[j][2],name[j][0]);
                    printf("%s",name[j][0]);
                }
                else
                {
                     name[j][2][0]='T';
                     name[j][2][1]='i';
                     name[j][2][2]='e';
                     printf("%s",name[j][2]);
                }
             }
             else
                printf("%-30s",name[j][k]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    char ch,comp,user,user2,c,A,Y;
    int i,k=0,a,b,d,l=0;
    do{
    system("cls");
    printf("||||||||||||||||||||||||----------------------- Computer Tic-Tac-Toe ------------------------||||||||||||||||||||||||||\n\n");


    printf("    You are alone. Drifting through space. Your ship is losing power and you are waiting to die. With only a few\n");
    printf("    hours left, you decide to boot up the old games computer and figure why not spend your few remaining moments.\n\n");

    printf("    You can play either with a FRIEND or the COMPUTER.\n\n");

    printf("    Let the fun begin...\n\n");

    printf("    To start the game Press ENTER. :\n\n ");
    scanf("%c",&ch);
    printf("\n");
    printf("The Board Layout...\n");
    int j;
    char d='1';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            s[i][j]=d;
            d++;
        }
    }
    Display();
    printf("Computer Tic Tac Toe board activated.\n");
    for(i=0;i<9;i++)
    {
        *(s[0]+i)='_';
    }
    Display();
    printf("PRESS '*' to play with a SECOND PLAYER or PRESS 'C' to play with the COMPUTER.\n");
    scanf(" %c",&user2);
    if(user2=='C' || user2=='c')
    {
        char me[100],you[]={"Computer"};
        printf("Enter your USER name : ");
        fflush(stdin);
        gets( me);
        printf("Make your selection of either X or O : ");
        scanf(" %c",&user);
        if(user == 'X')
            comp = 'O';
        else
            comp = 'X';
        printf("\nPress 1 to do the Coin Toss for who will start the game.\nPress 2 To allow the computer to start.\nMake your selection now. : ");
        scanf("%d",&a);
        printf("\n");
        if(a==1)
        {
            srand(time(0));
            b = (rand()%(2-1+1))+1;
            if(b==1)
            {
                printf("You have won the Coin Toss.\n");
                printf("Enter your position according to the board. : ");
                scanf("%d",&x);
                *(s[0]+x-1)=user;
                Display();
                printf("Wait the computer is making its move.\n");
                Sleep(1000);
                srand(time(0));
                y = (rand()%(8-1+1))+1;
                while(y==x)
                {
                    srand(time(0));
                    y = (rand()%(8-1+1))+1;
                }
                *(s[0]+y-1)=comp;
                Display();
            }
            else
            {
                printf("The Computer has won the Coin Toss.\n");
                srand(time(0));
                y = (rand()%(8-1+1))+1;
                *(s[0]+y-1)=comp;
                Display();
                printf("Enter your position according to the board. : ");
                scanf("%d",&x);
                while(x==y)
                {
                    printf("This position is taken already.\nEnter another position now. : ");
                    scanf("%d",&x);
                    continue;
                }
                *(s[0]+x-1)=user;
                Display();
            }
        }
        else if(a==2)
        {
            printf("You choose to start first.\n");
            srand(time(0));
            y = (rand()%(8-1+1))+1;
            *(s[0]+y-1)=comp;
            Display();
            printf("Enter your position according to the board. : ");
            scanf("%d",&x);
            while(x==y)
            {
                printf("This position is taken already.\nEnter another position now. : ");
                scanf("%d",&x);
                continue;
            }
            *(s[0]+x-1)=user;
            Display();
        }
        else{
            printf("You have decided to start first.\n");
            printf("Enter your position according to the board now. : ");
            scanf("%d",&x);
            *(s[0]+x-1)=user;
            Display();
            printf("Wait the computer is making its move.\n");
            Sleep(1000);
            srand(time(0));
            y = (rand()%(8-1+1))+1;
            while(y==x)
            {
                srand(time(0));
                y = (rand()%(8-1+1))+1;
            }
            *(s[0]+y-1)=comp;
            Display();
        }
        while(l==0)
        {
            if(b==1)
            {
                User(user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
                Comp(comp,user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
            }
            else{
                Comp(comp,user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
                User(user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
            }
        }

        if(l==1)
            printf("%s wins the game.\n",you);
        else if(l==2)
            printf("%s wins the game.\n",me);
        else
            printf("The match is a tie.\n");
        printf("Press the ENTER KEY to continue. : ");
        fflush(stdin);
        scanf("%c",&Y);
        if(Y=='L' || Y=='l');
            winnerList(l,me,you);
    }
    else if(user2=='*')
    {
        char me[100],you[100];
        printf("Enter the name of the first player. : ");
        fflush(stdin);
        gets( me);
        printf("Enter the name of the second player. : ");
        fflush(stdin);
        gets( you);
        printf("\nChoose your piece ( O or X ) respective to the first player. : ");
        scanf(" %c",&user);
        if(user=='X' || user=='x')
            comp = 'O';
        else if(user=='O' || user=='o')
            comp = 'X';
        else
            printf("\nPlease choose either X or O to play.\n");
        printf("Please enter any single digit to do the coin toss now. : ");
        fflush(stdin);
        scanf("%c",&A);
        printf("\n");
        srand(time(0));
        b = (rand()%(2-1+1))+1;
        if(b==1)
        {
            printf("%s won the coin toss.\n",me);
            while(l==0)
            {
                printf("%s Enter your position according to the board. : ",me);
                scanf("%d",&x);
                while(*(s[0]+x-1)!='_')
                {
                    printf("Sorry this position is already taken.\nPlease pick another position.\n");
                    scanf("%d",&x);
                }
                *(s[0]+x-1)=user;
                Display();
                l=winner(user,comp);
                if(l!=0)
                    break;
                printf("%s Enter your position according to the board now. : ",you);
                scanf("%d",&y);
                while(*(s[0]+y-1)!='_')
                {
                    printf("Sorry this position is already taken.\nPlease pick another position.\n");
                    scanf("%d",&y);
                }
                *(s[0]+y-1)=comp;
                Display();
                l= winner(user,comp);
                if(l!=0)
                    break;
            }
            if(l==1 || l==2 || l==3)
            {
                if(l==1)
                    printf("%s wins the game.\n",you);
                else if(l==2)
                    printf("%s wins the game.\n",me);
                else
                    printf("The match is tie.\n");
                printf("Press the ENTER KEY to continue. : ");
                fflush(stdin);
                scanf("%c",&Y);
                if(Y=='L' || Y=='l');
                    winnerList(l,me,you);
            }
        }
    }
    else
        printf("Please choose the correct option.\n\n");
    printf("Press the Y KEY to play again or N to quit.\n");
    fflush(stdin);
    scanf(" %c",&c);
    l=0;
    }while(c=='Y' || c=='y');
    return 0;
}
