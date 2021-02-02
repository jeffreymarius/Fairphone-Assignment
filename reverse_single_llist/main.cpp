/* 
 * Assignment 2:
 * Using C++, write the cleanest possible function you can think of to print a singly linked list in
 * reverse order and explain your implementation choice.
 * You can push your code to any kind of code repository. Just give us access to it.
 */
#include "lsingle.h"

int main()
{
    lsingle list;
    db_t data[] = {
           {123123123,"James",NULL},
           {989891111,"Clerk",NULL},
           {712882912,"Maxwell",NULL},
           {612393919,"Einstein",NULL},
    };           

    for(int i=0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        list.add_to_list(data[i].mob_no,data[i].contact);
    }

    list.print_list();

    list.reverse_list();

    return 0;
}
