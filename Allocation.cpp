//
//  Allocation.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include <stdio.h>
#include "Agent.hpp"

using namespace std;

class Allocation {

private:
    
    vector<Agent*> agents;
    vector<vector<float>> pieces;
        
public:

    Allocation() {}
    
    Allocation(vector<Agent*> agents) {
        
        this->agents = agents;
        (this->pieces).resize(agents.size());
    }
    
    ~Allocation() {}
    
    //TODO: sets the piece of the given index
    void setPiece(int agentIndex, vector<float> piece){

        //this->pieces[agentIndex]
        this->pieces[agentIndex] = piece;
        
    }
    
    string toString(vector<float> vec){
        ostringstream os;
        os << "[" << vec[0] << ", " << vec[1] << "]" << endl;
        return os.str();
        
    }
    
    string print(){

        ostringstream os;
        for (int i=0; i<pieces.size(); i++) {
            os << agents[i]->getName() << " gets " << toString(pieces[i])
            << " with value " << agents[i]->pieceValue(pieces[i]) << endl;
        }
        
        return os.str();
        
    }
    
    
    
};

