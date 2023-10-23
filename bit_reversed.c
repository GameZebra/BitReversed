#include<stdio.h>
#include<math.h>

void bitReversedV01(int num[], int length);
void bitReversedV02(char *num);
void bitReversedV03(char *num, int bits);
int bitMask(int start, int pattern,int bits);

int main(){
    printf("Bit  Reversed\n");
    int input[8][4]; //Moga li da go napravq bool
    // imam 8 4 bit numbers
    // later

//test
    // int a[2] = {1,2};
    // printf("%d", a[1]);
    // printf("\n");
    // printf("%d", a);
    // printf("\n");
    // printf("%d", *a);
    // printf("\n");

    //biray number input
    // int binaryLength = 4;
    // int num1[binaryLength];
    // for(int i = 0; i<4; i++){
    //     scanf("%d", &num1[i]);
    // }

    // bitReversedV01(num1, binaryLength);

    //v02
    unsigned char b = 0b00111011;
    // printf("%d", b);
    // printf("\n");
    // bitReversedV02(&b);
    // printf("%d", b);
    int a = 0xAA;
    // a = bitMask(0, 2, 8);
    // printf("%d", a);
    printf("%d\n", b);
    bitReversedV03(&b,8);
    printf("%d", b);

    //now miror the number <=> reversed array
    //variant 1 obhojdame prosto masiva naobratno
    // for(int i =0; i<binaryLength; i++){
    //     printf("%d", num1[i]);
    // }

    //variant 2 swap na purvi i posleden bit i taka n/2 puti
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