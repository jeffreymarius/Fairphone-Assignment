#include<iostream>
#include<cstring>
#include<cstdint>
using namespace std;

#define MAX_LEN 1024

typedef struct database {
    unsigned long mob_no;
    char contact[MAX_LEN];
    struct database *next;
}db_t;

class lsingle {
    private:
        int len;
        db_t *slist,*tmp;

    public:
        lsingle();
        ~lsingle();
        void add_to_list(unsigned long,std::string);
        void print_list();
        void reverse_list();
        void update_list_len();
        int  get_list_len();
};

lsingle::lsingle()
{
   slist = NULL;
   tmp   = NULL;
   len   = 0;
}

lsingle::~lsingle()
{
    while(slist != NULL)
    {
        tmp = slist;
        delete tmp;
        slist = slist->next;
    }
}

void lsingle::add_to_list(unsigned long num,std::string name)
{
   db_t *tmp = new db_t;
   tmp->mob_no = num;
   name.copy(tmp->contact,sizeof name);
   tmp->next = slist;
   slist = tmp;
   this->update_list_len();
}

void lsingle::print_list()
{
    tmp = slist;

    cout << "Linear Print:\n";
    while(tmp != NULL)
    {
        cout << std::addressof(tmp) << "Contact:" << tmp->contact << "\t" << "Mobile No:" << tmp->mob_no << "\n";
        tmp = tmp->next;
    }
}

int lsingle::get_list_len()
{
    return len;
}

void lsingle::update_list_len()
{
    len++;
}

/* Reason of Implementation:
   By this method the list needs to be traversed only once. 
 */
void lsingle::reverse_list()
{
    int llen = get_list_len(), ltmp = llen;
    db_t *rev_arr = new db_t [llen];

    tmp = slist;

    while(tmp != NULL)
    {
        std::memcpy(&rev_arr[llen-1],tmp,sizeof(db_t));
        tmp = tmp->next;
        llen--;
    }

    cout << "Reverse List:\n" << llen << ltmp;
    while(llen < ltmp)
    {
       cout << std::addressof(tmp) << "Contact:" << rev_arr[llen].contact << "\t" 
            << "Mobile No:" << rev_arr[llen].mob_no << "\n";
       llen++;
    }
}
