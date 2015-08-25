#include "queue_array.h"
int main(int argc, char const* argv[])
{
    Queue queue = BuildQueue(5);
    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 4);
    Enqueue(queue, 5);
    Enqueue(queue, 6);
    Dequeue(queue);
    Enqueue(queue, 7);
    ShowQueue(queue);
    DestroyQueue(queue);
}
