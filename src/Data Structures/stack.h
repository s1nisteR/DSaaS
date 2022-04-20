#ifndef DSAAS_STACK_H
#define DSAAS_STACK_H


typedef struct node
{
    int data;
    struct node* link;
}node;

node* top = nullptr;

bool push(int data)
{
    node* newItem = new node();
    if(!newItem)
    {
        return false;
    }
    newItem->data = data;
    newItem->link = top;
    top = newItem;
    return true;
}

bool pop(int* returnData)
{
    node* temp;
    if(top == nullptr)
    {
        return false;
    }
    else
    {
        temp = top;
        *returnData = temp->data;
        top = top->link;
        free(temp);
        return true;
    }
}

bool isEmpty() { return top == nullptr; }

bool getTop(int* returnData)
{
    if(!isEmpty())
    {
        *returnData = top->data;
        return true;
    }
    return false;
}

#endif //DSAAS_STACK_H
