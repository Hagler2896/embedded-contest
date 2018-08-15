#include <stdio.h>  
#include <stdlib.h>
#include <term.h>  
#include <termios.h>  
#include <unistd.h>  
#include <sys/time.h> 
#include <time.h>
#include <sys/ioctl.h> 
#include <sys/types.h> 


struct param1
{
    int a;
    int b;
    int c;

};

struct param2
{
    int a;
    int b;
    int c;

};

struct param
{
    struct param1 pr1;
    struct param2 pr2;

};


void gotoxy(int x, int y) {

     printf("\033[%d;%df",y,x);

     fflush(stdout);

}

int getch(void)  
{  
  int ch;  
  struct termios buf;  
  struct termios save;  
  
   tcgetattr(0, &save);  
   buf = save;  
   buf.c_lflag &= ~(ICANON|ECHO);  
   buf.c_cc[VMIN] = 1;  
   buf.c_cc[VTIME] = 0;  
   tcsetattr(0, TCSAFLUSH, &buf);  
   ch = getchar();  
   tcsetattr(0, TCSAFLUSH, &save);  
   return ch;  
}  
  
int main(void)  
{  
    int ch,ch1;  
    int path1,path2;
    struct param pr = {{10,20,30},{40,50,60}};
    while(1){  
        system("clear");
        gotoxy(3,0);
        printf("1. param1");
        gotoxy(3,2);
        printf("2. param2");
        gotoxy(3,3);
        printf("3. param3");
        gotoxy(3,4);
        ch = getch();  // 상 65 하 66
        //printf("%d", ch);  

        if(ch == 49) // 1번 파라미터 선택
        {
            path1 = 1;
            
        }

        else if (ch == 50)  // 2번 파라미터 선택택
        {
            path1 = 2;
        }
            while(1)
            {
                if(path1 == 1)
                {
                    system("clear");
                    gotoxy(3,0);
                    printf("1. 1-1");
                    gotoxy(3,2);
                    printf("2. 1-2");
                    gotoxy(3,3);
                    printf("3. 1-3");

                }

                else if(path1 == 2)
                {
                    system("clear");
                    gotoxy(3,0);
                    printf("1. 2-1");
                    gotoxy(3,2);
                    printf("2. 2-2");
                    gotoxy(3,3);
                    printf("3. 2-3");

                }

                ch = getch();  // 1번 파라미터의 세부 파라미터 선택

                if(ch == 49)    // 1-1번 파라미터 선택
                {
                    path2 = 1;
                }

                else if(ch == 50)   // 1-2번 파라미터 선택
                {
                    path2 = 2;
                }

                else if(ch == 51)   // 1-3번 파라미터 선택
                {
                    path2 = 3;
                }

                else if(ch == 113)
                {
                    break;
                }
                    while(1)
                    {
                        if(path1 == 1 &&path2 == 1) // 1-1번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("value : %d\n",pr.pr1.a);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr.pr1.a++;
                                printf("Param1-1 UP\n");
                            }

                            else if(ch == 66)
                            {
                                pr.pr1.a--;
                                printf("Param1-1 DOWN\n");
                            }
                        }

                        else if(path1 == 1 &&path2 == 2) // 1-2번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("value : %d\n",pr.pr1.b);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr.pr1.b++;
                                printf("Param1-2 UP\n");
                            }

                            else if(ch == 66)
                            {
                                pr.pr1.b--;
                                printf("Param1-2 DOWN\n");
                            }
                        }


                        else if(path1 == 1 &&path2 == 3) // 1-3번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("value : %d\n",pr.pr1.c);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr.pr1.c++;
                                printf("Param1-3 UP\n");
                            }

                            else if(ch == 66)
                            {
                                pr.pr1.c--;
                                printf("Param1-3 DOWN\n");
                            }
                        }


                        else if(path1 == 2 &&path2 == 1) // 2-1번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("value : %d\n",pr.pr2.a);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr.pr2.a++;
                                printf("Param2-1 UP\n");
                            }

                            else if(ch == 66)
                            {
                                pr.pr2.a--;
                                printf("Param2-1 DOWN\n");
                            }
                        }


                        else if(path1 == 2 &&path2 == 2) // 2-2번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("value : %d\n",pr.pr2.b);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr.pr2.b++;
                                printf("Param2-2 UP\n");
                            }

                            else if(ch == 66)
                            {
                                pr.pr2.b--;
                                printf("Param2-2 DOWN\n");
                            }
                        }

                        else if(path1 == 2 &&path2 == 3) // 2-3번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("value : %d\n",pr.pr2.c);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr.pr2.c++;
                                printf("Param2-3 UP\n");
                            }

                            else if(ch == 66)
                            {
                                pr.pr2.c--;
                                printf("Param2-3 DOWN\n");
                            }
                        }

                        ch = getch();
                        if(ch == 113)
                        {
                            break;
                        }

                

                    }
            }
    }
  
    return 0;  
}  

