#include <vector>
using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(vector); }

    vector<int> buildHeap(vector<int> &vector)
    {
        for (int i = (vector.size() - 2) / 2; i >= 0; i--)
            siftDown(i, vector.size() - 1, vector);
        return vector;
    }

    void siftDown(int currentIdx, int endIdx, vector<int> &heap)
    {
        int leftIdx = 2 * currentIdx + 1;
        while (leftIdx <= endIdx)
        {
            int rightIdx = 2 * currentIdx + 2;
            int idxToSwap;
            if (rightIdx <= endIdx && heap[rightIdx] < heap[leftIdx])
                idxToSwap = rightIdx;
            else
                idxToSwap = leftIdx;

            if (heap[idxToSwap] < heap[currentIdx])
            {
                swap(heap[currentIdx], heap[idxToSwap]);
                currentIdx = idxToSwap;
                leftIdx = 2 * currentIdx + 1;
            }
            else
                return;
        }
    }

    void siftUp(int currentIdx, vector<int> &heap)
    {
        int parentIdx = (currentIdx - 1) / 2;

        while (currentIdx >= 0 && heap[currentIdx] < heap[parentIdx])
        {
            swap(heap[currentIdx], heap[parentIdx]);
            currentIdx = parentIdx;
            parentIdx = (currentIdx - 1) / 2;
        }
    }
    int peek() { return heap[0]; }

    int remove()
    {
        int min_elem = peek();
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(0, heap.size() - 1, heap);
        return min_elem;
    }

    void insert(int value)
    {
        heap.push_back(value);
        siftUp(heap.size() - 1, heap);
    }
};
