#include<bits/stdc++.h>
using namespace std;

struct MinHeap {
    int Heap[10005];
    int size;
    int maxsize;
  
    MinHeap(int maxsize)
    {
        maxsize = maxsize;
        size = 0;
        Heap[0] = -1000000007;
    }
    MinHeap()
    {
        maxsize = 10005;
        size = 0;
        Heap[0] = -1000000007;
    }
  
    int parent(int pos) { return pos / 2; }
  
    int leftChild(int pos) { return (2 * pos); }

    int rightChild(int pos)
    {
        return (2 * pos) + 1;
    }
  
    bool isLeaf(int pos)
    {
        if (pos > (size / 2) && pos <= size) {
            return true;
        }
        return false;
    }
  
    void swap(int fpos, int spos)
    {
        int tmp;
        tmp = Heap[fpos];
        Heap[fpos] = Heap[spos];
        Heap[spos] = tmp;
    }
  
    void minHeapify(int pos)
    {
        if (isLeaf(pos))
            return;
  
        if (Heap[pos] > Heap[leftChild(pos)]
            || Heap[pos] > Heap[rightChild(pos)]) {
  
            if (Heap[leftChild(pos)]
                < Heap[rightChild(pos)]) {
                swap(pos, leftChild(pos));
                minHeapify(leftChild(pos));
            }
            else {
                swap(pos, rightChild(pos));
                minHeapify(rightChild(pos));
            }
        }
    }
  
    void insert(int element)
    {
        Heap[++size] = element;
  

        int current = size;
        while (Heap[current] < Heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }
  
    void print()
    {
        for (int i = 1; i <= size / 2; i++)
            printf(" %d %d %d\n", Heap[i], Heap[2 * i], Heap[2 * i + 1]);
        printf("\n");
    }
  
    int extractMin()
    {
        int popped = Heap[1];
        Heap[1] = Heap[size--];
        minHeapify(1);
        return popped;
    }
};

int main(){
    MinHeap m;

    m.insert(5);
    m.insert(3);
    m.insert(17);
    m.insert(10);
    m.insert(84);
    m.insert(19);
    m.insert(6);
    m.insert(22);
    m.insert(9);

    m.print();
}