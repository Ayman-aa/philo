#include <pthread.h>
#include <stdio.h>

void *msg(void *v)
{
    int r = *(int *)v;
    printf("the number is : %d\n", r);
    return NULL;
}

int main()
{
    pthread_t thread;
    int r = 6;
    pthread_create(&thread, NULL, msg, (void *)&r);
    pthread_join(thread, NULL);
    return 0;
}
