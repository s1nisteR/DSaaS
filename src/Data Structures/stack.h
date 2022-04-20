#ifndef DSAAS_STACK_H
#define DSAAS_STACK_H


typedef struct SNode
{
    int data;
    struct SNode* link;
}SNode;

typedef struct Stack
{
    SNode* top;
    Stack()
    {
        this->top = nullptr;
    }

    bool push(int data)
    {
        auto* newItem = new SNode();
        if(!newItem)
        {
            return false;
        }
        newItem->data = data;
        newItem->link = this->top;
        this->top = newItem;
        return true;
    }

    bool pop(int* returnData)
    {
        SNode* temp;
        if(this->top == nullptr)
        {
            return false;
        }
        else
        {
            temp = this->top;
            *returnData = temp->data;
            this->top = this->top->link;
            free(temp);
            return true;
        }
    }

    [[nodiscard]] bool isEmpty() const { return this->top == nullptr; }

    bool getTop(int* returnData) const
    {
        if(!isEmpty())
        {
            *returnData = top->data;
            return true;
        }
        return false;
    }


}Stack;



#endif //DSAAS_STACK_H
