#ifndef INTLIST_H
#define INTLIST_H

#include<cstdlib>
#include <exception>

class ListException: std::exception
{
    const char* what() const throw ()
    {
        return "Reading from invalid iterator!\n";
    }
};

class ListIterator;

class IntList
{
private:
    struct ListItem
    {
        int item;
        ListItem * next;

        ListItem(int i , ListItem *n = NULL)
        {
            item = i ;
            next = n ;
        }
    };

    int itemsCount;
    ListItem *first;
    ListItem *last;

public:
    friend ListIterator;
    typedef ListIterator iterator;

    IntList()
    {
        itemsCount = 0 ;
        first = last = NULL;
    }

    IntList(const IntList &orig);
    ~IntList();

    void InsertSubList(IntList &orig, int pos);
    void AddLast(const IntList & src);
    void AddFirst(int item);
    void AddLast(int item);
    void Remove(int item);
    void RemoveFirst();
    void RemoveLast();
    void ClearList();
    bool Finde(int item);
    int GetItemsCounts()
    {
        return itemsCount;
    }

    ListIterator begin();
    ListIterator end();
};

class ListIterator
{
private:
    IntList::ListItem *current;
public:
    friend IntList;

    ListIterator();
    ~ListIterator();

    ListIterator(const ListIterator &original);
    ListIterator &operator=(const ListIterator &right);

    int  &operator *() const;
    ListIterator operator++();

    bool operator==(const ListIterator &right) const;
    bool operator!=(const ListIterator &right) const
    {
        return !(*this == right);
    }

};

#endif //INTLIST_H
