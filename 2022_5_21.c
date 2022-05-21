#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INITSIZE 10

typedef int STD;

typedef struct Stack
{
    STD*base;
    int top;
    int size;
}ST;

void StackInit(ST*s)
{
    s->base=(STD*)malloc(sizeof(STD)*INITSIZE);
    s->top=0;
    s->size=INITSIZE;
}
void checkcapacity(ST*s)
{
    if(s->size==s->top)
    {
        s->size*=2;
        s->base=(STD*)realloc(s->base,sizeof(STD)*s->size);
    }
}
void push(ST*s,STD n)
{
    checkcapacity(s);
    s->base[s->top++]=n;
}
int StackEmpty(ST*s)
{
    return s->top>0?1:0;
}
void pop(ST*s)
{
    if(StackEmpty(s))
        printf("%d\n",s->base[--s->top]);
    else
        printf("error\n");
}
void top(ST*s)
{
    if(StackEmpty(s))
        printf("%d\n",s->base[s->top-1]);
    else
        printf("error\n");
}
int main()
{
    ST s;
    StackInit(&s);
    int n;
    scanf("%d",&n);
    int num;
    getchar();
    while(n--)
    {
        char fun[5]={0};
        scanf("%s %d",fun,&num);
        if(!strcmp(fun,"push"))
        {
            scanf("%d",&num);
            push(&s,num);
        }
        if(!strcmp(fun,"pop"))
            pop(&s);
        if(!strcmp(fun,"top"))
            top(&s);
    }
    return 0;
}