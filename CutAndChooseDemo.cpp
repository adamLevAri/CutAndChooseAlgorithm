//
//  CutAndChooseDemo.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "CutAndChoose.cpp"
#include "PiecewiseUniformAgent.cpp"
#include "PiecewiseConstantAgent.cpp"
#include <iostream>
#include <sstream>
#include <stdlib.h>


using namespace std;

int main(int argc, const char * argv[]){
    
    vector<vector<float>> vec;
    vec = {{0,1},{2,4},{6,9}};
    //Alice has two desired intervals, 0..1 and 3..6. Each interval has value 1.
    PiecewiseUniformAgent Alice(vec, "Alice");
    
    //George has four desired intervals: 0..1 with value 1, 1..2 with value 3, etc.
    PiecewiseConstantAgent George({11,22,33,44}, "George");
    
    cout << Alice.print() << endl;
    cout << George.print() << endl;
    
    //all details of George check
    cout << George.cakeValue() << " | " << George.cakeLength() << " | "
    << George.eval(1, 3) << " | " << George.mark(1, 77) << endl;
    
    //.mark() check
    cout << George.mark(1, 55) << " | " << George.mark(1.5, 44) << " | "
    << George.mark(1, 66) << " | " << George.mark(1.5, 55) << " | "
    << George.mark(1, 99) << " | " << George.mark(1, 0) << endl;
    
    //.eval() check
    cout << George.eval(1, 3) << " | " << George.eval(1.5, 3) << " | "
    << George.eval(1, 3.25) << " | " << George.eval(1.5, 3.25) << " | "
    << George.eval(3, 3) << " | " << George.eval(3, 7)  << " | "
    << George.eval(-1, 7) << endl;
    
    //*****************************
    
    cout << "ALICE SPECS:" <<endl;
    //all details of Alice check
    cout << Alice.cakeValue() << " | " << Alice.cakeLength() << " | "
    << Alice.eval(3, 1) << " | " << Alice.mark(1.5, 0.01) << endl;
    
    
    //*******************************
    
    cout << "MAIN:" << endl;
    
    PiecewiseConstantAgent Alice2 ({33,33,33}, "Alice2");
    PiecewiseConstantAgent George2 ({11,55}, "George2");
    
    
    //Cut & Choose Method:
    CutAndChoose cas;
    /*
    cout << "### Asymmetric protocol: ###" << endl;
    cout << "### Alice cuts and George chooses:" << endl;
    cout << cas.asymmetric_protocol({&Alice2, &George2}).print() << endl;

    cout <<"### George cuts and Alice chooses:" << endl;
    cout << cas.asymmetric_protocol({&George2, &Alice2}).print() << endl;

     */
    cout << "### Symmetric protocol: ###" << endl;
    cout << "### Alice cuts and George chooses:" << endl;
    cout << cas.symmetric_protocol({&Alice2, &George2}).print();
    
    cout <<"### George cuts and Alice chooses:" << endl;
    cout << cas.symmetric_protocol({&George2, &Alice2}).print();
    
    
        
    return 0;
}
    

