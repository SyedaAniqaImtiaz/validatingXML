#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
    int ch, flag = 0, array[100][2], count=0, test=0, t_value = 0;
    while ((ch = getchar()) != EOF) {
        if(!((isalpha(ch)) || (ch == '>') || (ch == '<') || (ch == '/')) || (isupper(ch))){
            //printf("checking for character \n");
            continue;
        }
        
        if((ch == '<') || (ch == '>')){
            //printf("checking for < or > \n");
            continue;
        }
        
        if(ch == '/'){
            flag = 1;
            //printf("checking for / \n");
        }
        
        if(isalpha(ch)){
            //printf("checking for %c \n", ch);
            if(flag == 0){
                push(ch);
                for(int x = 0; x < count; x++){
                    if(array[x][0] == ch){
                        printf("The repeated value is %c \n",array[x][0]);
                        array[x][1]++;
                        test = 1;
                        break;
                    }
                    else{
                        test = 0;
                    }
                }
                if(test == 0){
                    array[t_value][0] = ch;
                    printf("The new value is %c \n", array[t_value][0]);
                    array[t_value][1]++;
                    t_value++;
                }
                count++;
            }
            else{
                flag = 0;
                pop(ch);
                //if(pop(ch) == ch){
                    //count--;
                    //array[count][0] = '\0';
                    //}
                }
            }
        }
    if(isEmpty() == 1){
        printf("Valid \n");
        //printf("%d \n",count);
        //printf("%d \n",t_value);
        for(int i = 0; i < t_value; i++){
        printf("%c  ", array[i][0]);
        printf("%d \n", array[i][1]);
        }
        exit(0);
    }
    
    else{
        printf("NOT Valid \n");
        exit(1);
    }
}

