#ifndef FIELD_H
#define FIELD_H

#include<vector>



class Field
{
public:
    Field(const std::vector<std::vector<int>> & vec); //copies the content of the obj to an arr and calls the precomputation function
    Field(std::vector<std::vector<int>> && vec);//move the content of the obj to an arr and calls the precomputation function
    int Weight( int x1, int y1, int x2, int y2 );//Function returns the sum of all numbers in the define rectangle
    int PathCost();//This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner.
    void print(); //prints out all the elements in arr, weights and pathcost. This is used for testing purposes.
    void precomputation();//does precomputation for weights and pathcost
     
private:
    std::vector<std::vector<int>> arr;//store the data array
    std::vector<std::vector<int>> weights; //contains the precomputed sum for each element
    std::vector<std::vector<int>> pathcost;//contains the precomputed path cost for every cell 
};

//#include "Field.cpp"
#endif