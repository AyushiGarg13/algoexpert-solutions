using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node *node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
            insertBefore(head, node);
    }

    void setTail(Node *node)
    {
        if (tail == nullptr)
            setHead(node);
        else
            insertAfter(tail, node);
    }

    void insertBefore(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if (node->prev != nullptr)
            node->prev->next = nodeToInsert;
        else
            head = nodeToInsert;
        node->prev = nodeToInsert;
    }

    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if (node->next != nullptr)
            node->next->prev = nodeToInsert;
        else
            tail = nodeToInsert;
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert)
    {
        if (position == 1)
            setHead(nodeToInsert);
        else
        {
            Node *currentNode = head;

            int i = 1;
            while (currentNode != nullptr && position != i)
            {
                currentNode = currentNode->next;
                i++;
            }
            if (currentNode != nullptr)
                insertBefore(currentNode, nodeToInsert);
            else
                setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value)
    {
        Node *current_node = head;
        while (current_node != nullptr)
        {
            Node *nodeToRemove = current_node;
            current_node = current_node->next;

            if (nodeToRemove->value == value)
                remove(nodeToRemove);
        }
    }

    void remove(Node *node)
    {
        if (node == head)
            head = node->next;
        if (node == tail)
            tail = node->prev;
        if (node->prev != nullptr)
            node->prev->next = node->next;
        if (node->next != nullptr)
            node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    bool containsNodeWithValue(int value)
    {
        Node *current_node = head;
        while (current_node != nullptr && current_node->value != value)
            current_node = current_node->next;

        return current_node->value == value;
    }
};
