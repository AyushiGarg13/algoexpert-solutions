using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next = nullptr;
    LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList)
{
    LinkedList *currentNode = linkedList;
    while (currentNode->next != nullptr)
    {
        if (currentNode->value == currentNode->next->value)
            currentNode->next = currentNode->next->next;
        else
            currentNode = currentNode->next;
    }
    return linkedList;
}
