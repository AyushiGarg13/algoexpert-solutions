using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *middleNode(LinkedList *linkedList)
{
    LinkedList *singlepointer = linkedList, *doublepointer = linkedList;
    while (doublepointer != nullptr && doublepointer->next != nullptr)
    {
        singlepointer = singlepointer->next;
        doublepointer = doublepointer->next->next;
    }
    return singlepointer;
}
