#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item {
    int value, weight;
};

double fractionalKnapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(), [](Item a, Item b){
        return (double)a.value/a.weight > (double)b.value/b.weight; 
    });

    double totalValue = 0;

    for(int i = 0; i < items.size(); i++){
        if(items[i].weight<=W){
            
            totalValue += items[i].value;
            W -= items[i].weight;          
        } else {
            totalValue += W * ((double)items[i].value / items[i].weight);
            break;
        }
    }
    return totalValue;
}