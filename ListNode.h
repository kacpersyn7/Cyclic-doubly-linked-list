//
// Created by kacper on 09.01.17.
//

#ifndef ZADANIE4_LISTNODE_H
#define ZADANIE4_LISTNODE_H

#include "MyList.h"
template <class DT> class MyList;
template <class DT>
class ListNode
{
private:
    ListNode(const DT & data, ListNode *prior = nullptr, ListNode *next = nullptr)
            : dataItem(data), prior(prior), next(next) {}
    DT dataItem;
    ListNode *prior;
    ListNode *next;
    friend class MyList<DT>;
};


#endif //ZADANIE4_LISTNODE_H
