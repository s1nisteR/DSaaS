#ifndef DSAAS_LINKEDLIST_H
#define DSAAS_LINKEDLIST_H

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;

typedef struct LinkedList
{
    LNode* head;
    LinkedList()
    {
        this->head = nullptr;
    }


    bool insertAtFront(int data)
    {
        auto* newNode = new LNode;
        if(newNode == nullptr)
        {
            return false;
        }
        newNode->data = data;
        newNode->next = this->head;
        this->head = newNode;
        return true;
    }
    //implement more operations here like deletion from front and more


}LinkedList;





#endif //DSAAS_LINKEDLIST_H
