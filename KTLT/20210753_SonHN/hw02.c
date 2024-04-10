#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40
int get_the_nth_Fibbonacci_number(int *n);
int get_mode(int *mode);
int display_series(int n);
int check_bit_overflow_for_mode_1(int n);
int display_nth_Fibbonacci(int n);
void add_for_long_number(int num1[MAX_SIZE], int num2[MAX_SIZE], int result[MAX_SIZE]);
int Advanced_Fib_check(int *result, int *carry);

/*
Tổng quan chương trình: 
Hỗ trợ 2 chế độ
- Mode 1: In ra 1 dãy n số Fibonacci đầu tiên
- Mode 2: In ra số thứ n của dãy Fibbonacci 
Flow của Chương trình
1. Khởi tạo các biến local cần dùng trong main
2. Nhảy vào hàm get_mode => hỏi người dùng chế độ muốn dùng (mode 1 hoặc 2)
3. Nếu mode = 1 => execute get_the_nth_Fibbonacci_number để lấy n từ người dùng
   sau đó execute hàm display_series để in ra n số đầu tiên 
   (trong đó có sử dụng hàm check_bit_overflow_for_mode_1 check xem giá trị của n số đầu có tràn qua MAX_INT không)
4, nếu mode = 2 => execute get_the_nth_Fibbonacci_number để lấy n từ người dùng
    sau đó execute display_nth_Fibbonacci để in ra số fibbonacci thứ n
    (trong đó có sử dụng hàm con add_for_long_number để cộng số lớn theo dạng array,
    hàm con Advanced_Fib_check để check xem số Fib thứ n có lớn hơn số kí tự define ở MAX_SIZE hay không)
*/

int main(){
    int n, mode = 0;
    get_mode(&mode);
    if(mode == 1)
    {
        get_the_nth_Fibbonacci_number(&n);
        display_series(n);
    }else
    {
        get_the_nth_Fibbonacci_number(&n);
        display_nth_Fibbonacci(n);
    }
    return 0;
}

int check_overflow_for_mode_2(int *result, int *carry) 
{
    if((*result != 0) && (*carry == 1)) {
        printf("The value has overflowed");
        return 1;
    }
}

void add_for_long_number(int num1[MAX_SIZE], int num2[MAX_SIZE], int result[MAX_SIZE]){
    int carry = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        result[i] = (num1[i] + num2[i] + carry) % 10;
        carry = (num1[i] + num2[i] + carry) > 9 ? 1 : 0;    
    }
    if(check_overflow_for_mode_2((result+MAX_SIZE-1),&carry)) {
        exit(0);
    }

}

int display_nth_Fibbonacci(int n)
{
    int num1[MAX_SIZE] = {0}, num2[MAX_SIZE] = {1}, result[MAX_SIZE] = {0};

    for(int i = 1; i < n; i++) {
        add_for_long_number(num1, num2, result);
        for(int j = 0; j < MAX_SIZE; j++) {
            num1[j] = num2[j];
            num2[j] = result[j]; 
        }

    }
    printf("Fib(%d) = ", n);
    int  count = 0;
    for(int i = MAX_SIZE - 1; i >=0 ; i--) {
       if(result[i] == 0 && result[i-1] != 0) {
        count = i-1;
        break;
       }
    }
    for(int i = count; i >=0; i--) {
        printf("%d", result[i]);
    }

}

int check_bit_overflow_for_mode_1(int n)
{
    int sum_next;
    int number1 = 0;
    int number2 = 1;

     for (int i = 1; i <= n; i++) {
        if(number1 < 0) 
        {
            printf("The sequence has overflowed\n");
            return 1;              
        }    
        sum_next = number1 + number2;
        number1 = number2;
        number2 = sum_next;    
        }
    return 0;
}
int get_the_nth_Fibbonacci_number(int *n)
{
    int c;
    printf("\nEnter your number: ");

    while (scanf("%d", n) != 1 || *n < 0) {
        printf("\nInvalid input, please retype: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

int get_mode(int *mode)
{
    printf("\n\nWhich mode do you want to print: Series(Display first n value of Fibbonacci, Value < INT_MAX) mode= 1 \nor Big number (Display the nth Fibbonacci, Maximum value depend on MAX_SIZE digit) mode= 2:");
    scanf("%d", mode);
    while(*mode !=1 && *mode !=2) 
    {
    printf("retype your chose (1 or 2)");
    scanf("%d", mode);
    }
}
int display_series(int n)
{
    int sum_next;
    int number1 = 0;
    int number2 = 1;

    if(check_bit_overflow_for_mode_1(n))
    {
        return 0;
    }

        printf("Order       Value\n");
    
        for (int i = 0; i <= n; i++) {
            printf("%-9d  -   %d\n", i, number1);
            sum_next = number1 + number2;
            number1 = number2;
            number2 = sum_next;
            
        }
}
