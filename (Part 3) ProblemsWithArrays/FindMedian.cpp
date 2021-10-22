#include <iostream>


// This programs finds the agent who has the highest median of a number in each month.
int compareFunc(const void *voidA, const void *voidB) {
        return(*(int*)voidA - *(int*)voidB);
    }
int main(void){
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    
    int highestMed = 0;
    int bestAgent;
    for (int i = 0; i < 3; i++){
        qsort(sales[i], 12, sizeof(int), compareFunc);
        if ((sales[i][5]+sales[i][6])/2 > highestMed){
            bestAgent = i;
        }
    }
    std::cout << bestAgent;
    return 0;
}