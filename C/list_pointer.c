#include <stdio.h>
#include <string.h>
#include "list_pointer.h"
int main(int argc, const char *argv[])
{
    List list=BuildList();
    PtrToNode one=BuildNode(1);
    PtrToNode two=BuildNode(2);
    PtrToNode three=BuildNode(3);
    PtrToNode four=BuildNode(4);
    AddNode(list, one);
    AddNode(list, two);
    AddNode(list, three);
    ShowAll(list);
    DeleteNode(list, 2);
    ShowAll(list);
    InsertNode(list,four,1);
    ShowAll(list);
    DeleteList(list);
    return 0;
}

