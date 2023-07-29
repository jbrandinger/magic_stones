#include "implement.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

void bottom_up_analysis()
{
    //stones remain constant (inclduing 1 ensures a soltution)
    //vector<int> stones{1, 4, 7, 11, 15, 22};
    
    //test 1
    //int health = 527943;
    //time: 0.003 seconds
    
    //test 2
    //int health = 1055886;
    //time:  0.003 seconds
    
    //test 3
    //int health = 2111772;
    //time:  0.004 seconds
    
    //test 4
    //int health = 4223544;
    //time:  0.008 seconds
    
    //test 5
    //int health = 8447088;
    //time:  0.014 seconds
    
    //test 6
    //int health = 16894176;
    //time:  0.025 seconds
    
    //test 7
    //int health = 33788352;
    //time:  0.058 seconds
    
    //test 8
    //int health = 67576704;
    //time:  0.120 seconds
    
    //test 9
    //int health = 135153408;
    //time:  0.228 seconds
    
    //test 10
    //int health = 270306816;
    //time:  0.454 seconds
    
    // cout << "result: " << magicStonesBottomup(stones, health) << endl;
}
void top_down_analysis()
{
    //stones remain constant (inclduing 1 ensures a soltution)
    //vector<int> stones{1, 4, 7, 11, 15, 22};
    
    // all tests < 65,000 (stack overflow for greater health)
    
    //test 1
    //int health = 228;
    //time: 0.001 seconds
    
    //test 2
    //int health = 456;
    //time:  0.000 seconds
    
    //test 3
    //int health = 912;
    //time:  0.001 seconds
    
    //test 4
    //int health = 1824;
    //time:  0.002 seconds
    
    //test 5
    //int health = 3648;
    //time:  0.001 seconds
    
    //test 6
    //int health = 7296;
    //time:  0.000 seconds
    
    //test 7
    //int health = 14592;
    //time:  0.003 seconds
    
    //test 8
    //int health = 29184;
    //time:  0.000 seconds
    
    //test 9
    //int health = 58368;
    //time:  0.004 seconds
    
    //test 10
    //int health = 116736;
    //time:  stack overflow
    
    //cout << "Top Down result: " << magicStonesTopdown(stones, health) << endl;
}

void flip_analysis(){
    // vector<int> arr;
    // 
    // for (int i = 0; i < 292676608; i++) {
    //     arr.push_back(rand());
    // }
    
    //test 1 (571634 numbers in array)
    // time: 0.011 seconds
    
    //test 2 (1143268 numbers in array)
    // time: 0.013 seconds
    
    //test 3 (2286536 numbers in array)
    // time: 0.026 seconds
    
    //test 4 (4573072 numbers in array)
    // time: 0.051 seconds
    
    //test 5 (9146144 numbers in array)
    // time: 0.100 seconds
    
    //test 6 (18292288 numbers in array)
    // time: 0.221 seconds
    
    //test 7 (36584576 numbers in array)
    // time: 0.401 seconds
    
    //test 8 (73169152 numbers in array)
    // time: 0.833 seconds
    
    //test 9 (146338304 numbers in array)
    // time: 1.701 seconds
    
    //test 10 (292676608 numbers in array)
    // time: 3.345 seconds
    
    //cout << "Number of flips: " << countFlips(arr) << endl;
}


int main(){
    //bottom_up_analysis();
    //top_down_analysis();
    //flip_analysis();
    return 0;
}
