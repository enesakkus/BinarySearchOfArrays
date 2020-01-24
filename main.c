#include<stdio.h>

#define SIZE 15

void printHeader(void);
int searchArray(int a[], int low, int high, int searchKey);
void printRow(int a[], int low, int middle, int high);

int main(){

    size_t i;
    int a[SIZE];
    int searchKey;
    int result;

    printf("Welcome to binary search program...\n"
           "Please enter a number between 0 and 28: ");
    scanf("%d", &searchKey);

    for(i = 0; i < SIZE; i++){
        a[i] = 2 * i;
    }

    printHeader();

    result = searchArray(a, 0, SIZE-1, searchKey);

    if(result != -1){
        printf("\n%d found in array element %d\n", searchKey, result);
    }
    else{
        printf("\n%d not found\n", searchKey);
    }
}

int searchArray(int a[], int low, int high, int searchKey){

    int middle;

    while(low <= high){

        middle = (low + high) / 2;
        printRow(a, low, middle, high);

        if(searchKey == a[middle]){
            return middle;
        }
        else if(searchKey < a[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    return -1;
}

void printRow(int a[], int low, int middle, int high){

    size_t i;

    for(i = 0; i < SIZE; i++){
        if(i < low || i > high){
            printf("%s", "   ");
        }
        else if( i == middle){
            printf("%3d*", a[i]);
        }
        else{
            printf("%3d", a[i]);
        }
    }
    puts("");
}

void printHeader(void){

    size_t i;

    puts("\nSubscripts:");

    for(i = 0; i < SIZE; i++){
        printf("%3u", i);
    }
    puts("");
    for(i = 0; i <= SIZE * 4; i++){
        printf("%s", "-");
    }
    puts("");
}
