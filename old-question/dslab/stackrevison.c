#include<stdio.h>
#include<conio.h>

// new changes kiye h ki codes me hi push(4) krke 4 ko push krskte h
//pushuser foor user input pushes
void push();
void pop();
void display();
int top = -1;
int stack[100];
int size = 100;

void push(int value){
    // int value;
    if(top == size - 1){
        printf("overflow\n"); // Added newline for better readability
    }
    else{
       //printf("enter any value to push in the stack: "); // Corrected prompt
       // scanf("%d", &value);
        top = top + 1;
        stack[top] = value;
    }
}
void pushuser(){
    int value;
    if(top == size - 1){
        printf("overflow\n"); // Added newline for better readability
    }
    else{
       printf("enter any value to push in the stack: "); // Corrected prompt
       scanf("%d", &value);
        top = top + 1;
        stack[top] = value;
    }
}


void display(){
    int i;
    if(top == -1) { // Check if the stack is empty
        printf("Stack is empty\n");
    } 
    else{
        for(i = 0; i <= top; i++) // Changed comma to semicolon
        {
            printf("%d ", stack[i]); // Added space for readability
        }
        printf("\n");
    }
}

void pop(){
    if(top == -1){ // Use '==' for comparison
        printf("underflow\n"); // Added newline for better readability
    }
    else{
        top = top - 1;
    }
}

int main(){
    int choice;

    while(1){

        printf("perform the operation on the stack:\n"); // Added newline for clarity
        printf("press 1 for push, 2 for pop, 3 for display\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push(5);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                 push(4);
                 push(5);
                 display();
            default:
                printf("Invalid choice, please try again.\n"); // Corrected error message
        }
    }
    return 0;
}
