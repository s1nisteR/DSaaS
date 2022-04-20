#ifndef DSAAS_QUEUE_H
#define DSAAS_QUEUE_H

typedef struct QNode
{
    int data;
    struct QNode* link;
    explicit QNode(int d)
    {
        data = d;
        link = nullptr;
    }
}QNode;

typedef struct Queue
{
    QNode* front;
    QNode* rear;
    Queue()
    {
        this->front = this->rear = nullptr;
    }

    bool enqueue(int data)
    {
        auto newItem = new QNode(data);
        if(newItem == nullptr)
        {
            return false;
        }
        if(this->rear == nullptr)
        {
            this->front = this->rear = newItem;
            return true;
        }
        this->rear->link = newItem;
        this->rear = newItem;
        return true;
    }

    bool dequeue(int* returnData)
    {
        if(this->front == nullptr)
        {
            return false;
        }
        QNode* temp = this->front;
        *returnData = temp->data;
        this->front = this->front->link;
        if(this->front == nullptr)
        {
            this->rear = nullptr;
        }
        delete(temp);
        return true;
    }

    [[nodiscard]] bool isEmpty() const { return this->rear == nullptr; }

    bool getFront(int* returnData) const
    {
        if(!isEmpty())
        {
            *returnData = this->front->data;
            return true;
        }
        return false;
    }

    bool getRear(int* returnData) const
    {
        if(!isEmpty())
        {
            *returnData = this->rear->data;
            return true;
        }
        return false;
    }

}Queue;


#endif //DSAAS_QUEUE_H
