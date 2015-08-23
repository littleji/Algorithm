#include "stack_array.h" 
int main(int argc, char const* argv[])
{
    Stack stack = BuildStack(5);
    /*if (IsEmpty(stack)) {*/
        /*printf("stack is empty!\n");*/
    /*}*/
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);
    Push(stack, 5);
    Push(stack, 6);
    ShowStack(stack);
    DestroyStack(stack);
    return 0;
}
