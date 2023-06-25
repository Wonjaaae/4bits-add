#include <stdio.h>

//입력 값
int a, b;
int A[4], B[4];

//출력 값
int result[5];

//함수
void add(int s, int p); //덧셈(여기가 중요)
int de(int i); //이진수를 자연수로 바꿈(Result 변수 기준)

int main(void)
{
    //입력
    printf("please, enter a input that is two decimal numbers(4bits)...\n");
    scanf("%d%d", &a, &b);
    //이진수로 변환
    A[0] = a%2, B[0] = b%2;
    int k=a, l=b;
    for(int i=8, j=3; i>1; i=i/2, j--)
    {
        if(k>=i)k-=i, A[j]=1;
        if(l>=i)l-=i, B[j]=1;
    }

    //계산
    add(0, 0);

    //출력
    printf("\ndecimal add(used add command) : %d + %d = %d\n", a, b, a+b);
    printf("decimal add(used logic gates) : %d + %d = %d\n", a, b, de(0)/2); //논리회로 이용 결과
    printf("binary add : ");
    for(int i=3; i>=0; i--)printf("%d", A[i]);
    printf(" + ");
    for(int i=3; i>=0; i--)printf("%d", B[i]);
    printf(" = ");
    for(int i=4; i>=0; i--)printf("%d", result[i]);

}

void add(int s, int p)
{
    if(s==4)
    {
        if(p==1)result[s]=1;
        return;
    }
    int pp=0, next=0;

    //논리회로 시작 (중요부분)
    if(A[s] && B[s]) pp=1;
    else if(A[s] || B[s]) next=1;

    if(next && p) pp=1;
    else if(next || p)result[s]=1;

    add(s+1, pp);
    return;
}

int de(int i)
{
    if(i==5)return 0;
    int k=0;
    if(result[i])
    {
        k=1;
        for(int j=0; j<=i; j++)k=k*2;
    }
    return k + de(i+1);
}