//
//  badkan.cpp
//  CutAndChoose
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "badkan.hpp"

int main(){

    vector<vector<float>> vec;
    vec = {{0,1},{2,4},{6,9}};
    
    //Alice has two desired intervals, 0..1 and 3..6. Each interval has value 1.
    PiecewiseUniformAgent Alice(vec, "Alice");
    
    //George has four desired intervals: 0..1 with value 1, 1..2 with value 3, etc.
    PiecewiseConstantAgent George({11,22,33,44}, "George");
    
    
    badkan::TestCase testcase1;
    badkan::TestCase testcase2;
    testcase1.setname("George tests")
        .CHECK_EQUAL(George.cakeValue(), 110)
        .CHECK_EQUAL(George.cakeLength(), 4)
        .CHECK_EQUAL(George.eval(1, 3), 55)
        .CHECK_EQUAL(George.mark(1, 77), 3.5)
        .print();
    
    testcase2.setname("Alice tests")
        .CHECK_EQUAL(Alice.cakeValue(), 6)
        .CHECK_EQUAL(Alice.cakeLength(), 9)
        .CHECK_EQUAL(Alice.eval(3, 1), 0)
        .CHECK_EQUAL(Alice.mark(0, 2), 3)
        .print();

    
    return 0;
}

