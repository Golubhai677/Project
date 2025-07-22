#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
void display();
void back();
void coundown();
FILE *fptr;
int count = 0;

int main() {
    printf("\n\t\t\033[48;2;255;50;255;38;2;100;255;100;1;3mFor Better experience use full screen mode \033[0m");
    //printf("\n\t\t\033[38;2;0;200;0mFor Better experience use full screen mode \033[0m");
    Sleep(2000);
    display();
    back();
    return 0;
}

void display() {
    int j=0,p,sp=0, i = 0, w_marks = 0, marks = 0,wd_marks=0;
    char par[256],u_word[256], ch,backsp_remove;   /*in u_word assuming max word will 50 and each word max length will 20 */
    //char *word;
    double time_taken=0,total_time_taken=0;
    int len_word,k;
    time_t start,end;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL) {
        fptr = fopen("data.txt", "w");  // Create if not exist
        fclose(fptr);
        printf("\nNo data found.\n");
        return;
    }

    printf("\nHow many paragraph do you want to type: ");
    scanf("%d", &p);

    // Clear input buffer after scanf
    while ((ch = getchar()) != '\n' && ch != EOF);

    while ((fgets(par, sizeof(par), fptr)) != NULL && count < p) {
        if(count==p){
            break;
        }
        else{
            printf("\n\e[33m%s\n\e[0m", par);  // Yellow paragraph
            par[strcspn(par, "\n")] = '\0';
            //word = strtok(par," ");
                len_word=strlen(par);
                //word[strlen(word)+1]=' ';
                coundown("5");
                for(k=0;k<len_word;k++){
                    mis:
                    time(&start);                       /*this measure starting time*/
                    u_word[k]=getch();
                    time(&end);                       /*this measure ending time*/
                    time_taken=difftime(end,start);       /*check time between user start typing and end typing and 1- is for reduce time */
                    total_time_taken += time_taken;         /*Total time of user input*/
                    backsp_remove=u_word[k];
                    if(backsp_remove == 8){             /*this line is for backspace remove*/
                        goto mis;
                    }
                    if(par[k]==u_word[k]) {
                        marks++;
                        // marks=marks+(strlen(word));
                        // wd_marks++;
                        printf("\e[32m%c\e[0m", u_word[k]);  // Green = correct
                    }
                    else {
                        printf("\e[31m%c\b\e[0m", u_word[k]); // Red = incorrect
                        w_marks++; 
                        goto mis;
                    }
                }
            }
           

        count++;
        // printf("\n");
        
    }
    printf("\n\n\e[34mTotal correct letter is:%d\nTotal incorrect Word is:%d",marks,w_marks);

    printf("\nLetter Per Second: %.2f L/s",marks/total_time_taken);
    printf("\nWord Per Minute: %.2f W/m\e[0m",(marks/5)/(total_time_taken/60));
    //rewind(fptr);
    fclose(fptr);
}

void back(){
    char a[]="\n\t\e[1;36m  ========================================\e[0m";
    char b[]="\n\t\e[1;33m  * T H A N K   Y O U   F O R   U S I N G *\e[0m";
    char c[]="\n\t\e[1;32m   --- Developed by: G O L U   B H A I ---\e[0m";
    char d[]="\n\t\e[1;35m  ========================================\e[0m";
    char e[]="\n\t\e[1;31m            *** THE END ***            \e[0m";
    for(int i=0; i<sizeof(a); i++){
        printf("%c",a[i]);
        Sleep(25);
    }
    Sleep(150);
    for(int i=0; i<sizeof(b); i++){
        printf("%c",b[i]);
        Sleep(25);
    }
    Sleep(150);
    for(int i=0; i<sizeof(c); i++){
        printf("%c",c[i]);
        Sleep(25);
    }
    Sleep(150);
    for(int i=0; i<sizeof(d); i++){
        printf("%c",d[i]);
        Sleep(25);
    }
    Sleep(150);
    for(int i=0; i<sizeof(e); i++){
        printf("%c",e[i]);
        Sleep(25);
    }
    Sleep(150);
}
void coundown(const char *number){
    char local[20];
    strcpy(local,number);
    /* Predifine 0-9 number in ASCII Art */
    char *pattern[][3] = {
        {" _ ", "| |", "|_|"},  // 0
        {"   ", "  |", "  |"},  // 1
        {" _ ", " _|", "|_ "},  // 2
        {" _ ", " _|", " _|"},  // 3
        {"   ", "|_|", "  |"},  // 4
        {" _ ", "|_ ", " _|"},  // 5
        {" _ ", "|_ ", "|_|"},  // 6
        {" _ ", "  |", "  |"},  // 7
        {" _ ", "|_|", "|_|"},  // 8
        {" _ ", "|_|", " _|"}   // 9
    };

    /*
        i,j = loop control and value accessing.
        num = the actual integer taken from user.
        row = how many row goes to print in this case no of row is 3.
        digit = which charector goes to print i.e 4 It may diffrent.
    */
    int i,j,num,row,digit;

   /* convert into integer from sting */
    sscanf(local,"%d",&num);
    printf("\033[?25l\n\033");
    /* printing process start from here */
    for(j=num; j>=0;j--){   /* Loop run until num != 0 */

        if(num<3) printf("\033[1;31m");
        else if(num<5) printf("\033[1;33m");
        else printf("\033[32m");
        
        for(row=0; row<3; row++){   /* Access each row one by one */
            printf("\t\t\t\t\t\t\t\t\t");

            for(i=0; i<strlen(local); i++){    /* Print Art acording to row and digit */
                digit=local[i]-'0';
                /* store fist,second,third...integer from a local */
                printf("%s",pattern[digit][row]);/* print Art acording to row */

            }

            printf("\n");

        }

        num--;  /* num decreses by 1 everytime */
        sprintf(local,"%d",num);
        // /* update the integer local in string */
        Sleep(1000);    /* hold for 1 sec */
        printf("\033[3A\033[0J");
    }
    printf("\033[?25h\033[0m");
}
