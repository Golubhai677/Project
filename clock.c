#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    int hour=0,minute=0,second=0;
    printf("Enter time (hh mm ss): ");
    scanf("%d%d%d",&hour,&minute,&second);
    printf("\n");

    while(hour>0||minute>0||second>0){
        printf("\r%02d:%02d:%02d ",hour,minute,second);
        Sleep(1000);
        if(second==0){
            if(minute==0){
                if(hour==0){
                    break;
                }
                else{
                    hour--;
                    minute=59;
                    second=59;
                }
            }
            else{
                minute--;
                second=59;
            }
        }
        else{
            second--;
        }
    }
    printf("\r00:00:00 \n");
    printf("Time's up!");
    Beep(700,300);

    return 0;
}