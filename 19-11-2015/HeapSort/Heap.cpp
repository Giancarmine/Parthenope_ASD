#include "Heap.h"

void Print(IntArrayType IntArray, int Count) {
   int k;
   for (k = 0; k < Count; k++)   cout << setw(5) << IntArray[k];
   cout << endl;
   }

void FillArray(IntArrayType IntArray) {
   int k;
   srand(time(NULL));  // set an arbitrary starting point
   for (k = 0; k < Max; k++)   IntArray[k] = (1000.0 * rand()) / RAND_MAX;
   }

void HeapSort(IntArrayType IntArray, int Count){
    int Smallest, k;
    HeapClass H(IntArray, Count);

    for (k = Count - 1; k >= 1; k--){
        Smallest = H.Delete();      // Remove smallest item and place at index k
        IntArray[k] = Smallest;
    }   // At this point IntArray[0] contains the largest item by default
}
