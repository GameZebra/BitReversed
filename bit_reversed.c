#include<stdio.h>
#include<math.h>

void bitReversedV01(int num[], int length);
void bitReversedV02(char *num);
void bitReversedV03(char *num, int bits);
void bitReversedV04(char *num, int bits);
int bitMask(int start, int pattern,int bits);

int main(){
    printf("Bit  Reversed\n");

    // biray number input
    // int binaryLength = 4;
    // int num1[binaryLength];
    // for(int i = 0; i<4; i++){
    //     scanf("%d", &num1[i]);
    // }

    // bitReversedV01(num1, binaryLength);

    //v02 - v05 
    // just swap the number in the function and it will work
    unsigned char b = 0b00101011;
    printf("%d\n", b);
    bitReversedV04(&b,8);
    printf("%d", b);
    
}


void bitReversedV01(int num[], int length){
    //v01
    int swap = 0;
    for(int i = 0; i<length/2; i++){
        swap = num[i];
        num[i] = num[length-1-i];
        num[length-1-i] = swap;
    }
    for(int i =0; i<length; i++){
        printf("%d", num[i]);
    }
    printf("\n");
    
}
void bitReversedV02(char *num){
    // I thought it was cool because it didn't use memory for the swap
    // but it probbably does here (*num & 0xAA) >> 1)
    // this algorithm works only for (2^n) number of bits 
    *num = ((*num & 0xAA) >> 1) | ((*num & 0x55) << 1);
    *num = ((*num & 0xCC) >> 2) | ((*num & 0x33) << 2);
    *num = ((*num & 0xF0) >> 4) | ((*num & 0x0F) << 4);
}

void bitReversedV03(char *num, int bits){
    // this was my attempt to make the algorithm from above dinamic 
    // for different number of (2^n) bits  
    for(int i = 0; i < bits/2 -1; i++){
            *num = ((*num & bitMask(1, (int)pow(2,i), bits)) >> (int)pow(2, i)) | ((*num & bitMask(0, (int)pow(2,i), bits)) << (int)pow(2, i));
    }
}
void bitReversedV04(char *num, int bits){
    // here I swaped the pow() with faster algorithm
    *num = ((*num & bitMask(1, 1, bits)) >> 1 | ((*num & bitMask(0, 1, bits)) << 1));
    for(int i = 0; i < bits/2 -2; i++){
        int pattern = (int)(2<<i); 
        *num = (((*num & bitMask(1, pattern, bits))) >> pattern) | (((*num & bitMask(0, pattern, bits)) << pattern));
    }
}

int bitMask(int start, int pattern, int bits){
    // returns bitMask with sequential zeros and ones
    // start    - the value of the Most Segnificant Bit 0 or 1
    // pattern  - the number of sequential ones or zeros
    // bits     - the size of the mask
    // example: 0011 0011 - 
    // would require start = 0; pattern = 2; bits = 8;

    int mask = 0x00;
    for(int i = 0; i < bits/pattern/2; i++){
        for(int j = 0; j < pattern; j++){
            mask = mask << 1;
            mask = mask | start;
        }
        for(int j = 0; j < pattern; j++){
            mask = mask << 1;
            mask = mask | (start^0x01);
        }
    }
    return mask;
}