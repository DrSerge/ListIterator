#include<iostream>
#include"IntList.h"

class Set
{
private:
    IntList container;
public:
    void add(int x);
    void remove(int x);
    bool find(int x);
    void show();
};

using namespace std;

int main()
{
    Set myOwnSet;
    for(int i=0; i<10; ++i)
        myOwnSet.add(rand()%50);

    cout<<"My Set:"<<endl;
    myOwnSet.show();

    int num;

    cout<<endl;
    cout<<"Add YOUR NUMBER to My Set:"<<endl;
    cin>>num;
    myOwnSet.add(num);
    cout<<endl;
    cout<<"My Set:"<<endl;
    myOwnSet.show();

    cout<<endl;
    cout<<"Enter random number:"<<endl;
    cin>>num;

    cout<<endl;
    cout<<"Checking if "<<num<<" exist in My Set: ";
    if( myOwnSet.find(num) )
        cout<<num<<" exist in My Set"<<endl;
    else
        cout<<num<<" doestn't exist in My Set"<<endl;

    cout<<endl;
    cout<<"Deliting YOUR NUMBER from My Set:"<<endl;
    cin>>num;
    myOwnSet.remove(num);
    cout<<endl;
    myOwnSet.show();

    cout<<endl;
    cout<<"Well Done!"<<endl;

    return 0;
}

void Set::add(int x)
{
    container.AddLast(x);
}

void Set::remove(int x)
{
    container.Remove(x);
}

bool Set::find(int x)
{
    return container.Finde(x);
}
void Set::show()
{
    for(IntList::iterator it = container.begin(); it != container.end(); ++it )
        cout<<*it<<" ";
    cout<<endl;
}


