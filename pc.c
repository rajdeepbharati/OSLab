/**
 * Producer Consumer Synchronization Problem
 * Solution using Semaphores
 */

#include <stdio.h>
#include <stdlib.h>

int buffer, empty, full = 0, mutex = 1, op, x = 0;

int _wait(int s)
{
    while (s <= 0)
        ;
    return --s;
}

int _signal(int s)
{
    return ++s;
}

void produce()
{
    if (mutex == 1 && empty != 0)
    {
        mutex = _wait(mutex);
        full = _signal(full);

        empty = _wait(empty);
        mutex = _signal(mutex);

        ++x;
        printf("\n Producer produces an item %d\n", x);
    }
    else
        printf("\n Buffer is Full, cannot produce\n");
}

void consume()
{
    if (mutex == 1 && full != 0)
    {
        mutex = _wait(mutex);

        full = _wait(full);
        empty = _signal(empty);

        mutex = _signal(mutex);

        printf("\n Consumer consumed an item %d\n", x);
        --x;
    }
    else
        printf("\n Buffer is Empty, cannot consume\n");
}

int main()
{
    printf("Enter the buffer size: ");
    scanf("%d", &buffer);
    empty = buffer;

    while (1)
    {
        printf("\n\t choose an operation: ");
        printf("1.produce  2.consume  3.exit\n>>>: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            produce();
            break;
        case 2:
            consume();
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
