# include<stdio.h>
# include <conio.h>

int  main() {


    int arr[] = { 1  ,2 ,3,5};

     int n = 4;
        int x = n-1;
        // n = 6 ; hogya 
       for (int i = 0 ; i < n/2 ; i++){
           int temp = arr[i];
           arr[i]=arr[n-i-1];
           arr[n-i-1]=temp;
       }

       for(int i = 0 ; i < n ; i ++){
        printf("%d",arr[i]);
       }
}