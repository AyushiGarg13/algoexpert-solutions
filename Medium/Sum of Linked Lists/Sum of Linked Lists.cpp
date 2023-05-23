using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo)
{
    
    LinkedList *sumList = nullptr, *current_node = nullptr;
    int carryover = 0;
    while (linkedListOne != nullptr || linkedListTwo != nullptr || carryover > 0)
    {
        int sum = 0;
        if (linkedListOne != nullptr)
        {
            sum += linkedListOne->value;
            linkedListOne = linkedListOne->next;
        }
        if (linkedListTwo != nullptr)
        {
            sum += linkedListTwo->value;
            linkedListTwo = linkedListTwo->next;
        }
        sum += carryover;
        carryover = sum / 10;
        sum %= 10;

        if (sumList == nullptr)
        {
            sumList = new LinkedList(sum);
            current_node = sumList;
        }
        else
        {
            current_node->next = new LinkedList(sum);
            current_node = current_node->next;
        }
    }
    return sumList;
}