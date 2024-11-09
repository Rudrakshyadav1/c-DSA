#include<iostream>
#include<vector>
using namespace std;

int main(){
    // Petrol and distance vector structure {petrol, distance}
    vector<pair<int, int> > pumps = {{4, 6}, {6, 5}, {7, 3}, {4, 5}} ;
    
    int balance = 0;
    int deficit = 0;  
    int startIndex = 0; 
    for (int i = 0; i < pumps.size(); ++i) {
        int petrol = pumps[i].first;
        int distance = pumps[i].second;  
        balance += petrol - distance; 
        if (balance < 0) {  

            startIndex = i + 1;  
            deficit += balance;  
            balance = 0;  
        }
    }
    if (balance + deficit >= 0) {
        cout << "Truck can complete the circle starting at pump index: " << startIndex << endl;
    } else {
        cout << "Truck cannot travel the complete circular route from any starting point!" << endl;
    }
    
    return 0;
}
