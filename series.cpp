#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int seriesAlgo(int last){
    int series[last]={1};
    int divisors[] = {5,3,2};
    int arrPos = 1;
    // this will run n-2 times
    for(int i=2; arrPos<last; i++){
        int number = i;
        // this will run 3n-2 times
        for(int j =0;j<3;j++){
            if (number%divisors[j]==0){
                // this will run at most 3n-2*logn
                while(number%divisors[j]==0){
                    number = number/divisors[j];
                }
            }
        }

        if (number == 1){
            series[arrPos] = i;
            arrPos++;
        }
    }
    return series[last-1];
}
// the algorithm runtime is(0n + logn)

int seriesAlgo2(int last){
    int series[last]={1};
    unordered_set<int> value;
    value.insert(1);
    int divisors[] = {5,3,2};
    bool found = false;
    int arrPos = 1;
    for(int i=2; arrPos<last; i++){
        int number = i;
        for(int j =0;j<3;j++){
            found = false;
            if (number%divisors[j]==0){
                while(number%divisors[j]==0 && !found){
                    number = number/divisors[j];
                    if (arrPos>10){
                        if(value.find(number)!= value.end()){
                            found = true;
                        }
                    }
                }
            }
            if (found) break;
        }

        if (number == 1 || found){
            series[arrPos] = i;
            cout<<"im putting "<< i<<endl;
            cin.get();
            value.insert(i);
            arrPos++;
        }
    }
    delete set_kepper;
    return series[last-1];
}

int main(){
    cout<<seriesAlgo(1500);
}
