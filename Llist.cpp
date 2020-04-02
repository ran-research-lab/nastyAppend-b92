//
// Created by rarce on 03/03/20.
//

#include "Llist.h"
#include <iostream>
using namespace std;


Node* Llist::search(int val) const {
    Node *p = head;
    while(p != NULL) {
        if (p->data == val) return p;
        p = p->next;
    }
    return p;
}

void Llist::insertAfter(Node *curNode, int val) {
    Node *n = new Node(val);
    if (head == NULL) {
        head = tail = n;
    }
    else if (curNode == NULL) {
        n->next = head;
        head = n;
    }
    else {
        n->next = curNode->next;
        curNode->next = n;
        if (tail == curNode) tail = n;
    }
    length++;
}

void Llist::append(int val) {
    insertAfter(tail, val);
}

void Llist::prepend(int val) {
    insertAfter(NULL, val);
}

int Llist::at(int idx) const {
    if (idx < 0 || idx >= length) {
        cout << "invalid index... exiting" << endl;
        exit(1);
    }
    Node *p = head;
    for (int i = 0; i < idx; i++) p = p->next;
    return p->data;
}

void Llist::removeAfter(Node *curNode) {
    Node *toDelete;
    if (curNode == NULL) {
        toDelete = head;
        head = head->next;
        if (head == NULL) tail = NULL;
    }
    else {
        toDelete = curNode->next;
        curNode->next = toDelete->next;
        if (tail == toDelete) tail = curNode;
    }
    delete toDelete;
    length--;
}

Llist& Llist::operator=(const Llist &b) {
    if(&b != this) {
        length = b.length;

        while (head != NULL) removeAfter(NULL);
        Node *p = b.head;
        while(p != NULL) {
            append(p->data);
            p = p->next;
        }
    }
    return *this;
}