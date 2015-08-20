#include "list_array.h"
int main(int argc, const char *argv[])
{
    List list;
    BuildList(list);
    ShowList(list);
     AddNode(list,1);
    AddNode(list,2);
    AddNode(list,3);
    AddNode(list,4);
    AddNode(list,5);
    AddNode(list,6);
   ShowList(list);
    RemoveNode(list,3);
    RemoveNode(list,4);
    RemoveNode(list,5);
   ShowList(list);
    return 0;
}
