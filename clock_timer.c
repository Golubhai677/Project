#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main(){
    int hour=0,minute=0,second=0;
    int running=0;
    char ch;
    printf("Press Enter to start/pause, and 'q' then Enter to quit.\n");

    while(1){
        if(_kbhit()){
            ch=getch();
            if(ch==13){
                running=!running;
            }
            else if(ch=='q'||ch=='Q'){
                break;
            }
        }
        if(running){
            printf("\r%02d:%02d:%02d ",hour,minute,second);
            Sleep(1000);
            second++;
            if(second==60){
                minute++;
                second=0;
                if(minute==60){
                    hour++;
                    minute=0;
                    if(hour==24){
                        hour=0;
                    }
                }
            }
        }else{
            printf("\r%02d:%02d:%02d ",hour,minute,second);
            Sleep(100);
        }
    }
    printf("\nStopwatch stopped.\n");

    return 0;
}