#include "crow/crow_all.h"

#include "Data Structures/stack.h"
#include "Data Structures/queue.h"
#include "Data Structures/linkedlist.h"

int main()
{
    crow::SimpleApp m_app;
    Stack m_stack;
    Queue m_queue;
    LinkedList m_linkedList;
    bool status = true;

    //============================================STACK=================================================================
    CROW_ROUTE(m_app, "/stack/push/<int>")([&m_stack, &status](int data){
        status = m_stack.push(data);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}};
        }
    });

    CROW_ROUTE(m_app, "/stack/pop")([&m_stack, &status](){
        int temp;
        status = m_stack.pop(&temp);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}, {"value", temp}};
        }
    });

    CROW_ROUTE(m_app, "/stack/isempty")([&m_stack, &status](){
        status = m_stack.isEmpty();
        return crow::json::wvalue{{"isEmpty", status}};
    });

    CROW_ROUTE(m_app, "/stack/top")([&m_stack, &status](){
        int temp;
        status = m_stack.getTop(&temp);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}, {"value", temp}};
        }
    });
    //==================================================================================================================


    //===================================================QUEUE==========================================================
    CROW_ROUTE(m_app, "/queue/enqueue/<int>")([&m_queue, &status](int data){
        status = m_queue.enqueue(data);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}};
        }
    });

    CROW_ROUTE(m_app, "/queue/dequeue")([&m_queue, &status](){
        int temp;
        status = m_queue.dequeue(&temp);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}, {"value", temp}};
        }
    });

    CROW_ROUTE(m_app, "/queue/isempty")([&m_queue, &status](){
        status = m_queue.isEmpty();
        return crow::json::wvalue{{"isEmpty", status}};
    });

    CROW_ROUTE(m_app, "/queue/front")([&m_queue, &status](){
        int temp;
        status = m_queue.getFront(&temp);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}, {"value", temp}};
        }
    });

    CROW_ROUTE(m_app, "/queue/rear")([&m_queue, &status](){
        int temp;
        status = m_queue.getRear(&temp);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}, {"value", temp}};
        }
    });
    //==================================================================================================================

    CROW_ROUTE(m_app, "/linkedlist/insertFront/<int>")([&m_linkedList, &status](int data){
        status = m_linkedList.insertAtFront(data);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}};
        }
    });

    /*
    CROW_ROUTE(m_app, "/linkedlist/deleteFront")([&m_linkedList, &status](){
        int temp;
        status = m_linkedList.deleteFromFront(&temp);
        if(!status)
        {
            return crow::json::wvalue{{"success", false}};
        }
        else
        {
            return crow::json::wvalue{{"success", true}, {"value", temp}};
        }
    });
     */
    //above function will be added later



    m_app.port(8080).run();

    return 0;
}
