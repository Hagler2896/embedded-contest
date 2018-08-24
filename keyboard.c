#include <stdio.h>  
#include <stdlib.h>
#include <term.h>  
#include <termios.h>  
#include <unistd.h>  
#include <sys/time.h> 
#include <time.h>
#include <sys/ioctl.h> 
#include <sys/types.h> 

int ch,ch1;  
int path1,path2,path3;


// ---------------------------------------- parameter 구조체 정의 -------------------------
struct point1
{
    int row;
    int col;
};

struct point2
{
    int row;
    int col;
};

struct homography
{
    struct point1 point1;
    struct point2 point2;
};

struct threshhold
{
    int threshhold;

};

struct line_tracking
{
    struct homography homo;
    struct threshhold threshhold;

};

struct sudden_sign
{
    int h;
    int s;
    int v;

};

struct traffic_red
{
    int h;
    int s;
    int v;
};

struct traffic_yellow
{
    int h;
    int s;
    int v;
};

struct traffic_green
{
    int h;
    int s;
    int v;
};

struct traffic_light
{
    struct traffic_red red;
    struct traffic_yellow yellow;
    struct traffic_green green;
};

struct camera_servo_angle
{
    int x;
    int y;
};

struct param
{
    struct line_tracking line;
    struct sudden_sign sudden;
    struct traffic_light traffic;
    struct camera_servo_angle camera;
};


void gotoxy(int x, int y) {

     printf("\033[%d;%df",y,x);

     fflush(stdout);

}

void func(struct param* pr);


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
    struct param pr = {{{ {10,20}, {11,22} } , {30} },{40,50,60}, { {70,80,90} , {10,20,30}, {1,2,3} }, {8,9} };
    func(&pr);
    return 0;  
}  


