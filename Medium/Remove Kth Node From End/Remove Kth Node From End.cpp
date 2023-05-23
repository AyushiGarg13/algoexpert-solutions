#include <vector>
using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k)
{
    LinkedList *current_node = head;
    LinkedList *kth_node = head;
    while (k > 0)
    {
        kth_node = kth_node->next;
        k--;
    }
    if (kth_node == nullptr)
    {
        head->value = head->next->value;
        head->next = head->next->next;
        return;
    }
    while (kth_node->next != nullptr)
    {
        kth_node = kth_node->next;
        current_node = current_node->next;
    }
    current_node->next = current_node->next->next;
}
