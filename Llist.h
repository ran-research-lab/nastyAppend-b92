//
// Created by rarce on 03/03/20.
//
#include <cstdlib>

#ifndef LLIST_LLIST_H
#define LLIST_LLIST_H


class Node {
public:
    int data;
    Node* next;
    Node(int d, Node* n = NULL): data(d), next(n) {}
};
class Llist {
private:
    Node *head;
    Node *tail;
    int length;
public:
    Llist(): head(NULL), tail(NULL), length(0) {}
    int getSize() const {return length;}
    Node* search(int val) const;
    void insertAfter(Node *curNode, int val);
    void append(int val);
    void prepend(int val);
    void removeAfter(Node *curNode);
    Llist& operator=(const Llist &b);
    int at(int idx) const;
};


#endif //LLIST_LLIST_H
