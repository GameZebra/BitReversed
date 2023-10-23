#include<stdio.h>
#include<math.h>

void bitReversedV01(int num[], int length);
void bitReversedV02(char *num);
void bitReversedV03(char *num, int bits);
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

    //v02
    unsigned char b = 0b00101011;
    printf("%d\n", b);
    bitReversedV03(&b,8);
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
    *num = ((*num & 0xAA) >> 1) | ((*num & 0x55) << 1);
    *num = ((*num & 0xCC) >> 2) | ((*num & 0x33) << 2);
    *num = ((*num & 0xF0) >> 4) | ((*num & 0x0F) << 4);
}

void bitReversedV03(char *num, int bits){
    for(int i = 0; i < bits/2 -1; i++){
            *num = ((*num & bitMask(1, (int)pow(2,i), bits)) >> (int)pow(2, i)) | ((*num & bitMask(0, (int)pow(2,i), bits)) << (int)pow(2, i));
    }
}
int bitMask(int start, int pattern, int bits){
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