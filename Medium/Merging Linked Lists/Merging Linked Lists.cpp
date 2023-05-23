using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value)
    {
        this->value = value;
    }
};

LinkedList *mergingLinkedLists(LinkedList *linkedListOne, LinkedList *linkedListTwo)
{
    LinkedList *headOne = linkedListOne, *headTwo = linkedListTwo;
    while (linkedListOne != linkedListTwo)
    {
        linkedListOne == nullptr ? linkedListOne = headTwo : linkedListOne = linkedListOne->next;
        linkedListTwo == nullptr ? linkedListTwo = headOne : linkedListTwo = linkedListTwo->next;
    }
    return linkedListOne;
}
