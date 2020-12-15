#include <iostream>

using namespace std;

struct Elem
{
    Elem* link1,
        * link2;
    int info;
};

Elem* p;

void Create();
void Delete();

int main()
{
    
    Create();
    Delete();

    return 0;
}

void Create()
{
    p = new Elem;                       //1     
    p->info = 1;                        //2
    p->link2 = new Elem;                //3
    p->link2->info = 4;                 //4
    p->link2->link2 = NULL;             //5
    p->link1 = new Elem;                //6
    p->link1->info = 2;                 //7
    p->link1->link2 = new Elem;         //8
    p->link1->link2->info = 3;          //9
    p->link1->link2->link2 = NULL;      //10
    p->link2->link1 = p;                //11
    p->link1->link1 = p;                //12
    p->link1->link2->link1 = p->link1;  //13
}
void Delete()
{   
    delete p->link1->link2;             //14 - видалення четвертого елемента
    delete p->link1;                    //15 - видалення третього елемента
    delete p->link2;                    //16 - видалення другого елемента
    delete p;                           //17 - видалення першого елемента
}