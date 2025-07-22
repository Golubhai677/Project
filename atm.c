#include<stdio.h>
void main(){
    //char name;
    int password=582020,balance=2000,i=1 ,pin,a,b ;
    //printf("Enter the customer name");
    //scanf("%s",&name);
   
while (i<=3)
{
    printf("Enter the password");
    scanf("%d",&pin);
    if (pin==password){
        printf("1.withdrawal 2.balance");
        scanf("%d",&a);
        if (a==1){
            printf("Enter withdrawl amount");
            scanf("%d",&b);
            if (b <=balance){
                printf("Withdrawal successful");
                break;
            }
            else {
                printf("Insufficient Balance");
                break;
            }
        }
        else {
            printf("Balance=%d",balance);
            break;
        }
    }
    else {
        printf("Password incorrect\n");
        }
    i++;
}
if ( i>3){
    printf("Card blocked");
}
}

