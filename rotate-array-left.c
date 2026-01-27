// User function Template for C
// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(int arr[], int n, int d) {
    // code here
    
    d= d%n;
    if (d == 0) return;
    
    int temp[d];
    for ( int i = 0 ; i < d ; i++){
        temp[i] = arr[i];
    }
    
    for (int i = d ;i <n; i++){
        arr[i-d] = arr[i];
        
    }
    for ( int i = n-d ; i<n;i++){
        arr[i]=temp[i-(n-d)];
    }

    for ( int i =0 ; i < n ; i++){
        printf("%d",arr[i]);
    }
    
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int d = 2;
    int n = sizeof arr / sizeof arr[0];
    rotateArr(arr,n,d);


}