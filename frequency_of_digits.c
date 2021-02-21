#include <stdio.h>
#include <stdlib.h>

int main() {

    int freq[10] = {0}, temp; //freq[10] is the frequency array which will keep track of digit count
    char num[1000];
    
    scanf("%[^\n]s", num); 
    
    //Traverse through the string
    for(int i=0; num[i] != 0; i++) {
        if((atoi(&num[i])) || (num[i] - '0' == 0)) { //Check whether current char is integer or alphabet(atoi converts str to int and returns int)
            temp = num[i] - '0'; 
            freq[temp]++;
        }
    }
    
    for (int i=0; i<10; i++) {
        printf("%d ", freq[i]);
    }
      
    return 0;
}