void func(struct param* pr)
{
        while(1){  
        system("clear");
        gotoxy(3,0);
        printf("1. line_tracking");
        gotoxy(3,2);
        printf("2. sudden_sign");
        gotoxy(3,3);
        printf("3. traffic_light");
        gotoxy(3,4);
        printf("4. camera_servo_angle");
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

        else if (ch == 51)  // 3번 파라미터 선택택
        {
            path1 = 3;
        }

        else if (ch == 52)  // 4번 파라미터 선택택
        {
            path1 = 4;
        }

        else if(ch == 113)  // 종료
        {
            printf("\n");
            return 0; 
        }
            while(1)
            {
                if(path1 == 1)
                {
                    system("clear");
                    gotoxy(3,0);
                    printf("1. Homography");
                    gotoxy(3,2);
                    printf("2. ThreshHold");
                }

                else if(path1 == 2)
                {
                    system("clear");
                    gotoxy(3,0);
                    printf("1. h");
                    gotoxy(3,2);
                    printf("2. s");
                    gotoxy(3,3);
                    printf("3. v");
                }

                else if(path1 == 3)
                {
                    system("clear");
                    gotoxy(3,0);
                    printf("1. traffic_red");
                    gotoxy(3,2);
                    printf("2. traffic_yellow");
                    gotoxy(3,3);
                    printf("3. traffic_green");
                }

                else if(path1 == 4)
                {
                    system("clear");
                    gotoxy(3,0);
                    printf("1. x");
                    gotoxy(3,2);
                    printf("2. y");
                }
                ch = getch();  // 두번째 파라미터 선택

                if(ch == 49)   
                {
                    path2 = 1;
                }

                else if(ch == 50)  
                {
                    path2 = 2;
                }

                else if(ch == 51)   
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
                            label:
                            system("clear");
                            gotoxy(3,0);
                            printf("1. point1");
                            gotoxy(3,2);
                            printf("2. point2");

                            ch = getch();

                            if(ch == 113)
                            {
                                break;
                            }
                            while(1)
                            {
                                
                                if(ch == 49)
                                {
                                    point1:
                                    system("clear");
                                    gotoxy(3,0);
                                    printf("1. Point1_row");
                                    gotoxy(3,2);
                                    printf("2. Point1_col");
                                    path3 = 1;
                                }

                                else if(ch == 50)
                                {
                                    point2:
                                    system("clear");
                                    gotoxy(3,0);
                                    printf("1. Point2_row");
                                    gotoxy(3,2);
                                    printf("2. Point2_col");
                                    path3 = 2;
                                }

                                ch = getch();
                                
                                if(ch == 49 && path1 == 1 && path2 == 1 && path3 == 1)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("Point1_row : %d\n",pr->line.homo.point1.row);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto point1;
                                        }

                                        else if(ch == 65)
                                        {
                                            pr->line.homo.point1.row++;
                                            printf("UP");
                                            gotoxy(3,2);
                                            printf("Point1_row : %d\n",pr->line.homo.point1.row);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->line.homo.point1.row--;
                                            printf("DOWN");
                                            gotoxy(3,2);
                                            printf("Point1_row : %d\n",pr->line.homo.point1.row);
                                        }
                                    }
                                }

                                else if(ch == 50 && path1 == 1 && path2 == 1 && path3 == 1)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("Point1_col : %d\n",pr->line.homo.point1.col);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto point1;
                                        }

                                        else if(ch == 65)
                                        {
                                            pr->line.homo.point1.col++;
                                            printf("UP");
                                            gotoxy(3,2);
                                            printf("Point1_col : %d\n",pr->line.homo.point1.col);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->line.homo.point1.col--;
                                            printf("DOWN");
                                            gotoxy(3,2);
                                            printf("Point1_col : %d\n",pr->line.homo.point1.col);
                                        }
                                    }
                                }
                    
                                else if(ch == 49 && path1 == 1 && path2 == 1 && path3 == 2)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("Point2_row : %d\n",pr->line.homo.point2.row);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto point2;
                                        }

                                        else if(ch == 65)
                                        {
                                            pr->line.homo.point2.row++;
                                            printf("UP");
                                            gotoxy(3,2);
                                            printf("Point2_row : %d\n",pr->line.homo.point2.row);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->line.homo.point2.row--;
                                            printf("DOWN");
                                            gotoxy(3,2);
                                            printf("Point2_row : %d\n",pr->line.homo.point2.row);
                                        }
                                    }
                                }
                                
                                else if(ch == 50 && path1 == 1 && path2 == 1 && path3 == 2)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("Point2_col : %d\n",pr->line.homo.point2.col);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto point2;
                                        }

                                        else if(ch == 65)
                                        {
                                            pr->line.homo.point2.col++;
                                            printf("UP");
                                            gotoxy(3,2);
                                            printf("Point2_col : %d\n",pr->line.homo.point2.col);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->line.homo.point2.col--;
                                            printf("DOWN");
                                            gotoxy(3,2);
                                            printf("Point2_col : %d\n",pr->line.homo.point2.col);
                                        }
                                    }
                                }

                                if(ch == 113)
                                {
                                    goto label;
                                    //break;
                                }
                            }
                        }
                        else if(path1 == 1 &&path2 == 2) // 1-2번 파라미터를 선택했을때
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("ThreshHold_value : %d\n",pr->line.threshhold.threshhold);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr->line.threshhold.threshhold++;
                                printf("UP");
                                gotoxy(3,2);
                                printf("ThreshHold_value : %d\n",pr->line.threshhold.threshhold);
                            }

                            else if(ch == 66)
                            {
                                pr->line.threshhold.threshhold--;
                                printf("DOWN");
                                gotoxy(3,2);
                                printf("ThreshHold_value : %d\n",pr->line.threshhold.threshhold);
                            }
                        }

                        else if(path1 == 2 &&path2 == 1)
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("H : %d\n",pr->sudden.h);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr->sudden.h++;
                                printf("UP\n");
                                gotoxy(3,2);
                                printf("value : %d\n",pr->sudden.h);
                            }

                            else if(ch == 66)
                            {
                                pr->sudden.h--;
                                printf("DOWN\n");
                                gotoxy(3,2);
                                printf("value : %d\n",pr->sudden.h);
                            }
                        }

                        else if(path1 == 2 &&path2 == 2)
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("S : %d\n",pr->sudden.s);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr->sudden.s++;
                                printf("UP\n");
                                gotoxy(3,2);
                                printf("value : %d\n",pr->sudden.s);
                            }

                            else if(ch == 66)
                            {
                                pr->sudden.s--;
                                printf("DOWN\n");
                                gotoxy(3,2);
                                printf("value : %d\n",pr->sudden.s);
                            }
                        }

                        else if(path1 == 2 &&path2 == 3)
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("V : %d\n",pr->sudden.v);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr->sudden.v++;
                                printf("UP\n");
                                gotoxy(3,2);
                                printf("value : %d\n",pr->sudden.v);
                            }

                            else if(ch == 66)
                            {
                                pr->sudden.v--;
                                printf("DOWN\n");
                                gotoxy(3,2);
                                printf("value : %d\n",pr->sudden.v);
                            }
                        }

                        else if(path1 == 3 &&path2 == 1)
                        {
                                traffic_red:
                                system("clear");
                                gotoxy(3,0);
                                printf("1. traffic_red_H");
                                gotoxy(3,2);
                                printf("2. traffic_red_S");
                                gotoxy(3,3);
                                printf("3. traffic_red_V");

                                ch = getch();

                                if(ch == 49)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_red_H : %d\n",pr->traffic.red.h);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_red;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.red.h++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_red_H : %d\n",pr->traffic.red.h);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.red.h--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_red_H : %d\n",pr->traffic.red.h);
                                        }
                                    }
                                }

                                else if(ch == 50)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_red_S : %d\n",pr->traffic.red.s);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_red;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.red.s++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_red_S : %d\n",pr->traffic.red.s);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.red.s--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_red_S : %d\n",pr->traffic.red.s);
                                        }
                                    }
                                }

                                else if(ch == 51)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_red_V : %d\n",pr->traffic.red.v);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_red;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.red.v++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_red_V : %d\n",pr->traffic.red.v);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.red.v--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_red_V : %d\n",pr->traffic.red.v);
                                        }
                                    }
                                }
                        }

                        else if(path1 == 3 &&path2 == 2)
                        {
                                traffic_yellow:
                                system("clear");
                                gotoxy(3,0);
                                printf("1. traffic_yellow_H");
                                gotoxy(3,2);
                                printf("2. traffic_yellow_S");
                                gotoxy(3,3);
                                printf("3. traffic_yellow_V");

                                ch = getch();

                                if(ch == 49)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_yellow_H : %d\n",pr->traffic.yellow.h);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_yellow;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.yellow.h++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_yellow_H : %d\n",pr->traffic.yellow.h);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.yellow.h--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_yellow_H : %d\n",pr->traffic.yellow.h);
                                        }
                                    }
                                }

                                else if(ch == 50)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_yellow_S : %d\n",pr->traffic.yellow.s);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_yellow;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.yellow.s++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_yellow_S : %d\n",pr->traffic.yellow.s);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.yellow.s--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_yellow_S : %d\n",pr->traffic.yellow.s);
                                        }
                                    }
                                }

                                else if(ch == 51)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_yellow_V : %d\n",pr->traffic.yellow.v);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_yellow;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.yellow.v++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_yellow_V : %d\n",pr->traffic.yellow.v);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.yellow.v--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_yellow_V : %d\n",pr->traffic.yellow.v);
                                        }
                                    }
                                }
                        }

                        else if(path1 == 3 &&path2 == 3)        // traffic_green
                        {
                                traffic_green:
                                system("clear");
                                gotoxy(3,0);
                                printf("1. traffic_green_H");
                                gotoxy(3,2);
                                printf("2. traffic_green_S");
                                gotoxy(3,3);
                                printf("3. traffic_green_V");

                                ch = getch();

                                if(ch == 49)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_green_H : %d\n",pr->traffic.green.h);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_green;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.green.h++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_green_H : %d\n",pr->traffic.green.h);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.green.h--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_green_H : %d\n",pr->traffic.green.h);
                                        }
                                    }
                                }

                                else if(ch == 50)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_green_S : %d\n",pr->traffic.green.s);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_green;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.green.s++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_green_S : %d\n",pr->traffic.green.s);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.green.s--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_green_S : %d\n",pr->traffic.green.s);
                                        }
                                    }
                                }

                                else if(ch == 51)
                                {
                                    while(1)
                                    {
                                        system("clear");
                                        gotoxy(3,0);
                                        printf("UP / DOWN\n");
                                        gotoxy(3,2);
                                        printf("traffic_green_V : %d\n",pr->traffic.green.v);
                                        gotoxy(3,3);

                                        ch = getch();

                                        if(ch == 113)
                                        {
                                            goto traffic_green;
                                        }
                                        
                                        else if(ch == 65)
                                        {
                                            pr->traffic.green.v++;
                                            printf("UP\n");
                                            gotoxy(3,2);
                                            printf("traffic_green_V : %d\n",pr->traffic.green.v);
                                        }

                                        else if(ch == 66)
                                        {
                                            pr->traffic.green.v--;
                                            printf("DOWN\n");
                                            gotoxy(3,2);
                                            printf("traffic_green_V : %d\n",pr->traffic.green.v);
                                        }
                                    }
                                }
                        }
                
                        else if(path1 == 4 &&path2 == 1)
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("camera_sevo_X : %d\n",pr->camera.x);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr->camera.x++;
                                printf("UP\n");
                                gotoxy(3,2);
                                printf("camera_sevo_X : %d\n",pr->camera.x);
                            }

                            else if(ch == 66)
                            {
                                pr->camera.x--;
                                printf("DOWN\n");
                                gotoxy(3,2);
                                printf("camera_sevo_X : %d\n",pr->camera.x);
                            }
                        }

                        else if(path1 == 4 &&path2 == 2)
                        {
                            system("clear");
                            gotoxy(3,0);
                            printf("UP / DOWN\n");
                            gotoxy(3,2);
                            printf("camera_servo_Y : %d\n",pr->camera.y);
                            gotoxy(3,3);

                            if(ch == 65)
                            {
                                pr->camera.y++;
                                printf("UP\n");
                                gotoxy(3,2);
                                printf("camera_servo_Y : %d\n",pr->camera.y);
                            }

                            else if(ch == 66)
                            {
                                pr->camera.y--;
                                printf("DOWN\n");
                                gotoxy(3,2);
                                printf("camera_servo_Y : %d\n",pr->camera.y);
                            }
                        }

                        ch = getch();

                        if (ch == 49)
                        {
                            path3 = 1;
                        }

                        else if (ch == 50)
                        {
                            path3 = 2;
                        }

                        else if(ch == 113)
                        {
                            break;
                        }

                

                    }
            }
    }

}
