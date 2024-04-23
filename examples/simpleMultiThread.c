#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Args;

void* sumit(void* arguments) 
{
    Args* args = (Args*)arguments;
    int sum = args->a + args->b;
    sum++;
    printf("The sum is: %d\n", sum);
    printf("The sum is: %d\n", sum);
    return NULL;
}
void* product(void* arguments) 
{
    Args* args = (Args*)arguments;
    int prod = args->a * args->b;

    printf("The product is: %d\n", prod);
    printf("The product is: %d\n", prod);
    return NULL;
}

int main(int ac, char **av) 
{
    int a = atoi(av[1]);
    int b = atoi(av[2]);

    Args args = {a, b};
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, sumit, &args);
    pthread_create(&thread2, NULL, sumit, &args);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}
