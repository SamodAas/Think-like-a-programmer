// find an (struct) agent with the highest monthly sales median

#include <iostream>
using std::cout;
using std::qsort;

struct agent{
    int monthlySales[12];
};

int comparator(const void *a, const void *b){
    int * A = (int *)a;
    int * B = (int *)b;
    return *(int *)(A)- *(int *)(B);
}
int main(){

    agent agents[3]{
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    int sales_medians[3];
    int highest_median = 0;
    int agent;

    for (int i = 0; i < 3; i++){
        qsort(agents[i].monthlySales, 12, sizeof(int), comparator);
        sales_medians[i] = (agents[i].monthlySales[5]+agents[i].monthlySales[6])/2;
    }
    for (int i = 0; i< 3; i++){
        if (sales_medians[i]>highest_median){
            highest_median = sales_medians[i];
            agent = i;
        }
    }
    cout << "The agent with the highest median sales is agent number " << agent;
    // considering that there are twelve months and median is always
    // two middle numbers, there's no need to check if array has even 
    // or odd length
    
}