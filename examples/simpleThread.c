#include <pthread.h>
#include <stdio.h>

// Thread function definition.
// It must return a `void*` and accept a `void*` argument to be compatible with pthreads.
void *msg(void *v)
{
    // Properly cast the void pointer to an int pointer and dereference it to get the value.
    // This is necessary because data passed to the thread function must be via a void pointer.
    int r = *(int *)v;

    // Print the value that was passed to the thread.
    printf("the number is : %d\n", r);

    // Return NULL since no value needs to be returned from this thread.
    return NULL;
}

int main()
{
    // Declare a pthread_t variable to hold the thread's identifier.
    pthread_t thread;
    
    // Initialize an integer for demonstration purposes.
    int r = 6;
    
    // Create a new thread. The fourth argument is a pointer to the data being passed to the thread.
    // We cast the address of 'r' to `void*` to match the expected signature of the thread function.
    pthread_create(&thread, NULL, msg, (void *)&r);
    
    // Wait for the thread to complete execution.
    // This is important to ensure 'r' remains in scope and valid when the thread uses it.
    pthread_join(thread, NULL);
    return 0;
}
