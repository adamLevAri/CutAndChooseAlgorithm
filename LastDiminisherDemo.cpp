//
//  LastDiminisherDemo.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 26/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "PiecewiseUniformAgent.cpp"
#include "PiecewiseConstantAgent.cpp"
#include "LastDiminisher.cpp"
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
    
    int main(int argc, const char * argv[]){
      
        PiecewiseConstantAgent Alice({3,6,3}, "Alice");
        PiecewiseConstantAgent George({0,2,4,6}, "George");
        PiecewiseConstantAgent Abraham({6,4,2,0}, "Abraham");
        PiecewiseConstantAgent Hana({3,3,3,3}, "Hana");
        
        vector<Agent*> allAgents = {&Alice, &George, &Abraham, &Hana};
        for (int i=0; i<allAgents.size(); i++) {
            allAgents[i]->print();
        }
        //Last Diminisher Method:
        
        cout << "### Order: Alice, George, Abraham, Hanna" << endl;
        LastDiminisher ld(allAgents);
        
        cout << "### Order: Hanna, Abraham, George, Alice" << endl;
        reverse(allAgents.begin(), allAgents.end());
        LastDiminisher rld(allAgents);
        
        
        return 0;
    };


