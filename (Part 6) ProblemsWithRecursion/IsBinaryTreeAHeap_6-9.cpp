#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isHeap(vector<int> *heap, int index); // index has to be 0 so that the function would start
                                           // at the root. If this was a class method the index
                                           // parameter would be added in a wrapper function so that client wouldn't need to write that zero in.

int main(void){

    int nums[] = {1,5,7,9,4,1,8,7,9,10};
    vector<int> numbers(nums, nums+10);
    
    make_heap(numbers.begin(), numbers.end());
    
    int fakeTreeNums[] = {1,4,3,7,5,1,7,8,6,1,3,4};
    vector<int> fakeNumbers(fakeTreeNums, fakeTreeNums+12);

    if (isHeap(&numbers, 0)) cout << "Heap tree\n";
    else cout << "Not a heap tree\n";
    if (isHeap(&fakeNumbers, 0)) cout << "Heap tree\n";
    else cout << "Not a heap tree\n";
    return 0;
}

bool isHeap(vector<int> *heap, int index) {
    if (index >= heap->size()) return true;         // due to formula of finding children, the first thing the program does is chech if  
                                                    // index is not out of bounds
    
    // 0 index is special case due to multiplication from zero being a special case in c++
    if (index == 0){
        if (heap->at(0) >= heap->at(1) && (heap->at(0) >= heap->at(2))) {           // we check if both children are lower in value than the parent
            if (!isHeap(heap, 1)) return false;    // we recursively check the children and if any of them are false then all program returns false
            if (!isHeap(heap, 2)) return false;
        }
        else return false;
    }

    if (index*2+3 < heap->size()) {     // checking if both children are present
        if (heap->at(index) >= heap->at(index*2+1) && (heap->at(index) >= heap->at(index*2+2))) {
            if (!isHeap(heap, index*2+1)) return false;
            if (!isHeap(heap, index*2+2)) return false;
        }
        else return false;
    }
    else if (index*2+2 < heap->size()) {    // checking if there is one child

        if (heap->at(index) >= heap->at(index*2+1)) {
            return true;
        }
        else return false;
    }
    return true;
}

